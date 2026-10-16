#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800000_bsbansnooze.s")

void func_80800098_bsbansnooze(PlayerState *arg0) {
    void _babackpack_set_state(void *, s32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_800959C8(PlayerState *, f32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    void func_800A0CD0(void *, s32);
    void func_800A4DA4(PlayerState *, s32);

    if (func_8009E77C(arg0, 0x14) == 0) {
        func_800A0CD0(arg0, 0);
        _babackpack_set_state(arg0, 6);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 60.0f, 30.0f);
        func_800A4DA4(arg0, 8);
    }
}

void func_80800128_bsbansnooze(PlayerState *arg0, f32 arg1) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 50.0f, 100.0f) * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_8080019C_bsbansnooze.s")

void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
void func_8009FFD8(PlayerState *, s32, s32, s32, s32);

void func_808001FC_bsbansnooze(PlayerState *arg0) {
    void bainput_enable(PlayerState *, s32, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    (*(s8 *)((s8 *)(arg0) + (0x15D))) = 0;
    baanim_playForDuration_onceSmooth(arg0, 0x276, 1.5f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009DE38(arg0, 0x583, 1.0f);
    bainput_enable(arg0, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800278_bsbansnooze.s")

s32 bsbansnooze_entrypoint_0(s32 arg0) {
    extern s32 D_80800A40_bsbansnooze[];
    return ((s32 *)&D_80800A40_bsbansnooze)[arg0];
}

void func_8080037C_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

void func_8080039C_bsbansnooze(PlayerState *arg0) { void baphysics_set_target_horizontal_velocity(PlayerState *, f32); void func_8009DF94(PlayerState *, s32, f32, s32); func_80800098_bsbansnooze(arg0); baanim_playForDuration_onceSmooth(arg0, 0x279, 1.6f); func_8009FFD8(arg0, 1, 1, 3, 2); baphysics_set_target_horizontal_velocity(arg0, 0.0f); func_8009DF94(arg0, 0x58D, 1.0f, 0x7530); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800414_bsbansnooze.s")

s32 bsbansnooze_entrypoint_1(s32 arg0) {
    extern s32 D_80800A50_bsbansnooze[];
    return ((s32 *)&D_80800A50_bsbansnooze)[arg0];
}

void func_808004C0_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808004E0_bsbansnooze.s")

void func_80800588_bsbansnooze(s32 arg0)
{
  f32 anctrl_getAnimTimer(s32);
  s32 baanim_getAnimCtrlPtr();
  s32 bakey_released(s32, s32);
  s32 bastick_getZone(PlayerState *);
  s32 bs_setState(s32, s32);
  s32 func_8009BCD4(s32, s32);
  f32 func_800F3780(f32, s32 *, s32);
  void func_80800128_bsbansnooze(PlayerState *, f32);
  s32 player_inWater(s32);
  extern s32 D_80800A60_bsbansnooze;
  s32 var_s1;
  s32 new_var;
  new_var = baanim_getAnimCtrlPtr();
  var_s1 = 0;
  func_80800128_bsbansnooze(arg0, func_800F3780(anctrl_getAnimTimer(new_var), &D_80800A60_bsbansnooze, 3));
  if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 0x40400000) != 0))
  {
    var_s1 = 0x16F;
  }
  if (bakey_released(arg0, 1) != 0)
  {
    var_s1 = 0x172;
  }
  if (player_inWater(arg0) != 0)
  {
    var_s1 = 0x4C;
  }
  bs_setState(arg0, var_s1);
}

s32 bsbansnooze_entrypoint_2(s32 arg0) {
    extern s32 D_80800A78_bsbansnooze[];
    return ((s32 *)&D_80800A78_bsbansnooze)[arg0];
}

void func_8080064C_bsbansnooze(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800000_bsbansnooze(arg0);
}
void func_80800674_bsbansnooze(PlayerState *arg0)
{
    func_80800098_bsbansnooze(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_8080069C_bsbansnooze(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bsbansnooze_entrypoint_3(s32 arg0) {
    extern s32 D_80800A88_bsbansnooze[];
    return ((s32 *)&D_80800A88_bsbansnooze)[arg0];
}

void func_808006D0_bsbansnooze(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsbansnooze(arg0);
}
void func_808006F8_bsbansnooze(PlayerState *arg0)
{
    func_80800098_bsbansnooze(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800720_bsbansnooze(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x16F;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbansnooze_entrypoint_4(s32 arg0) {
    extern s32 D_80800A98_bsbansnooze[];
    return ((s32 *)&D_80800A98_bsbansnooze)[arg0];
}

void func_8080076C_bsbansnooze(s32 arg0)
{
    func_800951B4();
    func_80800000_bsbansnooze(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800794_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808008A4_bsbansnooze.s")

s32 bsbansnooze_entrypoint_5(s32 arg0) {
    extern s32 D_80800AA8_bsbansnooze[];
    return ((s32 *)&D_80800AA8_bsbansnooze)[arg0];
}

#include "common.h"
typedef struct player_state_s PlayerState;

void func_80800000_bsbwhirl(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
}

void func_80800008_bsbwhirl(PlayerState *arg0) {
    f32 func_80092B8C(PlayerState *, f32 *);
    f32 func_80092BE8(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    s8 func_800BF8E4(void);
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8F64(s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800F50_bsbwhirl;
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    if (func_800BF8E4() > 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x160))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (0x160))) = func_800C8A98();
            func_800C8E54((*(s32 *)((s8 *)(arg0) + (0x160))), 80.0f, 350.0f);
            func_800C8F64((*(s32 *)((s8 *)(arg0) + (0x160))), 0xB);
            func_800C8E84((*(s32 *)((s8 *)(arg0) + (0x160))), &D_80800F50_bsbwhirl);
        }
        sp24 = func_80092B8C(arg0, sp28);
        func_8009C128(arg0, sp34);
        func_800EF04C(sp34, sp28);
        func_800EF1B8(sp34, func_80092BE8(arg0), sp24);
        sp34[1] += sp24;
        func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x160))), sp34);
    }
}

void func_808000D8_bsbwhirl(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x160)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x160))) = _chlightfader_entrypoint_1(temp_a3, 0.25f, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_80800114_bsbwhirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_8080017C_bsbwhirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_80800200_bsbwhirl.s")

/* extern */

s32 func_808003A8_bsbwhirl(PlayerState *arg0, s32 arg1) {
    int bakey_pressed(PlayerState *, int);
    int bakey_released(PlayerState *, int);
    int bastick_getZone(PlayerState *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    s32 var_s1;

    var_s1 = arg1;
    if (bastick_getZone(arg0) > 0) {
        var_s1 = 0x1C;
    }
    if (bakey_released(arg0, 1) != 0) {
        var_s1 = 0x1E;
    }
    if ((bakey_pressed(arg0, 8) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x1D;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x2D;
    }
    return var_s1;
}

void func_80800430_bsbwhirl(void *arg0, s32 *arg1)
{
  f32 new_var;
  s32 _chusefeather_entrypoint_1(s32, s32);
  s32 _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
  s32 func_8009DF18(void *, s32, s32, s32);
  f32 func_800D8FF8();
  new_var = func_800D8FF8();
  *((f32 *) (((s8 *) arg0) + 0x16C)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x16C))) + new_var);
  if ((*((f32 *) (((s8 *) arg0) + 0x16C))) > 2.0f)
  {
    *((f32 *) (((s8 *) arg0) + 0x16C)) = 0.0f;
    _suinv_entrypoint_0(arg1, 0x1E, -1, 0x47, 1);
    if ((*arg1) != 0x1E)
    {
      func_8009DF18(arg0, 0x3E9, 0x3F4CCCCD, 0x6D60);
      _chusefeather_entrypoint_1(*((s32 *) (((s8 *) arg0) + 0x184)), 1);
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_0.s")

/* extern */

void bsbwhirl_entrypoint_1(s32 arg0) {
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr(s32);
    void bs_setState(PlayerState *, int);
    s32 sp1C;

    sp1C = 0;
    bainput_enable((void *)arg0, 1, 1);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0)) != 0) {
        sp1C = 0x1B;
    }
    func_80800008_bsbwhirl(arg0);
    bs_setState(arg0, sp1C);
}

/* extern */

void bsbwhirl_entrypoint_2(s32 arg0) { bainput_enable(arg0, 1, 1); func_8080017C_bsbwhirl(arg0); }


s32 bsbwhirl_entrypoint_3(s32 arg0) {
    extern s32 D_80800F98_bsbwhirl[];
    return ((s32 *)&D_80800F98_bsbwhirl)[arg0];
}

/* extern */

void bsbwhirl_entrypoint_4(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void baphysics_set_target_horizontal_velocity(void *, f32);
    s32 func_8009FFD8(s32, s32, s32, s32, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x23, 0x3F800000);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity((void *)arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_5.s")

void bsbwhirl_entrypoint_6()
{
    func_8080017C_bsbwhirl();
}

s32 bsbwhirl_entrypoint_7(s32 arg0) {
    extern s32 D_80800FA8_bsbwhirl[];
    return ((s32 *)&D_80800FA8_bsbwhirl)[arg0];
}

/* extern */

void bsbwhirl_entrypoint_8(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_8008C9F0(s32, s32, s32, s32, f32);
    s32 func_8009FFD8(s32, s32, s32, s32, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x11, 0x3F07AE14);
    func_8008C9F0(arg0, 0x42A00000, 0x43D48000, 0x3F0F5C29, 0.4f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_9.s")

void bsbwhirl_entrypoint_10()
{
    func_8080017C_bsbwhirl();
}

s32 bsbwhirl_entrypoint_11(s32 arg0) {
    extern s32 D_80800FB8_bsbwhirl[];
    return ((s32 *)&D_80800FB8_bsbwhirl)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_13.s")

void bsbwhirl_entrypoint_14(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080017C_bsbwhirl(arg0);
}
s32 bsbwhirl_entrypoint_15(s32 arg0) {
    extern s32 D_80800FC8_bsbwhirl[];
    return ((s32 *)&D_80800FC8_bsbwhirl)[arg0];
}

/* extern */

void bsbwhirl_entrypoint_16(PlayerState *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, f32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    void baphysics_set_target_horizontal_velocity(void *, f32);
    s32 func_8008B188(s32, s32);
    s32 func_8008CA4C(s32, s32);
    s32 func_8009D2D8(s32, s32);
    s32 func_800FCAE0(s32, s32, s32);
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x22);
    anctrl_setDuration(temp_v0, 0.5f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(arg0, 1);
    func_8009D2D8(arg0, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800FCAE0(0xD, 0, 0xFA0);
}

/* extern */

void bsbwhirl_entrypoint_17(s32 arg0) {
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr();
    void bs_setState(PlayerState *, int);
    s32 sp1C;

    sp1C = 0;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr()) != 0) {
        sp1C = 1;
    }
    func_80800008_bsbwhirl(arg0);
    bs_setState(arg0, sp1C);
}

void bsbwhirl_entrypoint_18()
{
    func_8080017C_bsbwhirl();
}

s32 bsbwhirl_entrypoint_19(s32 arg0) {
    extern s32 D_80800FD8_bsbwhirl[];
    return ((s32 *)&D_80800FD8_bsbwhirl)[arg0];
}

void bsbwhirl_entrypoint_20()
{
    _bsdrone_entrypoint_0();
}

void bsbwhirl_entrypoint_21(s32 arg0)
{
    func_80800200_bsbwhirl();
    func_80800008_bsbwhirl(arg0);
    _bsdrone_entrypoint_1(arg0);
}

void bsbwhirl_entrypoint_22(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_8080017C_bsbwhirl(arg0);
}
s32 bsbwhirl_entrypoint_23(s32 arg0) {
    extern s32 D_80800FE8_bsbwhirl[];
    return ((s32 *)&D_80800FE8_bsbwhirl)[arg0];
}

void bsbwhirl_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_8080017C_bsbwhirl(arg0);
}
void bsbwhirl_entrypoint_25()
{
    _bsrest_entrypoint_16();
}

void bsbwhirl_entrypoint_26(PlayerState *arg0) {
    int func_80800200_bsbwhirl(PlayerState *);
    void func_80800008_bsbwhirl(PlayerState *);
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 sp24;
    PlayerState *self;

    self = arg0;
    sp24 = 0;
    func_80800200_bsbwhirl(self);
    func_80800008_bsbwhirl(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        sp24 = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, sp24);
}

s32 bsbwhirl_entrypoint_27(s32 arg0) {
    extern s32 D_80800FF8_bsbwhirl[];
    return ((s32 *)&D_80800FF8_bsbwhirl)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_80800EA0_bsbwhirl.s")

void bsbwhirl_entrypoint_28(s32 *arg0) {
    s32 func_80800EA0_bsbwhirl();
    extern s32 func_80099B94;
    func_80800EA0_bsbwhirl(arg0, &func_80099B94);
}

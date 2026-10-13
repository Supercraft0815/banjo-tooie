#include "common.h"

void func_80800000_bsbwhirl(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_80800008_bsbwhirl.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/func_808003A8_bsbwhirl.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_1.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_16.s")

/* extern */

void bsbwhirl_entrypoint_17(s32 arg0) {
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 bs_setState(s32, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bwhirl/bsbwhirl_entrypoint_26.s")

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

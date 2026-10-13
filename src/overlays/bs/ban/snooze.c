#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800000_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800098_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800128_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_8080019C_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808001FC_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800278_bsbansnooze.s")

s32 bsbansnooze_entrypoint_0(s32 arg0) {
    extern s32 D_80800A40_bsbansnooze[];
    return ((s32 *)&D_80800A40_bsbansnooze)[arg0];
}

void func_8080037C_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

void func_8080039C_bsbansnooze(PlayerState *arg0) { void baphysics_set_target_horizontal_velocity(PlayerState *, f32); void func_8009DF94(PlayerState *, s32, f32, s32); func_80800098_bsbansnooze(arg0); baanim_playForDuration_onceSmooth(arg0, 0x279, 0x3FCCCCCD); func_8009FFD8(arg0, 1, 1, 3, 2); baphysics_set_target_horizontal_velocity(arg0, 0.0f); func_8009DF94(arg0, 0x58D, 1.0f, 0x7530); }

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800588_bsbansnooze.s")

s32 bsbansnooze_entrypoint_2(s32 arg0) {
    extern s32 D_80800A78_bsbansnooze[];
    return ((s32 *)&D_80800A78_bsbansnooze)[arg0];
}

void func_8080064C_bsbansnooze(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800000_bsbansnooze(arg0);
}
void func_80800674_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
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
void func_808006F8_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
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

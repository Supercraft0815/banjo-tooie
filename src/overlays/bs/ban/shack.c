#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800000_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800074_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800100_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800164_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080021C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808002AC_bsbanshack.s")

/* extern */

void func_8080030C_bsbanshack(PlayerState *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel);
    s32 func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    arg0->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(arg0, 0x145, 0x3FB33333);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 5, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080037C_bsbanshack.s")

s32 bsbanshack_entrypoint_0(s32 arg0) {
    extern s32 D_80800CB0_bsbanshack[];
    return ((s32 *)&D_80800CB0_bsbanshack)[arg0];
}

void func_80800430_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800450_bsbanshack(PlayerState *arg0) { s32 baanim_playForDuration_onceSmooth(void *, s32, s32); void baphysics_set_target_horizontal_velocity(PlayerState *, f32); s32 func_8009FFD8(PlayerState *, s32, s32, s32, s32); func_8080021C_bsbanshack(); baanim_playForDuration_onceSmooth(arg0, 0x295, 0x3FB33333); func_8009FFD8(arg0, 1, 1, 1, 2); baphysics_set_target_horizontal_velocity(arg0, 0.0f); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808004AC_bsbanshack.s")

s32 bsbanshack_entrypoint_1(s32 arg0) {
    extern s32 D_80800CC0_bsbanshack[];
    return ((s32 *)&D_80800CC0_bsbanshack)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808005DC_bsbanshack.s")

void func_80800744_bsbanshack(s32 arg0)
{
    func_808005DC_bsbanshack(arg0,0);
    func_80800164_bsbanshack(arg0);
}

void func_80800770_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    *(u8 *)((u8 *)arg0 + 0x15C) = 0;
    func_808005DC_bsbanshack(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808007A0_bsbanshack.s")

s32 bsbanshack_entrypoint_2(s32 arg0) {
    extern s32 D_80800CD0_bsbanshack[];
    return ((s32 *)&D_80800CD0_bsbanshack)[arg0];
}

void func_80800928_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800948_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808009E4_bsbanshack.s")

s32 bsbanshack_entrypoint_3(s32 arg0) {
    extern s32 D_80800CE0_bsbanshack[];
    return ((s32 *)&D_80800CE0_bsbanshack)[arg0];
}

void func_80800AD0_bsbanshack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800164_bsbanshack(arg0);
}
void func_80800AF8_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800B20_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bsbanshack_entrypoint_4(s32 arg0) {
    extern s32 D_80800CF0_bsbanshack[];
    return ((s32 *)&D_80800CF0_bsbanshack)[arg0];
}

void func_80800B54_bsbanshack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800164_bsbanshack(arg0);
}
void func_80800B7C_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsrest_entrypoint_16(arg0);
}
void func_80800BA4_bsbanshack(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(Actor *, u8 *);
    s32 next_state;
    s32 unused;

    next_state = 0;
    if (_bsrest_entrypoint_20() != 0) {
        next_state = 0x16C;
    }
    bs_setState((Actor *)arg0, (u8 *)next_state);
}

s32 bsbanshack_entrypoint_5(s32 arg0) {
    extern s32 D_80800D00_bsbanshack[];
    return ((s32 *)&D_80800D00_bsbanshack)[arg0];
}

void func_80800BF0_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800C10_bsbanshack.s")

/* extern */

void func_80800C6C_bsbanshack(Actor *arg0) {
    void* func_80800074_bsbanshack(Actor*, u32);
    s32 bs_setState(Actor *, u8 *);
    bs_setState(arg0, func_80800074_bsbanshack(arg0, 0U));
}

s32 bsbanshack_entrypoint_6(s32 arg0) {
    extern s32 D_80800D10_bsbanshack[];
    return ((s32 *)&D_80800D10_bsbanshack)[arg0];
}

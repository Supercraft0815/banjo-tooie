#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800000_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808000B0_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800114_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800174_bsvanswim.s")

/* extern */

void func_808001CC_bsvanswim(s32 arg0) {
    s32 _bsvan_entrypoint_0(s32);
    s32 func_800961AC(s32, s32);
    s32 func_8009BC34();
    func_8009BC34();
    func_800961AC(arg0, 1);
    _bsvan_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800200_bsvanswim.s")

void func_808002D0_bsvanswim(void *arg0) {
    f32 baphysics_get_vertical_velocity(void *);
    void baphysics_set_vertical_velocity(void *, f32);
    void func_8009C128(void *, f32 *);
    s32 func_8009FBB0(void *, f32 *, f32);
    void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
    f32 func_800F0E00(f32, f32);
    f32 mlAbsF(f32);
    s32 next_state;
    f32 position[3];
    s32 effect;

    next_state = 0;
    func_8009C128(arg0, position);
    position[1] += 60.0f;
    effect = func_8009FBB0(arg0, position, 20.0f);
    func_800BA930(effect, -30, -30, -30, 30, 30, 30);
    func_800BA22C(effect, 1);
    if (*(f32 *)((u8 *)arg0 + 0x16C) < 0.0f) {
        *(f32 *)((u8 *)arg0 + 0x16C) += func_800F0E00(mlAbsF(*(f32 *)((u8 *)arg0 + 0x16C)) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(arg0, *(f32 *)((u8 *)arg0 + 0x16C));
    }
    if (player_isStable(arg0)) {
        next_state = 0x11B;
    }
    if (!player_inWater(arg0)) {
        next_state = 0x11A;
    }
    if (baphysics_get_vertical_velocity(arg0) >= 0.0f) {
        next_state = 0x11B;
    }
    _bsvan_entrypoint_3(arg0);
    bs_setState(arg0, next_state);
}

s32 bsvanswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800980_bsvanswim[];
    return ((s32 *)&D_80800980_bsvanswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080042C_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080049C_bsvanswim.s")

void func_808005E8_bsvanswim()
{
    func_80800174_bsvanswim();
}

s32 bsvanswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800990_bsvanswim[];
    return ((s32 *)&D_80800990_bsvanswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080061C_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808006D0_bsvanswim.s")

void func_80800808_bsvanswim()
{
    func_80800174_bsvanswim();
}

s32 bsvanswim_entrypoint_2(s32 arg0) {
    extern s32 D_808009A0_bsvanswim[];
    return ((s32 *)&D_808009A0_bsvanswim)[arg0];
}

void func_8080083C_bsvanswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bsvanswim(arg0);
}
void func_80800864_bsvanswim(s32 arg0)
{
    func_80800114_bsvanswim();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_8080088C_bsvanswim(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x11B;
    }
    _bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp1C);
}

s32 bsvanswim_entrypoint_3(s32 arg0) {
    extern s32 D_808009B0_bsvanswim[];
    return ((s32 *)&D_808009B0_bsvanswim)[arg0];
}

void func_808008E4_bsvanswim(s32 arg0)
{
    func_80800114_bsvanswim();
    _bsdrone_entrypoint_0(arg0);
}
void func_8080090C_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bsvan_entrypoint_3(arg0);
}
void func_80800934_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bsvanswim(arg0);
}
s32 bsvanswim_entrypoint_4(s32 arg0) {
    extern s32 D_808009C0_bsvanswim[];
    return ((s32 *)&D_808009C0_bsvanswim)[arg0];
}

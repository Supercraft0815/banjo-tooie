#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800000_bscarry.s")

/* extern */

void func_808000D0_bscarry(s32 arg0) {
    s32 _bsdrone_entrypoint_3(s32);
    s32 func_8009E6EC();
    s32 func_80800000_bscarry(s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    if ((temp_v0 == 8) || (temp_v0 == 0x12) || (temp_v0 == 0x16)) {
        func_80800000_bscarry(arg0);
        return;
    }
    _bsdrone_entrypoint_3(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800128_bscarry.s")

/* extern */

void func_808001D4_bscarry(PlayerState *arg0) {
    s32 func_8009E69C(PlayerState *, s32);
    void bastick_popZone(PlayerState *);
    if (func_8009E69C(arg0, 0x400) == 0) {
        bastick_popZone(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800208_bscarry.s")

void func_8080027C_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

/* extern */

void func_8080029C_bscarry(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_8008C9F0(s32, s32, s32, s32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    func_80800208_bscarry();
    baanim_playForDuration_loopSmooth(arg0, 0x28, 0x3F4CCCCD);
    func_8009FFD8((PlayerState *)arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 0x41F00000, 0x42700000, 0x3FE66666, 1.2f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800310_bscarry.s")

s32 bscarry_entrypoint_0(s32 arg0) {
    extern s32 D_808007B0_bscarry[];
    return ((s32 *)&D_808007B0_bscarry)[arg0];
}

void func_808003D8_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_808003F8_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_8080047C_bscarry.s")

s32 bscarry_entrypoint_1(s32 arg0) {
    extern s32 D_808007C0_bscarry[];
    return ((s32 *)&D_808007C0_bscarry)[arg0];
}

void func_80800500_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800520_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800594_bscarry.s")

s32 bscarry_entrypoint_2(s32 arg0) {
    extern s32 D_808007D0_bscarry[];
    return ((s32 *)&D_808007D0_bscarry)[arg0];
}

void func_8080065C_bscarry(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808001D4_bscarry(arg0);
}
void func_80800684_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsdrone_entrypoint_0(arg0);
}
void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bscarry_entrypoint_3(s32 arg0) {
    extern s32 D_808007E0_bscarry[];
    return ((s32 *)&D_808007E0_bscarry)[arg0];
}

void func_808006E0_bscarry(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808001D4_bscarry(arg0);
}
void func_80800708_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800730_bscarry(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 _bahold_entrypoint_5(s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x3A;
    }
    if (_bahold_entrypoint_5(arg0) == 0) {
        sp1C = 0x73;
    }
    bs_setState(arg0, sp1C);
}

s32 bscarry_entrypoint_4(s32 arg0) {
    extern s32 D_808007F0_bscarry[];
    return ((s32 *)&D_808007F0_bscarry)[arg0];
}

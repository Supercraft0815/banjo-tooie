#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800000_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800018_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800038_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800274_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_1.s")

void bsstand_entrypoint_2(PlayerState *arg0) {
    s32 func_800A0CF4(PlayerState *, s32);
    s32 func_80090A2C();
    void func_800951B4(void* mem);
    func_800A0CF4(arg0, 0);
    func_80090A2C(arg0);
    func_800951B4(arg0);
}

s32 bsstand_entrypoint_3(s32 arg0) {
    extern s32 D_80800D98_bsstand[];
    return ((s32 *)&D_80800D98_bsstand)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_5.s")

void bsstand_entrypoint_6(s32 arg0) 
{
}
s32 bsstand_entrypoint_7(s32 arg0) {
    extern s32 D_80800DA8_bsstand[];
    return ((s32 *)&D_80800DA8_bsstand)[arg0];
}

void bsstand_entrypoint_8()
{
    func_80800038_bsstand();
}

void bsstand_entrypoint_9()
{
    _bsdrone_entrypoint_0();
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(s32 arg0)
{
    _bafpctrl_entrypoint_10(arg0,0);
    _bsdrone_entrypoint_2(arg0);
}

s32 bsstand_entrypoint_12(s32 arg0) {
    extern s32 D_80800DB8_bsstand[];
    return ((s32 *)&D_80800DB8_bsstand)[arg0];
}

#include "common.h"

s32 basetup_entrypoint_0() 
{
    return 0x4;
}

/* extern */

void func_80800008_basetup(s32 arg0) {
    s32 func_800A0FF0(s32);
    s32 func_800DA298(s32);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    s32 func_800EA090();
    s32 sp1C;
    s32 sp18;

    sp1C = func_800EA05C();
    sp18 = func_800EA090();
    if ((func_800DB9B0() == 0) && (((sp1C == 0x13A) && (sp18 == 0xE)) || ((sp1C == 0x136) && (sp18 == 0x1B))) && (func_800DA298(0x327) != 0)) {
        func_800A0FF0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800080_basetup.s")

/* extern */

void func_80800140_basetup(void *arg0) {
    s32 func_800C6A7C(s32 *, void *, s32 *, s32);
    s32 func_800EE7F8(s32 *, void *);
    s32 sp24[3];
    s32 sp18[3];

    func_800EE7F8(sp18, arg0);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) - 1000.0f);
    func_800C6A7C(sp18, arg0, sp24, 0x420025);
}

/* extern */

struct player_state_s;

void func_80800194_basetup(struct player_state_s *self, void *arg1, void *arg2) {
    int func_800A3274(struct player_state_s *);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    s32 func_800EA090(void);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800A3274(self);
    sp20 = func_800EA05C();
    sp1C = func_800EA090();
    if ((func_800DB9B0() == 0) && (((sp20 == 0x112) && (sp1C == 0xF)) || ((sp20 == 0x116) && (sp1C == 2))) && (sp24 == 0x12)) {
        func_80800140_basetup(arg1);
        func_80800140_basetup(arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/basetup_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_808002D4_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800394_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800534_basetup.s")

/* extern */

void func_808006F0_basetup(void) {
    s32 _gccubesearch_entrypoint_14(s32, s32);
    s32 _gemarkersDll_entrypoint_1();
    _gccubesearch_entrypoint_14(_gemarkersDll_entrypoint_1(), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_8080071C_basetup.s")

/* extern */

s32 func_80800778_basetup(s32 arg0) {
    u32 func_8009E958(void);
    void func_8009E9D8(s32);
    void func_8009EB18(s32);
    int func_800C6E38(s32);
    s32 func_800EA05C();
    s32 func_800EA068(s32);
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    temp_v0 = func_8009E958();
    var_s0 = temp_v0;
    if (temp_v0 != 1) {
        if ((temp_v0 == 9) && (func_800EA05C() == 0x116)) {
            var_s0 = 1;
            func_8009EB18(0);
        }
    } else if ((func_800EA068(8) != 0) && (func_800C6E38(0x15) != 0)) {
        var_s0 = 9;
    }
    if (func_800EA068(0x40) != 0) {
        temp_v0_2 = func_800EA05C();
        switch (temp_v0_2) {
            case 0x182:
                var_s0 = 0xC;
                break;
            case 0x188:
                var_s0 = 6;
                break;
            default:
                var_s0 = 9;
                break;
        }
        func_8009E9D8(var_s0);
    }
    return var_s0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/basetup_entrypoint_2.s")

void basetup_entrypoint_3(s32 arg0) 
{
}
void basetup_entrypoint_4(s32 arg0) 
{
}

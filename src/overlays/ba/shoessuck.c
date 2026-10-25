#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoessuck/bashoessuck_entrypoint_0.s")

void bashoessuck_entrypoint_1(s32 arg0, f32 arg1[3]) {
    s32 _gccubesearch_entrypoint_1(s32, f32[3]);
    void _gspropctrl_entrypoint_11(s32, f32[3]);
    void func_8009C128(s32, f32[3]);
    s32 temp_v0;

    func_8009C128(arg0, arg1);
    temp_v0 = _gccubesearch_entrypoint_1(0x16D, arg1);
    if (temp_v0 != 0) {
        _gspropctrl_entrypoint_11(temp_v0, arg1);
    }
}

void bashoessuck_entrypoint_2(struct player_state_s *arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_800932CC(arg0, 0);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800961AC(arg0, 1);
}

void bashoessuck_entrypoint_3(s32 arg0)
{
    func_800961AC(arg0,0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoessuck/bashoessuck_entrypoint_4.s")

s32 bashoessuck_entrypoint_5(struct player_state_s *arg0, f32 *arg1) {
    s32 _bashoes_entrypoint_9(void);
    void _bashoes_entrypoint_11(struct player_state_s *, s32);
    void _bamovespline_entrypoint_7(struct player_state_s *, s32);
    void _bamovespline_entrypoint_8(struct player_state_s *);
    void _bamovespline_entrypoint_9(struct player_state_s *, f32);
    Prop *_gccubesearch_entrypoint_5(s32 *, f32 *);
    s32 _glsplinefind_entrypoint_3(f32 *);
    void _gspropctrl_entrypoint_11(s32, f32[3]);
    void func_8009C128(s32, f32[3]);
    s32 baphysics_set_type(void *, s32);
    void func_8009BB24(void *, f32 *);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    f32 func_800C82CC(void *, f32 *);
    void *func_800D7520(s32);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    extern s32 D_80800800_bashoessuck[];
    Prop *firstProp;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    void *sp30;
    Prop *prop;
    u16 itemID;
    s32 sp24;

    if (_bashoes_entrypoint_9() != 0) {
        return 0;
    }
    func_8009BB24(arg0, sp58);
    sp58[1] = 0.0f;
    if (func_800EEFD4(sp58) < 1.0f) {
        return 0;
    }
    sp68 = yaw_get(arg0);
    firstProp = _gccubesearch_entrypoint_5(D_80800800_bashoessuck, arg1);
    if (firstProp == NULL) {
        return 0;
    }
    _gspropctrl_entrypoint_11(firstProp, sp34);
    sp24 = _glsplinefind_entrypoint_3(sp34);
    func_800C7A68(func_800D7520(sp24), 1.0f, arg1);
    prop = _gccubesearch_entrypoint_5(D_80800800_bashoessuck, arg1);
    if (prop == NULL) {
        return 0;
    }
    itemID = prop->ItemID;
    switch (itemID) {
        case 0x16B:
            _bashoes_entrypoint_11(arg0, 1);
            break;
        case 0x16C:
            _bashoes_entrypoint_11(arg0, 2);
            break;
    }
    func_8009C128(arg0, sp4C);
    sp30 = func_800D7520(sp24);
    sp6C = func_800C82CC(sp30, sp4C);
    func_800C7A68(sp30, sp6C, sp40);
    if (func_800EEB40(sp4C, sp40) < 1764.0f) {
        baphysics_set_type(arg0, 0x12);
        _bamovespline_entrypoint_7(arg0, sp24);
        _bamovespline_entrypoint_9(arg0, sp6C);
    } else {
        func_800F1E6C(sp4C, sp34, &sp64);
        if (mlAbsF(func_800F1DCC(sp64, sp68)) > 45.0f) {
            return 0;
        }
        sp70 = sp4C[1] - sp34[1];
        if (mlAbsF(sp70) > 20.0f) {
            return 0;
        }
        if (func_800EFB8C(sp4C, sp34) < sp70) {
            return 0;
        }
        baphysics_set_type(arg0, 0x12);
        _bamovespline_entrypoint_7(arg0, sp24);
        _bamovespline_entrypoint_8(arg0);
    }
    return 1;
}

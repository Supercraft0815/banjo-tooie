#include "common.h"

struct player_state_s;

s32 bashoessuck_entrypoint_0(struct player_state_s *arg0, f32 *arg1) {
    void func_8009C128(s32, f32[3]);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern f32 D_80800740_bashoessuck[][6];
    s32 pad;
    f32 position[3];
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    s32 i;
    s32 j;

    func_8009C128((s32)arg0, position);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 3; i++) {
            start[i] = position[i] + D_80800740_bashoessuck[j][i];
        }
        for (i = 0; i < 3; i++) {
            end[i] = position[i] + D_80800740_bashoessuck[j][i + 3];
        }
        if (func_800C6A7C(start, end, normal, 0x20020) != NULL
            && normal[1] < 0.8f) {
            func_800EE7F8(arg1, normal);
            return 1;
        }
    }
    func_800EFA4C(arg1, 0.0f, 1.0f, 0.0f);
    return 0;
}

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

void bashoessuck_entrypoint_4(struct player_state_s *arg0) {
    void _bamovespline_entrypoint_0(struct player_state_s *, f32 *);
    s32 _bamovespline_entrypoint_4(struct player_state_s *);
    void _bashoes_entrypoint_10(struct player_state_s *, f32);
    s32 bashoessuck_entrypoint_0(struct player_state_s *, f32 *);
    void baroll_setIdeal(struct player_state_s *, f32);
    f32 func_80013AAC(f32);
    u32 func_80092BC4(struct player_state_s *);
    void func_800932BC(void *, f32);
    f32 func_8009BB18(void *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1C98(f32 *, f32 *);
    int func_800F1EA4(f32 *, f32 *);
    void yaw_applyIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    s32 sp38;
    f32 sp2C[3];

    sp38 = func_80092BC4(arg0);
    func_800932CC(arg0, 0);
    if (_bamovespline_entrypoint_4(arg0) == 0) {
        func_800EFA4C(sp2C, 0.0f, func_8009BB18(arg0), 0.0f);
        yaw_setIdeal(arg0, sp2C[1]);
        return;
    }
    _bamovespline_entrypoint_0(arg0, sp78);
    if (bashoessuck_entrypoint_0(arg0, sp48) != 0) {
        func_800932CC(arg0, 1);
        _bashoes_entrypoint_10(arg0, 1.0f);
        func_800EFA20(sp6C, sp48, func_800EEAA4(sp78, sp48));
        func_800EFB24(sp60, sp78, sp6C);
        func_800EFA4C(sp54, 0.0f, 1.0f, 0.0f);
        if (sp48[1] > 0.99f) {
            sp9C = 0.0f;
            spA4 = 0.0f;
            spAC = 0.0f;
        } else {
            func_800EFA4C(sp3C, sp48[0], 0.0f, sp48[2]);
            func_800F1EA4(sp3C, &sp9C);
            spA4 = func_80013AAC(func_800F1C98(sp54, sp48));
            func_800EE97C(sp90, sp54, sp3C);
            spAC = (func_80013AAC(func_800F1C98(sp60, sp90)) - 90.0f) + 180.0f;
            if (sp60[1] < 0.0f) {
                spAC = 180.0f - spAC;
            }
            func_800EF934(sp84, sp60, -sp9C);
            if (sp84[0] < 0.0f) {
                spAC = 360.0f - spAC;
            }
        }
        if (sp38 != 0) {
            if (func_8009BB18(arg0) > 180.0f) {
                spAC += 180.0f;
            }
        }
        func_800932BC(arg0, sp9C);
        func_8009BF5C(arg0, spA4);
        yaw_setIdeal(arg0, spAC);
        baroll_setIdeal(arg0, 0.0f);
        if (sp38 == 0) {
            yaw_applyIdeal(arg0);
        }
    }
}

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

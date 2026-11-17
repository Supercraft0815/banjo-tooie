#include "common.h"

#include "overlays/bs/kaz/wingwhack.h"

extern s32 D_80800920_bskazwingwhack[];
extern s32 D_80800A80_bskazwingwhack[];
extern BtIntPtr D_80800AB8_bskazwingwhack[];
extern BtIntPtr D_80800AC8_bskazwingwhack[];

void func_80800000_bskazwingwhack(PlayerState *self, f32 arg1[3], f32 arg2, f32 arg3) {
    BtIntPtr temp_s0;
    f32 sp30[3];

    temp_s0 = func_800B5BE4(0xA);
    func_8009C128(self, sp30);
    func_800BA77C(temp_s0, 0, func_800136E4(func_800F1DF4(sp30, arg1) + arg2), arg3);
    if (func_8009EA2C() != 0) {
        func_800BA670(temp_s0, 0x619);
    } else {
        func_800BA670(temp_s0, 0x618);
    }
    func_800BABB8(temp_s0, arg1, NULL, 1.0f, D_80800A80_bskazwingwhack);
}

void func_808000DC_bskazwingwhack(PlayerState *self) {
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    yaw_set(self, func_80092BE8(self));
    func_800931AC(self, 1);
    _bskaz_entrypoint_2(self);
}

void func_80800148_bskazwingwhack(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, 0x138, 1.25f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_3_LOCKED_ROTATION);
    yaw_setVelocityBounded(self, 400.0f, 7.5f);
    baflag_set(self, BA_FLAG_36);
    baflag_set(self, BA_FLAG_5_HAS_PECKED);
    self->unk16C = func_8009BB5C(self);
    self->unk16C = func_800F13F0(self->unk16C, 1200.0f);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    func_800931AC(self, 3);
    func_8009328C(self, yaw_get(self));
    baphysics_set_vertical_velocity(self, 0.0f);
    baphysics_set_gravity(self, -200.0f);
    baphysics_set_terminal_velocity(self, -60.0f);
    func_8009DEC0(self, 0x459E, 0.95f, 1.05f, 26000, 26000);
    func_8009E4AC(self);
    self->unk170 = func_8009E138(self, 1);
}

void func_80800278_bskazwingwhack(PlayerState *self) {
    BanjoStateId next_state;
    f32 sp38[3];
    f32 temp_f0;
    f32 sp34;
    f32 var_f0;

    next_state = BS_STATE_0_INVALID;
    baphysics_set_target_yaw(self, yaw_get(self));
    temp_f0 = baanim_getTimer(self);
    if (temp_f0 < 0.5f) {
        var_f0 = func_800F10B4(temp_f0, 0.0f, 0.15f, self->unk170, 80.0f);
    } else {
        var_f0 = func_800F10B4(temp_f0, 0.8f, 0.6f, self->unk170, 80.0f);
    }
    sp34 = temp_f0;
    func_8009E55C(self, 1, var_f0);
    if (baanim_isAt(self, 0.05f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 12000);
    }
    if (baanim_isAt(self, 0.24f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 12000);
    }
    if (baanim_isAt(self, 0.48f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 12000);
    }
    if ((sp34 > 0.16f) && (sp34 < 0.82f)) {
        func_800F3BD0(self, 7, sp38);
        func_80800000_bskazwingwhack(self, sp38, 45.0f, 0.0f);
        func_800F3BD0(self, 9, sp38);
        func_80800000_bskazwingwhack(self, sp38, 70.0f, 0.0f);
    }
    if ((baanim_isAt(self, 0.64f) != 0) && (func_8008DF8C(self, 0xA) == 0)) {
        next_state = BS_STATE_DF;
    }
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bainput_should_feathery_flap(self) != 0) {
        next_state = BS_STATE_15C;
    }
    bs_setState(self, next_state);
}

BtIntPtr bskazwingwhack_entrypoint_0(s32 idx) {
    return D_80800AB8_bskazwingwhack[idx];
}

void func_808004A8_bskazwingwhack(PlayerState *self) {
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    _bskaz_entrypoint_2(self);
}

void func_808004DC_bskazwingwhack(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, ASSET_137_ANIM_BSKAZWINGWHACK_UNKNOWN, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    func_8009BA9C(self, NULL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009E4AC(self);
    func_8009E5A4(self, 2, 4);
    func_8009E55C(self, 2, 50.0f);
}

void func_80800580_bskazwingwhack(PlayerState *self) {
    AnimCtrl *animCtrl;
    BanjoStateId next_state;
    f32 animTimer;
    f32 sp28[3];
    AnimCtrl *otherAnimCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    animTimer = anctrl_getAnimTimer(animCtrl);
    if (anctrl_isAt(animCtrl, 0.27f) != 0) {
        func_8009E5A4(self, 2, 5);
    }
    if (anctrl_isAt(animCtrl, 0.442f) != 0) {
        func_8009E5A4(self, 2, 4);
    }
    if (anctrl_isAt(animCtrl, 0.71f) != 0) {
        func_8009E55C(self, 2, 0.0f);
    }
    baflag_clear(self, BA_FLAG_36);
    func_8009B9F0(self, func_800F3780(animTimer, D_80800920_bskazwingwhack, 0x2C));
    if (anctrl_isAt(animCtrl, 0.104f) != 0) {
        func_8009DF18(self, 0x459F, 1.0f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.154f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 15000);
    }
    if (anctrl_isAt(animCtrl, 0.317f) != 0) {
        func_8009DF18(self, 0x45A0, 1.05f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.367f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 15000);
    }
    if (anctrl_isAt(animCtrl, 0.58f) != 0) {
        func_8009DF18(self, 0x45A1, 0.95f, 26000);
    }
    if (anctrl_isAt(animCtrl, 0.63f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 15000);
    }
    if ((animTimer > 0.104f) && (animTimer < 0.222f)) {
        func_800F3BD0(self, 7, sp28);
        func_80800000_bskazwingwhack(self, sp28, 45.0f, 0.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((animTimer > 0.317f) && (animTimer < 0.4f)) {
        func_800F3BD0(self, 9, sp28);
        func_80800000_bskazwingwhack(self, sp28, func_800136E4(295.0f), 180.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((animTimer > 0.58f) && (animTimer < 0.7f)) {
        func_800F3BD0(self, 7, sp28);
        func_80800000_bskazwingwhack(self, sp28, 90.0f, -30.0f);
        baflag_set(self, BA_FLAG_36);
    }
    if (anctrl_isStopped(animCtrl) != 0) {
        next_state = BS_STATE_BB;
    }
    if (player_isStable(self) == 0) {
        next_state = BS_STATE_DF;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

BtIntPtr bskazwingwhack_entrypoint_1(s32 idx) {
    return D_80800AC8_bskazwingwhack[idx];
}
/* data_to_c.py: from asm/data/overlays/bs/kaz/wingwhack.data.s */
void func_80099B94(PlayerState *);
s32 D_80800920_bskazwingwhack [88] BT_DATA(4, overlays_bs_kaz_wingwhack, 0x0) = { 1023960469, 0, 1029946579, 1116334981, 1033852315, 1113637519, 1036831949, 1120347095, 1039811582, 1124626596, 1041489304, 1126093292, 1042985832, 1124059054, 1044475648, 1117070295, 1045965465, 1116758344, 1047455282, 1115739914, 1049136359, 1110607135, 1049881267, 1121703690, 1050626176, 1116051866, 1051743538, 1112436900, 1052491802, 1123351265, 1053236711, 1118645780, 1053981619, 1120016794, 1054726527, 1119727124, 1055474791, 1119762514, 1056219700, 1118375772, 1056964608, 1116251095, 1057337062, 1113349161, 1057709516, 1112324178, 1058083648, 1112976916, 1058456103, 1115974533, 1058828557, 1119620956, 1059201011, 1124249108, 1059575143, 1126213878, 1059947597, 1126818120, 1060320051, 1126413763, 1060692505, 1125065687, 1061064960, 1122837463, 1061439092, 1120396902, 1061811546, 1116255027, 1062184000, 1100412355, 1062556454, 1093486510, 1062930586, 1103568568, 1063303040, 1097481585, 1063675494, 1087037768, 1064047949, 1087939543, 1064420403, 1087939543, 1064794535, 1091011871, 1065166989, 1092416963, 1065353216, 1088107315 };
s32 D_80800A80_bskazwingwhack [14] BT_DATA(4, overlays_bs_kaz_wingwhack, 0x160) = { 2013397036, 65286, 0, -16384000, 1376256, 131110, 0, 0, 0, 2228736, 33554688, 16777259, 2490406, 18481152 };
BtIntPtr D_80800AB8_bskazwingwhack [4] BT_DATA(4, overlays_bs_kaz_wingwhack, 0x198) = { (BtIntPtr)func_808000DC_bskazwingwhack, (BtIntPtr)func_80800148_bskazwingwhack, (BtIntPtr)func_80800278_bskazwingwhack, (BtIntPtr)func_80099B94 };
BtIntPtr D_80800AC8_bskazwingwhack [6] BT_DATA(4, overlays_bs_kaz_wingwhack, 0x1A8) = { (BtIntPtr)func_808004A8_bskazwingwhack, (BtIntPtr)func_808004DC_bskazwingwhack, (BtIntPtr)func_80800580_bskazwingwhack, (BtIntPtr)func_80099B94, 0, 0 };

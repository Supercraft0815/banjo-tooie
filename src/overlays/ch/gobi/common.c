#include "common.h"

void chgobicommon_entrypoint_0(Actor *arg0) {
    s32 func_801022E4(Actor *);
    void func_80800070_chgobicommon(Actor *);
    void func_808000EC_chgobicommon(Actor *);
    void func_808001AC_chgobicommon(Actor *);
    s32 temp_v0;

    temp_v0 = func_801022E4(arg0);
    switch (temp_v0) {
        case 0x221:
            func_80800070_chgobicommon(arg0);
            return;
        case 0x222:
            func_808000EC_chgobicommon(arg0);
            return;
        case 0x223:
            func_808001AC_chgobicommon(arg0);
            return;
    }
}

void func_80800070_chgobicommon(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 func_800C0638(void);
    extern u32 D_8080021C_chgobicommon[4];
    extern u32 D_8080022C_chgobicommon[3];
    extern u32 D_80800238_chgobicommon[3];
    extern u32 D_80800244_chgobicommon[4];
    extern u32 D_80800254_chgobicommon[4];
    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = &arg0->position[0], D_8080021C_chgobicommon, D_80800244_chgobicommon);
    _subaddieaudioquick_entrypoint_4(arg0, temp_a1, D_8080022C_chgobicommon, D_80800254_chgobicommon);
    if (func_800C0638() == 0) {
        _subaddieaudioquick_entrypoint_3(arg0, temp_a1, D_80800238_chgobicommon, 0.03f);
    }
}

void func_808000EC_chgobicommon(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 func_800C0638(void);
    extern u32 D_80800200_chgobicommon[4];
    extern u32 D_80800210_chgobicommon[3];
    extern u32 D_80800264_chgobicommon[3];
    extern u32 D_80800270_chgobicommon[4];
    f32 *temp_s0;

    if (func_800C0638() == 0) {
        _subaddieaudioquick_entrypoint_4(arg0, &arg0->position[0], D_80800264_chgobicommon, D_80800270_chgobicommon);
    }
    temp_s0 = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, D_80800200_chgobicommon, 0.26f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, D_80800210_chgobicommon, 0.41f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, D_80800200_chgobicommon, 0.55f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, D_80800200_chgobicommon, 0.62f);
}

void func_808001AC_chgobicommon(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_80800200_chgobicommon[4];
    extern u32 D_80800210_chgobicommon[3];
    f32 *sp1C[2];

    sp1C[1] = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], D_80800200_chgobicommon, 0.65f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], D_80800210_chgobicommon, 0.0f);
}
/* data_to_c.py: from asm/data/overlays/ch/gobi/common.data.s */
u32 D_80800200_chgobicommon[4] BT_DATA(4, overlays_ch_gobi_common, 0x0) = { 0x130402, 0x1636B0, 0xA00E6, 0 };
u32 D_80800210_chgobicommon[3] BT_DATA(4, overlays_ch_gobi_common, 0x10) = { 0x130402, 0x1636B0, 0 };
u32 D_8080021C_chgobicommon[4] BT_DATA(4, overlays_ch_gobi_common, 0x1C) = { 0x13049C, 0x1636B0, 0xD00D9, 0xF30000 };
u32 D_8080022C_chgobicommon[3] BT_DATA(4, overlays_ch_gobi_common, 0x2C) = { 0x1305BB, 0xD00F3, 0x10C0000 };
u32 D_80800238_chgobicommon[3] BT_DATA(4, overlays_ch_gobi_common, 0x38) = { 0x1304CA, 0xD0126, 0x1400000 };
u32 D_80800244_chgobicommon[4] BT_DATA(4, overlays_ch_gobi_common, 0x44) = { 0x3EDC28F6, 0x3EF5C28F, 0x3F0F5C29, 0xBF800000 };
u32 D_80800254_chgobicommon[4] BT_DATA(4, overlays_ch_gobi_common, 0x54) = { 0x3F266666, 0x3F466666, 0x3F666666, 0xBF800000 };
u32 D_80800264_chgobicommon[3] BT_DATA(4, overlays_ch_gobi_common, 0x64) = { 0x1304CA, 0xD0126, 0x1400000 };
u32 D_80800270_chgobicommon[4] BT_DATA(4, overlays_ch_gobi_common, 0x70) = { 0x3E2E147B, 0x3EA3D70A, 0x3EF5C28F, 0xBF800000 };

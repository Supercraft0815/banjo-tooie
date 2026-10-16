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
    void _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    s32 func_800C0638(void);
    extern u32 D_8080021C_chgobicommon;
    extern u32 D_8080022C_chgobicommon;
    extern u32 D_80800238_chgobicommon;
    extern u32 D_80800244_chgobicommon;
    extern u32 D_80800254_chgobicommon;
    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_8080021C_chgobicommon, &D_80800244_chgobicommon);
    _subaddieaudioquick_entrypoint_4(arg0, temp_a1, &D_8080022C_chgobicommon, &D_80800254_chgobicommon);
    if (func_800C0638() == 0) {
        _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_80800238_chgobicommon, 0.03f);
    }
}

void func_808000EC_chgobicommon(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 func_800C0638(void);
    extern u32 D_80800200_chgobicommon;
    extern u32 D_80800210_chgobicommon;
    extern u32 D_80800264_chgobicommon;
    extern u32 D_80800270_chgobicommon;
    f32 *temp_s0;

    if (func_800C0638() == 0) {
        _subaddieaudioquick_entrypoint_4(arg0, (f32 *)((s8 *)arg0 + 4), &D_80800264_chgobicommon, &D_80800270_chgobicommon);
    }
    temp_s0 = (f32 *)((s8 *)arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, &D_80800200_chgobicommon, 0.26f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, &D_80800210_chgobicommon, 0.41f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, &D_80800200_chgobicommon, 0.55f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s0, &D_80800200_chgobicommon, 0.62f);
}

void func_808001AC_chgobicommon(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_80800200_chgobicommon;
    extern u32 D_80800210_chgobicommon;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800200_chgobicommon, 0.65f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800210_chgobicommon, 0.0f);
}

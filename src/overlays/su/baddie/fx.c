#include "common.h"

void subaddiefx_entrypoint_0(u8 *arg0, s32 arg1, u8 *arg2) {
    typedef struct {
        s32 angle0 : 15;
        s32 angle1 : 15;
        u32 active : 2;
        s16 phase0;
        s16 phase1;
    } FxState;
    typedef struct {
        u32 unused : 19;
        u32 enabled : 1;
        u32 rest : 12;
    } FxFlags;
    u8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    s32 _subaddieskeleton_entrypoint_2(s32, s32, f32 *);
    f32 func_800136E4(f32);
    f32 func_80013970(f32);
    s32 func_800B5BE4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32 *, s32, f32, s32 *);
    f32 func_800D8FF8(void);
    void func_800E3980(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_80103EAC(u8 *);
    f32 func_80103EF4(u8 *);
    OSThread *func_80104118(void);
    f32 func_8010A40C(u8 *);
    extern s32 D_808004E0_subaddiefx;
    extern s32 D_80800500_subaddiefx;
    f32 spBC[3];
    f32 spB8;
    f32 spAC[3];
    f32 spA0[3];
    f32 var_f20;
    f32 var_f28;
    f32 sp94;
    f32 phase1;
    f32 phase0[1];
    s32 var_s2;
    s32 sp84;
    s32 sp80;

    spB8 = func_80103EAC(arg0) * func_8010A40C(arg0);
    if ((arg1 == -1) || (_subaddieskeleton_entrypoint_2(*(s32 *)arg0, arg1, spBC) == 0)) {
        func_800EE7F8(spBC, (f32 *)(arg0 + 4));
        spBC[1] += 0.8f * func_80103EF4(arg0);
    }
    if (((FxFlags *)(arg0 + 0x7C))->enabled) {
        var_f28 = 0.0f;
        sp94 = func_800D8FF8();
        phase0[0] = ((FxState *)arg2)->phase0 * 0.00390625f;
        phase1 = ((FxState *)arg2)->phase1 * 0.00390625f;
        sp84 = func_800B5BE4(0x15);
        sp80 = func_800B5BE4(0x16);
        func_800BA3FC(sp84, 0x9E0);
        func_800BA3FC(sp80, 0x9E9);
        for (var_s2 = 0, var_f20 = 0.0f; var_s2 != 4; var_s2++) {
            func_800EEB9C(spA0, ((FxState *)arg2)->angle0 + var_f20, spB8 + var_f28);
            func_800EE780(spAC, spBC, spA0);
            spAC[1] += 30.0f * func_80013970(phase0[0] + var_f20);
            func_800BABB8(sp84, spAC, 0, 1.0f, &D_808004E0_subaddiefx);
            func_800EEB9C(spA0, ((FxState *)arg2)->angle1 + var_f20, spB8 + var_f28);
            func_800EE780(spAC, spBC, spA0);
            spAC[1] += 30.0f * func_80013970(phase1 + var_f20);
            func_800BABB8(sp80, spAC, 0, 1.0f, &D_808004E0_subaddiefx);
            var_f28 = 40.0f;
            var_f20 += 90.0f;
        }
        ((FxState *)arg2)->angle0 = (s32)func_800136E4(((FxState *)arg2)->angle0 + 390.0f * sp94);
        ((FxState *)arg2)->angle1 = (s32)func_800136E4(((FxState *)arg2)->angle1 - 430.0f * sp94);
        phase0[0] += sp94 * 100.0f;
        phase1 += sp94 * 150.0f;
        ((FxState *)arg2)->phase0 = (s32)(256.0f * phase1);
    }
    {
    void *temp_v0_2;
    f32 sp70[3];
    temp_v0_2 = func_80104118();
    if ((*(s16 *)((u8 *)temp_v0_2 + 0xE) == 0) || (*((u8 *)temp_v0_2 + 0xD) == 0)) {
        func_800EE7F8(temp_v0_2, spBC);
        *((u8 *)temp_v0_2 + 0xD) = 1;
    } else {
        func_800E3980(sp70);
        if (func_800EEB40(sp70, spBC) < func_800EEB40(sp70, temp_v0_2)) {
            func_800EE7F8(temp_v0_2, spBC);
        }
    }
    *((u8 *)temp_v0_2 + 0xC) = _subaddieaudioloop_entrypoint_7(*((u8 *)temp_v0_2 + 0xC), temp_v0_2, 1, &D_80800500_subaddiefx, *(s32 *)(arg0 + 0x70) & 1);
    if (!((FxState *)arg2)->active) {
        ((FxState *)arg2)->active = 1;
        *(s16 *)((u8 *)temp_v0_2 + 0xE) += 1;
    }
    }
}

/* extern */

void subaddiefx_entrypoint_1(s32 arg0, void *arg1) {
    typedef struct {
        s32 angle0 : 15;
        s32 angle1 : 15;
        u32 active : 2;
        s16 phase0;
        s16 phase1;
    } FxState;
    u8 _subaddieaudioloop_entrypoint_3(u8);
    OSThread *func_80104118(void);
    void *temp_v0;
    void *sp1C;

    if (((FxState *)arg1)->active) {
        temp_v0 = func_80104118();
        ((FxState *)arg1)->phase0 = 0;
        ((FxState *)arg1)->phase1 = 0;
        ((FxState *)arg1)->active = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0xD))) = 0;
        (*(s16 *)((s8 *)(temp_v0) + (0xE))) = (s16) ((*(s16 *)((s8 *)(temp_v0) + (0xE))) - 1);
        if ((*(s16 *)((s8 *)(temp_v0) + (0xE))) == 0) {
            sp1C = temp_v0;
            (*(u8 *)((s8 *)(sp1C) + (0xC))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xC))));
        }
    }
}

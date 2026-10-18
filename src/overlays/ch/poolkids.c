#include "common.h"

OSThread *chpoolkids_entrypoint_0(void)
{
    extern u8 D_808013F0_chpoolkids[];

    return (OSThread *) D_808013F0_chpoolkids;
}

OSThread *chpoolkids_entrypoint_1(void)
{
    extern u8 D_80801438_chpoolkids[];

    return (OSThread *) D_80801438_chpoolkids;
}

OSThread *chpoolkids_entrypoint_2(void)
{
    extern u8 D_80801480_chpoolkids[];

    return (OSThread *) D_80801480_chpoolkids;
}

/* extern */

void func_80800024_chpoolkids(void *arg0) {
    s32 _subaddiesect_entrypoint_1();
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1();
    (*(s32 *)((s8 *)(arg0) + (0x30))) = temp_v0;
    _subaddiesect_entrypoint_2(arg0, temp_v0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800058_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800290_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_808003DC_chpoolkids.s")

void func_80800618_chpoolkids(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80101DAC(Actor *, s32);
    void func_801020DC(void *, s32);
    void func_80102424(Actor *, s32);
    void func_80103014(u8 *);
    extern f32 D_80801508_chpoolkids[];
    extern f32 D_80801514_chpoolkids[];

    func_80102424(arg0, 6);
    switch (arg0->unk6C_9) {
        case 0x3A3:
            func_800EE7F8(arg0->position, D_80801508_chpoolkids);
            break;
        case 0x3A4:
            func_800EE7F8(arg0->position, D_80801514_chpoolkids);
            func_801020DC(arg0, 0);
            func_80101DAC(arg0, 0);
            break;
    }
    if (_glcutDll_entrypoint_20() == 0) {
        func_800EF1B8(arg0->position, func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 200.0f));
    }
    func_80103014(arg0);
}

/* extern */

void func_808006F8_chpoolkids(s32 arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    void func_80102424(Actor *, s32);
    void func_80800618_chpoolkids(Actor *);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    sp24 = func_800DA298(0x166);
    sp20 = func_800DA298(0x167);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800618_chpoolkids(arg0);
    } else if ((_glcutDll_entrypoint_19(0x2A) != 0) || (_glcutDll_entrypoint_19(0x29) != 0)) {
        sp1C = 1;
    } else if ((sp24 != 0) && (sp20 == 0)) {
        func_80102424(arg0, 4);
    } else if ((sp24 == 0) && (sp20 != 0)) {
        func_80102424(arg0, 5);
    } else if ((sp24 != 0) && (sp20 != 0)) {
        func_80800618_chpoolkids(arg0);
    }
    if (sp1C != 0) {
        func_800DA524(0x168);
        func_800DA524(0x1CE);
    }
}

void func_808007F0_chpoolkids(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_17(void);
    void func_800D0C78(u32, u32, u32);
    void func_80102424(Actor *, s32);

    switch (arg1) {
        case 0x1020:
        case 0x1021:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_17();
            break;
        case 0x1022:
            func_800D0C78(0x22, 1, 0);
            arg0->unk58 = 4.5f;
            func_80102424(arg0, 3);
            break;
        default:
            func_80102424(arg0, arg0->actorData[4]);
            break;
    }
}

/* extern */

void func_80800884_chpoolkids(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    if (_glcutDll_entrypoint_20() == 0) {
        func_8010D600(sp1C);
        (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
        func_80102BF8(arg0, 0x3E19999A, 0x40800000, 0x42F00000);
    }
}

/* extern */

void func_808008DC_chpoolkids(u8 *arg0) {
    s32 _fxripple_entrypoint_0(s32, f32 *);
    s32 func_800D9078(s32);
    f32 func_800DC178(f32, f32);
    func_800D9078(arg0 + 0x58);
    if ((*(f32 *)((s8 *)(arg0) + (0x58))) <= 0.0f) {
        _fxripple_entrypoint_0(3, (f32 *)(arg0 + 4));
        (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178(0.6f, 1.2f);
    }
}

void func_80800944_chpoolkids(Actor *arg0, f32 arg1) {
    s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    s32 _fxripple_entrypoint_0(s32, f32 *);
    s32 _fxsplash25d_entrypoint_0(f32 *);
    s32 _fxsplash_entrypoint_2(f32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80101E14(Actor *, f32);
    extern u32 D_80801520_chpoolkids;
    f32 position[3];
    s32 emitter;

    if (func_80101E14(arg0, arg1)) {
        func_800EE7F8(position, arg0->position);
        _subaddieaudioquick_entrypoint_2(arg0, position, &D_80801520_chpoolkids);
        _fxripple_entrypoint_0(3, position);
        _fxsplash25d_entrypoint_0(position);
        emitter = _fxsplash_entrypoint_2(position, 35.0f);
        func_800BA930(emitter, -350, 300, -350, 350, 500, 350);
        func_800BA22C(emitter, 6);
        func_800BA930(emitter, -150, 500, -150, 150, 800, 150);
        func_800BA22C(emitter, 6);
        position[1] -= 30.0f;
        emitter = _fxairbub_entrypoint_1(position, 20.0f, arg0->position[1], 1.0f);
        func_800BA930(emitter, -60, -250, -60, 60, -150, 60);
        func_800BA22C(emitter, 4);
    }
}

void func_80800AA0_chpoolkids(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_8080152C_chpoolkids;
    extern u32 D_8080153C_chpoolkids;
    extern u32 D_8080154C_chpoolkids;
    extern u32 D_8080155C_chpoolkids;
    f32 *temp_s1;

    temp_s1 = (f32 *)((s8 *)arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080152C_chpoolkids, 0.4f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080153C_chpoolkids, 0.18f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080154C_chpoolkids, 0.73f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080155C_chpoolkids, 0.77f);
}

void func_80800B38_chpoolkids(Actor *arg0) {
    extern u32 D_8080156C_chpoolkids;
    extern u32 D_8080157C_chpoolkids;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_8080156C_chpoolkids, &D_8080157C_chpoolkids);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800B68_chpoolkids.s")

u32 func_80800D3C_chpoolkids(s32 unused, s32 arg1, s32 arg2) {
    void func_80800D74_chpoolkids(Actor *);

    if (arg1 == 0x95) {
        func_80800D74_chpoolkids((Actor *) unused);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800D74_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/chpoolkids_entrypoint_3.s")

void func_808011A8_chpoolkids(Actor *arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808015A0_chpoolkids[];
    extern f32 D_808015EC_chpoolkids[3];
    s32 temp_s2;
    s32 count;
    int var_s0;

    temp_s2 = func_800B5BE4(0x23);
    count = 1;
    for (var_s0 = 0; var_s0 < count; var_s0++) {
        func_800BABB8(temp_s2, D_808015EC_chpoolkids, D_808015EC_chpoolkids, arg0->scale * 1.15f, D_808015A0_chpoolkids);
    }
}

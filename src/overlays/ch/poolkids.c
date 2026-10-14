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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800618_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_808006F8_chpoolkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_808007F0_chpoolkids.s")

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
    s32 _fxripple_entrypoint_0(s32, u8 *);
    s32 func_800D9078(s32);
    f32 func_800DC178(f32, f32);
    func_800D9078(arg0 + 0x58);
    if ((*(f32 *)((s8 *)(arg0) + (0x58))) <= 0.0f) {
        _fxripple_entrypoint_0(3, arg0 + 4);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178(0.6f, 1.2f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/poolkids/func_80800944_chpoolkids.s")

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

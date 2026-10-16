#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chmineprospector_entrypoint_0(void)
{
    extern u8 D_8080102C_chmineprospector[];

    return (OSThread *) D_8080102C_chmineprospector;
}

OSThread *chmineprospector_entrypoint_1(void)
{
    extern u8 D_80801074_chmineprospector[];

    return (OSThread *) D_80801074_chmineprospector;
}

OSThread *chmineprospector_entrypoint_2(void)
{
    extern u8 D_808010BC_chmineprospector[];

    return (OSThread *) D_808010BC_chmineprospector;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800024_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_8080029C_chmineprospector.s")

void func_80800340_chmineprospector(Actor *arg0, u8 *arg1) {
    void func_800DBEFC(s32 *, s32, s32);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC((s32 *) func_80104130(), 4, (s32) &arg0->actorData[4]);
        *(f32 *) &arg0->actorData[5] = arg0->position[1];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800398_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800540_chmineprospector.s")

void func_808005F0_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 func_800DC298(f32);
    extern u32 D_80800FB0_chmineprospector;
    if (func_800DC298(0.2f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 0x28), &D_80800FB0_chmineprospector, 0.8f);
    }
}

void func_80800638_chmineprospector(Actor *arg0) {
    extern u32 D_80800FB0_chmineprospector;
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_8080111C_chmineprospector;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 0x28);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_8080111C_chmineprospector, 0.03f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800FB0_chmineprospector, 0.65f);
}

void func_8080068C_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    s32 func_800DC298(f32);
    extern u32 D_80801128_chmineprospector;
    extern u32 D_80801134_chmineprospector;
    extern u32 D_80801144_chmineprospector;
    f32 * volatile sp1C;

    _subaddieaudioquick_entrypoint_4(arg0, sp1C = (f32 *) ((u8 *) arg0 + 0x28), &D_80801128_chmineprospector, &D_80801144_chmineprospector);
    if (func_800DC298(0.3f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801134_chmineprospector, 0.5f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808006EC_chmineprospector.s")

void func_8080084C_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_10(s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    s32 func_80108B04(s32, s32);
    void func_80800A64_chmineprospector(Actor *, s32, s32);
    extern s32 D_80800F58_chmineprospector;
    if (_subaddiedialog_entrypoint_10(_subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80800F58_chmineprospector, 7)) != 0) {
        func_80800A64_chmineprospector(arg0, 1, 0x30);
        func_80108B04(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808008A4_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800910_chmineprospector.s")

void func_80800970_chmineprospector(Actor *arg0) {
    void _capod_entrypoint_3(s32);
    void *temp_v0;
    void *sp1C;

    temp_v0 = func_80100094(arg0, 0);
    if (*(s32 *)((u8 *)temp_v0 + 0x10) != 0) {
        sp1C = temp_v0;
        _capod_entrypoint_3(0);
        *(s32 *)((u8 *)sp1C + 0x10) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808009B0_chmineprospector.s")

void func_80800A64_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    s32 *data;

    data = func_80100094(arg0, 0U);
    switch (data[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xF, arg2);
        case 2:
            data[4] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800AF0_chmineprospector.s")

/* extern */

void func_80800BF4_chmineprospector(Actor *arg0) {
    struct Unk800C7A68;
    s32 _glcutDll_entrypoint_20();
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7520(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void *func_80105494(Actor *);
    void func_80105A9C(Actor *, f32);
    if ((func_800DA298(0x5C) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800DA298(0x83) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800C7A68(func_800D7520((s32) (*(s32 *)func_80105494(arg0) << 0x15) >> 0x16), 0.999f, arg0->position);
        func_80102424(arg0, 2);
        goto block_8;
    }
    if (arg0->unk7A_5) {
        func_800FFAB0(arg0);
        return;
    }
block_8:
    func_80105A9C(arg0, 450.0f);
}

s32 func_80800CD4_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    if (arg1 == 0x95) {
        _suexpression_entrypoint_7(arg0, 1, 0x32);
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x42700000, 0x41A00000);
    } else {
        return 0;
    }
    return 1;
}

void func_80800D34_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, u32 *);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 func_800DC298(f32);
    extern s32 D_80801168_chmineprospector;
    extern s32 D_80801178_chmineprospector;
    f32 * volatile sp1C;

    _subaddieaudioquick_entrypoint_3(arg0, sp1C = (f32 *) ((u8 *) arg0 + 4), &D_80801168_chmineprospector, 0.5f);
    if (func_800DC298(0.1f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, sp1C, &D_80801178_chmineprospector);
    }
}

void func_80800D8C_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_80801184_chmineprospector;
    extern u32 D_80801194_chmineprospector;
    extern u32 D_808011A0_chmineprospector;
    extern u32 D_808011AC_chmineprospector;

    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_80801184_chmineprospector, &D_808011AC_chmineprospector);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_80801194_chmineprospector, 0.75f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_808011A0_chmineprospector, 0.6f);
}

void func_80800DF8_chmineprospector(s32 arg0) 
{
}
/* extern */

void func_80800E00_chmineprospector(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

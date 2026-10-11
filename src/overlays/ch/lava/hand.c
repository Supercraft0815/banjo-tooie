#include "common.h"

void func_80800000_chlavahand(void *arg0) {
    struct Flags {
        u8 pad0 : 7;
        u8 flag0 : 1;
        u8 pad1 : 7;
        u8 flag1 : 1;
    };
    ((struct Flags *)((u8 *)arg0 + 0x64))->flag0 = 1;
    ((struct Flags *)((u8 *)arg0 + 0x64))->flag1 = 0;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x38)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800024_chlavahand.s")

void func_80800124_chlavahand(u8 *arg0) {
    void _subaddieaudioloop_entrypoint_0(u8 *, f32);
    void _subaddieaudioloop_entrypoint_1(u8 *, s32);
    void _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, f32 *, u32, u32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_80013970(f32);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_80101DDC(u8 *);
    s32 func_80101E14(u8 *, f32);
    f32 func_80101F24(u8 *);
    void func_80102424(u8 *, s32);
    void func_80107070(u8 *, s32);
    void func_8010A800(u8 *, s32);
    s32 func_8010C754(u8 *);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    void func_80800024_chlavahand(u8 *);
    void func_80800910_chlavahand(u8 *);
    void func_80800A30_chlavahand(u8 *);
    extern u32 D_80801324_chlavahand;
    struct Flags {
        u32 pad : 2;
        u32 active : 1;
        u32 rest : 29;
    };
    f32 sp4C;
    s32 sp48;
    f32 sp44;
    u32 sp40;
    f32 sp3C;

    switch ((u32) *(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        if (((struct Flags *)(arg0 + 0x64))->active) {
            if (_subaddiejoy_entrypoint_6(arg0, 1)) {
                func_80800024_chlavahand(arg0);
            }
        } else if (func_800D90A4((f32 *)(arg0 + 0x58))) {
            if (func_8010C9FC((f32 *)(arg0 + 4), (s32) (((u32) *(u16 *)(arg0 + 0x76) >> 7) * 10.0f), 200, -200)) {
                func_80800024_chlavahand(arg0);
            }
        }
        *(f32 *)(arg0 + 0x38) = 0.1f;
        break;
    case 2:
    case 3:
        sp4C = func_80101F24(arg0);
        sp48 = func_8010C754(arg0);
        if (sp4C <= 0.09f) {
            *(f32 *)(arg0 + 0x38) = func_800F10B4(sp4C, 0.0f, 0.09f, 0.1f, *(f32 *)(arg0 + 0x54));
        } else if (sp4C >= 0.800000011920928955078125f) {
            *(f32 *)(arg0 + 0x38) = func_800F10B4(sp4C, 0.800000011920928955078125f, 1.0f, *(f32 *)(arg0 + 0x54), 0.1f);
        } else {
            *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x54);
        }
        _subaddieaudioloop_entrypoint_4(arg0, (f32 *)(arg0 + 4), sp48 < 1000, &D_80801324_chlavahand);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4((f32) sp48, 1000.0f, 0.0f, 0.8f, 1.2f));
        _subaddieaudioloop_entrypoint_1(arg0, (s32) (func_80013970(func_80101F24(arg0) * 180.0f) * 16000.0f));
        if (func_80101E14(arg0, 0.2f)) {
            func_800C4140((((u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21) + 0x1B5E01, (f32 *)(arg0 + 4), 0x04B000FA);
        } else if (func_80101E14(arg0, 0.52f)) {
            func_800C4140((((u32) (func_800DC178(1.15f, 1.25f) * 1023.0f) & 0x7FF) << 21) + 0x1B5E01, (f32 *)(arg0 + 4), 0x04B000FA);
        } else if (func_80101DDC(arg0)) {
            if (((struct Flags *)(arg0 + 0x64))->active) {
                *(f32 *)(arg0 + 0x58) = 1.0f;
            } else {
                *(f32 *)(arg0 + 0x58) = 2.0f;
            }
            func_80102424(arg0, 1);
            _subaddieaudioloop_entrypoint_2(arg0);
        }
        *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x38) * 150.0f;
        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x38) * 300.0f;
        break;
    case 4:
    case 5:
        sp44 = func_80101F24(arg0);
        if (func_800DC0C0() < 0.1f) {
            func_80800A30_chlavahand(arg0);
        }
        _subaddieaudioloop_entrypoint_4(arg0, (f32 *)(arg0 + 4), 1, &D_80801324_chlavahand);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp44, 0.8f, 1.2f));
        _subaddieaudioloop_entrypoint_1(arg0, (s32) (sp44 * 16000.0f));
        *(f32 *)(arg0 + 0x38) = func_800F15F8(*(f32 *)(arg0 + 0x38), *(f32 *)(arg0 + 0x54), 0.1f);
        if (func_80101E14(arg0, 0.02f)) {
            func_800C4140((((u32) (func_800DC178(1.4f, 1.5f) * 1023.0f) & 0x7FF) << 21) + 0x1D4E05, (f32 *)(arg0 + 4), 0x04B000FA);
        } else if (func_80101E14(arg0, 0.7f)) {
            func_800C4140(0x665F4601, (f32 *)(arg0 + 4), 0x04B000FA);
        }
        if (func_80101DDC(arg0)) {
            sp40 = (u32) *(u16 *)(arg0 + 0x72) >> 10;
            func_8010A800(arg0, 2);
            func_80107070(arg0, 2);
            func_80102424(arg0, sp40 == 4 ? 6 : 7);
        } else {
            sp3C = 1.0f + sp44;
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x54) * 150.0f * sp3C;
            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x54) * 300.0f * sp3C;
        }
        break;
    case 6:
    case 7:
        sp3C = (u32) arg0[0x9B] / 255.0f;
        _subaddieaudioloop_entrypoint_4(arg0, (f32 *)(arg0 + 4), 1, &D_80801324_chlavahand);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp3C, 0.8f, 1.2f));
        _subaddieaudioloop_entrypoint_1(arg0, (s32) (sp3C * 16000.0f));
        if (func_800DC0C0() < sp3C) {
            func_80800A30_chlavahand(arg0);
        }
        *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x54) * 150.0f * 2.0f * sp3C;
        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x54) * 300.0f * 2.0f * sp3C;
        break;
    case 8:
        if (arg0[0x5F]) {
            _subaddieaudioloop_entrypoint_2(arg0);
        }
        break;
    case 9:
        break;
    }
    func_80800910_chlavahand(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800910_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800A30_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800AAC_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800D8C_chlavahand.s")

OSThread *chlavahand_entrypoint_0(void)
{
    extern u8 D_808013D0_chlavahand[];

    return (OSThread *) D_808013D0_chlavahand;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800E0C_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800FB4_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_808011BC_chlavahand.s")

OSThread *chlavahand_entrypoint_1(void)
{
    extern u8 D_80801418_chlavahand[];

    return (OSThread *) D_80801418_chlavahand;
}

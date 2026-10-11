#include "common.h"

/* extern */

void func_80800000_chpufferfish(void *arg0) {
    s32 _subaddieDll_entrypoint_1();
    s32 func_800FFAB0(void *);
    if (_subaddieDll_entrypoint_1() == 0) {
        func_800FFAB0(arg0);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x34))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x38)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800040_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800274_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_808003C8_chpufferfish.s")

void func_80800518_chpufferfish(Actor *arg0) {
    struct PufferFlags {
        u32 : 2;
        u32 active : 1;
        u32 : 29;
    };
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800F1214(f32, f32, f32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_8010C9B0(f32 *, s32);
    void func_80800274_chpufferfish(Actor *, s32);
    void func_8080086C_chpufferfish(Actor *, s32);
    void func_8080093C_chpufferfish(Actor *, s32);
    extern u32 D_80801298_chpufferfish;
    f32 sp24;
    f32 sp20;
    f32 value;
    f32 scale;

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (func_80101F24(arg0) > 0.1f && func_80101F24(arg0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(arg0, 1);
        }
        if (((struct PufferFlags *)((u8 *)arg0 + 0x64))->active) {
            if (func_800D90A4((f32 *)((u8 *)arg0 + 0x2C)) && _subaddiejoy_entrypoint_6((u8 *)arg0, 1)) {
                func_8080086C_chpufferfish(arg0, 2);
            }
        } else {
            if (func_800D90A4((f32 *)((u8 *)arg0 + 0x58)) && func_8010C9B0((f32 *)((u8 *)arg0 + 4), 500)) {
                func_8080086C_chpufferfish(arg0, 2);
            }
        }
        break;
    case 3:
        if (func_80101F24(arg0) > 0.1f && func_80101F24(arg0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(arg0, 1);
        }
        if (((struct PufferFlags *)((u8 *)arg0 + 0x64))->active) {
            if (_subaddiejoy_entrypoint_6((u8 *)arg0, 0)) {
                func_8080086C_chpufferfish(arg0, 4);
            }
        } else if (func_80101E14(arg0, 0.999f)) {
            func_8080086C_chpufferfish(arg0, 4);
        }
        break;
    case 2:
        value = func_80101F24(arg0);
        sp24 = value;
        scale = *(f32 *)((u8 *)arg0 + 0x34);
        *(f32 *)((u8 *)arg0 + 0x38) = func_800F1214(value, scale, 2.0f * scale);
        if (func_80101DDC(arg0)) {
            _subaddieaudioloop_entrypoint_2(arg0);
            if (((u32)*(u8 *)((u8 *)arg0 + 0x79) >> 4) == 3) {
                func_80800274_chpufferfish(arg0, 4);
            } else {
                func_8080086C_chpufferfish(arg0, 3);
            }
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, (f32 *)((u8 *)arg0 + 4), 1, &D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp24, 0.8f, 1.4f));
        }
        break;
    case 4:
        value = func_80101F24(arg0);
        sp20 = value;
        scale = *(f32 *)((u8 *)arg0 + 0x34);
        *(f32 *)((u8 *)arg0 + 0x38) = func_800F1214(value, scale, 2.0f * scale);
        if (func_80101E14(arg0, 0.1f)) {
            _subaddieaudioloop_entrypoint_2(arg0);
            func_8080086C_chpufferfish(arg0, 1);
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, (f32 *)((u8 *)arg0 + 4), 1, &D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp20, 0.8f, 1.4f));
        }
        func_8080093C_chpufferfish(arg0, 1);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_8080086C_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_8080093C_chpufferfish.s")

void func_80800AB0_chpufferfish(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 _subaddieDll_entrypoint_11(void *, s32, s32);
    f32 func_800136E4(f32);
    s32 func_800CC63C(s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void func_80102924(void *, f32);
    void func_80102950(void *, f32);
    void func_80102BAC(void *, f32, f32, f32);
    void func_80102C58(void *, f32, f32, f32);
    f32 func_80102D78(void *, void *);
    void func_8010CE28(void *, f32 *);
    f32 rotation[3];
    s32 atBoundary;
    u8 *region;

    region = (u8 *)func_800CC63C((*(u32 *)((u8 *)arg0 + 0x70) >> 25) - 1, ((*(u32 *)((u8 *)arg0 + 0x70) << 22) >> 26) - 1);
    if (*(f32 *)((u8 *)arg0 + 8) >= *(s16 *)(region + 0xE) + *(f32 *)(region + 4)) {
        atBoundary = 1;
        func_80102950(arg0, 355.0f);
    } else if (*(f32 *)((u8 *)arg0 + 8) <= *(f32 *)(region + 4) - *(s16 *)(region + 0xE)) {
        atBoundary = 1;
        func_80102950(arg0, 5.0f);
    } else {
        atBoundary = 0;
    }
    if (arg1 & 6) {
        func_8010CE28(arg0, rotation);
        if (arg1 & 2) {
            func_80102924(arg0, rotation[1]);
        } else {
            func_80102924(arg0, func_800136E4(rotation[1] - 180.0f));
        }
        rotation[0] = func_800136E4(-rotation[0]);
        if (rotation[0] > 25.0f && rotation[0] < 180.0f) {
            rotation[0] = 25.0f;
        } else if (rotation[0] < 335.0f && rotation[0] > 180.0f) {
            rotation[0] = 335.0f;
        }
        func_80102950(arg0, rotation[0]);
    }
    if (func_800D90A4((f32 *)((u8 *)arg0 + 0x20))) {
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x28) = func_800DC178(2.0f, 4.0f);
        *(f32 *)((u8 *)arg0 + 0x18) = func_800DC178(arg2, arg3);
        if (!atBoundary) {
            func_80102950(arg0, func_800DC178(-8.333333f, 8.333333f));
        }
        if (arg1 & 5) {
            func_80102924(arg0, func_800DC178(-35.0f, 35.0f) + *(f32 *)((u8 *)arg0 + 0x48));
        }
    }
    if (!_subaddieDll_entrypoint_11(arg0, (s32)*(f32 *)((u8 *)arg0 + 0x54), (s32)(*(f32 *)((u8 *)arg0 + 0x24) * (*(f32 *)((u8 *)arg0 + 0x38) * 3.0f)))) {
        func_80102924(arg0, func_80102D78(arg0, region));
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x28) = func_800DC178(2.0f, 4.0f);
    }
    *(f32 *)((u8 *)arg0 + 0x1C) = func_800136E4(func_800F10B4(func_800F1DCC(*(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x54)), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(arg0, 0.05f, 0.05f, 4.0f);
    func_80102C58(arg0, 0.05f, 0.01f, 0.5f);
    *(f32 *)((u8 *)arg0 + 0x4C) = func_800F1FF0(*(f32 *)((u8 *)arg0 + 0x4C), *(f32 *)((u8 *)arg0 + 0x1C), 0.01f, 0.005f, 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800E20_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800F30_chpufferfish.s")

OSThread *chpufferfish_entrypoint_0(void)
{
    extern u8 D_808012A8_chpufferfish[];

    return (OSThread *) D_808012A8_chpufferfish;
}

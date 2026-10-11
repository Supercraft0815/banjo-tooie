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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800AB0_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800E20_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800F30_chpufferfish.s")

OSThread *chpufferfish_entrypoint_0(void)
{
    extern u8 D_808012A8_chpufferfish[];

    return (OSThread *) D_808012A8_chpufferfish;
}

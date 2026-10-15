#include "common.h"

/* extern */

void func_80800000_chpotogoldbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    _chswitch_entrypoint_7(arg0, 0xA2D);
    _chswitch_entrypoint_8(arg0, 0x601);
}

s32 func_80800030_chpotogoldbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x408, 7, 0);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chpotogoldbits_entrypoint_0(void)
{
    extern u8 D_80800920_chpotogoldbits[];

    return (OSThread *) D_80800920_chpotogoldbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldbits/func_8080007C_chpotogoldbits.s")

void func_80800188_chpotogoldbits(u8 *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    f32 func_80013970(f32);
    s32 func_800D90A4(u8 *);
    s32 func_800D91EC(u8 *, s32);
    s32 func_800EFE50(u8 *, u8 *, u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800FFA88(s32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103110(u8 *, s32);
    extern s32 D_80800968_chpotogoldbits;
    extern s32 D_80800978_chpotogoldbits;
    struct GoldFlags { u32 other : 1; u32 played : 1; };
    f32 temp_f0;
    u8 *sp2C;

    switch ((u32) *(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        func_80103110(arg0, 0);
        break;
    case 2:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800978_chpotogoldbits);
        }
        sp2C = arg0 + 4;
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 3);
        }
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, &D_80800968_chpotogoldbits);
        break;
    case 3:
        sp2C = arg0 + 4;
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, &D_80800968_chpotogoldbits);
        if (func_800D91EC(arg0 + 0x24, (*(s32 *)((s8 *)(arg0) + (0x54)))) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, &D_80800978_chpotogoldbits);
            func_80101FDC(arg0, 4);
        }
        break;
    case 4:
        func_80103110(arg0, 0);
        break;
    case 5:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800978_chpotogoldbits);
        }
        sp2C = arg0 + 4;
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 6);
        }
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, &D_80800968_chpotogoldbits);
        break;
    case 6:
        sp2C = arg0 + 4;
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, &D_80800968_chpotogoldbits);
        if (func_800D90A4(arg0 + 0x24) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, &D_80800978_chpotogoldbits);
            func_80101FDC(arg0, 1);
        }
        break;
    case 8:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 9:
        if (func_800D91EC(arg0 + 0x24, (*(s32 *)((s8 *)(arg0) + (0x54)))) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800978_chpotogoldbits);
            ((struct GoldFlags *)(arg0 + 0x74))->played = 0;
            func_80101FDC(arg0, 0xA);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_80800968_chpotogoldbits);
        break;
    case 10:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(arg0 + 0x34) != 0) {
            (*(f32 *)((s8 *)(arg0) + (0x50))) = 0.5f;
            func_80101FDC(arg0, 0xB);
        }
        break;
    case 11:
        if (func_800D90A4(arg0 + 0x50) != 0) {
            func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
        }
        (*(s8 *)((s8 *)(arg0) + (0x9B))) = (s8) (u32) func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x50))), 0.5f, 0.0f, 255.0f, 0.0f);
        break;
    }
    sp2C = arg0 + 4;
    temp_f0 = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x24))), 0.0f, (*(f32 *)((s8 *)(arg0) + (0x54))), 0.0f, 1.0f);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = temp_f0;
    func_800EFE50(sp2C, arg0 + 0x28, arg0 + 0x18, temp_f0);
    if (*(f32 *)(arg0 + 0x34)) {
        temp_f0 = func_800F10B4(*(f32 *)(arg0 + 0x34), 0.3f, 0.0f, 0.0f, 1.0f);
        temp_f0 = func_80013970(temp_f0 * 180.0f);
        (*(f32 *)(arg0 + 8)) += temp_f0 * 20.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldbits/func_80800618_chpotogoldbits.s")

/* extern */

void chpotogoldbits_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_80101180(s32, s32, s32);
    func_80101180(0x408, 8, 0);
}

OSThread *chpotogoldbits_entrypoint_2(void)
{
    extern u8 D_80800988_chpotogoldbits[];

    return (OSThread *) D_80800988_chpotogoldbits;
}

/* extern */

void func_80800810_chpotogoldbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _chdoormake_entrypoint_7(s32, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 func_800EA090(void);
    s32 func_8010108C(void *, s32, s32);
    void func_80101FDC(Actor *, u32);
    if (func_800EA090() == 0xD) {
        func_80101FDC(arg0, 4);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 212.0f, 2, -1);
    _chdoormake_entrypoint_5(arg0, 1.0f);
    _chdoormake_entrypoint_7(arg0, 0.5f);
    _chdoormake_entrypoint_8(arg0, 2);
    if (arg0->unk70_10 == 4) {
        func_8010108C(arg0, 8, 0);
    }
}

OSThread *chpotogoldbits_entrypoint_3(void)
{
    extern u8 D_808009D0_chpotogoldbits[];

    return (OSThread *) D_808009D0_chpotogoldbits;
}

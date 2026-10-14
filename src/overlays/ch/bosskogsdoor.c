#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bosskogsdoor/func_80800000_chbosskogsdoor.s")

void func_80800090_chbosskogsdoor(u8 *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    f32 func_800D8FF8();
    s32 func_800D90A4(u8 *);
    s32 func_800D91EC(u8 *, f32);
    s32 func_800DA544(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103110(u8 *, s32);
    f32 func_80103EF4(u8 *);
    extern s32 D_808008B0_chbosskogsdoor;
    extern s32 D_808008E8_chbosskogsdoor;
    extern s32 D_808008F8_chbosskogsdoor;
    extern s32 D_80800904_chbosskogsdoor;
    extern s32 D_8080090C_chbosskogsdoor;
    f32 temp_f0;
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        break;
    case 2:
        if (func_800D90A4(arg0 + 0x2C) != 0) {
            func_80101FDC(arg0, 3);
            func_800DA544(0x1B8);
        }
        break;
    case 3:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (*(f32 *)((s8 *)(arg0) + (0x20))) += 1200.0f * temp_f0;
        if ((*(f32 *)((s8 *)(arg0) + (0x20))) > -220.0f) {
            (*(f32 *)((s8 *)(arg0) + (0x20))) = -220.0f;
            func_80101FDC(arg0, 4);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (*(f32 *)((s8 *)(arg0) + (0x1C))) += 1200.0f * temp_f0;
        if ((*(f32 *)((s8 *)(arg0) + (0x1C))) > 2480.0f) {
            (*(f32 *)((s8 *)(arg0) + (0x1C))) = 2480.0f;
            func_80101FDC(arg0, 5);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 5:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (*(f32 *)((s8 *)(arg0) + (0x20))) += 1200.0f * temp_f0;
        if ((*(f32 *)((s8 *)(arg0) + (0x20))) > 0.0f) {
            (*(f32 *)((s8 *)(arg0) + (0x20))) = 0.0f;
            func_80101FDC(arg0, 6);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 6:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (*(f32 *)((s8 *)(arg0) + (0x1C))) -= 1200.0f * temp_f0;
        if ((*(f32 *)((s8 *)(arg0) + (0x1C))) < 2204.0f) {
            func_80101FDC(arg0, 7);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800904_chbosskogsdoor);
            _subaddieaudioloop_entrypoint_2(arg0);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 4, &D_808008B0_chbosskogsdoor);
        break;
    case 7:
        if (func_800D91EC(arg0 + 0x58, (f32)((u32)*(u16 *)(arg0 + 0x76) >> 7) / 10.0f) != 0) {
            func_80101FDC(arg0, 8);
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_808008F8_chbosskogsdoor);
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_808008E8_chbosskogsdoor);
        }
        break;
    case 9:
        func_80103110(arg0, 0);
        break;
    }
    temp_f0 = func_80103EF4(arg0);
    (*(f32 *)((s8 *)(arg0) + (8))) = (*(f32 *)((s8 *)(arg0) + (0x34))) + func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x58))), 0.0f, (f32)((u32)*(u16 *)(arg0 + 0x76) >> 7) / 10.0f, 0.0f, temp_f0);
}

/* extern */

s32 func_80800458_chbosskogsdoor(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0x49:
        if (arg2 == 0x40) {
            _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x930);
            func_80101FDC(arg0, 2);
            func_800EFA4C((f32 *)arg0->actorData, -7472.0f, 2405.0f, -1240.0f);
            ((f32 *)arg0->actorData)[5] = 5.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}

OSThread *chbosskogsdoor_entrypoint_0(void)
{
    extern u8 D_80800918_chbosskogsdoor[];

    return (OSThread *) D_80800918_chbosskogsdoor;
}

/* extern */

void func_808004F4_chbosskogsdoor(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_80102424(void *, s32);
    if (func_800DA298(0x1B8) != 0) {
        func_80102424(arg0, 4);
        arg0->unk74_30 = 1;
        return;
    }
    func_80102424(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bosskogsdoor/func_80800544_chbosskogsdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bosskogsdoor/func_80800714_chbosskogsdoor.s")

OSThread *chbosskogsdoor_entrypoint_1(void)
{
    extern u8 D_808009EC_chbosskogsdoor[];

    return (OSThread *) D_808009EC_chbosskogsdoor;
}

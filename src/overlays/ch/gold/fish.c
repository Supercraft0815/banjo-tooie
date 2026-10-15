#include "common.h"

/* extern */

void func_80800000_chgoldfish(u8 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    s32 func_808005F0_chgoldfish(u8 *, s32);
    s32 func_80800BA8_chgoldfish(u8 *, f32 *);
    if (func_800DA298(0x1BF) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
        return;
    }
    if (func_800DA298(0x1DA) != 0) {
        func_808005F0_chgoldfish(arg0, 6);
    } else if (func_800DA298(0x51E) != 0) {
        func_808005F0_chgoldfish(arg0, 3);
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x38)));
    (*(f32 *)((s8 *)(arg0) + (0x4C))) = 90.0f;
    func_80800BA8_chgoldfish(arg0, arg0 + 4);
}

void func_8080009C_chgoldfish(u8 *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_7(u8 *, u8 *, s32 *);
    f32 func_80013970(f32);
    void func_8008FE68(f32 *);
    void func_8008FE94(s32, f32 *);
    void func_80090708(s32);
    s32 func_800CD08C(s32, u8 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(u8 *, u8 *);
    f32 func_800F1214(f32, f32, f32);
    s32 func_800F54E4(void);
    s32 func_800F71D4(s32);
    void func_8010C964(Actor *);
    s32 func_8010CE70(u8 *, s32, s32);
    s32 func_808005F0_chgoldfish(u8 *, s32);
    void func_80800924_chgoldfish(u8 *);
    void func_80800964_chgoldfish(u8 *);
    f32 func_80800AB4_chgoldfish(u8 *, u8 *, u8 *, u8 *, f32, f32);
    s32 func_80800BA8_chgoldfish(u8 *, f32 *);
    extern s32 D_80800D20_chgoldfish;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 2:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            func_8010C964((Actor *)arg0);
            break;
    }
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            if (func_800DA298(0x51E)) {
                func_808005F0_chgoldfish(arg0, 2);
            } else {
                _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800D20_chgoldfish);
            }
            break;
        case 2:
            if (!func_800DA298(0x1DA)) {
                func_800DA544(0x1DA);
                _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x15BF, 0xE, (f32 *)(arg0 + 4), 0x67);
            }
            break;
        case 3:
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                *(f32 *)(arg0 + 0x54) = func_800DC178(0.0f, 360.0f);
                if (*(f32 *)(arg0 + 0x4C) == 90.0f) {
                    *(f32 *)(arg0 + 0x50) = 270.0f;
                } else {
                    *(f32 *)(arg0 + 0x50) = 90.0f;
                }
                func_800EE7F8(arg0 + 0x28, arg0 + 4);
                func_800CD08C((*(u32 *)(arg0 + 0x70) >> 25) - 1, arg0 + 0x18);
                if (func_80800BA8_chgoldfish(arg0, arg0 + 0x18)) {
                    func_808005F0_chgoldfish(arg0, 4);
                }
            }
            break;
        case 4:
            if (func_80800AB4_chgoldfish(arg0, arg0 + 0x28, arg0 + 0x18, arg0 + 4, 0.5f, 50.0f) == 1.0f) {
                func_808005F0_chgoldfish(arg0, 3);
            }
            break;
        case 5:
            func_8008FE94(1, (f32 *)(arg0 + 0x18));
            sp3C = func_80800AB4_chgoldfish(arg0, arg0 + 0x28, arg0 + 0x18, arg0 + 4, 1.0f, 150.0f);
            if (sp3C == 1.0f) {
                func_80090708(0);
                func_808005F0_chgoldfish(arg0, 6);
            }
            *(f32 *)(arg0 + 0x38) = 1.0f - sp3C * 0.5f;
            *(f32 *)(arg0 + 0x38) *= *(f32 *)(arg0 + 0x24);
            func_80800924_chgoldfish(arg0);
            break;
        case 6:
            func_8008FE68((f32 *)(arg0 + 4));
            *(f32 *)(arg0 + 8) += 200.0f;
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                *(f32 *)(arg0 + 0x58) = 40.0f;
                _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, func_800DC128(0x15C2, 0x15C5), 0xE, (f32 *)(arg0 + 4), 0x67);
            }
            if (func_800F71D4(func_800F54E4())) {
                func_808005F0_chgoldfish(arg0, 7);
            }
            break;
        case 7:
            sp34 = *(f32 *)(arg0 + 8);
            sp38 = func_80800AB4_chgoldfish(arg0, arg0 + 0x28, arg0 + 0x18, arg0 + 4, 1.0f, 200.0f);
            *(f32 *)(arg0 + 0x44) = func_80013970(func_800F1214(sp38, 270.0f, 540.0f)) * 70.0f;
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                func_808005F0_chgoldfish(arg0, 8);
            }
            if (*(f32 *)(arg0 + 8) <= *(f32 *)(arg0 + 0x34) && *(f32 *)(arg0 + 0x34) < sp34) {
                func_80800964_chgoldfish(arg0 + 4);
            }
            *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x24) * sp38;
            break;
        case 8:
            if (func_8010CE70(arg0, 6, -1)) {
                func_808005F0_chgoldfish(arg0, 9);
            }
            break;
        case 9:
        case 10:
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808004AC_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808005F0_chgoldfish.s")

void func_80800924_chgoldfish(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80800D4C_chgoldfish;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80800D4C_chgoldfish);
}

/* extern */

void func_80800964_chgoldfish(u8 *arg0) {
    s32 _fxairbub_entrypoint_1(f32 *, f32, f32, s32);
    s32 _fxripple_entrypoint_0(s32, f32 *);
    s32 _fxsplash25d_entrypoint_0(f32 *);
    s32 _fxsplash_entrypoint_2(f32[3], f32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    f32 func_800BED50();
    void func_800C4140(s32, f32 *, s32);
    f32 sp3C[3];
    f32 sp38;
    s32 temp_s0;
    s32 temp_v0;

    sp38 = func_800BED50();
    sp3C[0] = ((f32 *)arg0)[0];
    sp3C[1] = sp38;
    sp3C[2] = ((f32 *)arg0)[2];
    func_800C4140(0x7FFB5C09, (f32 *)arg0, 0x04B000FA);
    temp_s0 = _fxsplash_entrypoint_2(sp3C, 35.0f);
    _fxripple_entrypoint_0(3, sp3C);
    func_800BA930(temp_s0, -0x15E, 0x12C, -0x15E, 0x15E, 0x1F4, 0x15E);
    func_800BA22C(temp_s0, 0xA);
    func_800BA930(temp_s0, -0x96, 0x1F4, -0x96, 0x96, 0x320, 0x96);
    func_800BA22C(temp_s0, 0xA);
    _fxsplash25d_entrypoint_0(sp3C);
    sp3C[1] -= 30.0f;
    temp_v0 = _fxairbub_entrypoint_1(sp3C, 20.0f, sp38, 0x3F800000);
    func_800BA930(temp_v0, -0x3C, -0xFA, -0x3C, 0x3C, -0x96, 0x3C);
    func_800BA22C(temp_v0, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800AB4_chgoldfish.s")

/* extern */

s32 func_80800BA8_chgoldfish(u8 *arg0, f32 *arg1) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    func_800EFA4C(sp2C, arg1[0], arg1[1] + 300.0f, arg1[2]);
    arg1[1] -= 300.0f;
    if (func_800BEF00(sp2C, arg1, sp20, 0) != 0) {
        arg1[1] += 20.0f;
        return 1;
    }
    return 0;
}

OSThread *chgoldfish_entrypoint_0(void)
{
    extern u8 D_80800D94_chgoldfish[];

    return (OSThread *) D_80800D94_chgoldfish;
}

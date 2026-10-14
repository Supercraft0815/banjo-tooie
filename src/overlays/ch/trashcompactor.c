#include "common.h"

OSThread *chtrashcompactor_entrypoint_0(void)
{
    extern u8 D_808008D0_chtrashcompactor[];

    return (OSThread *) D_808008D0_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_1(void)
{
    extern u8 D_80800918_chtrashcompactor[];

    return (OSThread *) D_80800918_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_2(void)
{
    extern u8 D_80800960_chtrashcompactor[];

    return (OSThread *) D_80800960_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_3(void)
{
    extern u8 D_808009A8_chtrashcompactor[];

    return (OSThread *) D_808009A8_chtrashcompactor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_80800030_chtrashcompactor.s")

void func_808000BC_chtrashcompactor(void *arg0) {
    typedef struct {
        s32 marker;
        f32 position[3];
        u8 pad10[8];
        f32 start[3];
        u8 pad24[4];
        f32 end[3];
        f32 height;
        u8 pad38[4];
        s32 child;
        u8 pad40[16];
        s32 trigger;
        f32 sound;
        f32 timer;
        u8 pad5C[8];
        u32 flags64:11;
        u32 automatic:1;
        u32 camera:1;
        u32 flags65:19;
        u8 pad68[10];
        u16 state:6;
        u16 flags72:10;
        u16 pad74;
        u16 kind:9;
        u16 flags76:7;
    } Compactor;
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _capod_entrypoint_14(void);
    s32 _chmrtannoy_entrypoint_0(void);
    f32 _subaddieaudioloop_entrypoint_8(void *, s32 *, s32, f32);
    s32 _subaddieaudioquick_entrypoint_2(void *, f32 *, s32 *);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, f32 *, s32);
    void _sudeflect_entrypoint_2(f32 *, f32 *, s32);
    void func_800187B4(s32, f32, f32, f32);
    s32 func_8008FDC4(void);
    s32 func_80090150(void);
    s32 func_80090248(void);
    void func_800904C8(s32);
    s32 func_80090658(s32);
    s32 func_80090708(s32);
    u8 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800E15CC(s32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    s32 func_800F6478(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(void *, s32);
    void func_80104004(void *, f32 *, f32 *);
    void *func_80106790(s32);
    extern s32 D_808009F0_chtrashcompactor;
    extern s32 D_808009FC_chtrashcompactor;
    extern s32 D_80800A0C_chtrashcompactor;
    s32 player;
    s32 blocked;
    s32 deflect;
    f32 position[3];
    s32 closingDone;
    f32 closingBlend;
    s32 loweringDone;
    f32 loweringHeight;
    s32 raisingDone;
    s32 openingDone;
    f32 openingBlend;
    Compactor *child;
    f32 minimum[3];
    f32 maximum[3];

    player = func_800F54E4();
    blocked = func_800F64A4(player, 0x10000);
    deflect = 0;
    if (!blocked && !func_800DA298(0x1A0)) {
        if (func_800F6438(player) && func_800F6478(player) && ((Compactor *)arg0)->kind == 0x33) {
            func_800F5A00(player, position);
            if (position[0] > -2500.0f && position[2] > -800.0f) {
                ((Compactor *)arg0)->camera = 1;
                _capod_entrypoint_13(((Compactor *)arg0)->marker, 0, 8, 0x10);
                func_80101180(0x3A7, 0xA, 1);
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(((Compactor *)arg0)->marker, 0x1334, 0x44, ((Compactor *)arg0)->position, 0xA3);
                func_800DA544(0x1A0);
                func_80101FDC(arg0, 2);
                ((Compactor *)arg0)->timer = 8.0f;
            }
        }
        blocked = 1;
    }
    ((Compactor *)arg0)->sound = _subaddieaudioloop_entrypoint_8(arg0, &D_808009F0_chtrashcompactor, ((Compactor *)arg0)->state != 1, ((Compactor *)arg0)->sound);
    switch (((Compactor *)arg0)->state) {
        case 1:
            deflect = 1;
            if (!blocked && func_80090248()) {
                blocked = func_8008FDC4();
                if ((((Compactor *)arg0)->trigger & blocked) && func_80090150()) {
                func_80090708(2);
                ((Compactor *)arg0)->camera = 1;
                _capod_entrypoint_13(((Compactor *)arg0)->marker, 0, ((Compactor *)arg0)->kind == 0x32 ? 2 : 4, 0x20);
                func_80101FDC(arg0, 3);
                ((Compactor *)arg0)->timer = 0.45f;
                }
            }
            break;
        case 2:
            if (func_800D9078(&((Compactor *)arg0)->timer)) {
                ((Compactor *)arg0)->automatic = 1;
                func_80101FDC(arg0, 3);
                ((Compactor *)arg0)->timer = 0.45f;
            }
            break;
        case 3:
            closingDone = func_800D9078(&((Compactor *)arg0)->timer);
            closingBlend = func_800F12D4(((Compactor *)arg0)->timer, 0.0f, 0.45f, 1.0f, 0.0f);
            func_800EFE50(((Compactor *)arg0)->position, ((Compactor *)arg0)->start, ((Compactor *)arg0)->end, closingBlend);
            if (closingDone) {
                _subaddieaudioquick_entrypoint_2(arg0, ((Compactor *)arg0)->position, &D_808009FC_chtrashcompactor);
                _subaddieaudioquick_entrypoint_2(arg0, ((Compactor *)arg0)->position, &D_80800A0C_chtrashcompactor);
                func_800E15CC(2, 80.0f, 0.85f);
                func_800187B4(0, 2.0f, 1.0f, 1.0f);
                func_80101FDC(arg0, 4);
                if (!((Compactor *)arg0)->automatic) {
                    func_800904C8(0x9A);
                }
                ((Compactor *)arg0)->timer = 0.85f;
            }
            break;
        case 4:
            loweringDone = func_800D9078(&((Compactor *)arg0)->timer);
            loweringHeight = func_800F10B4(((Compactor *)arg0)->timer, 0.0f, 0.85f, 400.0f, 800.0f);
            ((Compactor *)arg0)->height = loweringHeight;
            if (loweringDone) {
                func_80101FDC(arg0, 5);
                ((Compactor *)arg0)->timer = 0.8f;
            }
            break;
        case 5:
            if (func_800D9078(&((Compactor *)arg0)->timer)) {
                func_80101FDC(arg0, 6);
                ((Compactor *)arg0)->timer = 0.15f;
            }
            break;
        case 6:
            raisingDone = func_800D9078(&((Compactor *)arg0)->timer);
            ((Compactor *)arg0)->height = func_800F10B4(((Compactor *)arg0)->timer, 0.0f, 0.15f, 800.0f, 400.0f);
            if (raisingDone) {
                if (!((Compactor *)arg0)->automatic) {
                    func_80090708(0);
                    func_800904C8(0x5A);
                    func_80090658(1);
                }
                func_80101FDC(arg0, 7);
                ((Compactor *)arg0)->timer = 1.0f;
            }
            break;
        case 7:
            openingDone = func_800D9078(&((Compactor *)arg0)->timer);
            openingBlend = func_800F12D4(((Compactor *)arg0)->timer, 0.0f, 0.45f, 0.0f, 1.0f);
            func_800EFE50(((Compactor *)arg0)->position, ((Compactor *)arg0)->start, ((Compactor *)arg0)->end, openingBlend);
            if (openingDone) {
                if (!((Compactor *)arg0)->automatic) {
                    func_80090658(0);
                    if (((Compactor *)arg0)->camera) {
                        _capod_entrypoint_14();
                        ((Compactor *)arg0)->camera = 0;
                    }
                }
                ((Compactor *)arg0)->automatic = 0;
                func_80101FDC(arg0, 8);
                ((Compactor *)arg0)->timer = 3.5f;
            }
            break;
        case 8:
            deflect = 1;
            if (func_800D9078(&((Compactor *)arg0)->timer)) {
                func_80101FDC(arg0, 1);
            }
            break;
    }
    if (((Compactor *)arg0)->child) {
        child = func_80106790(((Compactor *)arg0)->child);
        func_800EE7F8(child->position, ((Compactor *)arg0)->position);
        child->position[1] += ((Compactor *)arg0)->height;
    }
    if (deflect) {
        func_80104004(arg0, minimum, maximum);
        func_800EF04C(minimum, ((Compactor *)arg0)->position);
        func_800EF04C(maximum, ((Compactor *)arg0)->position);
        _sudeflect_entrypoint_2(minimum, maximum, 0xA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_80800684_chtrashcompactor.s")

/* extern */

void func_808007A4_chtrashcompactor(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0x9F5);
    _chswitch_entrypoint_8(arg0, 512);
    _chswitch_entrypoint_9(arg0);
}

void func_808007DC_chtrashcompactor(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x3B7, 7, 0);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

/* extern */

void func_8080081C_chtrashcompactor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void func_800C87DC(s32 *);
    s32 sp24[3];

    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 1, 0x9F5) != 0) {
        _chdoormake_entrypoint_9(arg0, 0, 0, 0x10);
        _chdoormake_entrypoint_8(arg0, 0xC);
    }
    func_800C87DC(sp24);
    _subaddiefade_entrypoint_11(arg0, sp24);
}

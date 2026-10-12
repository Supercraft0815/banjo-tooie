#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_80800000_chcaptainblubber.s")

void func_80800078_chcaptainblubber(Actor *arg0) {
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
    void _subaddieitem_entrypoint_2(s32);
    s32 func_801000D8(Actor*, s32, s32);
    void func_80102424(Actor*, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_801000D8(arg0, 0, 0x14);
    sp1C = temp_v0;
    _subaddieitem_entrypoint_0(temp_v0, 0x4E4U, 0x3E8, 3);
    _subaddieitem_entrypoint_2(sp1C);
    func_80102424(arg0, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_808000CC_chcaptainblubber.s")

void func_808001F0_chcaptainblubber(Actor *arg0) {
    struct BlubberFlags {
        u8 pad[0x70];
        u32 pad70 : 28;
        u32 expression : 1;
        u32 pad73 : 3;
    };
    s32 _subaddiedialog_entrypoint_3(f32 *, s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80105998(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    void func_8010C93C(Actor *, f32 *, f32);
    f32 sp34[3];
    void *sp30;

    func_8010C93C(arg0, arg0->position, 0.75f);
    if (((struct BlubberFlags *)arg0)->expression) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    }
    func_800D1824(0x4E);
    switch (arg0->unk70_10) {
        case 1:
        case 2:
            if (func_800F64A4(func_800F54E4(), 0x201)) {
                if (func_800DA298(0xDF)) {
                    if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x12C, 0x3C, 0)) {
                        func_80800000_chcaptainblubber(arg0);
                    }
                } else if (_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 0x12C, 0x3C, 0)) {
                    func_80800000_chcaptainblubber(arg0);
                }
            } else if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x12C, 0x3C, 0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1208, 0xE, arg0->position, 0x64);
            }
            break;
        case 5:
            sp30 = func_80100094(arg0, 0);
            _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp34);
            if (_subaddieitem_entrypoint_3(arg0, sp34, sp30)) {
                func_80102424(arg0, 6);
                func_80100074(arg0, 0, 0);
                func_800F82D4(func_800F54E4(), 1);
            }
            break;
        case 6:
            if (func_80101DDC(arg0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x100B, 0xE, arg0->position, 0x64);
                arg0->unk64_19 = 0;
                func_80102424(arg0, 7);
                arg0->position[0] -= 175.0f;
                arg0->position[2] -= -33.0f;
            }
            break;
        case 7:
            if (func_80101E14(arg0, 0.999f) && arg0->unk64_19) {
                func_800F82D4(func_800F54E4(), 0);
                func_80102424(arg0, 8);
                func_80105A9C(arg0, 500.0f);
            }
            break;
        case 8:
            func_80105834(arg0);
            func_800A54C0(arg0->position);
            if (func_80105998(arg0, 0.84f)) {
                func_80102424(arg0, 9);
            }
            break;
        case 9:
            func_800A54C0(arg0->position);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 10);
            }
            break;
        case 10:
            func_80105834(arg0);
            if (func_80105A5C(arg0)) {
                _capod_entrypoint_22();
                func_800FFA88(arg0->unk0);
            }
            break;
        case 12:
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 13);
            }
            break;
        case 13:
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 12);
            }
            break;
    }
    func_80800A1C_chcaptainblubber(arg0);
    func_8080143C_chcaptainblubber(arg0);
}

s32 func_80800580_chcaptainblubber(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _capod_entrypoint_17(f32);
    void _capod_entrypoint_14(void);
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80108528(s32, u32 *, s32, Actor **);
    s32 _chappearfx_entrypoint_1(s32, s32, s32, s32);
    void func_80108B04(Actor *, u32);
    s32 func_800F5410(s32);
    extern s32 D_808016D8_chcaptainblubber;
    Actor *spawned;
    s32 text;
    s32 flags;

    switch (arg1) {
        case 0x95:
            _suexpression_entrypoint_7(arg0, 1, 0x64);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x41F00000, 0x41700000);
            return 1;
        case 0x2E:
            switch (((s16 *)&arg2)[0]) {
                case 0x1006:
                case 0x1007:
                case 0x106B:
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1008, 0x4E, arg0->position, 0x64);
                    func_80102424(arg0, 2);
                    return 1;
                case 0x1008:
                    if (((s16 *)&arg2)[1] > 0) {
                        if (func_800D1A04(0x4E) <= 0) {
                            _subaddiedialog_entrypoint_11(arg0->unk0, 0x100A, 0xE, arg0->position, 0x64);
                        } else {
                            func_80800078_chcaptainblubber(arg0);
                        }
                    } else {
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1009, 0xE, arg0->position, 0x64);
                    }
                    return 1;
                case 0x1009:
                case 0x100A:
                    func_80102424(arg0, 2);
                    return 1;
                case 0x100B:
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x103F, 0x4E, arg0->position, 0x64);
                    func_800DA544(0xE0);
                    func_800D175C(0x4E, -1);
                    return 1;
                case 0x103F:
                    return 1;
            }
            return 0;
        case 0x30:
            if (((s16 *)&arg2)[0] == 0x1006 || ((s16 *)&arg2)[0] == 0x1007 ||
                ((s16 *)&arg2)[0] == 0x1008 || ((s16 *)&arg2)[0] == 0x106B) {
                return 1;
            }
            return 0;
        case 0xE:
            if (_capod_entrypoint_17(0.3f)) {
                func_80108B04(arg0, 0);
            }
            return 3;
        case 0xB:
            _capod_entrypoint_14();
            if (func_800C064C()) {
                func_800C01A8(0x6B, 0);
                _capod_entrypoint_21((s32)arg0->unk0, (s32)arg0->unk0, 4, 0x2011);
            }
            return 4;
        case 0x2F:
            switch (((s16 *)&arg2)[0]) {
                case 0x100B:
                    func_800C01A8(0x6B, 0);
                    _capod_entrypoint_13((s32)arg0->unk0, (s32)arg0->unk0, 0, 0x6010);
                    func_800FC6B0(0xE);
                    break;
                case 0x103F:
                    arg0->unk64_19 = 1;
                    break;
            }
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_808016D8_chcaptainblubber, arg0->scale);
            return 1;
        case 0x3D:
            spawned = func_80108528(0x1F0, arg0->actorData, (s32)arg0->unk54, &arg0);
            spawned->unk74_7 = 0x33;
            if (func_800DB9B0()) {
                _chappearfx_entrypoint_1((s32)spawned, 0x20, 0, 0x3F800000);
            }
            if (arg2) {
                func_800FFA88(arg0->unk0);
            }
            return 1;
        case 0x32:
            text = 0;
            flags = 0xE;
            switch (arg0->unk70_10) {
                case 1:
                    if (func_800DA298(0xDF)) {
                        text = 0x1007;
                    } else {
                        func_800DA544(0xDF);
                        switch (func_800F5410(func_800F54E4())) {
                            case 1:
                                text = 0x1006;
                                break;
                            case 0xA:
                                text = 0x106B;
                                break;
                        }
                    }
                    break;
                case 2:
                    text = 0x1008;
                    flags = 0x4E;
                    break;
            }
            if (text) {
                _subaddiedialog_entrypoint_11(arg0->unk0, text, flags, arg0->position, 0x64);
            }
            arg0->unk64_20 = 0;
            return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_80800A1C_chcaptainblubber.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_8080143C_chcaptainblubber.s")

void func_808014C8_chcaptainblubber(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
OSThread *chcaptainblubber_entrypoint_0(void)
{
    extern u8 D_8080176C_chcaptainblubber[];

    return (OSThread *) D_8080176C_chcaptainblubber;
}

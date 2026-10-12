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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_808001F0_chcaptainblubber.s")

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

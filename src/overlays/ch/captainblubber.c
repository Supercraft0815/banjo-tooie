#include "common.h"
BT_NATIVE_ONLY(void func_80105834();)
void func_8080143C_chcaptainblubber(Actor *arg0);
#include "core2/actor_animation_entry.h"
void func_80800000_chcaptainblubber(Actor *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, BtIntPtr);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    extern s32 D_808016C0_chcaptainblubber[3];
    extern s32 func_8010D5DC;
    if (!arg0->unk64_20) {
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(&func_8010D5DC, (BtIntPtr)arg0->unk0);
        func_8008F938(1);
        func_8008F990(D_808016C0_chcaptainblubber, 0x43FA0000);
        arg0->unk64_20 = 1;
    }
}

void func_80800078_chcaptainblubber(Actor *arg0) {
    void _subaddieitem_entrypoint_0(BtIntPtr, BtUIntPtr, s32, s32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    void *func_801000D8(Actor *actor,s32 slot,s32 size);
    void func_80102424(Actor*, s32);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_801000D8(arg0, 0, 0x14);
    sp1C = temp_v0;
    _subaddieitem_entrypoint_0(temp_v0, 0x4E4U, 0x3E8, 3);
    _subaddieitem_entrypoint_2(sp1C);
    func_80102424(arg0, 5);
}

s32 func_800DA298(s32);
void func_800FFA88(Unk80132ED0 *);

void func_808000CC_chcaptainblubber(Actor *arg0) {
    struct BlubberData {
        f32 position[3];
        f32 pad[4];
        f32 unk1C;
    };
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    s32 _glcutDll_entrypoint_20();
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    extern f32 D_808016CC_chcaptainblubber[3];
    Prop *prop;

    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(arg0->position, D_808016CC_chcaptainblubber);
        func_80102424(arg0, 0xB);
        return;
    }
    prop = _gccubesearch_entrypoint_1(0x299, arg0->position);
    if (prop == NULL) {
        func_800FFA88(arg0->unk0);
        return;
    }
    _gspropctrl_entrypoint_11(prop, ((struct BlubberData *)arg0->actorData)->position);
    arg0->unk54 = _gspropctrl_entrypoint_12(prop);
    arg0->unk79_4 = 0;
    if (func_800EEAD4(arg0->position, ((struct BlubberData *)arg0->actorData)->position) > 1000000.0f) {
        func_800FFA88(arg0->unk0);
        return;
    }
    ((struct BlubberData *)arg0->actorData)->unk1C = 0.0f;
    arg0->position[0] += 175.0f;
    arg0->position[2] += -33.0f;
    if (func_800DA298(0xE0)) {
        func_80108B04(arg0, 1);
    }
}

void func_808001F0_chcaptainblubber(Actor *arg0) {
    struct BlubberFlags {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u32 pad70 : 28, u32 pad73 : 3);
        u32 expression : 1;
        BT_BITFIELD_ORDER(u32 pad73 : 3, u32 pad70 : 28);
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
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _capod_entrypoint_17(f32);
    void _capod_entrypoint_14(void);
    s32 _capod_entrypoint_21(BtIntPtr, BtIntPtr, s32, s32);
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80108528(s32, u32 *, s32, Actor **);
    s32 _chappearfx_entrypoint_1(BtIntPtr, s32, s32, s32);
    void func_80108B04(Actor *, u32);
    s32 func_800F5410(BtIntPtr);
    extern s32 D_808016D8_chcaptainblubber[4];
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
                _capod_entrypoint_21((BtIntPtr)arg0->unk0, (BtIntPtr)arg0->unk0, 4, 0x2011);
            }
            return 4;
        case 0x2F:
            switch (((s16 *)&arg2)[0]) {
                case 0x100B:
                    func_800C01A8(0x6B, 0);
                    _capod_entrypoint_13((BtIntPtr)arg0->unk0, (BtIntPtr)arg0->unk0, 0, 0x6010);
                    func_800FC6B0(0xE);
                    break;
                case 0x103F:
                    arg0->unk64_19 = 1;
                    break;
            }
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808016D8_chcaptainblubber, arg0->scale);
            return 1;
        case 0x3D:
            spawned = func_80108528(0x1F0, arg0->actorData, (s32)arg0->unk54, &arg0);
            spawned->unk74_7 = 0x33;
            if (func_800DB9B0()) {
                _chappearfx_entrypoint_1((BtIntPtr)spawned, 0x20, 0, 0x3F800000);
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
typedef struct { f32 values[3]; } Times3; typedef struct { f32 values[4]; } Times4; typedef struct { f32 values[7]; } Times7;
int func_80800A1C_chcaptainblubber(Actor *arg0) {



    extern ActorAnimationEntry D_80801650_chcaptainblubber[];
    extern Times4 D_808016E8_chcaptainblubber;
    extern Times3 D_808016F8_chcaptainblubber;
    extern Times3 D_80801704_chcaptainblubber;
    extern Times3 D_80801710_chcaptainblubber;
    extern Times7 D_8080171C_chcaptainblubber;
    extern Times3 D_80801738_chcaptainblubber;
    extern s32 D_80801744_chcaptainblubber[];
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C3F48(u32);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 spAC = 0;
    Times4 sp9C;
    Times3 sp90;
    Times3 sp84;
    Times3 sp78;
    Times7 sp5C;
    Times3 sp50;
    f32 sp44[3];
    f32 sp38[3];

    switch (D_80801650_chcaptainblubber[arg0->unk70_10].index) {
    case 0x159:
        sp9C = D_808016E8_chcaptainblubber;
        if (func_80101E4C(arg0, sp9C.values)) {
            func_800C4140(0x119564 + (((u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
            func_800C4140(0x119614 + (((u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.22f)) {
            func_800C4140(0x4CB194E3, arg0->position, 0x04B000FA);
        } else if (func_80101E14(arg0, 0.4f)) {
            func_800C4140(0x4CB194E4, arg0->position, 0x04B000FA);
        }
        break;
    case 0x1C0:
        if (func_80101E14(arg0, 0.14f)) {
            func_800C4140(0x7FF19612, arg0->position, 0x04B000FA);
        } else if (func_80101E14(arg0, 0.55f)) {
            spAC = 1;
            func_800C4140(0x1B5C50 + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        break;
    case 0x15A:
        sp90 = D_808016F8_chcaptainblubber;
        sp84 = D_80801704_chcaptainblubber;
        if (arg0->unk70_10 == 11) {
            if (func_80101E14(arg0, 0.24f)) {
                func_800C3F48(0x9C612 + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21));
            }
        } else if (func_80101E4C(arg0, sp90.values)) {
            if (arg0->unk70_10 == 9) {
                func_800C3F48(0x7FE7D612);
            } else {
                func_800C4140(0x7FE7D612, arg0->position, 0x04B000FA);
            }
        }
        if (func_80101E4C(arg0, sp84.values)) {
            spAC = 1;
            func_800C4140(0x177450 + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        break;
    case 0x1BF:
        sp78 = D_80801710_chcaptainblubber;
        if (func_80101E4C(arg0, sp78.values)) {
            spAC = 1;
            func_800C4140(0x119451 + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        break;
    case 0x17B:
        sp5C = D_8080171C_chcaptainblubber;
        sp50 = D_80801738_chcaptainblubber;
        if (func_80101E4C(arg0, sp5C.values)) {
            spAC = 1;
            func_800C4140(0x451 + (((func_800DC128(0x36B0, 0x3E81) >> 5) & 0x3FF) << 11) + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        break;
    case 0x16D:
        if (func_80101E14(arg0, 0.07f)) {
            func_800C4140(0x7FF19612, arg0->position, 0x04B000FA);
        } else if (func_80101E14(arg0, 0.9f)) {
            spAC = 1;
            func_800C4140(0x9C451 + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x04B000FA);
        }
        break;
    }
    if (spAC) {
        _subaddieskeleton_entrypoint_0(arg0, 0x14, sp38);
        _subaddieskeleton_entrypoint_0(arg0, 6, sp44);
        func_800BBCB8(sp38, 0, 1.0f, 1, D_80801744_chcaptainblubber);
        func_800BBCB8(sp44, 0, 1.0f, 1, D_80801744_chcaptainblubber);
    } BT_NATIVE_ONLY(return 0;)
}

void func_8080143C_chcaptainblubber(Actor *arg0) {
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern ActorAnimationEntry D_80801650_chcaptainblubber[];
    f32 sp24[3];

    if (D_80801650_chcaptainblubber[arg0->unk70_10].index == 0x1C0) {
        _subaddieskeleton_entrypoint_0(arg0, 3, sp24);
        sp24[1] = 0.0f;
    } else {
        func_800EFA4C(sp24, arg0->position[0], 0.0f, arg0->position[2]);
    }
    _chbadshad_entrypoint_1(arg0, sp24, 2.0f * arg0->scale);
}

void func_808014C8_chcaptainblubber(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
OSThread *chcaptainblubber_entrypoint_0(void)
{
    extern ActorData D_8080176C_chcaptainblubber[];
    return (OSThread *) D_8080176C_chcaptainblubber;
}
#include "captainblubber_data.inc"

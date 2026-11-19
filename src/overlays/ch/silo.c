#include "gc/newoption.h"

typedef struct {
    s16 unk0[3];
    s16 icon;
} SiloOption;
typedef struct { s16 audio[6]; SiloOption options[7]; } SiloTable;
extern SiloTable D_808012E0_chsilo; BT_IDO_ONLY(extern SiloOption D_808012EC_chsilo[];)

s32 func_80800000_chsilo(s32 arg0) {
    s32 rom_read_word(s32, u32 *);
    s32 result;
    u32 word;
    u32 address;
    s32 offset;

    result = *(s32 *)&D_808012E0_chsilo.options[arg0];
    address = (result & 0xFFFF) + 0xB0000000;
    offset = ((u32)result & 0xFFFF0000) >> 16;
    if (address & 2) {
        address = (address >> 2) << 2;
        rom_read_word(address, &word);
        result = (word & 0xFFFF0000) >> 16;
    } else {
        rom_read_word(address, &word);
        result = word & 0xFFFF;
    }
    if (offset != 0) {
        offset += 0xB0000000;
        if (offset & 2) {
            offset = (u32)offset >> 2;
            offset *= 4;
            rom_read_word(offset, &word);
            result += (word & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(offset, &word);
            result += word & 0xFFFF;
        }
    }
    return result + 0xA0;
}

void func_80800104_chsilo(Actor *arg0, s32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; BT_BITFIELD_ORDER(u8 high : 1, u8 low : 6); u8 flag : 1; BT_BITFIELD_ORDER(u8 low : 6, u8 high : 1); };
    if (!arg0->unk74_30) {
        arg2 |= 6;
        _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x6F);
        ((struct Flags *)arg0)->flag = 1;
    }
}

/* extern */

s32 func_8080015C_chsilo(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    if (arg1 == ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
        return 0;
    }
    if (func_800DA298(arg1 + 0x32C) == 0) {
        return 0;
    }
    return 1;
}

s32 func_808001A8_chsilo(void *arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    do {
        if (func_8080015C_chsilo(arg0, var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 8);
    return var_s1;
}

/* extern */

void func_80800210_chsilo(BtIntPtr arg0, BtIntPtr arg1) {

    _gcnewoption_entrypoint_32((void *)arg1, 111);
}

void func_80800238_chsilo(void *arg0, BtIntPtr arg1) {



    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    do {
        if (func_8080015C_chsilo(arg0, var_s0) != 0) {
            _gcnewoption_entrypoint_12((OptionState *)arg1, var_s1, (s16) (var_s0 + 9));
            _gcnewoption_entrypoint_31(arg1, var_s1, BT_DATA_FIELD(D_808012E0_chsilo.options, D_808012EC_chsilo)[var_s0 - 1].icon);
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void func_808002E8_chsilo(Actor *arg0, s32 arg1) {
    s32 func_8080015C_chsilo(void *, s32);
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    do {
        if (func_8080015C_chsilo(arg0, var_s0) != 0) {
            if (var_s1 == arg1) {
                arg0->unk58 = (f32) var_s0;
                return;
            }
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void func_80800378_chsilo(BtIntPtr arg0) {
    s32 func_800903D0(BtIntPtr);
    func_800903D0(arg0 + 0x18);
}

/* extern */

void func_80800398_chsilo(Actor *arg0, s32 arg1) {
    void func_800F4CC0(BtIntPtr);
    void func_800F4CEC(BtIntPtr, u32);
    BtIntPtr func_800F54E4(void);
    if (arg1 != 0) {
        if (!arg0->unk74_29) {
            func_800F4CEC(func_800F54E4(), 0x33);
            arg0->unk74_29 = 1;
        }
    } else if (arg0->unk74_29) {
        func_800F4CC0(func_800F54E4());
        arg0->unk74_29 = 0;
    }
}

/* extern */

s32 func_80800420_chsilo(Actor *arg0, s32 arg1) {
    BtIntPtr func_800F54E4(void);
    s32 func_800F7B9C(BtIntPtr, s32);
    if (arg1 != 0) {
        if (!arg0->unk64_19) {
            if (func_800F7B9C(func_800F54E4(), 0x8B) != 2) {
                return 0;
            }
            arg0->unk64_19 = 1;
        }
    } else if (arg0->unk64_19) {
        func_800F7B9C(func_800F54E4(), 0x90);
        arg0->unk64_19 = 0;
    }
    return 1;
}

s32 func_808004C0_chsilo(u8 *arg0, s32 arg1) {









    s32 _plcamera_entrypoint_3(BtIntPtr, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    void func_8008FE68(f32 *);
    s32 func_80090708(s32);
    void func_800907C0(f32 *);
    void func_800C964C(s32);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    BtIntPtr func_800F54E4(void);
    s32 func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80102424(u8 *, s32);
    void func_8010A828(void **, s32);
    void func_80800398_chsilo(Actor *, s32);
    s32 func_80800420_chsilo(Actor *, s32);
    extern s16 D_808012C0_chsilo[8];
    void _gcnewoption_entrypoint_35(s32, s32, s32, s32);
    BtIntPtr camera;
    s32 count;
    void *option;
    struct SiloFlag { BT_BITFIELD_ORDER(u8 high : 3, u8 low : 4); u8 active : 1; BT_BITFIELD_ORDER(u8 low : 4, u8 high : 3); };

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _subaddieDll_entrypoint_4(arg0, 1);
            break;
        case 2:
            func_800DA544((*(s32 *)(arg0 + 0x6C) & 0x1FF) + 0x32C);
            ((struct SiloFlag *)(arg0 + 0x65))->active = 1;
            *(f32 *)(arg0 + 0x24) = 5.0f;
            break;
        case 6:
            *(f32 *)(arg0 + 0x24) = 0.5f;
            break;
        case 5:
            _gcnewoption_entrypoint_6((Actor *)arg0, 0);
            func_80090708(0);
            func_8010A828((void **)arg0, 2);
            break;
        case 8:
            func_80800420_chsilo(arg0, 0);
            break;
        case 11:
            _plcamera_entrypoint_3(func_800F54E4(), 1);
            break;
    }
    func_80102424(arg0, arg1);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _subaddieDll_entrypoint_4(arg0, 0);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), D_808012C0_chsilo);
            break;
        case 6:
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), D_808012C0_chsilo);
            break;
        case 4:
            camera = func_800F54E4();
            func_800F82D4(camera, 1);
            _plcamera_entrypoint_3(camera, 0);
            func_80800398_chsilo(arg0, 1);
            func_8008FE68((f32 *)(arg0 + 0x28));
            break;
        case 5:
            count = func_808001A8_chsilo((BtIntPtr)arg0);
            _gcnewoption_entrypoint_4((Actor *)arg0, 0, BT_NATIVE_ONLY((BtIntPtr)) BT_IDO_ONLY((u32 *))_gcnewoption_entrypoint_35, 0, 0x184F);
            option = func_80100094((BtIntPtr)arg0, 0);
            _gcnewoption_entrypoint_8(option, count >= 6 ? 5 : count);
            _gcnewoption_entrypoint_9(option, count);
            _gcnewoption_entrypoint_10(option, 0);
            func_80800210_chsilo((BtIntPtr)arg0, (BtIntPtr)option);
            _gcnewoption_entrypoint_14(option, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42(option, 0.1f);
            _gcnewoption_entrypoint_11(option);
            func_8010A828((void **)arg0, 10);
            break;
        case 10:
            func_80090708(2);
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), D_808012C0_chsilo);
            break;
        case 8:
            func_800C964C(0x10);
            func_80800420_chsilo(arg0, 1);
            func_80800398_chsilo(arg0, 1);
            func_800EE7F8((f32 *)(arg0 + 0x28), (f32 *)(arg0 + 4));
            *(f32 *)(arg0 + 0x2C) -= 150.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), D_808012C0_chsilo);
            break;
        case 11:
            func_80800398_chsilo(arg0, 1);
            func_80800420_chsilo(arg0, 1);
            func_800EE7F8((f32 *)(arg0 + 0x28), (f32 *)(arg0 + 4));
            *(f32 *)(arg0 + 0x2C) -= 150.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            break;
        case 9:
            func_80800398_chsilo(arg0, 0);
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 8) - 25.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            func_80800378_chsilo((BtIntPtr)arg0);
            break;
    }
    return 1;
}

void func_8080087C_chsilo(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_1(u32, f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_8010A828(void **, s32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    s32 pad;
    f32 *volatile position;
    f32 *volatile data;
    Prop *prop;

    prop = _gccubesearch_entrypoint_1(0x309, position = arg0->position);
    arg0->unk6C_0 = arg0->unk74_7 - 50;
    arg0->scale = 1.0f;
    if (prop == NULL) {
        func_800EE7F8(data = (f32 *)arg0->actorData, position);
        func_800EF1B8(data, arg0->rotation[1] - 90.0f, 200.0f);
    } else {
        _gspropctrl_entrypoint_11(prop, (f32 *)arg0->actorData);
    }
    func_8010A828((void **)arg0, 2);
    if (func_800DA298(arg0->unk6C_0 + 0x32C)) {
        arg0->unk64_20 = 1;
        if (func_800DA9E4(0x6BF, 0)) {
            if (func_8010CB0C(position, (s32)(arg0->scale * 55.0f),
                             (s32)(arg0->scale * 500.0f),
                             (s32)(arg0->scale * -50.0f))) {
                func_808004C0_chsilo((u8 *)arg0, 8);
                return;
            }
        }
        func_808004C0_chsilo((u8 *)arg0, 1);
        return;
    }
    func_808004C0_chsilo((u8 *)arg0, 1);
}

/* extern */

void func_808009E8_chsilo(Actor *volatile arg0) {
    void *func_80100094(Actor *, u32);

    void func_80800398_chsilo(Actor *, s32);
    Actor *actor;
    if (func_80100094(*(Actor **)&arg0, 0) != 0) {
        _gcnewoption_entrypoint_6(*(Actor **)&arg0, 0);
    }
    actor = arg0;
    if ((*(Actor **)&arg0)->unk70_10 == 0xA) {
        func_80800398_chsilo(actor, 0);
    }
}

/* extern */

void func_80800A40_chsilo(Actor *arg0) {
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    f32 func_800D8FF8(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_8010CAC0(f32 *, u32);
    s32 sp1C;

    sp1C = func_80090178(1);
    if ((func_8010CAC0(arg0->position, 0x1F4) != 0) && (sp1C != 0) && (*(f32 *)&arg0->actorData[3] <= 0.0f)) {
        switch (arg0->unk70_10) {
        case 2:
        case 3:
        case 7:
            break;
        default:
            if (func_800DA9E4(0x334, 1) == 0) {
                func_80800104_chsilo(arg0, 0xDA6, 8);
            }
            if (arg0->unk6C_0) {
                func_808004C0_chsilo((u8 *) arg0, 2);
            }
        }
    } else if ((*(f32 *)&arg0->actorData[3] <= 0.0f) || (sp1C == 0)) {
        switch (arg0->unk70_10) {
        case 1:
        case 6:
            break;
        default:
            func_808004C0_chsilo((u8 *) arg0, 6);
        }
    } else {
        *(f32 *)&arg0->actorData[3] -= func_800D8FF8();
    }
}

void func_80800B80_chsilo(Actor *arg0) {
    s32 _gcgoto_entrypoint_1(s32, s32);

    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    s32 func_8008FA2C(s32, s32);
    void func_8008FB58(f32 *, f32, f32);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    void func_800904C8(s32);
    void func_800907C0(f32 *);
    void func_800A7AD4(s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_8010CAC0(f32 *, u32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    s32 func_80800000_chsilo(s32);
    extern s16 D_808012D0_chsilo[8];

    f32 delta;

    delta = func_800D8FF8();
    if (arg0->unk6C_0) {
        switch (arg0->unk70_10) {
        case 1:
            func_8008FB58(arg0->position, arg0->scale * 30.0f, arg0->scale * 60.0f);
            func_80800A40_chsilo(arg0);
            break;
        case 2:
            func_8008FB58(arg0->position, arg0->scale * 30.0f, arg0->scale * 60.0f);
            if (func_80101DDC(arg0)) {
                func_808004C0_chsilo((u8 *)arg0, 3);
            }
            break;
        case 3:
            if (func_8010CB0C(arg0->position, (s32)(arg0->scale * 55.0f),
                    (s32)(arg0->scale * 45.0f), (s32)(arg0->scale * -50.0f)) &&
                func_8008FA2C(1, 0)) {
                if (func_808001A8_chsilo(arg0) > 0) {
                    if (func_80800420_chsilo(arg0, 1)) {
                        func_808004C0_chsilo((u8 *)arg0, 4);
                    }
                } else {
                    func_80800104_chsilo(arg0, 0xDA8, 0);
                    func_80800378_chsilo((BtIntPtr)arg0);
                    func_808004C0_chsilo((u8 *)arg0, 7);
                }
            } else {
                func_80800A40_chsilo(arg0);
            }
            break;
        case 4:
            *(f32 *)&arg0->actorData[4] += (arg0->position[0] - *(f32 *)&arg0->actorData[4]) * 0.2f;
            *(f32 *)&arg0->actorData[6] += (arg0->position[2] - *(f32 *)&arg0->actorData[6]) * 0.2f;
            if (*(f32 *)&arg0->actorData[5] < arg0->position[1] - 150.0f) {
                _subaddieaudioquick_entrypoint_2((u8 *)arg0, arg0->position, D_808012E0_chsilo.audio);
                func_808004C0_chsilo((u8 *)arg0, 5);
            } else {
                *(f32 *)&arg0->actorData[5] -= 300.0f * delta;
                func_800907C0((f32 *)&arg0->actorData[4]);
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808012D0_chsilo);
            }
            break;
        case 5:
            _gcnewoption_entrypoint_0(func_80100094(arg0, 0));
            break;
        case 11:
            if (arg0->position[1] < *(f32 *)&arg0->actorData[5]) {
                func_80800398_chsilo(arg0, 0);
                func_80800420_chsilo(arg0, 0);
                _subaddieaudioquick_entrypoint_2((u8 *)arg0, arg0->position, D_808012E0_chsilo.audio);
                func_80800378_chsilo((BtIntPtr)arg0);
                func_808004C0_chsilo((u8 *)arg0, 7);
            } else {
                *(f32 *)&arg0->actorData[5] += 300.0f * delta;
                func_800907C0((f32 *)&arg0->actorData[4]);
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808012D0_chsilo);
            }
            break;
        case 10:
            if (func_80101DDC(arg0)) {
                func_800DA544(0x6BF);
                func_800A7AD4(1, 0x11);
                _gcgoto_entrypoint_1(func_80800000_chsilo((s32)arg0->unk58 - 1),
                    *(s16 *)((u8 *)&D_808012E0_chsilo + 8 + (s32)arg0->unk58 * sizeof(SiloOption)));
            }
            break;
        case 6:
            func_8008FB58(arg0->position, arg0->scale * 30.0f, arg0->scale * 60.0f);
            func_80800A40_chsilo(arg0);
            if (func_80101DDC(arg0)) {
                func_808004C0_chsilo((u8 *)arg0, 1);
            }
            break;
        case 8:
            if (func_80101E14(arg0, 0.4f)) {
                func_808004C0_chsilo((u8 *)arg0, 9);
            }
            break;
        case 9:
            if (!func_8010CAC0(arg0->position, (s32)(arg0->scale * 150.0f))) {
                func_808004C0_chsilo((u8 *)arg0, 3);
            }
            break;
        case 7:
            if (!func_8010CB0C(arg0->position, (s32)(arg0->scale * 55.0f),
                    (s32)(arg0->scale * 500.0f), (s32)(arg0->scale * -50.0f))) {
                func_808004C0_chsilo((u8 *)arg0, 3);
            }
            break;
        }
        if (func_80090178(0x10000) &&
            func_8010CAC0(arg0->position, (s32)(arg0->scale * 60.0f))) {
            func_800904C8(0x1F);
        }
    }
}

s32 func_80801080_chsilo(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DF744(s32, s32);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    BtIntPtr temp;

    switch (arg1) {
    case 0x40:
        if (arg0->unk6C_0) {
            func_808004C0_chsilo((u8 *)arg0, 2);
        }
        break;
    case 0x1F:
        func_801015D0(arg0);
        if (arg0->unk64_20) {
            func_800DF744(3, 2);
        } else {
            func_800DF744(3, 1);
        }
        break;
    case 0x95:
        func_8080087C_chsilo(arg0);
        break;
    case 0x20:
        temp = func_80101080();
        switch (((s16 *)&arg2)[1]) {
        case 3:
            func_808002E8_chsilo(arg0, ((s16 *)&arg2)[0]);
            func_808004C0_chsilo((u8 *)arg0, 0xA);
            break;
        case 0:
            func_80800238_chsilo(arg0, temp);
            break;
        case 2:
            func_808004C0_chsilo((u8 *)arg0, 0xB);
            break;
        }
        break;
    case 0x2E:
        arg0->unk74_30 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808011C8_chsilo(BtIntPtr arg0, s32 arg1) {

    s32 func_800EB854();
    void *func_80100094(Actor *, u32);
    s32 func_801018A4(BtIntPtr, BtIntPtr);
    BtIntPtr temp_v0;

    if (func_800EB854() == 3) {
        temp_v0 = func_80100094(arg0, 0);
        if (temp_v0 != 0) {
            _gcnewoption_entrypoint_1((void *)temp_v0, arg1);
        }
    } else {
        func_801018A4(arg0, arg1);
    }
}

OSThread *chsilo_entrypoint_0(void)
{
    extern ActorData D_80801384_chsilo[1];
    return (OSThread *) D_80801384_chsilo;
}
#include "silo_data.inc"

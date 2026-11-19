#include "common.h"
typedef struct { s16 map; s16 next; } IntroTickerMap;
struct TickerMusic { s16 map; s16 stopTrack; s16 playTrack; s16 padding; }; s32 func_80800000_chintroticker(u8 *arg0) {
    s32 func_800EA05C();
    void func_800FC6B0(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);






    extern struct TickerMusic D_80800830_chintroticker[];
    extern s32 D_808008A8_chintroticker[];
    struct TickerMusic *entry;
    void *end;
    s32 map;
    s32 playTrack;
    s32 none = -1;

    map = func_800EA05C();
    entry = D_80800830_chintroticker; end = D_808008A8_chintroticker;
    do {
        if (map == entry->map) {
            if (entry->stopTrack != none && func_800FCCD4(entry->stopTrack)) {
                func_800FCAE0(entry->stopTrack, 0, 0x2EE0);
                func_800FCA90(entry->stopTrack);
            }
            playTrack = entry->playTrack;
            if (none != playTrack) {
                func_800FC6B0(playTrack);
            }
        }
        entry++;
    } while (entry != end); BT_NATIVE_ONLY(return 0;)
}

s32 func_808000B0_chintroticker(u8 *arg0, s32 arg1) {
    void _gcfrontend_entrypoint_9(s32);
    extern s32 D_808008A8_chintroticker[];
    struct TickerState {
        u8 padding[0x79];
        BT_BITFIELD_ORDER(u8 state : 4, u8 other : 4);
        BT_BITFIELD_ORDER(u8 other : 4, u8 state : 4);
    };
    s32 state = 0;
    s32 value;

    switch (arg1) {
    case 0xA1:
    case 0xA2:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xA6:
    case 0xA7:
    case 0xA8:
    case 0xA9:
    case 0xAA:
    case 0xAB:
    case 0xAC:
        state = 2;
        break;
    case 0x17E:
    case 0x18C:
    case 0x18D:
    case 0x18E:
    case 0x18F:
    case 0x190:
        state = 3;
        break;
    case 0x192:
    case 0x193:
    case 0x194:
    case 0x195:
    case 0x197:
    case 0x198:
    case 0x199:
        state = 4;
        break;
    case 0x191:
    case 0x196:
        state = 5;
        break;
    case 0x18B:
        state = 1;
        break;
    case 0x167:
        break;
    }
    value = D_808008A8_chintroticker[state];
    if (value != 0) {
        _gcfrontend_entrypoint_9(value);
    }
    ((struct TickerState *)arg0)->state = state;
    return 1;
}

void func_80800188_chintroticker(u8 *arg0, s32 arg1) {
    u8 func_800167F4(void);
    void _chattract_entrypoint_1(s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);

    if (arg1 == 0xA1 || arg1 == 0x18B || arg1 == 0x18E || arg1 == 0x194 || arg1 == 0x196) {
        switch (arg0[0x79] >> 4) {
        case 0:
            break;
        case 1:
            if (func_800167F4() != 0) {
                _chattract_entrypoint_1(3);
            }
            break;
        case 2:
            func_800DA544(0x578);
            break;
        case 3:
            func_800DA524(0x360);
            func_800DA524(0x3B);
            break;
        case 4:
            func_800DA544(0x360);
            func_800DA524(0x3B);
            func_800DA524(0x578);
            break;
        case 5:
            break;
        }
    }
}

/* extern */

void func_80800254_chintroticker(Actor *arg0) {
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    switch (arg0->unk79_4) {
    case 2:
        func_800DA524(0x578);
        return;
    case 3:
        func_800DA544(0x360);
        func_800DA524(0x3B);
        return;
    case 4:
        func_800DA524(0x360);
        func_800DA544(0x3B);
        func_800DA524(0x1A5);
        func_800DA544(0x578);
        /* fallthrough */
    default:
    case 0:
    case 1:
    case 5:
        return;
    }
}

void func_808002DC_chintroticker(u8 *arg0) {
    s16 _glcutDll_entrypoint_18(void);
    void _glintrosyncDll_entrypoint_2(f32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    s32 func_80800000_chintroticker(u8 *);
    extern s32 D_808008C0_chintroticker;
    extern IntroTickerMap D_808008C4_chintroticker[28];
    s32 *var_s0;
    s32 *end;
    s32 temp_s2;
    Actor *actor = (Actor *)arg0;

    temp_s2 = func_800EA05C();
    var_s0 = &D_808008C0_chintroticker; end = (s32 *)D_808008C4_chintroticker;
    do {
        if (temp_s2 == *var_s0) {
            _glintrosyncDll_entrypoint_2(0.0f);
        }
        var_s0++;
    } while (var_s0 != end);
    if (func_808000B0_chintroticker(arg0, temp_s2) == 0) {
        func_800FFAB0(actor);
        return;
    }
    func_80800188_chintroticker(arg0, temp_s2);
    if (_glcutDll_entrypoint_18() == 0x68) {
        actor->unk64_20 = 1;
    }
    func_80800000_chintroticker(arg0);
    ((f32 *)actor->actorData)[4] = 0.0;
    ((f32 *)actor->actorData)[5] = 0.0;
}

void func_808003BC_chintroticker(s32 arg0) 
{
}
void func_808003C4_chintroticker(BtIntPtr arg0) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_13(void);
    void _glcutDll_entrypoint_12(s32 arg0);
    void _glcutDll_entrypoint_17(void);
    void _gsattract_entrypoint_5(s32);
    void func_800A7990(s32, s32, s32);
    s32 func_800D395C(void);
    int func_800DB9B0(void);
    void func_800EA334(s32);
    Actor *actor = (Actor *)arg0;

    func_80800254_chintroticker(actor);
    if (func_800D395C() != 0) {
        _gcfrontend_entrypoint_10();
        func_800EA334(1);
        return;
    }
    if (func_800DB9B0() != 0) {
        _glcutDll_entrypoint_12(1);
        _glcutDll_entrypoint_17();
        return;
    }
    switch (actor->unk79_4) {
    case 2:
        func_800A7990(0xAF, 4, 1);
        return;
    case 1:
        _gsattract_entrypoint_5(0);
        return;
    case 4:
        func_800A7990(0x160, 4, 1);
        return;
    case 5:
        _gcfrontend_entrypoint_13();
        break;
    case 3:
        break;
    }
}

void func_808004A8_chintroticker(BtIntPtr arg0, s32 arg1) {
    void _glcutDll_entrypoint_14(s32);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    void func_800A7990(s32, s32, s32);
    int func_800A8264(void);
    void func_808003C4_chintroticker(BtIntPtr);
    Actor *actor = (Actor *)arg0;

    if (func_800A8264() == 0) {
        if (arg1 >= 0) {
            if (actor->unk64_20) {
                _glcutDll_entrypoint_14(1);
                _glcutDll_entrypoint_24(arg1, -1, -1);
                return;
            }
            func_800A7990(arg1, 0, 1);
            return;
        }
        func_808003C4_chintroticker(arg0);
    }
}

void func_80800530_chintroticker(BtIntPtr arg0, s32 arg1) {
    void func_808004A8_chintroticker(BtIntPtr, s32);
    extern IntroTickerMap D_808008C4_chintroticker[28];
    IntroTickerMap *var_v1;
    s16 temp_a1;
    u32 var_v0;

    var_v1 = D_808008C4_chintroticker;
    for (var_v0 = 0; var_v0 != 0x1C; var_v0++) {
        if (arg1 == var_v1->map) {
            break;
        }
        var_v1++;
    }
    if (var_v0 < 0x1CU) {
loop_4:
        temp_a1 = var_v1->next;
        var_v0 += 1;
        if (temp_a1 < 0) {
            func_808004A8_chintroticker(arg0, temp_a1);
            return;
        }
        var_v1++;
        if (var_v0 >= 0x1CU) {

        } else {
            goto loop_4;
        }
    }
}

void func_808005AC_chintroticker(BtIntPtr arg0) {
    s32 func_800EA05C(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_800DA298(s32);
    int func_800A8264(void);
    s32 func_80015FA0(s32);
    s32 func_80016B30(s32, s32);
    void _gcfrontend_entrypoint_10(void);
    void _glintrosyncDll_entrypoint_4(f32);
    f32 func_800D9004(void);
    f32 func_800D8FF8(void);
    extern IntroTickerMap D_808008C4_chintroticker[28];
    extern ActorData D_80800934_chintroticker[1];
    IntroTickerMap *entry;
    void *end;
    s32 map;
    Actor *actor = (Actor *)arg0;

    map = func_800EA05C();
    if (func_800DA9E4(0, 0)) {
        entry = D_808008C4_chintroticker; end = D_80800934_chintroticker;
        do {
            if (map == entry->map) {
                func_808004A8_chintroticker(arg0, entry->next);
            }
            entry++;
        } while (entry != end);
    }
    switch (actor->unk79_4) {
    case 1:
        if (func_800DA298(0xD56) && !func_800A8264() && func_80015FA0(0) == 1) {
            _gcfrontend_entrypoint_10();
        }
        break;
    case 2:
    default:
        if (func_80016B30(0, 1) == 1) {
            func_80800530_chintroticker(arg0, map);
        }
        break;
    }
    _glintrosyncDll_entrypoint_4(func_800D9004());
    ((f32 *)actor->actorData)[4] += func_800D9004();
    ((f32 *)actor->actorData)[5] += func_800D8FF8();
}

OSThread *chintroticker_entrypoint_0(void)
{
    extern ActorData D_80800934_chintroticker[1];
    return (OSThread *) D_80800934_chintroticker;
}
#include "ticker_data.inc"

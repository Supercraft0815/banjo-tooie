#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800000_chintroticker.s")

s32 func_808000B0_chintroticker(u8 *arg0, s32 arg1) {
    void _gcfrontend_entrypoint_9(s32);
    extern s32 D_808008A8_chintroticker[];
    struct TickerState {
        u8 padding[0x79];
        u8 state : 4;
        u8 other : 4;
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
    s32 func_800167F4(void);
    void _chattract_entrypoint_1(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);

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
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
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
    s32 _glcutDll_entrypoint_18();
    void _glintrosyncDll_entrypoint_2(f32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    s32 func_80800000_chintroticker(u8 *);
    extern s32 D_808008C0_chintroticker;
    extern s16 D_808008C4_chintroticker;
    s32 *var_s0;
    s32 *end;
    s32 temp_s2;
    Actor *actor = (Actor *)arg0;

    temp_s2 = func_800EA05C();
    var_s0 = &D_808008C0_chintroticker; end = (s32 *)&D_808008C4_chintroticker;
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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808003C4_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808004A8_chintroticker.s")

void func_80800530_chintroticker(s32 arg0, s32 arg1) {
    s32 func_808004A8_chintroticker(s32, s16);
    extern s16 D_808008C4_chintroticker;
    s16 *var_v1;
    s16 temp_a1;
    u32 var_v0;

    var_v1 = &D_808008C4_chintroticker;
    for (var_v0 = 0; var_v0 != 0x1C; var_v0++) {
        if (arg1 == *var_v1) {
            break;
        }
        var_v1 += 2;
    }
    if (var_v0 < 0x1CU) {
loop_4:
        temp_a1 = var_v1[1];
        var_v0 += 1;
        if (temp_a1 < 0) {
            func_808004A8_chintroticker(arg0, temp_a1);
            return;
        }
        var_v1 += 2;
        if (var_v0 >= 0x1CU) {

        } else {
            goto loop_4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808005AC_chintroticker.s")

OSThread *chintroticker_entrypoint_0(void)
{
    extern u8 D_80800934_chintroticker[];

    return (OSThread *) D_80800934_chintroticker;
}

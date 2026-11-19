#include "1EE9AB0_types.h"
s32 func_80111340()
{
    return 0x8C;
}

void func_80111348(s32 *arg0) {
    void func_801113B8(void *);
    void func_80111590(void *, f32, f32, f32, f32);
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    func_801113B8(arg0);
    func_80111590(arg0, 10.0f, 10.0f, 120.0f, 120.0f);
    func_80111B8C(arg0, 1.4f, 14.0f);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
}

/* extern */

void func_801113B8(void *arg0) {
    void func_800EFD24(f32 *);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x10);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x38);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x44);
}

/* extern */

void func_80111410(void *arg0, void *arg1, void *arg2, f32 arg3) {
    f32 func_80013728(f32);
    f32 func_800D8FF8(void);
    f32 func_800F212C(f32, f32);
    f32 sqrtf(f32);
    f32 delta[3];
    f32 dt;
    f32 length;
    f32 step[3];
    f32 inverse;

    delta[0] = func_80013728(((f32 *)arg1)[0] - ((f32 *)arg2)[0]);
    delta[1] = func_80013728(((f32 *)arg1)[1] - ((f32 *)arg2)[1]);
    delta[2] = func_80013728(((f32 *)arg1)[2] - ((f32 *)arg2)[2]);
    length = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
    if (length != 0.0f) {
        dt = func_800D8FF8();
        inverse = 1.0f / length;
        step[0] = (*(f32 *)((s8 *)*&((Obj1EE9AB0_arg0 *)arg0)->unk34_voidp + 8) * dt) * (delta[0] * inverse);
        step[1] = (*(f32 *)((s8 *)*&((Obj1EE9AB0_arg0 *)arg0)->unk34_voidp + 0xC) * dt) * (delta[1] * inverse);
        step[2] = (arg3 * dt) * (delta[2] * inverse);
        step[0] = func_800F212C(step[0], delta[0]);
        step[1] = func_800F212C(step[1], delta[1]);
        step[2] = func_800F212C(step[2], delta[2]);
        ((f32 *)arg2)[0] += step[0];
        ((f32 *)arg2)[1] += step[1];
        ((f32 *)arg2)[2] += step[2];
    }
}

void func_80111590(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (4))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (8))) = arg3;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0xC))) = arg4;
}

/* extern */

s32 func_801115C8(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 func_800EEAA4(f32 *, f32 *);
    f32 sp1C;
    f32 temp_f0;

    sp1C = func_800EEAA4(arg0, arg2);
    temp_f0 = func_800EEAA4(arg0, arg3);
    if (((sp1C < arg1 && arg1 < temp_f0) || (arg1 < sp1C && temp_f0 < arg1)) && temp_f0 != sp1C) {
        *arg4 = (arg1 - sp1C) / (temp_f0 - sp1C);
        return 1;
    }
    return 0;
}

void func_80111680(f32 *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 arg4, f32 arg5, void *arg6) {
    s32 func_800D8FEC();
    s32 func_800EE780();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    int func_800EEEA8(f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800EF2A0(f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    f32 spFC[3];
    f32 spF0[3];
    f32 spE4[3];
    f32 spD8[3];
    f32 spCC[3];
    f32 spC0[3];
    f32 spB4[3];
    f32 distance = 0.0f;
    s32 spAC;
    f32 change = 0.0f;
    s32 i;
    f32 timestep = 0.0033333334f;
    f32 sp94[3];
    f32 sp90;
    f32 sp8C;
    f32 sp80[3];
    f32 sp74[3];
    s32 sp70 = 0;
    s32 sp6C = 0;
    f32 sp68;

    if (func_800EEAD4(arg0, arg1) < 0.01f) {
        func_800EE7F8(arg1, arg0);
        func_800EFD24(arg3);
    }
    if (func_800EEAD4(arg0, arg6) < 0.01f) {
        func_800EFB24(sp80, arg2, arg0);
        if (func_800EEEA8(sp80)) {
            func_800EFA4C(sp80, 1.0f, 0.0f, 0.0f);
        }
        func_800EFA4C(sp74, 0.0f, 1.0f, 0.0f);
        func_800EE97C(sp94, sp80, sp74);
        func_800EF2A0(sp94);
        sp90 = func_800EEAA4(sp94, arg0);
        func_800EF2A0(sp80);
        sp8C = func_800EEAA4(sp80, arg0);
        sp70 = sp6C = 1;
    }
    spAC = func_800D8FEC() * 5;
    i = 0;
    if (spAC > 0) {
    do {
        func_800EFB24(spFC, arg0, arg1);
        func_800EF334(spFC, arg4);
        func_800EFB24(spF0, spFC, arg3);
        func_800EF334(spF0, arg5);
        func_800EE7F8(spE4, arg3);
        func_800EE7F8(spD8, spE4);
        func_800EF174(spD8, spF0, timestep);
        func_800EE7F8(spCC, arg1);
        func_800EE780(spB4, spE4, spD8);
        func_800EF334(spB4, 0.5f * timestep);
        if (sp70 || sp6C) {
            func_800EE780(spC0, spCC, spB4);
            if (sp70 && func_801115C8(sp94, sp90, arg1, spC0, &sp68)) {
                func_800EF334(spB4, sp68);
                sp70 = 0;
                func_800EF174(spD8, sp94, -func_800EEAA4(spD8, sp94));
            } else if (sp6C && func_801115C8(sp80, sp8C, arg1, spC0, &sp68)) {
                func_800EF334(spB4, sp68);
                sp6C = 0;
                func_800EF174(spD8, sp80, -func_800EEAA4(spD8, sp94));
            }
        }
        func_800EE780(spC0, spCC, spB4);
        change += func_800EEAD4(arg3, spD8) / spAC;
        func_800EE7F8(arg1, spC0);
        func_800EE7F8(arg3, spD8);
        distance += func_800EEF94(spB4);
    } while (++i < spAC);
    }
    func_800EE7F8(arg6, arg0);
}    typedef struct { u8 pad0[0x30]; f32 unk30; f32 unk34; } Obj1EE9AB0_func_80111A38_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80111A38(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    void func_80111680(f32 *, f32 *, f32 *, void *, f32, f32, void *);
    f32 func_80112550(PlayerState *, f32[3]);
    f32 sp2C[3];
    u8 *temp_v0;
    func_80112550(arg0, sp2C);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111680(arg1, arg2, sp2C, temp_v0 + 0x24, (((Obj1EE9AB0_func_80111A38_temp_v0 *)temp_v0)->unk30), (((Obj1EE9AB0_func_80111A38_temp_v0 *)temp_v0)->unk34), temp_v0 + 0x38);
}

void func_80111A98(u8 *arg0) {
    func_801107F0(arg0, (*(s32 *)((s8 *)(arg0) + (0x34))) + 0x5C);
}

/* extern */

void func_80111ABC(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8((((Obj1EE9AB0_arg0 *)arg0)->unk34) + 26, arg1);
}

void func_80111AE0(void *arg0, f32 *arg1) {
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_80110898(arg0);
    func_801107F0(arg0, sp24);
    if (func_8010FFD0(sp20) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp24, arg1);
        func_80110770(arg0, arg1);
        return;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp24);
    func_80110770(arg0, sp24);
}

/* extern */

void func_80111B8C(s32 *arg0, f32 arg1, f32 arg2) {
    f32 func_800A3048(BtIntPtr);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x30))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x34))) = (f32) (arg2 * var_f2);
}

void func_80111C04(void *arg0) {
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    f32 dot;

    func_801107F0(arg0, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 20);
    func_800EFB24(sp28, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 26,
                 (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    func_800EFB24(sp34, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 20,
                 (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    func_800EF2A0(sp28);
    func_800EF2A0(sp34);
    dot = func_800EEAA4(sp28, sp34);
    if (dot < 0.0f || (((Obj1EE9AB0_arg0 *)arg0)->unk34)[29] < 0.0f) {
        func_80110770(arg0, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    }
    (((Obj1EE9AB0_arg0 *)arg0)->unk34)[29] = dot;
}

/* extern */

s32 func_80111CC8(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    BtIntPtr sp24;

    sp24 = func_80110898(arg0);
    func_801107F0(arg0, sp34);
    if (func_8010FFD0(sp24) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp34, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp34);
    func_8011106C(arg0, sp28);
    func_800EF04C(sp34, sp28);
    func_80110770(arg0, sp34);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

void func_80111DB0(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 sp34[3];
    f32 distance;
    f32 step;
    f32 delta;
    u8 *data;

    func_800EFB24(sp34, arg1, arg2);
    distance = func_800EEF94(sp34);
    if (0.01f < distance) {
        delta = func_800D8FF8();
        data = *(u8 **)(arg0 + 0x34);
        step = func_800FF060(distance, arg3, *(f32 *)(data + 0x80), *(f32 *)(data + 0x84), *(f32 *)(data + 0x7C), delta);
        if (distance < step) {
            step = distance;
            *arg3 = 0.0f;
        }
        func_800EF174(arg2, sp34, step / distance);
    } else {
        *arg3 = 0.0f;
    }
}

/* extern */

void func_80111E88(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 func_800D8FF8();
    f32 var_f20;
    f32 temp_f0;
    f32 targetVelocity;
    f32 acceleration;

    temp_f0 = func_800D8FF8();
    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    targetVelocity = (arg0 - *arg1) * arg3;
    acceleration = (targetVelocity - *arg2) * arg4;
    *arg2 += acceleration * temp_f0;
    var_f20 = *arg1 + (*arg2 * temp_f0);
    if (arg0 < *arg1) {
        if (var_f20 < arg0) {
            var_f20 = arg0;
            *arg2 = 0.0f;
        }
    } else if (arg0 < var_f20) {
        var_f20 = arg0;
        *arg2 = 0.0f;
    }
    *arg1 = var_f20;
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1EE9AB0_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1EE9AB0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ typedef struct { u8 pad0[0x30]; f32 unk30; f32 unk34; } Obj1EE9AB0_func_80111F70_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80111F70(u8 *arg0, u8 *arg1, u8 *arg2, void *arg3, f32 *arg4) {
    void func_80111DB0(u8 *, f32 *, f32 *, f32 *);
    f32 sp24;
    f32 temp_f12;
    u8 *temp_v0;

    sp24 = (((Obj1EE9AB0_arg2 *)arg2)->unk4);
    func_80111DB0(arg0, arg1, arg2, arg3);
    (((Obj1EE9AB0_arg2 *)arg2)->unk4) = sp24;
    temp_f12 = (((Obj1EE9AB0_arg1 *)arg1)->unk4);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111E88(temp_f12, arg2 + 4, arg4, (((Obj1EE9AB0_func_80111F70_temp_v0 *)temp_v0)->unk30), (((Obj1EE9AB0_func_80111F70_temp_v0 *)temp_v0)->unk34));
}

/* extern */

s32 func_80111FD4(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    BtIntPtr sp2C;
    u8 *temp_v0;

    sp2C = func_80110898(arg0);
    func_801107F0(arg0, sp3C);
    if (func_8010FFD0(sp2C) != 0) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x34)))) + (0x78))) = 0.0f;
        func_80113640(arg0, sp3C, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98((u8 *) arg0);
    func_80111ABC(arg0, arg1);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111F70(arg0, arg1, sp3C, temp_v0 + 0x78, temp_v0 + 0x88);
    func_8011106C(arg0, sp30);
    func_800EF04C(sp3C, sp30);
    func_80110770(arg0, sp3C);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

/* extern */

void func_801120CC(s32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800A3048(BtIntPtr);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x7C))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x80))) = (f32) (arg2 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x84))) = (f32) (arg3 * var_f2);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s16 D_80137340[25];
s16 D_80137372 BT_DATA(4, bss_core2bss2_2_music_tail, 0x1952);
#endif

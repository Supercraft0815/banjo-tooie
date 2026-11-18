#include "core2/1EEF790.h"

s32 func_80115EA0() 
{
    return 0x5C;
}

void func_80115EA8(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800D8FF8(void);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 mlAbsF(f32);

    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = arg0 - *arg1;
    sp30 = mlAbsF(sp34);
    if (0.001f < sp30) {
        sp2C = func_800FF060(sp34, arg2, arg4, arg5, arg3, func_800D8FF8());
        if (sp30 < mlAbsF(sp2C)) {
            *arg2 = 0.0f;
            *arg1 = arg0;
            return;
        }
        *arg1 += sp2C;
        return;
    }
    *arg2 = 0.0f;
    *arg1 = arg0;
} typedef struct { f32 unk0; union { u8 * unk4; void * unk4_voidp; }; f32 unk8; } Obj1EEF790_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80115F98(void *arg0) {
    (((Obj1EEF790_arg0 *)arg0)->unk8) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.0f;
    (((Obj1EEF790_arg0 *)arg0)->unk0) = 0.0f;
}    typedef struct { u8 pad0[0x4C]; f32 unk4C; u8 pad50[0x4]; f32 unk54; } Obj1EEF790_func_80115FB0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80115FB0(u8 *arg0) {
    f32 temp_f0;
    u8 *temp_v0;

    func_80115F98((((Obj1EEF790_arg0 *)arg0)->unk4));
    func_80115F98((((Obj1EEF790_arg0 *)arg0)->unk4) + 0x14);
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4)) + (0x4C))) = 0.0f;
    temp_v0 = (((Obj1EEF790_arg0 *)arg0)->unk4);
    temp_f0 = (((Obj1EEF790_func_80115FB0_temp_v0 *)temp_v0)->unk4C);
    (((Obj1EEF790_func_80115FB0_temp_v0 *)temp_v0)->unk54) = temp_f0;
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4)) + (0x50))) = temp_f0;
    (*(s16 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4)) + (0x2E))) = 0;
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4)) + (0x58))) = 1.0f;
}

/* extern */

void func_80116024(void *arg0 BT_PASS2(, f32 *bt_a1)) {
    s32 func_80116218();
    func_80116218(BT_NATIVE_ONLY(arg0) BT_PASS2(, bt_a1));
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x2C))) = 0;
}

void func_80116050(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4_voidp)) + (4))) = arg1;
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4_voidp)) + (0x18))) = (f32) (arg1 * 0.5f);
    (*(f32 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4_voidp)) + (0x40))) = arg1;
}

void func_8011607C(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 46) = arg1;
}

/* extern */

void func_80116088(u8 *arg0, BtIntPtr arg1) {
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_801107B0(void *, void *);
    f32 sp1C[3];

    func_801107B0(arg0, sp1C);
    if (func_800F1E6C(sp1C, (f32 *)arg1, (f32 *)(((Obj1EEF790_arg0 *)arg0)->unk4 + 0x28)) != 0) {
        (*(s8 *)((s8 *)((((Obj1EEF790_arg0 *)arg0)->unk4)) + (0x2C))) = 1;
    }
}

void func_801160DC(PlayerState *self, f32 arg1) {
    struct ba_anim_s *temp_v0;
    u8 flag = 1;

    (*(f32 *)((s8 *)(self->anim) + (0x20))) = arg1;
    temp_v0 = self->anim;
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x20)));
    (*(u8 *)((s8 *)(self->anim) + (0x24))) = flag;
    temp_v0 = self->anim;
    (*(u8 *)((s8 *)(temp_v0) + (0x10))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (0x24)));
    (*(f32 *)((s8 *)(self->anim) + (0x44))) = arg1;
    (*(u8 *)((s8 *)(self->anim) + (0x48))) = flag;
}

void func_80116120(void *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800D8FF8(void);
    f32 func_800F22EC(void *);
    void func_800F2388(void *, void *, void *);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);

    f32 delta[2];
    f32 distance;
    f32 step;
    f32 scale;

    func_800F2388(delta, arg0, arg1);
    distance = func_800F22EC(delta);
    if (0.01f < distance) {
        step = func_800FF060(distance, arg2, arg4, arg5, arg3, func_800D8FF8());
        if (distance < step) {
            scale = 1.0f;
            *arg2 = 0.0f;
        } else {
            scale = step / distance;
        }
        arg1[0] += delta[0] * scale;
        arg1[1] += delta[1] * scale;
    } else {
        *arg2 = 0.0f;
    }
}

s32 func_80116218(s32 *arg0, f32 *arg1) {
    f32 func_800136E4(f32);
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 func_800F5F50(s32);
    s32 func_80110840(s32 *);
    f32 angle;
    f32 speed;
    f32 sine;
    u8 *state;
    f32 delta[2];

    state = ((Obj1EEF790_arg0 *)arg0)->unk4;
    if (state[0x2C] != 0) {
        angle = *(f32 *)(state + 0x28);
    } else {
        angle = func_800F5F50(func_80110840(arg0));
    }
    angle = func_800136E4((arg1[1] - angle) + 180.0f);
    state = ((Obj1EEF790_arg0 *)arg0)->unk4;
    if (*(s16 *)(state + 0x2E) != 0) {
        if (state[0x48] != 0) {
            speed = *(f32 *)(state + 0x44);
        } else {
            speed = *(f32 *)(state + 0x40);
        }
    } else {
        speed = 0.0f;
    }
    func_80115EA8(speed, (f32 *)(state + 0x34), (f32 *)(state + 0x3C),
                 20.0f, 40.0f, -10.0f);
    sine = func_800137AC(angle);
    delta[0] = *(f32 *)(((Obj1EEF790_arg0 *)arg0)->unk4 + 0x34) * -func_800137C4();
    delta[1] = *(f32 *)(((Obj1EEF790_arg0 *)arg0)->unk4 + 0x34) * sine;
    state = ((Obj1EEF790_arg0 *)arg0)->unk4;
    func_80116120(delta, (f32 *)(state + 0x50), (f32 *)(state + 0x4C),
                 20.0f, 40.0f, -10.0f);
    state = ((Obj1EEF790_arg0 *)arg0)->unk4;
    arg1[0] += *(f32 *)(state + 0x58) * (*(f32 *)(state + 0x54) * 0.5f);
    state = ((Obj1EEF790_arg0 *)arg0)->unk4;
    arg1[1] += *(f32 *)(state + 0x58) * *(f32 *)(state + 0x50);
    (((Obj1EEF790_arg0 *)arg0)->unk4)[0x48] = 0; BT_NATIVE_ONLY(return 0;)
}

void func_801163A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Obj1EEF790_arg0 *)arg0)->unk4_voidp + 88) = arg1;
}

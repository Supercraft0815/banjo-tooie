#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressjoint/func_80800000_suexpressjoint.s")

s32 suexpressjoint_entrypoint_0(s16 arg0) {
    s16 func_80800000_suexpressjoint(s16);
    extern u8 D_80801824_suexpressjoint[][16];
    s32 temp_v0;
    u8 value;

    temp_v0 = func_80800000_suexpressjoint(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    value = D_80801824_suexpressjoint[temp_v0][0];
    return value + 0x20;
}

/* extern */

void suexpressjoint_entrypoint_1(void *arg0, s16 arg1) {
    s16 func_80800000_suexpressjoint(s16);
    (*(s16 *)((s8 *)(arg0) + (4))) = arg1; (*(s16 *)((s8 *)(arg0) + (6))) = func_80800000_suexpressjoint((*(s16 *)((s8 *)(arg0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressjoint/suexpressjoint_entrypoint_2.s")

void suexpressjoint_entrypoint_3(s32 arg0, void *arg1, s32 arg2) {
    typedef struct {
        f32 timer;
        s16 id;
        s16 index;
        u8 amount;
        u8 pad9[3];
        f32 weights[4];
        f32 total;
        u8 current[4];
    } Joint;
    typedef struct {
        void *unk0;
        u8 (*values)[4];
        u8 pad8[2];
        u8 defaultValue;
        u8 padB;
        u8 count;
        u8 padD[3];
    } JointInfo;
    extern JointInfo D_80801818_suexpressjoint[];
    u32 func_800D5298(void);
    u32 func_800D52A4(void);
    s32 func_800D52F4(void);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    f32 targets[4];
    s32 selected;
    f32 step;
    u8 *current;
    s32 i;
    Joint *joint = arg1;

    joint->total = 0.0f;
    current = joint->current;
    selected = D_80801818_suexpressjoint[joint->index].defaultValue;
    if (arg2 && func_800D52F4() == joint->id) {
        selected = func_800D52A4() - 1;
        if (selected < 0) {
            selected = D_80801818_suexpressjoint[joint->index].defaultValue;
        }
        if (func_800D5298()) {
            joint->timer = 0.05f;
        }
        if (joint->timer > 0.0f) {
            joint->timer -= func_800D8FF8();
        } else if (joint->timer < 0.0f) {
            selected = D_80801818_suexpressjoint[joint->index].defaultValue;
            joint->timer = 0.0f;
        }
        step = (100 - joint->amount) * 0.2f;
        if (step < 2.0f) {
            step = 2.0f;
        }
        joint->amount = func_800F15F8(joint->amount, 100.0f, step);
    } else {
        joint->amount -= joint->amount * 0.2f;
    }
    for (i = 0; i < D_80801818_suexpressjoint[joint->index].count; i++) {
        targets[i] = D_80801818_suexpressjoint[joint->index].values[selected][i];
        *current += (targets[i] - *current) * 0.15f;
        joint->weights[i] = *current * 0.01f;
        joint->total += joint->weights[i];
        current++;
    }
    if (joint->total != 0.0f) {
        for (i = 0; i < D_80801818_suexpressjoint[joint->index].count; i++) {
            joint->weights[i] /= joint->total;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressjoint/suexpressjoint_entrypoint_4.s")

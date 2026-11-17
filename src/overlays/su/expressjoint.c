#include "common.h"

typedef struct { u8 pad0[0x8]; s16 unk8; u8 padA[0xE]; s16 unk18; u8 pad1A[0xE]; s16 unk28; u8 pad2A[0xE]; s16 unk38; } Objexpressjoint_func_80800000_suexpressjoint_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */ s32 func_80800000_suexpressjoint(s32 arg0) {
    extern s16 D_80801820_suexpressjoint;
    extern s16 D_80801830_suexpressjoint;
    extern s32 D_80801838_suexpressjoint;
    s32 *var_v0;
    s32 var_v1;

    if (arg0 == D_80801820_suexpressjoint) {
        return 0;
    }
    var_v0 = &D_80801838_suexpressjoint;
    var_v1 = 2;
    if (arg0 == D_80801830_suexpressjoint) {
        return 1;
    }
loop_5:
    if (arg0 == (((Objexpressjoint_func_80800000_suexpressjoint_var_v0 *)var_v0)->unk8)) {
        return var_v1;
    }
    if (arg0 == (((Objexpressjoint_func_80800000_suexpressjoint_var_v0 *)var_v0)->unk18)) {
        return var_v1 + 1;
    }
    if (arg0 == (((Objexpressjoint_func_80800000_suexpressjoint_var_v0 *)var_v0)->unk28)) {
        return var_v1 + 2;
    }
    if (arg0 == (((Objexpressjoint_func_80800000_suexpressjoint_var_v0 *)var_v0)->unk38)) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x10;
    if (var_v1 == 0x16) {
        return -1;
    }
    goto loop_5;
}

s32 suexpressjoint_entrypoint_0(s16 arg0) {
    s32 func_80800000_suexpressjoint(s32);
    extern u8 D_80801824_suexpressjoint[][16];
    s32 temp_v0;
    u8 value;

    temp_v0 = func_80800000_suexpressjoint(arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    value = D_80801824_suexpressjoint[temp_v0][0];
    return value + 0x20;
}                  typedef struct { u8 pad0[0x4]; s16 unk4; s16 unk6; s8 unk8; } Objexpressjoint_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void suexpressjoint_entrypoint_1(void *arg0, s16 arg1) {
    s32 func_80800000_suexpressjoint(s32);
    (((Objexpressjoint_arg0 *)arg0)->unk4) = arg1; (((Objexpressjoint_arg0 *)arg0)->unk6) = func_80800000_suexpressjoint((((Objexpressjoint_arg0 *)arg0)->unk4));
}

typedef struct {
        void *unk0;
        u8 (*values)[4];
        u8 pad8[2];
        u8 defaultValue;
        u8 padB;
        u8 count;
        u8 padD[3];
} JointInfo;

void suexpressjoint_entrypoint_2(void *arg0, s16 arg1) {
    extern JointInfo D_80801818_suexpressjoint[];
    u8 *dest;
    JointInfo *info;
    s32 i;

    dest = (u8 *)arg0 + 0x20;
    suexpressjoint_entrypoint_1(arg0, arg1);
    ((Objexpressjoint_arg0 *)arg0)->unk8 = 0;
    info = &D_80801818_suexpressjoint[((Objexpressjoint_arg0 *)arg0)->unk6];
    i = 0;
    if (info->count > 0) {
        do {
            *dest++ = info->values[info->defaultValue][i++];
            info = &D_80801818_suexpressjoint[((Objexpressjoint_arg0 *)arg0)->unk6];
        } while (i < info->count);
    }
}

void suexpressjoint_entrypoint_3(BtIntPtr arg0, void *arg1, s32 arg2) {
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

typedef struct {
        f32 timer;
        s16 id;
        s16 index;
        u8 amount;
        u8 pad9[3];
        f32 weights[4];
        f32 total;
        u8 current[4];
} ExpressJoint;

void suexpressjoint_entrypoint_4(ExpressJoint *joint, Actor *actor) {
    typedef struct {
        f32 rotation[3];
        f32 translation[3];
        f32 scale[3];
    } JointTransform;
    typedef struct {
        u8 bone;
        u8 flags;
        JointTransform *transforms;
    } JointPart;
    extern JointInfo D_80801818_suexpressjoint[];
    void * func_800AE6BC(void *list);
    void *func_801040A8(Actor *);
    struct func_800E0960_1_s;
    void func_800E0AFC(struct func_800E0960_1_s *, u8, f32, f32, f32, f32);
    void func_800E0B8C(struct func_800E0960_1_s *, u8, f32, f32, f32, f32);
    void func_800E0C20(struct func_800E0960_1_s *, u8, f32, f32, f32, f32);
    s32 i, j, k;
    f32 translation[3];
    f32 rotation[3];
    f32 scale[3];
    f32 amount;
    BtIntPtr model;

    amount = joint->amount * 0.01f;
    model = func_800AE6BC(func_801040A8(actor));
    for (i = 0; i < D_80801818_suexpressjoint[joint->index].padB; i++) {
        for (j = 0; j < 3; j++) {
            rotation[j] = 0.0f;
            translation[j] = 0.0f;
            scale[j] = 0.0f;
            for (k = 0; k < D_80801818_suexpressjoint[joint->index].count; k++) {
                rotation[j] += ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].transforms[k].rotation[j] * joint->weights[k];
                translation[j] += ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].transforms[k].translation[j] * joint->weights[k];
                scale[j] += ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].transforms[k].scale[j] * joint->weights[k];
            }
        }
        if (((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].flags & 1) {
            func_800E0AFC((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, amount, translation[0], translation[1], translation[2]);
        } else {
            func_800E0AFC((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, -amount, translation[0], translation[1], translation[2]);
        }
        if (((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].flags & 2) {
            func_800E0C20((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, amount, rotation[0], rotation[1], rotation[2]);
        } else {
            func_800E0C20((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, -amount, rotation[0], rotation[1], rotation[2]);
        }
        if (((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].flags & 4) {
            func_800E0B8C((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, amount, scale[0], scale[1], scale[2]);
        } else {
            func_800E0B8C((void *)model, ((JointPart *)D_80801818_suexpressjoint[joint->index].unk0)[i].bone, -amount, scale[0], scale[1], scale[2]);
        }
    }
}

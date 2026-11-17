#include "common.h"

typedef struct { u8 pad0[0x18]; f32 unk18; s32 unk1C; u8 pad20[0x8]; s32 unk28; } Objblink_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void chblink_entrypoint_0(u8 *arg0, s32 arg1) {
    s32 func_800DC128(s32 arg0, s32 arg1);
    f32 func_800DC178(f32, f32);
    (((Objblink_arg0 *)arg0)->unk28) = arg1;
    (((Objblink_arg0 *)arg0)->unk18) = func_800DC178(0.0f, 5.0f);
    (((Objblink_arg0 *)arg0)->unk1C) = func_800DC128(0, 0x14);
}    typedef struct { u8 pad0[0x24]; s32 unk24; } Objblink_chblink_entrypoint_1_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

/* extern */

s16 chblink_entrypoint_1(s32 arg0) {
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    s16 sp1E;
    s16 temp_v0;
    int var_a0;
    u8 *temp_v0_2;
    f32 *var_v1;

    temp_v0 = func_8001B668(0, 0x2C);
    sp1E = temp_v0;
    temp_v0_2 = func_8001B798(temp_v0);
    var_v1 = (f32 *) temp_v0_2;
    (((Objblink_chblink_entrypoint_1_temp_v0_2 *)temp_v0_2)->unk24) = arg0;
    for (var_a0 = 0; var_a0 < 2; var_a0++) {
        var_v1[var_a0 + 4] = 0.0f;
        var_v1[var_a0 + 2] = 0.0f;
        var_v1[var_a0] = 0.0f;
    }
    chblink_entrypoint_0(temp_v0_2, 2);
    return sp1E;
}

void func_808000CC_chblink(f32 *arg0, s32 arg1, f32 arg2, f32 arg3) {
    f32 *temp_v0;

    temp_v0 = arg0;
    temp_v0 += arg1;
    temp_v0[2] = arg2;
    if (arg3 != 0.0f) {
        temp_v0[4] = (temp_v0[2] - temp_v0[0]) / arg3;
        return;
    }
    temp_v0[0] = temp_v0[2];
}

void func_80800118_chblink(void *arg0, s32 *arg1, s32 arg2) {
    typedef struct {
        f32 values[6];
        f32 timer;
        s32 index;
    } BlinkState;
    typedef struct {
        f32 duration;
        u8 channel;
        u8 pad[3];
        f32 value;
        f32 transition;
    } BlinkStep;
    f32 func_800D8FF8(void);
    f32 mlAbsF(f32);
    BlinkState *state = arg0;
    BlinkStep *steps = (BlinkStep *)arg1;
    f32 remaining;
    BlinkStep *step;

    remaining = func_800D8FF8();
    while (0.0f < remaining) {
        state->timer -= remaining;
        if (0.0f < state->timer)
            break;
        remaining = mlAbsF(state->timer);
        step = &steps[state->index];
        func_808000CC_chblink(arg0, step->channel, step->value, step->transition);
        step++;
        if (step->channel == 2) {
            step = steps;
            if (!arg2) {
                chblink_entrypoint_0(arg0, 1);
                return;
            } else {
                state->index = 0;
            }
        } else {
            state->index++;
        }
        state->timer = step->duration;
    }
}

void chblink_entrypoint_2(s16 arg0) {
    void *func_8001B798(s16);
    f32 func_800D8FF8(void);
    void func_80800118_chblink(void *, s32 *, s32);
    extern s32 D_80800430_chblink[84];
    f32 *sp1C;
    f32 sp18;
    f32 temp_f2;
    s32 var_v1;
    f32 *var_v0;

    sp1C = func_8001B798(arg0);
    sp18 = func_800D8FF8();
    func_80800118_chblink(sp1C, D_80800430_chblink, 1);
    var_v1 = 0;
    var_v0 = sp1C;
    do {
        var_v1 += 4;
        if (var_v0[2] != var_v0[0]) {
            temp_f2 = var_v0[4];
            var_v0[0] += temp_f2 * sp18;
            if ((temp_f2 > 0.0f && var_v0[2] < var_v0[0]) ||
                (temp_f2 < 0.0f && var_v0[0] < var_v0[2])) {
                var_v0[0] = var_v0[2];
            }
        }
        var_v0++;
    } while (var_v1 != 8);
}

/* extern */

void chblink_entrypoint_3(s16 arg0) {
    void func_8001B754(s16 handle);
    func_8001B754(arg0);
}    typedef struct { f32 unk0; u8 pad4[0x20]; s32 unk24; } Objblink_chblink_entrypoint_4_temp_s3; /* offsets.py genstruct: fields from raw offsets on temp_s3; rename once understood */

void chblink_entrypoint_4(s16 arg0) {
    void *func_8001B798(s16);
    void func_800DF744(s32, s32);
    f32 func_800F1214(f32, f32, f32);
    extern s32 D_80800580_chblink[][3];
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;
    void *temp_s3;

    temp_s3 = func_8001B798(arg0);
    var_s1 = 0;
    do {
        temp_v0 = (((Objblink_chblink_entrypoint_4_temp_s3 *)temp_s3)->unk24);
        temp_s0 = D_80800580_chblink[temp_v0][var_s1];
        if (temp_s0 != -1) {
            func_800DF744(temp_s0, (s32) func_800F1214((((Objblink_chblink_entrypoint_4_temp_s3 *)temp_s3)->unk0), 1.0f, (f32) D_80800580_chblink[temp_v0][2]));
        }
        var_s1++;
    } while (var_s1 != 2);
}
/* data_to_c.py: from asm/data/overlays/ch/blink.data.s */
s32 D_80800430_chblink[84] BT_DATA(4, overlays_ch_blink, 0x0) = { 1073741824, 16777216, 1065353216, 1036831949, 1024148374, 0, 1065353216, 1036831949, 1036831949, 16777216, 0, 1036831949, 1024148374, 0, 0, 1036831949, 1084227584, 16777216, 1065353216, 1031127695, 1024148374, 0, 1065353216, 1031127695, 1031127695, 16777216, 0, 1031127695, 1024148374, 0, 0, 1031127695, 1045220557, 16777216, 1065353216, 1035489772, 1024148374, 0, 1065353216, 1035489772, 1035489772, 16777216, 0, 1035489772, 1024148374, 0, 0, 1035489772, 1065353216, 16777216, 1065353216, 1036831949, 1024148374, 0, 1065353216, 1036831949, 1036831949, 16777216, 0, 1036831949, 1024148374, 0, 0, 1036831949, 1084227584, 16777216, 1065353216, 1036831949, 1024148374, 0, 1065353216, 1036831949, 1036831949, 16777216, 0, 1036831949, 1024148374, 0, 0, 1036831949, 0, 33554432, 0, 0 };
s32 D_80800580_chblink [4] [ 3 ] BT_DATA(4, overlays_ch_blink, 0x150) = { { 52, 53, 8 }, { 1, -1, 4 }, { 3, 3, 4 }, { 56, 57, 8 } };

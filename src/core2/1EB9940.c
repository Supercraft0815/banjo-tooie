#include "common.h"
#ifdef BT_NATIVE
#include "core2/animation_resource.h"
#define CHANNEL(entry) (*(u16 *)(entry) & 15)
#define GROUP(entry) (*(u16 *)(entry) >> 4)
#else
#define CHANNEL(entry) ((entry)->channel)
#define GROUP(entry) ((entry)->group)
#endif

/* extern */

typedef struct { f32 unk0; f32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; f32 unk18; f32 unk1C; f32 unk20; } Obj1EB9940_arg3; /* offsets.py genstruct: fields from raw offsets on arg3; rename once understood */ typedef struct { s16 unk0; s16 unk2; s16 unk4; } Obj1EB9940_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_800E0050(s16 *arg0, f32 arg1, s32 arg2, f32 *arg3) {
    struct Entry { BT_BITFIELD_ORDER(u16 group : 12, u16 channel : 4); BT_BITFIELD_ORDER(u16 channel : 4, u16 group : 12); s16 count; };
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
    f32 temp_f0;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    struct Entry *var_s1;

    temp_f0 = func_800E0414(arg0, arg1);
    (((Obj1EB9940_arg3 *)arg3)->unk8) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk4) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk0) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk20) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk1C) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk18) = 0.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk14) = 1.0f;
    (((Obj1EB9940_arg3 *)arg3)->unk10) = 1.0f;
    (((Obj1EB9940_arg3 *)arg3)->unkC) = 1.0f;
    var_s3 = 0;
    var_s1 = (struct Entry *)((u8 *)arg0 + 8);
    var_s2 = 0;
    if ((((Obj1EB9940_arg0 *)arg0)->unk4) > 0) {
loop_1:
        var_s0 = CHANNEL(var_s1);
        if (arg2 != GROUP(var_s1)) {
            if (var_s3 != 0) {
                return;
            }
            goto block_7;
        }
        var_s3 = 1;
        if (var_s0 >= 9) {
            var_s0 -= 9;
        }
        arg3[var_s0] = func_800E04C0((u8 *)var_s1, temp_f0, 0);
block_7:
        var_s2 += 1;
        var_s1 = (struct Entry *)((u8 *)var_s1 + var_s1->count * 4 + 4);
        if (var_s2 >= (((Obj1EB9940_arg0 *)arg0)->unk4)) {

        } else {
            goto loop_1;
        }
    }
}

#ifdef BT_NATIVE
void func_800E0170(s16 *arg0, f32 arg1, s32 arg2, BoneTransformList *arg3) {
#else
void func_800E0170(s16 *arg0, f32 arg1, s32 arg2, s32 arg3) {
#endif
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
#ifndef BT_NATIVE
    void func_800E084C(s32, f32 *, u32);
#endif
    s32 channel;
    u8 *element;
    u32 group;
    s32 i;
    s32 duration;
    f32 progress;
    s32 pad_before[1];
    f32 transform[3][3];
    s32 pad[2];

    progress = func_800E0414(arg0, arg1);
    if (arg2 != 0) {
        duration = arg0[1] - arg0[0];
    } else {
        duration = 0;
    }
    element = (u8 *)(arg0 + 4);
    group = 0;
    for (i = 0; i < arg0[2]; i++) {
        if (group != (u32)*(u16 *)element >> 4) {
            if (group != 0) {
                func_800E084C(arg3, transform[0], group);
            }
            group = (u32)*(u16 *)element >> 4;
            transform[0][0] = transform[0][1] = transform[0][2] = 0.0f;
            transform[1][0] = transform[1][1] = transform[1][2] = 1.0f;
            transform[2][0] = transform[2][1] = transform[2][2] = 0.0f;
        }
        channel = *(u16 *)element & 0xF;
        if (channel >= 9) {
            channel -= 9;
        }
#ifdef BT_NATIVE
        transform[channel / 3][channel % 3] = func_800E04C0(element, progress, duration);
#else
        transform[0][channel] = func_800E04C0(element, progress, duration);
#endif
        element += *(s16 *)(element + 2) * 4 + 4;
    }
    func_800E084C(arg3, transform[0], group);
}

void func_800E02F8(s16 *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5) {
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
    f32 temp_f20;
    u8 *var_s1;
    s32 var_fp;
    s32 var_s2;
    s32 var_s3;
    u16 temp_v0;
    u32 temp_v1;

    temp_f20 = func_800E0414(arg0, arg1);
    var_s3 = 0;
    if (arg2 != 0) {
        var_fp = arg0[1] - arg0[0];
    } else {
        var_fp = 0;
    }
    var_s1 = (u8 *)(arg0 + 4);
    var_s2 = 0;
    if (arg0[2] > 0) {
        do {
            temp_v0 = *(u16 *)var_s1;
            temp_v1 = (u32)temp_v0 >> 4;
            if (((s32)temp_v1 >= arg3) && (arg4 >= (s32)temp_v1) && ((temp_v0 & 0xF) == 7)) {
                arg5[var_s3] = func_800E04C0((u8 *)var_s1, temp_f20, var_fp);
                var_s3 += 1;
            }
            var_s2 += 1;
            var_s1 += *(s16 *)(var_s1 + 2) * 4 + 4;
        } while (var_s2 < arg0[2]);
    }
}

f32 func_800E0414(s16 *arg0, f32 arg1) {
    return (arg1 * (arg0[1] - arg0[0])) + arg0[0];
}

s32 func_800E0440(s16 *arg0) {
    return arg0[1];
}

s32 func_800E0448(s16 *arg0) {
    return arg0[0];
}

s32 func_800E0450(void *arg0) {
    return ((((Obj1EB9940_arg0 *)arg0)->unk2) - (((Obj1EB9940_arg0 *)arg0)->unk0)) + 1;
}

s32 func_800E0464(s16 *arg0) {
    return arg0[2];
}

f32 func_800E046C(void *arg0, s32 arg1) {

    s32 temp_v0;
    s16 temp_v1;

    temp_v0 = (((Obj1EB9940_arg0 *)arg0)->unk2);
    if (!(arg1 != temp_v0)) {
        return 0.999999f;
    }
    temp_v1 = (((Obj1EB9940_arg0 *)arg0)->unk0);
    return (f32) (arg1 - temp_v1) / (f32) (temp_v0 - temp_v1);
}

void func_800E04AC(void *arg0)
{
}

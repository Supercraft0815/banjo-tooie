#include "core2/1EC8070.h"
#ifdef BT_NATIVE
#include <math.h>
#include <limits.h>
#endif

// TODO rename operations based on whether they output to a new vector or output to an input vector.
// add vs sum/subtract vs difference? What to do for scalar multiplication? apply_scale vs scale?

// ml_vec3f_sum
void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// ml_vec3f_scaled_sum
void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale) {
    dst[0] = a[0] + b[0] * scale;
    dst[1] = a[1] + b[1] * scale;
    dst[2] = a[2] + b[2] * scale;
}

// ml_vec3f_copy
void func_800EE7F8(f32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_copy
void func_800EE814(s16 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_copy
void func_800EE830(s32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_to_vec3f
void func_800EE84C(f32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3f
void func_800EE88C(f32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3i
void func_800EE8CC(s32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec2f_to_vec3f
void func_800EE8E8(f32 dst[3], f32 src[2]) {
    dst[0] = src[0];
    dst[1] = 0;
    dst[2] = src[1];
}

// ml_vec3f_to_vec3i
void func_800EE904(s32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_to_vec3s
void func_800EE940(s16 dst[3], f32 src[3]) {
#ifdef BT_NATIVE
    /* MIPS truncates to a word, then stores its low halfword. */
    for(int i=0;i<3;++i) {
        f32 value=src[i];s32 word=isfinite(value) && value>=-2147483648.0f && value<2147483648.0f ? (s32)value : INT_MIN;
        dst[i]=(s16)(u16)word;
    }
#else
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
#endif
}

// ml_vec3f_cross_product
void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3i_cross_product
void func_800EE9EC(f32 dst[3], s32 a[3], s32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3f_dot_product
f32 func_800EEAA4(f32 a[3], f32 b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ml_vec3f_distance
f32 func_800EEAD4(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return sqrtf(SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]));
}

// ml_vec3f_distance_sq
f32 func_800EEB40(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]);
}

void func_800EEB9C(f32 dst[3], f32 angle, f32 distance) {
    f32 func_800137F4(f32);
    f32 func_80013788(void);
    dst[0] = func_800137F4(angle) * distance;
    dst[1] = 0.0f;
    dst[2] = func_80013788() * distance;
}    typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1EC8070_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_800EEBF0(f32 *arg0, f32 *arg1, f32 arg2) {
    func_800EFD24(arg0);
    func_800EF214(arg0, (((Obj1EC8070_arg1 *)arg1)->unk0), (((Obj1EC8070_arg1 *)arg1)->unk4), arg2);
}

void func_800EEC30(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_800EFD24(arg0);
    func_800EF214(arg0, arg1, arg2, arg3);
}

/* extern */

void func_800EEC70(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_80013788();
    f32 func_800137F4(f32);
    f32 func_800138D0(f32);
    f32 sp1C;

    sp1C = func_800138D0(arg1) * arg3;
    (((Vec3f *)arg0)->pos.y) = 0.0f;
    (((Vec3f *)arg0)->pos.x) = (f32) (func_800137F4(arg2) * sp1C);
    (((Vec3f *)arg0)->pos.z) = (f32) (func_80013788() * sp1C);
}

int func_800EECE0(f32 a[3], f32 b[3]) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

int func_800EED58(s32 *arg0, s32 *arg1) {
    return (arg0[0] == arg1[0]) && (arg0[1] == arg1[1]) && (arg0[2] == arg1[2]);
}

int func_800EEDA0(s16 *arg0, s16 *arg1) { return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2]; }

/* extern */

int func_800EEDE8(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 mlAbsF(f32);
    return mlAbsF(arg0[0] - arg1[0]) < arg2 &&
           mlAbsF(arg0[1] - arg1[1]) < arg2 &&
           mlAbsF(arg0[2] - arg1[2]) < arg2;
}

int func_800EEEA8(f32 vec[3])
{
    return !(vec[0] != 0 || vec[1] != 0 || vec[2] != 0);
}

int func_800EEF24(f32 vec[3]) {
    return vec[0] != 0 || vec[1] != 0 || vec[2] != 0;
}

f32 func_800EEF94(f32 *arg0) {
    f32 z = arg0[2];
    f32 x = arg0[0];
    f32 y = arg0[1];
    return sqrtf((z * z) + ((x * x) + (y * y)));
}

f32 func_800EEFD4(f32 *arg0) {
    f32 z = arg0[2];
    f32 x = arg0[0];
    f32 y = arg0[1];
    return (z * z) + ((x * x) + (y * y));
}    typedef struct { f32 unk0; s32 unk4; f32 unk8; } Obj1EC8070_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

f32 func_800EEFFC(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (((Obj1EC8070_arg0 *)arg0)->unk8);
    temp_f2 = (((Obj1EC8070_arg0 *)arg0)->unk0);
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

f32 func_800EF030(void *arg0) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = (((Obj1EC8070_arg0 *)arg0)->unk8);
    temp_f12 = (((Obj1EC8070_arg0 *)arg0)->unk0);
    return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
}

void func_800EF04C(f32 *arg0, f32 *arg1) {
    (((Obj1EC8070_arg0 *)arg0)->unk0) += (((Obj1EC8070_arg1 *)arg1)->unk0);
    arg0[1] += arg1[1];
    arg0[2] += arg1[2];
}

void func_800EF080(s16 *arg0, s16 *arg1) {
    arg0[0] += arg1[0];
    arg0[1] += arg1[1];
    arg0[2] += arg1[2];
}

void func_800EF0B4(s16 *arg0, f32 *arg1) {
    arg0[0] += arg1[0];
    arg0[1] += arg1[1];
    arg0[2] += arg1[2];
}

void func_800EF11C(f32 *arg0, s16 *arg1) {
    arg0[0] += arg1[0];
    arg0[1] += arg1[1];
    arg0[2] += arg1[2];
}

void func_800EF174(f32 dst[3], f32 src[3], f32 scale) {
    dst[0] += src[0] * scale;
    dst[1] += src[1] * scale;
    dst[2] += src[2] * scale;
}

/* extern */

void func_800EF1B8(f32 *arg0, f32 arg1, f32 arg2) {
    f32 func_80013788();
    f32 func_800137F4(f32);
    arg0[0] += arg2 * func_800137F4(arg1);
    arg0[2] += arg2 * func_80013788();
}

/* extern */

void func_800EF214(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_80013788();
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 func_800137F4(f32);
    f32 sp24;
    sp24 = func_800137AC(arg1) * arg3;
    arg0[1] += arg3 * func_800137C4();
    arg0[0] += sp24 * func_800137F4(arg2);
    arg0[2] += sp24 * func_80013788();
}

void func_800EF2A0(f32 vec[3])
{
    f32 length_squared = (vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);

    if (length_squared != 0)
    {
        f32 inverse = 1.0f / sqrtf(length_squared);
        vec[0] *= inverse;
        vec[1] *= inverse;
        vec[2] *= inverse;
    }
}

// ml_vec3f_apply_scale
void func_800EF334(f32 vec[3], f32 scale) {
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

// ml_vec3f_set_length
void func_800EF368(f32 vec[3], f32 target_length) {
    f32 length_sq;

    length_sq = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (length_sq != 0.0f) {
        func_800EF334(vec, target_length / sqrtf(length_sq));
    }
}

// ml_vec3f_subtract
void func_800EF3DC(f32 dst[3], f32 src[3]) {
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

void func_800EF410(f32 arg0[3], f32 arg1[3])
{
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_800EFA20(void *, void *, f32);

    f32 length_squared = (arg1[0]*arg1[0] + arg1[1]*arg1[1] + arg1[2]*arg1[2]);
    f32 inverse;

    if (length_squared != 0)
    {
        inverse = 1.0f / sqrtf(length_squared);
        func_800EFA20(arg0, arg1, inverse);
    }
    else
    {
        func_800EE7F8(arg0, arg1);
    }
}

/* extern */

void func_800EF49C(void *arg0) {
    f32 func_800136E4(f32);
    (((Vec3f *)arg0)->pos.x) = func_800136E4((((Vec3f *)arg0)->pos.x));
    (((Vec3f *)arg0)->pos.y) = func_800136E4((((Vec3f *)arg0)->pos.y));
    (((Vec3f *)arg0)->pos.z) = func_800136E4((((Vec3f *)arg0)->pos.z));
}

void func_800EF4E4(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800137F4(f32);
    f32 func_80013788(void);
    f32 value[3];
    f32 sine, cosine;
    f32 rotated;

    sine = func_800137F4(arg1);
    cosine = func_80013788();
    value[0] = arg4 * sine + arg5 * cosine;
    arg0[1] = arg4 * cosine - arg5 * sine;
    sine = func_800137F4(arg2);
    cosine = func_80013788();
    rotated = value[0];
    arg0[0] = rotated * sine + arg3 * cosine;
    arg0[2] = rotated * cosine - arg3 * sine;
}

void func_800EF5A0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800137F4(f32);
    f32 func_80013788(void);
    f32 sine, cosine;
    f32 rotated, y;

    sine = func_800137F4(arg1[0]);
    cosine = func_80013788();
    rotated = arg3 * sine + arg4 * cosine;
    arg0[1] = arg3 * cosine - arg4 * sine;
    sine = func_800137F4(arg1[1]);
    cosine = func_80013788();
    arg0[0] = rotated * sine + arg2 * cosine;
    arg0[2] = rotated * cosine - arg2 * sine;
    sine = func_800137F4(arg1[2]);
    cosine = func_80013788();
    y = arg0[0];
    rotated = y * cosine - arg0[1] * sine;
    arg0[0] = rotated;
    arg0[1] = arg0[1] * cosine + y * sine;
}

void func_800EF6A8(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800137F4(f32);
    f32 func_80013788(void);
    f32 sine, cosine;
    f32 rotated, y;

    sine = func_800137F4(arg1[2]);
    cosine = func_80013788();
    arg0[1] = arg2 * sine + arg3 * cosine;
    arg0[0] = arg2 * cosine - arg3 * sine;
    sine = func_800137F4(arg1[0]);
    cosine = func_80013788();
    y = arg0[1];
    rotated = y * sine + arg4 * cosine;
    arg0[1] = y * cosine - arg4 * sine;
    sine = func_800137F4(arg1[1]);
    cosine = func_80013788();
    y = arg0[0];
    arg0[2] = rotated * cosine - y * sine;
    arg0[0] = y * cosine + rotated * sine;
}

void func_800EF7B0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 cosine, sine;
    f32 y, z, x;

    cosine = func_800137AC(arg1[1]);
    sine = func_800137C4();
    arg0[1] = arg3;
    arg0[2] = arg4 * cosine - arg2 * sine;
    arg0[0] = arg4 * sine + arg2 * cosine;
    cosine = func_800137AC(arg1[0]);
    sine = func_800137C4();
    z = arg0[1] * cosine - arg0[2] * sine;
    arg0[2] = arg0[1] * sine + arg0[2] * cosine;
    arg0[1] = z;
    cosine = func_800137AC(arg1[2]);
    sine = func_800137C4();
    z = arg0[0] * cosine - arg0[1] * sine;
    arg0[1] = arg0[0] * sine + arg0[1] * cosine;
    arg0[0] = z;
}

void func_800EF8BC(f32 dst[3], f32 src[3], f32 pitch) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 cosine, sine, value;
    cosine = func_800137AC(pitch);
    sine = func_800137C4();
    dst[0] = src[0];
    value = src[1] * cosine - src[2] * sine;
    dst[2] = src[1] * sine + src[2] * cosine;
    dst[1] = value;
}

void func_800EF934(f32 dst[3], f32 src[3], f32 yaw) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 cosine, sine, value;
    cosine = func_800137AC(yaw);
    sine = func_800137C4();
    value = src[2] * sine + src[0] * cosine;
    dst[1] = src[1];
    dst[2] = src[2] * cosine - src[0] * sine;
    dst[0] = value;
}

void func_800EF9A8(f32 dst[3], f32 src[3], f32 roll) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 cosine, sine, value;
    cosine = func_800137AC(roll);
    sine = func_800137C4();
    value = src[0] * cosine - src[1] * sine;
    dst[1] = src[0] * sine + src[1] * cosine;
    dst[2] = src[2];
    dst[0] = value;
}

void func_800EFA20(void *arg0, void *arg1, f32 arg2) {
    (((Vec3f *)arg0)->pos.x) = (f32) ((((Vec3f *)arg1)->pos.x) * arg2);
    (((Vec3f *)arg0)->pos.y) = (f32) ((((Vec3f *)arg1)->pos.y) * arg2);
    (((Vec3f *)arg0)->pos.z) = (f32) ((((Vec3f *)arg1)->pos.z) * arg2);
}

void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    (((Obj1EC8070_arg0 *)arg0)->unk0) = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}

void func_800EFA6C(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    (((Prop *)arg0)->position[0]) = arg1;
    (((Prop *)arg0)->position[1]) = arg2;
    (((Prop *)arg0)->position[2]) = arg3;
}

void func_800EFA88(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (((Obj1EC8070_arg0 *)arg0)->unk4) = arg2;
    (*(s32 *)((s8 *)(arg0) + (8))) = arg3;
}

void func_800EFA98(f32 dst[3], f32 src[3], f32 length) {
    f32 squared;
    squared = src[0] * src[0] + src[1] * src[1] + src[2] * src[2];
    if (squared != 0.0f) {
        func_800EFA20(dst, src, length / sqrtf(squared));
    } else {
        func_800EE7F8(dst, src);
    }
}

void func_800EFB24(void *arg0, void *arg1, void *arg2) {
    (((Vec3f *)arg0)->pos.x) = (f32) ((*(f32 *)((s8 *)(arg1) + (0))) - (((Vec3f *)arg2)->pos.x));
    (((Vec3f *)arg0)->pos.y) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) - (((Vec3f *)arg2)->pos.y));
    (((Vec3f *)arg0)->pos.z) = (f32) ((*(f32 *)((s8 *)(arg1) + (8))) - (((Vec3f *)arg2)->pos.z));
}                   typedef struct { s32 unk0; s32 unk4; s32 unk8; } Obj1EC8070_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

void func_800EFB58(void *arg0, void *arg1, void *arg2) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg1) + (0))) - (((Obj1EC8070_arg2 *)arg2)->unk0));
    (((Obj1EC8070_arg0 *)arg0)->unk4) = (s32) ((*(s32 *)((s8 *)(arg1) + (4))) - (((Obj1EC8070_arg2 *)arg2)->unk4));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) ((*(s32 *)((s8 *)(arg1) + (8))) - (((Obj1EC8070_arg2 *)arg2)->unk8));
}

f32 func_800EFB8C(f32 *arg0, f32 *arg1) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (((Obj1EC8070_arg0 *)arg0)->unk0) - (((Obj1EC8070_arg1 *)arg1)->unk0);
    temp_f2 = (((Obj1EC8070_arg0 *)arg0)->unk8) - (((Obj1EC8070_arg1 *)arg1)->unk8);
    if ((temp_f0 != 0.0f) || (temp_f2 != 0.0f)) {
        return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    }
    return 0.0f;
}

f32 func_800EFBFC(void *arg0, void *arg1) {
    f32 mlAbsF(f32);

    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = mlAbsF((((Obj1EC8070_arg1 *)arg1)->unk0) - (((Obj1EC8070_arg0 *)arg0)->unk0));
    temp_f0 = mlAbsF((((Obj1EC8070_arg1 *)arg1)->unk8) - (((Obj1EC8070_arg0 *)arg0)->unk8));
    if (sp1C < temp_f0) {
        var_f12 = sp1C;
    } else {
        var_f12 = temp_f0;
    }
    return (sp1C + temp_f0) - (var_f12 * 0.41421357f);
}

f32 func_800EFC7C(void *arg0, void *arg1) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = (*(f32 *)((s8 *)(arg0) + (0))) - (((Obj1EC8070_arg1 *)arg1)->unk0);
    temp_f12 = (*(f32 *)((s8 *)(arg0) + (8))) - (((Obj1EC8070_arg1 *)arg1)->unk8);
    if ((temp_f2 != 0.0f) || (temp_f12 != 0.0f)) {
        return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
    }
    return 0;
}

/* extern */

void func_800EFCD8(f32 *arg0, f32 arg1, f32 arg2) {
    f32 func_80013788();
    f32 func_800137F4(f32);
    (*(f32 *)((s8 *)(arg0) + (0))) = func_800137F4(arg1) * arg2;
    arg0[2] = func_80013788() * arg2;
}

// ml_vec3f_clear
void func_800EFD24(f32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3i_clear
void func_800EFD3C(s32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3s_clear
void func_800EFD4C(s16 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

/* extern */

void func_800EFD60(f32 arg0[3], f32 arg1[3], f32 arg2) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 mlAbsF(f32);
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;

    sp1C = mlAbsF(func_800137AC(arg2));
    temp_f0 = mlAbsF(func_800137C4());
    temp_f2 = (((Obj1EC8070_arg1 *)arg1)->unk0);
    temp_f12 = (((Obj1EC8070_arg1 *)arg1)->unk8);
    (((Obj1EC8070_arg0 *)arg0)->unk0) = (f32) ((temp_f2 * sp1C) + (temp_f12 * temp_f0));
    arg0[1] = arg1[1];
    (((Obj1EC8070_arg0 *)arg0)->unk8) = (f32) ((temp_f12 * sp1C) + (temp_f2 * temp_f0));
}

void func_800EFDE8(f32 *arg0, u8 *arg1, f32 *arg2) {
    f32 sp1C[3];

    func_800EFA20(sp1C, arg1, -1.0f);
    func_800EFA20(arg0, arg2, 2.0f * func_800EEAA4(sp1C, arg2));
    func_800EF3DC(arg0, sp1C);
}

#include "common.h"

void func_80102780(void *arg0, void *arg1) {
    (((Vec3f *)arg1)->pos.x) = (f32) (((Actor *)arg0)->rotation[0]);
    (((Vec3f *)arg1)->pos.y) = (f32) (((Actor *)arg0)->rotation[1]);
    (((Vec3f *)arg1)->pos.z) = (f32) (((Actor *)arg0)->rotation[2]);
}

/* extern */

void func_8010279C(void *arg0, void *arg1) {
    f32 func_800136E4(f32);
    (((Actor *)arg0)->rotation[0]) = func_800136E4((((Vec3f *)arg1)->pos.x));
    (((Actor *)arg0)->rotation[1]) = func_800136E4((((Vec3f *)arg1)->pos.y));
    (((Actor *)arg0)->rotation[2]) = func_800136E4((((Vec3f *)arg1)->pos.z));
}

f32 *func_801027F4(u8 *arg0) {
    extern f32 D_80135AA0;
    if (((u32) (((Actor *)arg0)->pad94) >> 0x1F) != 0) {
        func_80102780(arg0, &D_80135AA0);
        D_80135AA0 = -D_80135AA0;
        return &D_80135AA0;
    }
    return arg0 + 0x44;
}

s32 func_80102844(Actor *arg0, f32 arg1, s32 arg2, f32 *arg3) {
    void func_80102424(Actor *, s32);
    void func_80102924(void *, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78(Actor *, f32 *);

    func_80102924(arg0, func_80102D78(arg0, arg3));
    func_80102B2C(arg0, arg1);
    if (func_80102CF4(arg0, 0x41200000) != 0) {
        if (arg2 != -1) {
            func_80102424(arg0, arg2);
        }
        return 1;
    }
    return 0;
}

f32 func_801028C4(Actor *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_80102D78(Actor *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    f32 func_800F2094(f32, f32);

    arg0->unk54 = func_80102D78(arg0, arg1);
    arg0->rotation[1] = func_800F1FF0(arg0->rotation[1], arg0->unk54, arg2, arg3, arg4);
    return func_800F2094(arg0->rotation[1], arg0->unk54);
}

void func_80102924(void *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (((Actor *)arg0)->unk54) = func_800136E4(arg1);
}

void func_80102950(void *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (((Actor *)arg0)->unk50) = func_800136E4(arg1);
}

/* extern */

void func_8010297C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800DC0C0(void);
    f32 temp_f16;
    f32 var_f0;
    f32 sum;

    temp_f16 = 2.0f * ((func_800DC0C0() - 0.5f) * (arg3 - arg2));
    if (temp_f16 >= 0.0f) {
        var_f0 = arg2;
    } else {
        var_f0 = -arg2;
    }
    sum = arg1 + temp_f16;
    func_80102924(arg0, var_f0 + sum);
}

/* extern */

f32 func_80102A04(void *arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    struct Flags {
        u8 pad[0x74];
        u32 unused : 27;
        u32 snap : 1;
        u32 rest : 4;
    };
    f32 delta;
    f32 temp_f0;
    f32 limit;

    if (arg2 == arg1) {
        return arg1;
    }
    temp_f0 = func_80013728(arg2 - arg1);
    if (((struct Flags *)arg0)->snap && ((temp_f0 >= 50.0f) || (temp_f0 < -50.0f))) {
        return arg2;
    }
    delta = temp_f0 > 0.0f
        ? (temp_f0 < (limit = (f32)arg3) ? temp_f0 : limit)
        : ((limit = (f32)-arg3) < temp_f0 ? temp_f0 : limit);
    delta += arg1;
    return func_800136E4(delta);
}

void func_80102B2C(Actor *arg0, f32 arg1) {
    arg0->rotation[1] = func_80102A04(arg0, arg0->rotation[1], arg0->unk54, (s32) arg1);
}

void func_80102B6C(u8 *arg0, f32 arg1) {
    (((Actor *)arg0)->rotation[0]) = func_80102A04(arg0, (((Actor *)arg0)->rotation[0]), (((Actor *)arg0)->unk50), (s32) arg1);
}

void func_80102BAC(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) { f32 func_800F1FF0(f32, f32, f32, f32, f32); arg0->rotation[1] = func_800F1FF0(arg0->rotation[1], arg0->unk54, arg1, arg2, arg3); }

/* extern */

void func_80102BF8(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800D8FF8();
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    f32 temp_f0;

    temp_f0 = func_800D8FF8();
    (((Actor *)arg0)->rotation[1]) = func_800F1FF0((((Actor *)arg0)->rotation[1]), (((Actor *)arg0)->unk54), arg1, temp_f0 * arg2, temp_f0 * arg3);
}

void func_80102C58(Actor *arg0, volatile s32 arg1, f32 arg2, f32 arg3) {
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    arg0->rotation[0] = func_800F1FF0(arg0->rotation[0], arg0->unk50, (*(f32 *)&arg1), arg2, arg3);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80102CA4(void *arg0) {
    s32 func_800F20BC(f32, f32, s32);
    BT_IDO_ONLY(func_800F20BC((((Actor *)arg0)->rotation[0]), (((Actor *)arg0)->unk50), 0x40400000);) BT_NATIVE_ONLY(return func_800F20BC((((Actor *)arg0)->rotation[0]), (((Actor *)arg0)->unk50), 0x40400000);)
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80102CCC(void *arg0) {
    s32 func_800F20BC(f32, f32, s32);
    BT_IDO_ONLY(func_800F20BC((((Actor *)arg0)->rotation[1]), (((Actor *)arg0)->unk54), 0x40400000);) BT_NATIVE_ONLY(return func_800F20BC((((Actor *)arg0)->rotation[1]), (((Actor *)arg0)->unk54), 0x40400000);)
}

s32 func_80102CF4(Actor *arg0, s32 arg1) {
    s32 *p = &arg1;
    s32 func_800F20BC(f32, f32, s32);
    (void)p;
    return func_800F20BC(arg0->rotation[1], arg0->unk54, arg1);
}    typedef struct { u8 pad0[0x48]; f32 unk48; } Obj1EDC070_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80102D20(u8 *arg0, s32 arg1, f32 arg2) {
    s32 *p = &arg1;
    s32 func_800F20BC(f32, f32, s32);
    (void)p;
    func_800F20BC((((Obj1EDC070_arg0 *)arg0)->unk48), arg2, arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80102D4C(u8 *arg0, s32 arg1) { s32 *p = &arg1;
    s32 func_800F20BC(f32, f32, s32);
    (void)p;
    BT_IDO_ONLY(func_800F20BC((((Actor *)arg0)->rotation[0]), (((Actor *)arg0)->unk50), arg1);) BT_NATIVE_ONLY(return func_800F20BC((((Actor *)arg0)->rotation[0]), (((Actor *)arg0)->unk50), arg1);)
}

/* extern */

f32 func_80102D78(Actor *arg0, f32 *arg1) {
    f32 func_800F1DF4(f32 *, f32 *);
    return func_800F1DF4(arg0->position, arg1);
}

/* extern */

s32 func_80102D98(Actor *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 func_8001210C(s32);
    int func_800DC298(f32);
    if ((func_8001210C(((u32)(u16)arg0->unk0->unk10 >> 1) & arg1) == arg2) && (func_800DC298(arg3) != 0)) {
        func_8010297C(arg0, arg0->rotation[1], arg4, arg5);
        return 1;
    }
    return 0;
}

s32 func_80102E08(Actor *arg0) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30 = 0;
    f32 sp24[3];

    func_800EE7F8(sp4C, arg0->position);
    func_800EE7F8(sp40, arg0->position);
    sp4C[1] += 50.0f;
    sp40[1] -= 50.0f;
    if (func_800BEF00(sp4C, sp40, sp34, arg0->unk14)) {
        arg0->position[1] = sp40[1];
        if (func_800F1B78(sp24, sp34, arg0->rotation[1], 1.0f)) {
            arg0->rotation[0] = sp24[0];
            arg0->rotation[2] = sp24[2];
            sp30 = 1;
        }
    }
    return sp30;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 D_80135AA0 BT_DATA(4, bss_core2bss2_2_music_tail, 0x80);
#endif

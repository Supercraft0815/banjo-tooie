#include "common.h"

void idflasha_entrypoint_0(s16 arg0, u32 arg1, u8 *arg2, s32 arg3, s16 *arg4) {
    s32 value = *arg4;
    u32 end = (arg3 << 4) + arg1;

    if (arg1 < end) {
        do {
            arg1 += 0x10;
            arg2 += 0x10;
            arg2[-1] = value;
        } while (arg1 < end);
    }
}               typedef struct { s16 unk0; s16 unk2; s32 unk4; s32 unk8; s32 unkC; f32 unk10; f32 unk14; } Objflasha_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_80800038_idflasha(BtIntPtr arg0, s32 arg1) {
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
    f32 temp_f0;
    f32 var_f0;
    s32 temp_v0;

    if (arg1 == 1) {
        (((Objflasha_arg0 *)arg0)->unk0) = 0;
        (((Objflasha_arg0 *)arg0)->unk2) = func_800DC214(200, 255);
        (((Objflasha_arg0 *)arg0)->unk4) += 1;
        temp_f0 = func_800DC264(0.08f, 0.12f);
        (((Objflasha_arg0 *)arg0)->unk10) = temp_f0;
        (((Objflasha_arg0 *)arg0)->unk14) = temp_f0;
    }
    if (arg1 == 0) {
        temp_v0 = (((Objflasha_arg0 *)arg0)->unk4);
        (((Objflasha_arg0 *)arg0)->unk0) = 0;
        if (temp_v0 > 0 && temp_v0 < (((Objflasha_arg0 *)arg0)->unk8)) {
            var_f0 = func_800DC264(0.1f, 0.2f);
        } else {
            (((Objflasha_arg0 *)arg0)->unk4) = 0;
            (((Objflasha_arg0 *)arg0)->unk8) = func_800DC214(1, 4);
            var_f0 = func_800DC264(4.0f, 6.0f);
        }
        (((Objflasha_arg0 *)arg0)->unk10) = var_f0;
    }
    (((Objflasha_arg0 *)arg0)->unkC) = arg1; BT_NATIVE_ONLY(return 0;)
}

s32 idflasha_entrypoint_1(s16 *arg0) {
    return arg0[0];
}

void idflasha_entrypoint_2(s32 arg0) 
{
}
/* extern */

void idflasha_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800038_idflasha(BtIntPtr, s32);
    (((Objflasha_arg0 *)arg0)->unk0) = 0;
    (((Objflasha_arg0 *)arg0)->unk4) = 0;
    (((Objflasha_arg0 *)arg0)->unk8) = 2;
    (((Objflasha_arg0 *)arg0)->unkC) = 0;
    func_80800038_idflasha((BtIntPtr)arg0, 0);
}

void idflasha_entrypoint_4(void *arg0, BtIntPtr arg1, s32 arg2) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
#ifndef BT_NATIVE
    extern s32 _idflasha_entrypoint_0;
#endif
    struct Flash {
        s16 value;
        s16 peak;
        s32 unk4;
        s32 unk8;
        s32 state;
        f32 timer;
        f32 duration;
    };
    f32 delta;
    f32 timer;
    f32 duration;
    struct Flash *flash = arg0;

    delta = func_800D8FF8();
    if ((flash->state == 0) &&
        func_800F1574(&flash->timer, delta)) {
        func_80800038_idflasha((BtIntPtr)arg0, 1);
    }
    if (flash->state == 1) {
        timer = *&flash->timer;
        if (timer <= 0.04f) {
            flash->value = (timer / 0.04f) * flash->peak;
        } else {
            duration = flash->duration;
            if (timer < duration - 0.04f) {
                flash->value = flash->peak;
            } else {
                flash->value = ((duration - timer) / 0.04f) * flash->peak;
            }
        }
        if (func_800F1574(&flash->timer, delta)) {
            func_80800038_idflasha((BtIntPtr)arg0, 0);
        }
    }
    _glid_entrypoint_0(arg1, arg2, &_idflasha_entrypoint_0, (BtIntPtr)arg0);
}

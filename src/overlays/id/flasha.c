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
}

s32 func_80800038_idflasha(s32 arg0, s32 arg1) {
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
    f32 temp_f0;
    f32 var_f0;
    s32 temp_v0;

    if (arg1 == 1) {
        (*(s16 *)((s8 *)arg0 + 0)) = 0;
        (*(s16 *)((s8 *)arg0 + 2)) = func_800DC214(200, 255);
        (*(s32 *)((s8 *)arg0 + 4)) += 1;
        temp_f0 = func_800DC264(0.08f, 0.12f);
        (*(f32 *)((s8 *)arg0 + 0x10)) = temp_f0;
        (*(f32 *)((s8 *)arg0 + 0x14)) = temp_f0;
    }
    if (arg1 == 0) {
        temp_v0 = (*(s32 *)((s8 *)arg0 + 4));
        (*(s16 *)((s8 *)arg0 + 0)) = 0;
        if (temp_v0 > 0 && temp_v0 < (*(s32 *)((s8 *)arg0 + 8))) {
            var_f0 = func_800DC264(0.1f, 0.2f);
        } else {
            (*(s32 *)((s8 *)arg0 + 4)) = 0;
            (*(s32 *)((s8 *)arg0 + 8)) = func_800DC214(1, 4);
            var_f0 = func_800DC264(4.0f, 6.0f);
        }
        (*(f32 *)((s8 *)arg0 + 0x10)) = var_f0;
    }
    (*(s32 *)((s8 *)arg0 + 0xC)) = arg1;
}

s32 idflasha_entrypoint_1(s16 *arg0) {
    return arg0[0];
}

void idflasha_entrypoint_2(s32 arg0) 
{
}
/* extern */

void idflasha_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800038_idflasha(s32, s32);
    (*(s16 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (8))) = 2;
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0;
    func_80800038_idflasha((s32)arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flasha/idflasha_entrypoint_4.s")

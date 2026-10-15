#include "common.h"

s32 func_80800000_idflame(u8 *arg0, s16 arg1) {
    s32 var_v1;
    int temp_v0;
    temp_v0 = arg0[0xA];
    var_v1 = 0;
    if (temp_v0 <= 0) {
        goto end;
    }
loop:
    if (arg1 < ((s16 *)arg0)[var_v1 + 6]) {
        goto end;
    }
    var_v1++;
    if (var_v1 < temp_v0) {
        goto loop;
    }
end:
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_1.s")

void idflame_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_3.s")

void idflame_entrypoint_4(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    f32 func_800D8FF8(void);
    extern s32 _idflame_entrypoint_0;
    f32 dt;
    s32 i;
    union {
        u8 *ptr;
        s32 value;
    } cursor;

    dt = func_800D8FF8();
    ((f32 *)arg0)[0] += ((f32 *)arg0)[1] * 64.0f * dt;
    cursor.value = (s32)((f32 *)arg0)[0];
    if (cursor.value >= 0x2001) {
        ((f32 *)arg0)[0] -= 8192.0f;
        cursor.value = (s32)((f32 *)arg0)[0];
    }
    *(s16 *)(arg0 + 8) = cursor.value;
    cursor.ptr = arg0;
    i = 0;
    if ((s32)arg0[0xA] >= 0) {
        do {
            ((f32 *)cursor.ptr)[7] += ((f32 *)cursor.ptr)[23] * dt;
            i++;
            cursor.ptr += 4;
        } while ((s32)arg0[0xA] >= i);
    }
    _glid_entrypoint_0(arg1, arg2, &_idflame_entrypoint_0, (s32)arg0);
}

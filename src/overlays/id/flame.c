#include "common.h"

extern struct {
    s16 *start;
    s16 *end;
    s16 *limit;
} B_80800560_idflame;

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

/* extern */

void idflame_entrypoint_0(s32 arg0, u32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    f32 func_8001395C(f32);
    s32 func_80800000_idflame(u8 *, s16);
    s16 temp_s4;
    s32 temp_v0;
    u32 temp_s5;
    u32 var_s0;
    u8 *temp_v1;
    u8 *var_s1;

    temp_s4 = (*(s16 *)((s8 *)(arg4) + (8)));
    temp_s5 = (arg3 * 0x10) + arg1;
    var_s0 = arg1;
    var_s1 = arg2;
    if (arg1 < temp_s5) {
        do {
            (*(s16 *)((s8 *)(var_s1) + (0xA))) = (s16) ((*(s16 *)((s8 *)(var_s0) + (0xA))) + temp_s4);
            temp_v0 = func_80800000_idflame(arg4, (*(s16 *)((s8 *)(var_s0) + (0))));
            temp_v1 = (u8 *)((f32 *)arg4 + temp_v0);
            *(s16 *)var_s1 = (s16)(s32)((f32)*(s16 *)var_s0 + ((f32 *)arg4)[temp_v0 + 0x1F] * func_8001395C((*(f32 *)(temp_v1 + 0x1C) - (f32)*(s16 *)(var_s0 + 2)) * *(f32 *)(temp_v1 + 0x3C)));
            var_s0 += 0x10;
            var_s1 += 0x10;
        } while (var_s0 < temp_s5);
    }
}

void idflame_entrypoint_1(s32 arg0, s16 *arg1, s32 arg2, s32 arg3) {
    s16 value;
    s16 *pos;
    s16 *end;
    s16 *dst;

    value = *arg1; pos = B_80800560_idflame.start; end = B_80800560_idflame.end; arg1 = end - 1;
    while (pos < end) {
        if (value < *pos) {
            break;
        }
        pos++;
    }
    if (pos == end) {
        *pos = value;
        B_80800560_idflame.end++;
        return;
    }
    dst = end;
    while (pos < dst) {
        *dst = *arg1;
        dst--;
        arg1--;
    }
    *pos = value;
    B_80800560_idflame.end++;
}

void idflame_entrypoint_2(s32 arg0) 
{
}
void idflame_entrypoint_3(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _glid_entrypoint_2(u8 *, s32, void (*)(s32, s16 *, s32, s32), void *);
    void _glidmake_entrypoint_2(void *arg0, s32 arg1, s16 *arg2, s16 *arg3);
    s16 _glidmake_entrypoint_3(s32 *arg0, s32 arg1);
    f32 func_800DC264(f32 arg0, f32 arg1);
    void *heap_alloc(s32 size);
    void heap_free(void *mem);
    void _idflame_entrypoint_1(s32 arg0, s16 *arg1, s32 arg2, s32 arg3);
    s32 value;
    s32 count;
    f32 height;
    f32 difference;
    f32 threshold;
    s16 min[3];
    s16 max[3];
    f32 speed;
    register s16 *pos;
    s32 i;
    u8 *cursor;

    count = _glidmake_entrypoint_3((s32 *)arg2, arg3);
    ((f32 *)arg0)[0] = 0.0;
    ((f32 *)arg0)[1] = (f32)arg1;
    _glidmake_entrypoint_2((void *)arg2, arg3, min, max);
    B_80800560_idflame.start = heap_alloc(count * 2);
    B_80800560_idflame.end = B_80800560_idflame.start;
    B_80800560_idflame.limit = B_80800560_idflame.start + count;
    _glid_entrypoint_2((u8 *)arg2, arg3, _idflame_entrypoint_1, arg0);
    threshold = (f32)(max[0] - min[0]) * 0.11f;
    arg0[0xA] = 0;
    pos = B_80800560_idflame.start + 1;
    while (pos < B_80800560_idflame.end) {
        value = *pos++;
        difference = (f32)(value - pos[-2]);
        if (difference <= threshold) {
            continue;
        }
        if (arg0[0xA] >= 8) {
            continue;
        }
        ((s16 *)(arg0 + 0xC))[arg0[0xA]] = value;
        arg0[0xA]++;
    }
    heap_free(B_80800560_idflame.start);
    B_80800560_idflame.start = B_80800560_idflame.end = B_80800560_idflame.limit = NULL;
    height = (f32)(max[1] - min[1]);
    difference = (f32)(max[0] - min[0]) * 0.0125f;
    i = 0;
    if ((s32)arg0[0xA] >= 0) {
        speed = (f32)arg1 * height;
        speed *= 0.03125f;
        cursor = arg0;
        do {
            *(f32 *)(cursor + 0x1C) = 0.0f;
            *(f32 *)(cursor + 0x3C) = 6.2831855f / func_800DC264(height * 0.5f, height);
            *(f32 *)(cursor + 0x5C) = func_800DC264(speed * 0.5f, speed);
            *(f32 *)(cursor + 0x7C) = func_800DC264(2.0f * difference, difference * 5.0f);
            i++;
            cursor += 4;
        } while ((s32)arg0[0xA] >= i);
    }
}

void idflame_entrypoint_4(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    f32 func_800D8FF8(void);
#ifndef BT_NATIVE
    extern s32 _idflame_entrypoint_0;
#endif
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

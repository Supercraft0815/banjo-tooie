#include <ultra64.h>
s32 func_800CAA24(f32 *arg0, f32 *arg1, f32 *arg2) {
    struct Data { f32 pad[9]; f32 planes[4][4]; };
    s32 i;
    f32 x, y, z, v;
    f32 *plane;

    for (i = 0; i < 4; i++) {
        plane = ((struct Data *)arg0)->planes[i];
        x = plane[0];
        y = plane[1];
        z = plane[2];
        v = x >= 0.0f ? arg1[0] : arg2[0];
        x *= v;
        v = y >= 0.0f ? arg1[1] : arg2[1];
        y *= v;
        v = z >= 0.0f ? arg1[2] : arg2[2];
        z *= v;
        if (plane[3] + (x + y + z) >= 0.0f) {
            return 0;
        }
    }
    return 1;
}

s32 func_800CAB70(f32 *arg0, s16 *arg1, s16 *arg2) {
    struct Data { f32 pad[9]; f32 planes[4][4]; };
    s32 i;
    f32 x, y, z;
    s16 v;
    f32 *plane;
    for (i = 0; i < 4; i++) {
        plane = ((struct Data *)arg0)->planes[i];
        x = plane[0];
        y = plane[1];
        z = plane[2];
        v = x >= 0.0f ? arg1[0] : arg2[0];
        x *= v;
        v = y >= 0.0f ? arg1[1] : arg2[1];
        y *= v;
        v = z >= 0.0f ? arg1[2] : arg2[2];
        z *= v;
        if (plane[3] + (x + y + z) >= 0.0f) {
            return 0;
        }
    }
    return 1;
}

s32 func_800CACEC(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 func_800EEAA4(f32 *, f32 *);
    f32 delta[3];
    s32 var_s0;
    f32 *var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 9;
    delta[0] = arg1[0] - arg0[0];
    delta[1] = arg1[1] - arg0[1];
    delta[2] = arg1[2] - arg0[2];
loop_1:
    if (arg2 <= func_800EEAA4(delta, var_s1)) {
        return 0;
    }
    var_s0 += 0x10;
    var_s1 += 4;
    if (var_s0 == 0x40) {
        return 1;
    }
    goto loop_1;
}


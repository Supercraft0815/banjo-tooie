#include "common.h"

u8 *func_800B26F0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x28)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

s32 func_800B270C(s16 *arg0) {
    return arg0[5];
}

s32 func_800B2714(s32 *arg0) {
    u8 *result = (u8 *) arg0;
    result += arg0[3];
    return (s32) result;
}

u8 *func_800B2720(u8 *arg0) {
    s32 temp_v1;

    if (arg0 == NULL) {
        return NULL;
    }
    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x1C)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B274C(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2768(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x40)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2784(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x3C)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B27A0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x38)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B27BC(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x30)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

f32 func_800B27D8(f32 *arg0) {
    return arg0[18];
}

u8 *func_800B27E0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

s32 func_800B27FC(s32 arg0) {
    arg0 += ((s16 *)arg0)[4];
    return arg0;
}

u8 *func_800B2808(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x2C)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2824(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x14)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

s32 func_800B2840(s32 arg0) {
    arg0 += ((s32 *)arg0)[4];
    return arg0;
}

u8 *func_800B284C(u8 *arg0) {
    s32 offset;
    u8 *result;
    u8 *ret;

    offset = *(s32 *)(arg0 + 0x20);
    result = arg0 + offset;
    if (offset == 0) {
        ret = NULL;
    } else {
        ret = result;
    }
    return ret;
}

u8 *func_800B2868(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x34)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

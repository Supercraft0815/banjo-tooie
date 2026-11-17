#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_model.h"
#endif

typedef struct { u8 pad0[0x14]; s32 unk14; s32 unk18; s32 unk1C; u8 pad20[0x4]; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; } Obj1E8BFE0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ u8 *func_800B26F0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk28);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

s32 func_800B270C(s16 *arg0) {
    return arg0[5];
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800B2714(void *arg0) {
    return (u8 *)arg0 + ((u32 *)arg0)[3];
}
#else
s32 func_800B2714(s32 *arg0) {
    u8 *result = (u8 *) arg0;
    result += arg0[3];
    return (s32) result;
}
#endif

u8 *func_800B2720(u8 *arg0) {
    s32 temp_v1;

    if (arg0 == NULL) {
        return NULL;
    }
    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk1C);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B274C(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk24);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2768(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk40);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2784(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk3C);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B27A0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk38);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B27BC(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk30);
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

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk18);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800B27FC(void *arg0) {
    return (u8 *)arg0 + ((s16 *)arg0)[4];
}
#else
s32 func_800B27FC(s32 arg0) {
    arg0 += ((s16 *)arg0)[4];
    return arg0;
}
#endif

u8 *func_800B2808(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk2C);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

u8 *func_800B2824(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk14);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800B2840(void *arg0) {
    return (u8 *)arg0 + ((u32 *)arg0)[4];
}
#else
s32 func_800B2840(s32 arg0) {
    arg0 += ((s32 *)arg0)[4];
    return arg0;
}
#endif

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

    temp_v1 = (((Obj1E8BFE0_arg0 *)arg0)->unk34);
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

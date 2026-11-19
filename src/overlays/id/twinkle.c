#include "common.h"
#include "core2/world_effect.h"

 void idtwinkle_entrypoint_0(s32 arg0, s16 *arg1, u8 *arg2, void *arg3) {
    s32 i;
    s32 distance;
    s32 delta[3];

    for (i = 0; &delta[i] < &delta[3]; i++) {
        delta[i] = arg1[i] - ((s16 *)arg3)[i + 7];
    }
    distance = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (((TwinkleEffect *)arg3)->unk14 >= distance) {
        arg0 = 0;
        if (((TwinkleEffect *)arg3)->count > 0) {
            arg2 = ((TwinkleEffect *)arg3)->particles;
            do {
                if (*(s16 *)(arg2 + 8) == arg1[0] &&
                    *(s16 *)(arg2 + 0xA) == arg1[1] &&
                    *(s16 *)(arg2 + 0xC) == arg1[2]) {
                    break;
                }
                arg0++;
                arg2 += 0x10;
            } while (arg0 < ((TwinkleEffect *)arg3)->count);
        }
        if (arg0 == ((TwinkleEffect *)arg3)->count && ((TwinkleEffect *)arg3)->count < 10) {
            *(s16 *)(((TwinkleEffect *)arg3)->particles + ((TwinkleEffect *)arg3)->count * 0x10 + 8) = arg1[0];
            *(s16 *)(((TwinkleEffect *)arg3)->particles + ((TwinkleEffect *)arg3)->count * 0x10 + 0xA) = arg1[1];
            *(s16 *)(((TwinkleEffect *)arg3)->particles + ((TwinkleEffect *)arg3)->count * 0x10 + 0xC) = arg1[2];
            (((TwinkleEffect *)arg3)->count)++;
        }
    }
}

void idtwinkle_entrypoint_1(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    if ((*(s16 *)((s8 *)(arg3) + (0x26))) == (*(s16 *)((s8 *)(arg3) + (0x24)))) {
        (*(s16 *)((s8 *)(arg3) + (0xE))) = (s16) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s16 *)((s8 *)(arg3) + (0x10))) = (s16) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s16 *)((s8 *)(arg3) + (0x12))) = (s16) (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s16 *)((s8 *)(arg3) + (0x24))) = (s16) ((*(s16 *)((s8 *)(arg3) + (0x24))) + 1);
}

void idtwinkle_entrypoint_2(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 *end = arg1 + arg3 * 0x10;
    s32 i;
    u8 *entry;
    f32 scale;
    s16 x;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        i = 0;
        if (*(s16 *)(arg4 + 0x28) > 0) {
            x = *(s16 *)arg1;
            entry = ((TwinkleEffect *)arg4)->particles;
            do {
                if (x == *(s16 *)(entry + 8) &&
                    *(s16 *)(arg1 + 2) == *(s16 *)(entry + 0xA) &&
                    *(s16 *)(arg1 + 4) == *(s16 *)(entry + 0xC)) {
                    break;
                }
                i++;
                entry += 0x10;
            } while (i < *(s16 *)(arg4 + 0x28));
        }
        if (i != *(s16 *)(arg4 + 0x28)) {
            scale = *(f32 *)(((TwinkleEffect *)arg4)->particles + i * 0x10);
            arg2[12] = (u32)((f32)arg1[12] + (f32)(255 - arg1[12]) * scale);
            arg2[13] = (u32)((f32)arg1[13] + (f32)(255 - arg1[13]) * scale);
            arg2[14] = (u32)((f32)arg1[14] + (f32)(255 - arg1[14]) * scale);
        }
    }
}

void func_80800478_idtwinkle(void *arg0, BtIntPtr arg1, s32 arg2) {
    void _glid_entrypoint_2(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s32), BtIntPtr arg3);
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
#ifndef BT_NATIVE
    extern s32 _idtwinkle_entrypoint_0;
#endif
#ifndef BT_NATIVE
    extern s32 _idtwinkle_entrypoint_1;
#endif
    s32 temp;
    s32 offset;
    s32 i;

    ((TwinkleEffect *)arg0)->unk26 = func_800DC214(0, ((TwinkleEffect *)arg0)->unkC);
    ((TwinkleEffect *)arg0)->unk24 = 0;
    _glid_entrypoint_2(arg1, arg2, &_idtwinkle_entrypoint_1, arg0);
    temp = func_800DC214(((TwinkleEffect *)arg0)->unk18, ((TwinkleEffect *)arg0)->unk1A);
    ((TwinkleEffect *)arg0)->unk14 = temp * temp;
    ((TwinkleEffect *)arg0)->count = 0;
    _glid_entrypoint_2(arg1, arg2, &_idtwinkle_entrypoint_0, arg0);
    i = 0;
    offset = 0;
    while (i < ((TwinkleEffect *)arg0)->count) {
        *(f32 *)(((TwinkleEffect *)arg0)->particles + offset) = 0.0f;
        *(((TwinkleEffect *)arg0)->particles + offset + 0xF) = 0xA;
        *(((TwinkleEffect *)arg0)->particles + offset + 0xE) = 0;
        *(f32 *)(((TwinkleEffect *)arg0)->particles + offset + 4) = func_800DC264(0.0f, 1.0f);
        i++;
        offset += 0x10;
    }
}

/* extern */

void idtwinkle_entrypoint_3(void *arg0) {
    void heap_free(void *memory);
    heap_free(((TwinkleEffect *)arg0)->particles);
}

#ifdef BT_NATIVE
void idtwinkle_entrypoint_4(void *data, s32 variant, void *model, s32 mesh, s32 flags) {
    u8 *arg0 = (u8 *)data;
    BtIntPtr arg2 = (BtIntPtr)model;
#else
void idtwinkle_entrypoint_4(u8 *arg0, s32 variant, BtIntPtr arg2, s32 mesh) {
#endif
    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
    s16 _glidmake_entrypoint_3(s32 *arg0, s32 variant);
    f32 func_800DC264(f32, f32);
    void *heap_alloc(s32);
    f32 sqrtf(f32);
    s16 start[3];
    s16 end[3];
    s16 delta[3];
    s32 i;
    s32 sum = 0;
    f32 scale;

    _glidmake_entrypoint_2(arg2, mesh, (u8 *)start, (u8 *)end);
    *(s16 *)(arg0 + 0xC) = _glidmake_entrypoint_3(arg2, mesh);
    for (i = 0; i != 3; i++) {
        delta[i] = end[i] - start[i];
        sum += delta[i] * delta[i];
    }
    *(s16 *)(arg0 + 0x1A) = (s32)((f32)(s32)sqrtf((f32)sum) * 0.25f);
    *(s16 *)(arg0 + 0x18) = (s32)((f32)*(s16 *)(arg0 + 0x1A) * 0.5f);
    scale = (f32)variant * 0.1f + 1.0f;
    *(f32 *)(arg0 + 0x20) = scale;
    *(f32 *)(arg0 + 0x1C) = func_800DC264(0.0f, scale);
    ((TwinkleEffect *)arg0)->particles = heap_alloc(0xA0);
    *(s16 *)(arg0 + 0x28) = 0;
}

#ifdef BT_NATIVE
void idtwinkle_entrypoint_5(void *data, void *model, s32 mesh) {
    u8 *arg0 = (u8 *)data;
    BtIntPtr arg1 = (BtIntPtr)model;
#else
void idtwinkle_entrypoint_5(u8 *arg0, BtIntPtr arg1, s32 mesh) {
#endif
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*mesh)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    f32 func_800D8FF8(void);
    f32 func_800DC264(f32, f32);
#ifndef BT_NATIVE
    extern s32 _idtwinkle_entrypoint_2;
#endif
    s32 pad[2];
    s32 done;
    f32 dt;
    s32 offset;
    u8 *item;

    dt = func_800D8FF8();
    done = 0;
    if (*(f32 *)(arg0 + 0x1C) > 0.0f) {
        *(f32 *)(arg0 + 0x1C) -= dt;
        if (*(f32 *)(arg0 + 0x1C) <= 0.0f) {
            func_80800478_idtwinkle(arg0, arg1, mesh);
        }
    } else {
        offset = 0;
        if (*(s16 *)(arg0 + 0x28) > 0) {
        do {
            item = ((TwinkleEffect *)arg0)->particles + offset;
            if (*(f32 *)(item + 4) > 0.0f) {
                *(f32 *)(item + 4) -= dt;
            } else if (item[0xE] == 0) {
                *(f32 *)item += (f32)*(s8 *)(item + 0xF) * dt;
                item = ((TwinkleEffect *)arg0)->particles + offset;
                if (*(f32 *)item >= 1.0f) {
                    *(f32 *)item = 1.0f;
                    item = ((TwinkleEffect *)arg0)->particles + offset;
                    *(s8 *)(item + 0xF) = -*(s8 *)(item + 0xF);
                } else if (*(f32 *)item < 0.0f) {
                    *(f32 *)item = 0.0f;
                    (((TwinkleEffect *)arg0)->particles + offset)[0xE] = 1;
                }
            } else {
                done++;
            }
            offset += 0x10;
        } while (offset < *(s16 *)(arg0 + 0x28) * 0x10);
        }
        _glid_entrypoint_0(arg1, mesh, &_idtwinkle_entrypoint_2, (BtIntPtr)arg0);
        if (done == *(s16 *)(arg0 + 0x28)) {
            *(f32 *)(arg0 + 0x1C) = func_800DC264(0.0f, *(f32 *)(arg0 + 0x20));
        }
    }
}

#ifdef BT_NATIVE
void idtwinkle_entrypoint_6(void *data, u8 **begin, u8 **end) {
    TwinkleEffect *effect = data;
    *begin = effect->particles;
    *end = effect->particles + effect->count * 0x10;
}
#else
void idtwinkle_entrypoint_6(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = *(s32 *)(arg0 + 0x2C);
    *arg2 = (*(s16 *)(arg0 + 0x28) << 4) + *(s32 *)(arg0 + 0x2C);
}
#endif

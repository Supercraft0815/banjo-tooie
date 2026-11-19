#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EE8B70_native.inc"
#else
#include "common.h"

typedef struct {
    s32 *model;
    s32 count;
    s32 *current;
    s32 *limit;
} LightBuffer;

void *func_8010F280(s32 arg0) {
    struct entry { s32 data[9]; s32 value; };
    extern LightBuffer D_80137240;
    extern s32 D_80137250;
    s32 *dst;
    s32 *src;
    u32 cursor;
    s32 count;

    for (cursor = (u32)&D_80137250; (s32 *)cursor < D_80137240.current; cursor += sizeof(struct entry)) {
        if (((struct entry *)cursor)->value < arg0) {
            break;
        }
    }
    if ((s32 *)cursor == D_80137240.current) {
        if (D_80137240.current < D_80137240.limit) {
            D_80137240.current += 10;
            return (void *)cursor;
        }
        return NULL;
    }
    if (D_80137240.current == D_80137240.limit) {
        D_80137240.current -= 10;
    }
    dst = D_80137240.current + 10;
    count = ((struct entry *)D_80137240.current - (struct entry *)cursor) * sizeof(struct entry);
    dst--;
    src = D_80137240.current - 1;
    while (count > 0) {
        *dst-- = *src--;
        count -= 4;
    }
    D_80137240.current += 10;
    return (void *)cursor;
}

void func_8010F384(s32 *arg0, s32 arg1, s32 arg2) {
    void func_80019224(f32 *, f32 *);
    void func_800193C4(f32 *, f32 *);
    void func_800B237C(void *, f32 *, f32 *);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800(s32, f32 *);
    void func_800C883C(s32, void *);
    void func_800C8900(s32, s32 *);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    void func_800DF900(u8 *);
    void func_800EE830(s32 *, s32 *);
    void mlMtxPop(void);
    f32 sqrtf(f32);
    extern LightBuffer D_80137240;
    int count;
    f32 center[3];
    f32 norm;
    f32 scale, distance;
    int light;
    int *entry;
    f32 delta[3];
    f32 pos[3];
    f32 radii[2];
    int value;
    int colors[3];
    count = arg1 < 0 ? -arg1 : arg1;
    count *= 40;
    D_80137240.limit = (s32 *)(count + (s32)D_80137240.current);
    func_800B237C((void *)func_800DF8B4(arg0), center, &norm);
    scale = func_800DF8C4((void *)arg0);
    func_80019224(center, center);
    norm *= scale;
    func_800DF900((void *)arg0);
    light = func_800C8760(0, 2);
    if (light != 0) {
        do {
            func_800C8800(light, pos);
            func_800C883C(light, radii);
            delta[0] = pos[0] - center[0];
            delta[1] = pos[1] - center[1];
            delta[2] = pos[2] - center[2];
            distance = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            if (!(radii[1] + norm <= distance)) {
                func_800C8900(light, colors);
                value = (s32)((f32)(colors[0] + colors[1] + colors[2]) * (1.0f - distance / (radii[1] + norm)));
                entry = func_8010F280(value);
                if (entry != NULL) {
                    entry[9] = value;
                    func_800193C4(delta, pos);
                    entry[0] = delta[0];
                    entry[1] = delta[1];
                    entry[2] = delta[2];
                    radii[0] /= scale;
                    radii[1] /= scale;
                    entry[3] = radii[0] * 256.0f;
                    entry[4] = radii[1] * radii[1];
                    entry[5] = 16384.0f / (radii[1] - radii[0]);
                    func_800EE830(entry + 6, colors);
                }
            }
            light = func_800C878C(light, 0, 2);
        }
        while (light != 0);
    }
    D_80137240.count = (s32)(((s32)D_80137240.current - (s32)&D_80137240 - 16) / 40);
    mlMtxPop();
}

void func_8010F68C(s32 arg0, s32 arg1) {
    u32 func_800B2344(void *);
    f32 sqrtf(f32);
    extern s32 D_80137244;
    extern u32 D_80137248;
    extern s32 D_80137250;
    struct header { u8 pad[22]; BT_BITFIELD_ORDER(u16 other : 15, u16 active : 1); BT_BITFIELD_ORDER(u16 active : 1, u16 other : 15); };
    struct header *model;
    u32 end[1];
    s32 *light;
    s32 x, y, z, squared, distance, inner, scale, attenuation;
    u32 limit;
    s32 red;
    s32 vertex;
    s32 green, blue;
    s32 enabled;

    limit = func_800B2344((void *)arg0) * 10 + (u32)arg1;
    end[0] = limit;
    model = (struct header *)arg0;
    vertex = arg0 + 24;
    if (D_80137244 != 0) {
        if ((u32)arg1 < limit) {
            do {
                light = &D_80137250;
                if (!(*(u16 *)(vertex + 6) & 0x1000)) {
                    red = ((u8 *)arg1)[6];
                    green = ((u8 *)arg1)[7];
                    blue = ((u8 *)arg1)[8];
                    if ((u32)light < D_80137248) {
                        do {
                            x = light[0] - ((s16 *)vertex)[0];
                            y = light[1] - ((s16 *)vertex)[1];
                            z = light[2] - ((s16 *)vertex)[2];
                            squared = x*x + y*y + z*z;
                            distance = squared;
                            if (squared < light[4]) {
                                if (squared != 0) {
                                    distance = (s32)(sqrtf((f32)squared) * 256.0f);
                                }
                                inner = light[3];
                                if (inner < distance) {
                                    attenuation = 0x4000 - ((light[5] * (distance - inner)) >> 8);
                                    scale = attenuation * 4;
                                } else {
                                    scale = 0x10000;
                                }
                                red += (light[6] * scale) >> 16;
                                green += (light[7] * scale) >> 16;
                                blue += (light[8] * scale) >> 16;
                            }
                            light += 10;
                        } while ((u32)light < D_80137248);
                    }
                    if (red >= 256) red = 255;
                    ((u8 *)vertex)[12] = red;
                    green = green < 256 ? green : 255;
                    ((u8 *)vertex)[13] = green;
                    if (blue >= 256) blue = 255;
                    ((u8 *)vertex)[14] = blue;
                }
                arg1 += 10;
                vertex += 16;
            } while ((u32)arg1 < end[0]);
        }
        enabled = 1;
        model->active = enabled;
    } else if (model->active) {
        if ((u32)arg1 < limit) {
            do {
                if (!(*(u16 *)(vertex + 6) & 0x1000)) {
                    ((u8 *)vertex)[12] = ((u8 *)arg1)[6];
                    ((u8 *)vertex)[13] = ((u8 *)arg1)[7];
                    ((u8 *)vertex)[14] = ((u8 *)arg1)[8];
                }
                arg1 += 10;
                vertex += 16;
            } while ((u32)arg1 < end[0]);
        }
        model->active = 0;
    }
}

void func_8010F950(s32 *arg0, s32 arg1, volatile s32 arg2, s32 arg3) {
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8BC(s32 *);
    void func_8010F384(s32 *, s32, s32);
    void func_8010F68C(s32, s32);
    extern LightBuffer D_80137240;
    extern s32 D_80137250;
    s32 temp;
    s32 sp18;

    D_80137240.model = arg0;
    D_80137240.current = &D_80137250;
    func_8010F384(arg0, arg1, arg3);
    sp18 = func_800DF8B4(D_80137240.model); temp = func_800DF8BC(D_80137240.model);
    func_8010F68C(sp18, temp);
}

#endif

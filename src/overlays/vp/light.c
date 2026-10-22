#include "common.h"

/* extern */

u8 *vplight_entrypoint_0(u8 *arg0, u8 *arg1) {
    void *heap_alloc(s32);
    void rare_memset(void *, u8, int);
    struct {
        s32 size;
        s32 unused[8];
        u8 *allocation;
    } work;
    s32 temp_t4;
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *var_v1;
    u8 *temp_a0_2;
    u8 *temp_t2;
    u8 *var_a0;
    u8 *var_v0;
    u8 *base;

    work.size = ((*(s32 *)(arg0 + 0x14)) * 0x10) + ((*(u16 *)(arg0 + 0x10)) * 2);
    work.allocation = heap_alloc(work.size);
    rare_memset(work.allocation, 0, work.size);
    temp_t2 = work.allocation;
    temp_t2 += *(s32 *)(arg0 + 0x14) * 0x10;
    temp_a0_2 = ((*(u16 *)((s8 *)(arg0) + (0x10))) * 2) + temp_t2;
    var_v0 = temp_t2;
    if ((u32) temp_t2 < (u32) temp_a0_2) {
        do {
            var_v0 += 2;
            (*(s16 *)((s8 *)(var_v0) + (-2))) = -1;
        } while ((u32) var_v0 < (u32) temp_a0_2);
    }
    temp_a2 = ((*(s32 *)((s8 *)(arg0) + (0x14))) * 4) + arg1 + 0x14;
    temp_a1 = arg1 + 0x14;
    var_a0 = work.allocation;
    var_v1 = temp_a1;
    base = arg0;
    base += *(s32 *)(arg0 + 0x1C);
    if (temp_a1 < temp_a2) {
        do {
            temp_t4 = (var_v1 - temp_a1) >> 2;
            if ((*(u16 *)((s8 *)(var_v1) + (2))) != 0) {
                (*(s8 *)((s8 *)(var_a0) + (0))) = 1;
                (*(s8 *)((s8 *)(var_a0) + (1))) = 0;
                *(s16 *)(temp_t2 + *(s32 *)(temp_t4 * 0x14 + base + 0x10) * 2) = temp_t4;
            }
            var_v1 += 4;
            var_a0 += 0x10;
        } while (var_v1 < temp_a2);
    }
    return work.allocation;
}

void vplight_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void func_80800134_vplight(s16 *arg0, f32 *arg1, f32 arg2, s32 *arg3, s32 *arg4) {
    s32 lo;
    s32 hi;
    s32 i;
    f32 low;
    f32 high;
    s16 min;
    s16 max;

    for (i = 0; i < 3; i++) {
        low = arg1[i] - arg2;
        high = arg1[i] + arg2;
        lo = (s32)(*(f32 *)((u8 *)arg0 + 0x18) * low);
        hi = (s32)(*(f32 *)((u8 *)arg0 + 0x18) * high);
        if (low < 0.0f) {
            lo--;
        }
        if (high < 0.0f) {
            hi--;
        }
        min = arg0[i];
        max = arg0[i + 3];
        if (lo < min) {
            lo = min;
        }
        if (max < lo) {
            lo = max;
        }
        if (hi < min) {
            hi = min;
        }
        if (max < hi) {
            hi = max;
        }
        arg3[i] = lo - min;
        arg4[i] = hi - min;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_2.s")

void func_808004B0_vplight(void *arg0, s32 position[3]) {
    void func_800C8800(void *, f32 *);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

void func_80800518_vplight(s32 arg0, s32 *range) {
    void func_800C8898(s32, f32 *);
    f32 values[3];

    func_800C8898(arg0, values);
    range[0] = (s32)(values[0] * 256.0f);
    range[1] = (s32)(values[1] * values[1]);
    range[2] = (s32)(values[2] * 16384.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_3.s")

void vplight_entrypoint_4(Vtx *vertices, s32 count) {
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8900(s32, s32 *);
    f32 sqrtf(f32);
    Vtx *end;
    s32 x, y, z;
    s32 squared, distance, strength;
    s32 r, g, b;
    s32 position[3];
    s32 range[3];
    s32 color[3];
    s32 light;
    s32 attenuation;

    end = vertices + count;
    if (vertices < end) {
      do {
        r = vertices->v.cn[0];
        g = vertices->v.cn[1];
        b = vertices->v.cn[2];
        light = func_800C8760(0, 4);
        if (light != 0) {
          do {
            func_808004B0_vplight((void *)light, position);
            func_80800518_vplight(light, range);
            func_800C8900(light, color);
            x = position[0] - vertices->v.ob[0];
            y = position[1] - vertices->v.ob[1];
            z = position[2] - vertices->v.ob[2];
            squared = x * x + y * y + z * z;
            distance = squared;
            if (squared < range[1]) {
                if (squared != 0) {
                    distance = (s32)(sqrtf((f32)squared) * 256.0f);
                }
                if (range[0] < distance) {
                    attenuation = 0x4000 - (((distance - range[0]) * range[2]) >> 8);
                    strength = attenuation * 4;
                } else {
                    strength = 0x10000;
                }
                r += (color[0] * strength) >> 16;
                g += (color[1] * strength) >> 16;
                b += (color[2] * strength) >> 16;
            }
            light = func_800C878C(light, 0, 4);
          } while (light != 0);
        }
        if (r >= 256) r = 255;
        if (g >= 256) g = 255;
        if (b >= 256) b = 255;
        vertices->v.cn[0] = r;
        vertices->v.cn[1] = g;
        vertices->v.cn[2] = b;
        vertices++;
      } while (vertices < end);
    }
}

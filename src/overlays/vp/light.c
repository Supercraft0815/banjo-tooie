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

void vplight_entrypoint_2(u8 *arg0, s16 *arg1) {
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800();
    void func_800C883C(s32, void *);
    u8 func_800C89D8(s32);
    struct LightEntry { u8 active, count, lights[14]; };
    struct LightEntry *base = (struct LightEntry *)arg0;
    s16 *indices;
    struct LightEntry *end;
    s32 changed;
    s32 cell;
    f32 position[4];
    f32 radius[2];
    s32 low[3];
    s32 high[3];
    s32 light;
    struct LightEntry *entry;
    u8 *slot;
    u8 *flags;
    s32 i;
    s32 x, y, z;
    s16 index;
    s32 scan;

    end = base + *(s32 *)((u8 *)arg1 + 0x14);
    indices = (s16 *)(arg0 + (*(s32 *)((u8 *)arg1 + 0x14) << 4));
    flags = (u8 *)arg1;
    flags += *(s32 *)((u8 *)arg1 + 0x1C);
    light = func_800C8760(2, 2);
    while (light != 0) {
        changed = func_800C89D8(light);
        entry = base;
        for (; entry < end; entry++) {
            if (entry->active) {
                if (entry->count) {
                    for (scan = 0, slot = (u8 *)entry; scan < 14; scan++, slot++) {
                        if (light == slot[2]) {
                            if (changed) {
                                slot[2] = 0;
                                entry->count--;
                            }
                            flags[(entry - base) * 20 + 3] = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (changed) {
            func_800C8800(light, position);
            func_800C883C(light, radius);
            func_80800134_vplight(arg1, position, radius[1], low, high);
            for (z = low[2]; z <= high[2]; z++) {
                for (y = low[1]; y <= high[1]; y++) {
                    for (x = low[0]; x <= high[0]; x++) {
                        cell = y * ((u16 *)arg1)[6] + (u32)(((u16 *)arg1)[7] * z + x);
                        index = indices[cell];
                        if (index >= 0) {
                            entry = base + index;
                            i = 0;
                            if (entry->active) {
                                do {
                                    slot = (u8 *)entry + i;
                                    i++;
                                    if (slot[2] == 0) {
                                        slot[2] = light;
                                        entry->count++;
                                        (index * 20 + flags)[3] = 1;
                                        break;
                                    }
                                } while (i != 14);
                            }
                        }
                    }
                }
            }
        }
        light = func_800C878C(light, 2, 2);
    }
}

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

void vplight_entrypoint_3(u32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    void func_800C8900(s32, s32 *);
    f32 sqrtf(f32);
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_a0;
    s32 sp98[3];
    s32 sp8C[3];
    s32 sp80[3];
    s32 temp_a1;
    s32 var_a2;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1;
    u32 temp_fp;
    u32 loop_end;
    u32 var_s0;
    u8 temp_v0;
    u8 *temp_s1;
    u8 *temp_s6;

    temp_s6 = (u8 *)arg0;
    temp_s6 += arg1 * 16;
    temp_fp = (arg3 * 0x10) + arg2;
    if (temp_s6[1] != 0) {
        loop_end = temp_fp;
        var_s5 = 0;
loop_2:
        if ((temp_s6 + var_s5)[2] == 0) {
            var_s5 += 1;
            if (var_s5 != 0xE) {
                goto loop_2;
            }
        }
        if (var_s5 < 0xE) {
            do {
                temp_s1 = temp_s6 + var_s5;
                temp_v0 = temp_s1[2];
                if (temp_v0 != 0) {
                    func_808004B0_vplight((void *)temp_v0, sp98);
                    var_s0 = arg2;
                    func_80800518_vplight(temp_s1[2], sp8C);
                    func_800C8900(temp_s1[2], sp80);
                    if (arg2 < temp_fp) {
                        do {
                            temp_v0_2 = sp98[0] - *(s16 *)(var_s0 + 0);
                            temp_v1 = sp98[1] - *(s16 *)(var_s0 + 2);
                            temp_a0 = sp98[2] - *(s16 *)(var_s0 + 4);
                            temp_a1 = temp_v0_2 * temp_v0_2 + temp_v1 * temp_v1 + temp_a0 * temp_a0;
                            var_a2 = temp_a1;
                            if (temp_a1 < sp8C[1]) {
                                if (temp_a1 != 0) {
                                    var_a2 = (s32)(sqrtf((f32)temp_a1) * 256.0f);
                                }
                                if (sp8C[0] < var_a2) {
                                    var_v0 = 0x4000 - (((var_a2 - sp8C[0]) * sp8C[2]) >> 8);
                                    var_v1 = var_v0 << 2;
                                } else {
                                    var_v1 = 0x10000;
                                }
                                var_v0 = *(u8 *)(var_s0 + 12) + ((sp80[0] * var_v1) >> 16);
                                if (var_v0 >= 256) var_v0 = 255;
                                *(u8 *)(var_s0 + 12) = var_v0;
                                var_v0 = *(u8 *)(var_s0 + 13) + ((sp80[1] * var_v1) >> 16);
                                if (var_v0 >= 256) var_v0 = 255;
                                *(u8 *)(var_s0 + 13) = var_v0;
                                var_v0 = *(u8 *)(var_s0 + 14) + ((sp80[2] * var_v1) >> 16);
                                if (var_v0 >= 256) var_v0 = 255;
                                *(u8 *)(var_s0 + 14) = var_v0;
                            }
                            var_s0 += 0x10;
                        } while (var_s0 < loop_end);
                    }
                }
                var_s5 += 1;
            } while (var_s5 < 0xE);
        }
    }
}

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

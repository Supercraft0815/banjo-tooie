#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EE8100_native.inc"
#else
#include "common.h"
#ifdef BT_NATIVE
#include "core2/geometry_callbacks.h"
#endif
typedef struct { s32 data[9]; f32 value; } GuestPointLight; typedef struct { s32 *render; s32 ambient[3]; u8 bones, count, pad[2]; GuestPointLight *used, *end; GuestPointLight entries[9]; } GuestPointLighting; BT_NATIVE_ONLY(_Static_assert(offsetof(GuestPointLighting, used) == 0x14, "guest point-light used offset"); _Static_assert(offsetof(GuestPointLighting, entries) == 0x1C, "guest point-light entries offset"); _Static_assert(sizeof(GuestPointLighting) == 0x184, "guest point-light state"); GuestPointLighting D_80137080 BT_DATA(4, bss_core2bss2_2_music_tail, 0x1660);)
void *func_8010E810(void)
{
    BT_IDO_ONLY(extern u8 D_80137080[];)

    return &D_80137080;
}

void *func_8010E81C(f32 arg0) {
    struct entry { s32 data[9]; f32 value; };
    struct list { s32 data[5]; struct entry *start; struct entry *end; };
    BT_IDO_ONLY(extern u8 D_80137080[];)
    BT_IDO_ONLY(extern s32 D_8013709C;)
    s32 *dst;
    s32 *src;
    u32 cursor;
    s32 bytes;

    for (cursor = (u32)BT_DATA_FIELD(D_80137080.entries, &D_8013709C); (struct entry *)cursor < (struct entry *)BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start); cursor += sizeof(struct entry)) {
        if (arg0 < ((struct entry *)cursor)->value) {
            break;
        }
    }
    if ((struct entry *)cursor == (struct entry *)BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start)) {
        if (BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) < BT_DATA_FIELD(D_80137080.end, ((struct list *)D_80137080)->end)) {
            BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start)++;
            return (void *)cursor;
        }
        return NULL;
    }
    if (BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) == BT_DATA_FIELD(D_80137080.end, ((struct list *)D_80137080)->end)) {
        BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start)--;
    }
    dst = (s32 *)(BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) + 1);
    bytes = ((struct entry *)BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) - (struct entry *)cursor) * sizeof(struct entry);
    dst--;
    src = (s32 *)BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) - 1;
    while (bytes > 0) {
        *dst-- = *src--;
        bytes -= 4;
    }
    BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start)++;
    return (void *)cursor;
}

void *func_8010E924(s32 arg0, f32 *arg1, f32 arg2, f32 arg3) {
    struct entry { s32 data[9]; f32 value; };
    void func_800193C4(f32 *, f32 *);
    void func_800C8800(s32, f32 *);
    void func_800C883C(s32, void *);
    void func_800C8900(s32, s32 *);
    f32 sqrtf(f32);
    struct entry *entry;
    f32 distance;
    f32 delta[3];
    f32 position[3];
    f32 radius[2];

    func_800C8800(arg0, position);
    func_800C883C(arg0, radius);
    delta[0] = position[0] - arg1[0];
    delta[1] = position[1] - arg1[1];
    delta[2] = position[2] - arg1[2];
    distance = sqrtf((delta[0] * delta[0] + delta[1] * delta[1]) + delta[2] * delta[2]);
    if (radius[1] + arg2 <= distance) {
        return NULL;
    }
    entry = func_8010E81C(distance);
    if (entry == NULL) {
        return NULL;
    }
    entry->value = distance;
    func_800193C4(delta, position);
    entry->data[0] = (s32)delta[0];
    entry->data[1] = (s32)delta[1];
    entry->data[2] = (s32)delta[2];
    radius[0] /= arg3;
    radius[1] /= arg3;
    entry->data[3] = (s32)(radius[0] * 256.0f);
    entry->data[4] = (s32)(radius[1] * radius[1]);
    entry->data[5] = (s32)(16384.0f / (radius[1] - radius[0]));
    func_800C8900(arg0, &entry->data[6]);
    return entry;
}

void func_8010EACC(void *arg0, s32 arg1, f32 arg2) {
    struct entry { s32 data[9]; f32 value; };
    struct list { u8 data[0x11]; s8 count; u8 pad[2]; struct entry *start; struct entry *end; };
    BT_IDO_ONLY(extern u8 D_80137080[];)
    void func_80019224(f32 *, f32 *);
    void func_800B237C(void *, f32[3], f32 *);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    void func_800DF900(u8 *);
    void *func_8010E924(s32, f32 *, f32, f32);
    void mlMtxPop(void);
    s32 current;
    f32 center[3];
    f32 norm;
    s32 amount;
    s32 list;
    s32 pad;

    if (arg1 < 0) {
        amount = -arg1;
    } else {
        amount = arg1;
    }
    BT_DATA_FIELD(D_80137080.end, ((struct list *)D_80137080)->end) = amount + BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start);
    list = func_800DF8B4(arg0);
    func_800B237C((void *)list, center, &norm);
    arg2 = func_800DF8C4(arg0);
    func_80019224(center, center);
    norm *= arg2;
    func_800DF900(arg0);
    current = func_800C8760(0, 1);
    if (current != 0) {
        do {
            func_8010E924(current, center, norm, arg2);
            current = func_800C878C(current, 0, 1);
        } while (current != 0);
    }
    BT_DATA_FIELD(D_80137080.count, ((struct list *)D_80137080)->count) = (s32)((u8 *)BT_DATA_FIELD(D_80137080.used, ((struct list *)D_80137080)->start) - BT_DATA_FIELD((u8 *)&D_80137080, D_80137080) - 0x1C) / 40;
    mlMtxPop();
}

void func_8010EBE4(s32 arg0, s32 arg1, s32 arg2) {
    u32 func_800B2344(void *);
    f32 sqrtf(f32);
    BT_IDO_ONLY(extern u8 D_80137080[];)
    BT_IDO_ONLY(extern s32 D_8013709C;)
    u32 end[2];
    s32 *light;
    s32 x, y, z, squared, distance, inner, scale, attenuation;
    u32 limit;
    s32 red;
    s32 vertex;
    s32 green, blue;
    s32 color;
    s32 baseRed, baseGreen, baseBlue;

    limit = func_800B2344((void *)arg0) * 10 + (u32)arg2;
    vertex = arg0 + 24;
    end[0] = limit;
    if (BT_DATA_FIELD(D_80137080.count, D_80137080[17]) != 0) {
        if ((u32)arg2 < limit) {
            do {
                if (!(*(u16 *)(vertex + 6) & 0x1000)) {
                    light = BT_DATA_FIELD(D_80137080.entries, &D_8013709C);
                    red = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[0], D_80137080 + 4));
                    green = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[1], D_80137080 + 8));
                    blue = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[2], D_80137080 + 12));
                    if ((u32)light < *(u32 *)(BT_DATA_FIELD(&D_80137080.used, D_80137080 + 20))) {
                        do {
                            x = light[0] - *(s16 *)(vertex + 0);
                            y = light[1] - *(s16 *)(vertex + 2);
                            z = light[2] - *(s16 *)(vertex + 4);
                            squared = x*x + y*y + z*z;
                            if (squared < light[4]) {
                                distance = (s32)(sqrtf((f32)squared) * 256.0f);
                                scale = 0x10000;
                                inner = light[3];
                                if (inner < distance) {
                                    attenuation = 0x4000 - ((light[5] * (distance - inner)) >> 8);
                                    scale = (attenuation << 16) >> 14;
                                }
                                red += (light[6] * scale) >> 16;
                                green += (light[7] * scale) >> 16;
                                blue += (light[8] * scale) >> 16;
                            }
                            light += 10;
                        } while ((u32)light < *(u32 *)(BT_DATA_FIELD(&D_80137080.used, D_80137080 + 20)));
                    }
                    color = (*(u8 *)(arg2 + 6) * red) >> 8;
                    if (color >= 256) color = 255;
                    *(u8 *)(vertex + 12) = color;
                    color = (*(u8 *)(arg2 + 7) * green) >> 8;
                    if (color >= 256) color = 255;
                    *(u8 *)(vertex + 13) = color;
                    color = (*(u8 *)(arg2 + 8) * blue) >> 8;
                    if (color >= 256) color = 255;
                    *(u8 *)(vertex + 14) = color;
                }
                arg2 += 10;
                vertex += 16;
            } while ((u32)arg2 < end[0]);
        }
    } else {
        baseRed = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[0], D_80137080 + 4));
        baseGreen = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[1], D_80137080 + 8));
        baseBlue = *(s32 *)(BT_DATA_FIELD(&D_80137080.ambient[2], D_80137080 + 12));
        if ((u32)arg2 < limit) {
        do {
            if (!(*(u16 *)(vertex + 6) & 0x1000)) {
                *(u8 *)(vertex + 12) = (*(u8 *)(arg2 + 6) * baseRed) >> 8;
                *(u8 *)(vertex + 13) = (*(u8 *)(arg2 + 7) * baseGreen) >> 8;
                *(u8 *)(vertex + 14) = (*(u8 *)(arg2 + 8) * baseBlue) >> 8;
            }
            arg2 += 10;
            vertex += 16;
        } while ((u32)arg2 < end[0]);
    }
    }
}

void func_8010EECC(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    struct state { s32 *actor; s32 data[3]; s8 value; u8 pad[3]; s32 *start; };
    BT_IDO_ONLY(extern u8 D_80137080[];)
    extern s32 D_80137084;
    BT_IDO_ONLY(extern s32 D_8013709C;)
    void func_800C87B8(s32 *);
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8BC(s32 *);
    s32 func_800DF8CC(s32 *);
    int func_800DF8D4(s32 *);
    void func_8010EBE4(s32, s32, s32);
    s32 pad;
    s32 sp28;
    s32 sp24;

    BT_DATA_FIELD(D_80137080.render, ((struct state *)D_80137080)->actor) = arg0;
    BT_DATA_FIELD(D_80137080.bones, ((struct state *)D_80137080)->value) = func_800DF8D4(arg0);
    BT_DATA_FIELD(D_80137080.used, ((struct state *)D_80137080)->start) = BT_DATA_FIELD(D_80137080.entries, &D_8013709C);
    func_8010EACC(arg0, arg1, arg3);
    func_800C87B8(BT_DATA_FIELD(D_80137080.ambient, &D_80137084));
    sp24 = func_800DF8B4(arg0);
    sp28 = func_800DF8CC(arg0);
    func_8010EBE4(sp24, sp28, func_800DF8BC(arg0));
}

#endif

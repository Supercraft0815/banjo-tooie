#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EE7960_native.inc"
#else
#include "common.h"
#ifdef BT_NATIVE
#include "core2/geometry_callbacks.h"
#endif

typedef struct { s32 *render; s32 ambient[3]; u8 bones, count, pad[2]; s32 *lights; f32 *start, *end; } GuestModelLighting; BT_NATIVE_ONLY(_Static_assert(offsetof(GuestModelLighting, lights) == 0x14, "guest model-light handle"); _Static_assert(sizeof(GuestModelLighting) == 0x20, "guest model-light state"); GuestModelLighting D_80137060 BT_DATA(4, bss_core2bss2_2_music_tail, 0x1640);) BT_IDO_ONLY(extern s32 D_80137074;) typedef struct { s32 * unk0; u8 pad4[0xC]; s8 unk10; u8 pad11[0x3]; u8 * unk14; f32 * unk18; f32 * unk1C; } Obj1EE7960_D_80137060;

s32 func_8010E070(void) {
    void func_800192FC(f32 *, f32 *);
    s32 func_800B3784(u8 *);
    void func_800B37A4(u8 *, s32 *, s32 *);
    void func_800B37B8(s32, s32 *);
    void func_800EF368(f32 *, f32);
    BT_IDO_ONLY(extern s32 D_80137060;)
    BT_IDO_ONLY(extern s32 D_80137064;)
    BT_IDO_ONLY(extern s32 D_80137078;)
    BT_IDO_ONLY(extern s32 D_8013707C;)
    BT_IDO_ONLY(f32 *p;) BT_NATIVE_ONLY(f32 sum;)
    BT_IDO_ONLY(f32 sum;) BT_NATIVE_ONLY(f32 *p;)
    f32 scale;

    BT_DATA_FIELD(D_80137060.count, *((u8 *)&D_80137060 + 0x11)) = func_800B3784(BT_DATA_FIELD(D_80137060.lights, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk14));
    func_800B37A4(BT_DATA_FIELD(D_80137060.lights, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk14), BT_DATA_FIELD((s32 *)&D_80137060.start, &D_80137078), BT_DATA_FIELD((s32 *)&D_80137060.end, &D_8013707C));
    if (BT_DATA_FIELD(D_80137060.bones, *((u8 *)&D_80137060 + 0x10)) == 0) {
        for (p = BT_DATA_FIELD(D_80137060.start, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk18);
             p < BT_DATA_FIELD(D_80137060.end, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk1C); p += 7) {
            func_800192FC(p, p);
            func_800EF368(p, 256.0f);
        }
    }
    if (BT_DATA_FIELD(D_80137060.count, *((u8 *)&D_80137060 + 0x11)) >= 2) {
        sum = 0.0f;
        for (p = BT_DATA_FIELD(D_80137060.start, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk18);
             p < BT_DATA_FIELD(D_80137060.end, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk1C); p += 7) {
            sum += p[6];
        }
        sum = 1.0f / sum;
        for (p = BT_DATA_FIELD(D_80137060.start, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk18);
             p < BT_DATA_FIELD(D_80137060.end, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk1C); p += 7) {
            scale = 1.0f - p[6] * sum;
            ((s32 *)p)[3] *= scale;
            ((s32 *)p)[4] *= scale;
            ((s32 *)p)[5] *= scale;
        }
    }
    func_800B37B8(BT_DATA_FIELD(D_80137060.lights, *(s32 *)((u8 *)&D_80137060 + 0x14)), &BT_DATA_FIELD(D_80137060.ambient, D_80137064)); BT_NATIVE_ONLY(return 0;)
}

void func_8010E204(void *arg0, s32 arg1, f32 arg2) {
    void func_80019224(f32 *, f32 *);
    void func_800B237C(void *, f32 *, f32 *);
    void func_800B3494(s32, f32 *, f32);
    void func_800B3748(s32);
    void func_800B388C(u8 *, s32);
    void func_800B38C8(s32);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    BT_IDO_ONLY(extern s32 D_80137074;)
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;
    func_800B388C(BT_DATA_FIELD(D_80137060.lights, D_80137074), arg1 < 0 ? -arg1 : arg1);
    func_800B237C(func_800DF8B4(arg0), sp24, &sp20);
    sp1C = func_800DF8C4(arg0);
    func_80019224(sp24, sp24);
    sp20 *= sp1C;
    func_800B3494(BT_DATA_FIELD(D_80137060.lights, D_80137074), sp24, sp20);
    if (arg1 < 0) {
        func_800B3748(BT_DATA_FIELD(D_80137060.lights, D_80137074));
    }
    func_800B38C8(BT_DATA_FIELD(D_80137060.lights, D_80137074));
}

void func_8010E2C4(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 func_800B37E4(s32, s32);
    int func_800DF8D4(s32 *);
    s32 func_8010E070();
    BT_IDO_ONLY(extern s32 D_80137060;)
    (BT_DATA_FIELD(D_80137060.render, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk0)) = arg0;
    (BT_DATA_FIELD(D_80137060.bones, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk10)) = func_800DF8D4(arg0);
    if (arg2 != 0) {
        func_800B37E4((BT_DATA_FIELD(D_80137060.lights, *(s32 *)((s8 *)(&D_80137060) + (0x14)))), arg2);
    } else {
        func_8010E204(arg0, arg1, arg3);
    }
    func_8010E070();
}

/* extern */

void func_8010E334(void) {
    s32 func_800B3310(s32);
    BT_DATA_FIELD(D_80137060.lights, D_80137074) = func_800B3310(0x4);
}

/* extern */

void func_8010E358(void) {
    s32 func_800B38E8(s32);
    if (BT_DATA_FIELD(D_80137060.lights, D_80137074) != 0) {
        BT_DATA_FIELD(D_80137060.lights, D_80137074) = func_800B38E8(BT_DATA_FIELD(D_80137060.lights, D_80137074));
    }
}

void func_8010E390(void) {
    s32 func_800B3370(s32);
    BT_IDO_ONLY(extern s32 D_80137074;)
    func_800B3370(BT_DATA_FIELD(D_80137060.lights, D_80137074));
    BT_DATA_FIELD(D_80137060.lights, D_80137074) = 0;
}

s32 func_8010E3B8()
{
    return BT_DATA_FIELD(D_80137060.lights, D_80137074);
}

void func_8010E3C4(f32 *arg0, s32 *arg1, f32 *arg2) {
    s32 i;
    f32 length;
    f32 vec[3];

    for (i = 0; i < 3; i++) {
        vec[i] = (arg2[0] * arg0[i * 4] + arg2[1] * arg0[i * 4 + 1]) + arg2[2] * arg0[i * 4 + 2];
    }
    length = sqrtf((vec[0] * vec[0] + vec[1] * vec[1]) + vec[2] * vec[2]);
    if (length > 0.0f) {
        length = 256.0f / length;
        arg1[0] = (s32)(vec[0] * length);
        arg1[1] = (s32)(vec[1] * length);
        arg1[2] = (s32)(vec[2] * length);
    } else {
        arg1[2] = 0;
        arg1[1] = 0;
        arg1[0] = 0;
    }
}

void func_8010E4C4(f32 *arg0, s32 *arg1, s32 arg2) {
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8BC(s32 *);
    s32 func_800DF8CC(s32 *);
    BT_IDO_ONLY(extern s32 D_80137060;)
    typedef struct { s16 light[3]; u8 color[4]; } Color;
    Color *start, *end, *p;
    u8 *vertex;
    s8 *normals, *normal;
    f32 *light;
    s32 x, y, z;
    s32 r, g, b;
    s32 dot;
    s32 value, value2;
    s32 direction[3];
    s32 value3;
    s32 base;
    s32 lr, lg, lb;

    base = func_800DF8B4(BT_DATA_FIELD(D_80137060.render, *(s32 **)&D_80137060));
    vertex = (u8 *)(*arg1 * 16 + base + 24);
    base = func_800DF8CC(BT_DATA_FIELD(D_80137060.render, *(s32 **)&D_80137060));
    normals = (s8 *)(*arg1 * 4 + base);
    start = (Color *)func_800DF8BC(BT_DATA_FIELD(D_80137060.render, *(s32 **)&D_80137060)) + *arg1;
    end = start + arg2;
    *arg1 += arg2;
    if (BT_DATA_FIELD(D_80137060.count, *((u8 *)&D_80137060 + 0x11))) {
        r = BT_DATA_FIELD(D_80137060.ambient[0], *((s32 *)&D_80137060 + 1));
        g = BT_DATA_FIELD(D_80137060.ambient[1], *((s32 *)&D_80137060 + 2));
        b = BT_DATA_FIELD(D_80137060.ambient[2], *((s32 *)&D_80137060 + 3));
        for (p = start; p < end; p++) {
            p->light[0] = r;
            p->light[1] = g;
            p->light[2] = b;
        }
        for (light = BT_DATA_FIELD(D_80137060.start, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk18);
             light < BT_DATA_FIELD(D_80137060.end, ((Obj1EE7960_D_80137060 *)&D_80137060)->unk1C); light += 7) {
            p = start;
            normal = normals;
            if (BT_DATA_FIELD(D_80137060.bones, *((u8 *)&D_80137060 + 0x10))) {
                func_8010E3C4(arg0, direction, light);
                x = direction[0];
                y = direction[1];
                z = direction[2];
            } else {
                x = light[0];
                y = light[1];
                z = light[2];
            }
            lr = ((s32 *)light)[3];
            lg = ((s32 *)light)[4];
            lb = ((s32 *)light)[5];
            for (; p < end; p++, normal += 4) {
                dot = x * normal[0] + y * normal[1] + normal[2] * z;
                if (dot > 0) {
                    p->light[0] += (dot * lr) >> 15;
                    p->light[1] += (dot * lg) >> 15;
                    p->light[2] += (dot * lb) >> 15;
                }
            }
        }
        for (; start < end; start++, vertex += 16) {
            value = (start->light[0] * start->color[0]) >> 8;
            if (value >= 256) value = 255;
            vertex[12] = value;
            value = (start->light[1] * start->color[1]) >> 8;
            if (value >= 256) value = 255;
            vertex[13] = value;
            value = (start->light[2] * start->color[2]) >> 8;
            if (value >= 256) value = 255;
            vertex[14] = value;
        }
    } else {
        r = BT_DATA_FIELD(D_80137060.ambient[0], *((s32 *)&D_80137060 + 1));
        g = BT_DATA_FIELD(D_80137060.ambient[1], *((s32 *)&D_80137060 + 2));
        b = BT_DATA_FIELD(D_80137060.ambient[2], *((s32 *)&D_80137060 + 3));
        for (; start < end; start++, vertex += 16) {
            vertex[12] = (start->color[0] * r) >> 8;
            vertex[13] = (start->color[1] * g) >> 8;
            vertex[14] = (start->color[2] * b) >> 8;
        }
    }
}

void func_8010E7F4(void) {
    BT_IDO_ONLY(extern s32 D_80137060;)
    BT_DATA_FIELD(D_80137060.render, *(s32 *)((s8 *)(&D_80137060) + (0))) = 0;
    BT_DATA_FIELD(D_80137060.start, *(s32 *)((s8 *)(&D_80137060) + (0x18))) = 0;
    BT_DATA_FIELD(D_80137060.end, *(s32 *)((s8 *)(&D_80137060) + (0x1C))) = 0;
}

#endif

#include "common.h"

void *func_80800000_dbmorph(s16 *arg0, s32 arg1) {
    u8 *entry = (u8 *)arg0 + 4;
    s32 i = 0;
    s32 count = *arg0;
    if (count <= 0) goto done;
    do {
        i++;
        if (arg1 == entry[2]) return entry;
        entry += *(s32 *)(entry + 8);
    } while (i < count);
done:
    return NULL;
}

s32 dbmorph_entrypoint_0(s16 *arg0) {
    return arg0[1];
}

s32 dbmorph_entrypoint_1(s16 *arg0) {
    return arg0[0];
}

/* extern */

u8 dbmorph_entrypoint_2(void) {
    void *func_80800000_dbmorph();
    return (*(u8 *)((s8 *)(func_80800000_dbmorph()) + (3)));
}

typedef struct {
    u8 pad[0x16];
    u16 other : 15;
    u16 dirty : 1;
} MorphTarget;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 flags;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} MorphVertex;

typedef struct {
    u8 pad[3];
    u8 count;
    s16 start;
    s16 reset;
    u8 reserved[4];
} MorphHeader;

typedef struct {
    s16 count;
    s16 pad;
    MorphVertex deltas[1];
} MorphBlock;

void dbmorph_entrypoint_3(void *arg0, MorphTarget *arg1, void *arg2, s32 arg3, f32 *weights) {
    s32 aligned4_memcpy(void *, void *, s32);
    void *func_800B2190(void *);
    void *func_80800000_dbmorph();
    f32 weight;
    MorphVertex *delta;
    MorphBlock *block;
    s16 *indices;
    s16 dx;
    s16 dy;
    s16 dz;
    s32 r;
    s32 g;
    MorphHeader *header;
    s32 b;
    s32 a;
    s16 ds;
    s16 dt;
    MorphVertex *dst;
    MorphVertex *src;
    MorphVertex *src_base;
    MorphVertex *dst_base;
    s32 dirty;
    s32 i;

    dirty = arg1->dirty;
    header = func_80800000_dbmorph(arg0, arg3);
    src_base = func_800B2190(arg2);
    dst_base = func_800B2190(arg1);
    src = src_base + header->start;
    dst = dst_base + header->start;
    if (dirty) {
        i = header->reset;
        while (i != 0) {
            if (src->flags & 0x4000) {
                aligned4_memcpy(dst, src, 16);
                i--;
            }
            dst++;
            src++;
        }
        dirty = 0;
    }
    block = (MorphBlock *) (header + 1);
    for (i = 0; i < header->count; i++, weights++) {
        weight = *weights;
        if (weight != 0.0f) {
            delta = block->deltas;
            indices = (s16 *) (delta + block->count);
            dx = delta->x * weight;
            dy = delta->y * weight;
            dz = delta->z * weight;
            r = delta->r;
            g = delta->g;
            b = delta->b;
            a = delta->a;
            ds = delta->s * weight;
            dt = delta->t * weight;
            dirty = 1;
            while (*indices >= -1) {
                if (*indices == -1) {
                    delta++;
                    dx = delta->x * weight;
                    dy = delta->y * weight;
                    dz = delta->z * weight;
                    r = delta->r;
                    g = delta->g;
                    b = delta->b;
                    a = delta->a;
                    ds = delta->s * weight;
                    dt = delta->t * weight;
                } else {
                    dst = dst_base + *indices;
                    src = src_base + *indices;
                    dst->x += dx;
                    dst->y += dy;
                    dst->z += dz;
                    dst->s += ds;
                    dst->t += dt;
                    dst->r += (r - src->r) * weight;
                    dst->g += (g - src->g) * weight;
                    dst->b += (b - src->b) * weight;
                    dst->a += (a - src->a) * weight;
                }
                indices++;
            }
            indices++;
        } else {
            indices = (s16 *) (block->deltas + block->count);
            while (*indices++ != -2) {
            }
        }
        if ((u32) indices & 3) {
            indices++;
        }
        block = (MorphBlock *) indices;
    }
    arg1->dirty = dirty;
}

void dbmorph_entrypoint_4(s16 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    s32 func_800ADE2C(s32, s32);
    void *func_800B2190(void *);
    void *func_80100480(s32, s32);
    s32 func_80116568(s32, void *, void *, s32);
    s32 remaining;
    s16 *output;
    s16 *data;
    Vtx *input;
    Vtx *vertices;
    Vtx *source;
    s16 *entry;
    s16 *cursor;
    s32 count;

    entry = func_80800000_dbmorph(arg0, arg3);
    count = entry[3];
    vertices = func_800B2190(arg1);
    if (*(u16 *)(arg1 + 0x16) & 1) {
        source = entry[2] + vertices;
    } else {
        input = func_800B2190(arg2);
        source = input;
        source += entry[2];
    }
    data = func_80100480(4, count);
    cursor = data;
    remaining = count;
    if (count != 0) {
        do {
            if (source->v.flag & 0x4000) {
                *cursor++ = source->v.ob[0];
                *cursor++ = source->v.ob[1];
                *cursor++ = source->v.ob[2];
                remaining--;
            }
            source++;
        } while (remaining != 0);
        remaining = count;
    }
    func_80116568(func_800ADE2C(arg4, entry[0]), data, data, count);
    output = data;
    cursor = output;
    source = entry[2] + vertices;
    if (count != 0) {
        do {
            if (source->v.flag & 0x4000) {
                source->v.ob[0] = *cursor++;
                source->v.ob[1] = *cursor++;
                source->v.ob[2] = *cursor++;
                remaining--;
            }
            source++;
        } while (remaining != 0);
    }
}

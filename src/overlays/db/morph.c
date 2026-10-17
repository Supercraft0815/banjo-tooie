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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/morph/dbmorph_entrypoint_3.s")

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

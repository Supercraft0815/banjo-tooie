#include "common.h"

typedef struct {
    u8 pad0[0x16];
    u16 count : 15;
    u16 flags : 1;
    Vtx vertices[1];
} VertexListView;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B0D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B0ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B1110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B1328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B1508.s")

u8 func_800B196C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019480(f32 *, f32, f32, f32);
    void func_800198D4(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800EF2A0(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    extern s32 D_80127EA0;
    s32 index;
    f32 position[3];
    f32 rotation[3];
    f32 distance;
    f32 radialDistance;
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    f32 delta[3];
    f32 radius[3];
    u8 *entry;
    u8 *limit;

    entry = *(s16 *)arg0 * 0x18 + arg0 + 8;
    limit = *(s16 *)(arg0 + 2) * 0x10 + entry;
    while ((u32)entry < (u32)limit) {
        index = entry[0xD] - 1;
        if (!((1 << index) & arg8)) {
            position[0] = *(s16 *)(entry + 4);
            position[1] = *(s16 *)(entry + 6);
            position[2] = *(s16 *)(entry + 8);
            rotation[0] = entry[0xA] * 2;
            rotation[1] = entry[0xB] * 2;
            rotation[2] = entry[0xC] * 2;
            func_80019AA0(&D_80127EA0, func_800ADE2C(arg5, *(s8 *)(entry + 0xE)));
            func_800198D4(position, rotation);
            func_80019480(start, 0.0f, 0.0f, (f32)-*(s16 *)(entry + 2) * 0.5f);
            func_80019480(end, 0.0f, 0.0f, (f32)*(s16 *)(entry + 2) * 0.5f);
            func_80019480(radius, (f32)*(s16 *)entry, 0.0f, (f32)-*(s16 *)(entry + 2) * 0.5f);
            func_800EF3DC(radius, start);
            func_800EFB24(normal, start, end);
            func_800EF2A0(normal);
            func_800EFB24(delta, arg6, start);
            distance = normal[0] * delta[0] + normal[1] * delta[1] + normal[2] * delta[2];
            if (arg7 < distance) {
                goto rejected;
            }
            func_800EFB24(delta, arg6, end);
            if (arg7 < -(normal[0] * delta[0] + normal[1] * delta[1] + normal[2] * delta[2])) {
                goto rejected;
            }
            delta[0] = arg6[0] - (start[0] + normal[0] * distance);
            delta[1] = arg6[1] - (start[1] + normal[1] * distance);
            delta[2] = arg6[2] - (start[2] + normal[2] * distance);
            radialDistance = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            if (sqrtf(radius[0] * radius[0] + radius[1] * radius[1] + radius[2] * radius[2]) < radialDistance - arg7) {
                goto rejected;
            }
            return entry[0xD];
rejected:
            mlMtxPop();
        }
        entry += 0x10;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B1D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B1F8C.s")

void *func_800B2190(void *arg0) {
    return (u8 *)arg0 + 0x18;
}

void func_800B2198(void *arg0, void *arg1, void *arg2) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(arg2) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
    (*(s32 *)((s8 *)(arg2) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
    (*(s32 *)((s8 *)(arg2) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

void func_800B21CC(void *arg0, void *arg1, void *arg2) {
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(s16 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (*(s16 *)((s8 *)(arg0) + (6)));
    (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (*(s16 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

/* extern */

s32 func_800B2248(void *arg0) {
    f32 mlAbsF(f32);
    s32 maximum;
    s32 value;

    maximum = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 0)));
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 4)));
    if (maximum < value) {
        maximum = value;
    }
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 6)));
    if (maximum < value) {
        maximum = value;
    }
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 0xA)));
    if (maximum < value) {
        maximum = value;
    }
    return maximum;
}

u8 *func_800B2324(u8 *arg0, u8 **arg1, u8 **arg2) {
    u8 *base;

    base = arg0 + 0x18;
    *arg1 = base;
    *arg2 = (u8 *)((((u32)*(u16 *)(arg0 + 0x16) >> 1) * 0x10) + (u32)*arg1);
    return base;
}

u32 func_800B2344(void *arg0) {
    return (u32) (*(u16 *)((s8 *)arg0 + 0x16)) >> 1;
}

f32 func_800B2354(void *arg0) {
    return (f32) (u32) *(u16 *)((s8 *)arg0 + 0x14);
}

void func_800B237C(void *list, f32 center[3], f32 *norm) {
    s16 *coords = (s16 *)list;
    center[0] = coords[6];
    center[1] = coords[7];
    center[2] = coords[8];
    *norm = (u32)((u16 *)list)[9];
}

void func_800B23E0(void* arg0) 
{
    heap_free(arg0);
}
void *func_800B2400(VertexListView *list, s32 side) {
    void *heap_alloc_sided(s32, s32);
    s32 aligned4_memcpy(void *, void *, s32);
    void *copy;
    s32 size;
    size = list->count * sizeof(Vtx) + 0x18;
    copy = heap_alloc_sided(size, side ? 1 : 2);
    aligned4_memcpy(copy, list, size);
    return copy;
}

void func_800B2464(VertexListView *this, s32 color[3], VertexListView *src) {
    Vtx *start_ptr, *end_ptr, *i_ptr, *src_ptr;
    int i;

    if (color[0] != 0xFF || color[1] != 0xFF || color[2] != 0xFF) {
        start_ptr = this->vertices;
        end_ptr = start_ptr + this->count;
        for (i_ptr = start_ptr, src_ptr = src->vertices; i_ptr < end_ptr; i_ptr++, src_ptr++) {
            for (i = 0; i < 3; i++) {
                i_ptr->v.cn[i] = (src_ptr->v.cn[i] * color[i]) >> 8;
            }
        }
        osWritebackDCache(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
    }
}

void func_800B2540(VertexListView *this, s32 color[3]) {
    Vtx *start_ptr, *end_ptr, *i_ptr;
    int i;

    start_ptr = this->vertices;
    end_ptr = start_ptr + this->count;

    for (i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++) {
        for (i = 0; i < 3; i++) {
            i_ptr->v.cn[i] = color[i];
        }
    }

    osWritebackDCache(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
}

/* extern */

void func_800B25D8(VertexListView *arg0, VertexListView *arg1, s32 arg2) {
    s32 _dbpalette_entrypoint_0(s32, s32, s32 *);
    s32 sp5C[5];
    int i;
    Vtx *temp_s4;
    Vtx *temp_s6;
    Vtx *var_s1;
    Vtx *var_s2;

    temp_s6 = arg0->vertices;
    temp_s4 = arg0->count + arg0->vertices;
    var_s1 = temp_s6;
    var_s2 = arg1->vertices;
    if ((u32) temp_s6 < (u32) temp_s4) {
        do {
            _dbpalette_entrypoint_0(arg2, var_s2->v.flag & 0x1FF, sp5C);
            for (i = 0; i < 3; i++) {
                var_s1->v.cn[i] = (var_s2->v.cn[i] * sp5C[i]) >> 8;
            }
            var_s1++;
            var_s2++;
        } while ((u32) var_s1 < (u32) temp_s4);
    }
    osWritebackDCache(temp_s6, (temp_s4 - temp_s6) * sizeof(Vtx));
}

/* extern */

void func_800B26C8(void) {
    s32 defrag();
    defrag();
}

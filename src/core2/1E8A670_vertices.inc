#include "common.h"
#ifdef BT_NATIVE
#include "native_model.h"
#include "native_palette.h"
#include "memory.h"
typedef NativeVertexList VertexListView;
#define VERTEX_COUNT(list) ((list)->count_flags >> 1)
#define VERTEX_ADDRESS(p) (p)
#define VERTEX_WRITEBACK(p,size) ((void)0)
#define VERTEX_PALETTE const void *
#else
typedef struct VertexListView {
    u8 pad0[0x16];
    u16 count : 15;
    u16 flags : 1;
    Vtx vertices[1];
} VertexListView;
#define VERTEX_COUNT(list) ((list)->count)
#define VERTEX_ADDRESS(p) ((u32)(p))
#define VERTEX_WRITEBACK(p,size) osWritebackDCache(p,size)
#define VERTEX_PALETTE s32
#endif

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
    #ifdef BT_NATIVE
    *arg2 = *arg1 + ((u32)*(u16 *)(arg0+0x16)>>1)*16;
#else
    *arg2 = (u8 *)((((u32)*(u16 *)(arg0 + 0x16) >> 1) * 0x10) + (u32)*arg1);
#endif
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
#ifndef BT_NATIVE
    s32 aligned4_memcpy(void *, void *, s32);
#endif
    void *copy;
    s32 size;
    size = VERTEX_COUNT(list) * sizeof(Vtx) + 0x18;
    #ifdef BT_NATIVE
    (void)side;
    copy = heap_alloc(size);
#else
    copy = heap_alloc_sided(size, side ? 1 : 2);
#endif
    aligned4_memcpy(copy, list, size);
    return copy;
}

void func_800B2464(VertexListView *this, s32 color[3], VertexListView *src) {
    Vtx *start_ptr, *end_ptr, *i_ptr, *src_ptr;
    int i;

    if (color[0] != 0xFF || color[1] != 0xFF || color[2] != 0xFF) {
        start_ptr = this->vertices;
        end_ptr = start_ptr + VERTEX_COUNT(this);
        for (i_ptr = start_ptr, src_ptr = src->vertices; i_ptr < end_ptr; i_ptr++, src_ptr++) {
            for (i = 0; i < 3; i++) {
                i_ptr->v.cn[i] = (src_ptr->v.cn[i] * color[i]) >> 8;
            }
        }
        VERTEX_WRITEBACK(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
    }
}

void func_800B2540(VertexListView *this, s32 color[3]) {
    Vtx *start_ptr, *end_ptr, *i_ptr;
    int i;

    start_ptr = this->vertices;
    end_ptr = start_ptr + VERTEX_COUNT(this);

    for (i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++) {
        for (i = 0; i < 3; i++) {
            i_ptr->v.cn[i] = color[i];
        }
    }

    VERTEX_WRITEBACK(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
}

/* extern */

void func_800B25D8(VertexListView *arg0, VertexListView *arg1, VERTEX_PALETTE arg2) {
#ifndef BT_NATIVE
    s32 _dbpalette_entrypoint_0(s32, s32, s32 *);
#endif
    s32 sp5C[5];
    int i;
    Vtx *temp_s4;
    Vtx *temp_s6;
    Vtx *var_s1;
    Vtx *var_s2;

    temp_s6 = arg0->vertices;
    temp_s4 = VERTEX_COUNT(arg0) + arg0->vertices;
    var_s1 = temp_s6;
    var_s2 = arg1->vertices;
    if (VERTEX_ADDRESS(temp_s6) < VERTEX_ADDRESS(temp_s4)) {
        do {
            _dbpalette_entrypoint_0(arg2, var_s2->v.flag & 0x1FF, sp5C);
            for (i = 0; i < 3; i++) {
                var_s1->v.cn[i] = (var_s2->v.cn[i] * sp5C[i]) >> 8;
            }
            var_s1++;
            var_s2++;
        } while (VERTEX_ADDRESS(var_s1) < VERTEX_ADDRESS(temp_s4));
    }
    VERTEX_WRITEBACK(temp_s6, (temp_s4 - temp_s6) * sizeof(Vtx));
}

/* extern */

void func_800B26C8(void) {
#ifndef BT_NATIVE
    s32 defrag();
    defrag();
#endif
    /* The native heap does not move allocations. */
}

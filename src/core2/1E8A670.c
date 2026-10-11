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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B196C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B2248.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B237C.s")

void func_800B23E0(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B2400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B2464.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A670/func_800B25D8.s")

/* extern */

void func_800B26C8(void) {
    s32 defrag();
    defrag();
}

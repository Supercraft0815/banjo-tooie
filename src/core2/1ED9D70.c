#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100480.s")

void func_8010052C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801005B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100610.s")

void func_80100670()
{
    func_80100610();
}

typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;

typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

FreeList *freelist_new(s32, s32);
void *freelist_next(FreeList **, s32 *);

void func_80100690(s32 *arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    extern FreeList *D_80135A60;
    if (D_80135A60 == 0) {
        D_80135A60 = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A60, arg0);
}

extern FreeList *D_80135A64;

void func_801006E0(s32 *arg0) {
    FreeList *volatile *list = &D_80135A64;
    if (D_80135A64 == 0) {
        *list = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A64, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_8010072C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801007B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801009C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100AC4.s")

void func_80100B3C(void) {
    extern s32 D_80135A68;
    D_80135A68 = 0x3667;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100D24.s")

void func_80100E18(s16 arg0) {
    void *freelist_at(FreeList *, s16);
    extern FreeList *D_80135A60;
    (*(s8 *)((s8 *)(freelist_at(D_80135A60, arg0)) + (0xA))) = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100F0C.s")

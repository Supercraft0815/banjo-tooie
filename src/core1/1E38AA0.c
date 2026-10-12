#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80020F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021574.s")

typedef struct { u8 pad[0x2C]; ALLink *free; } PoolFreeList;

s32 *func_80021794(void) {
    extern PoolFreeList *D_800411F4;
    ALLink *sp4;

    sp4 = NULL;
    if (D_800411F4->free != NULL) {
        sp4 = D_800411F4->free;
        D_800411F4->free = D_800411F4->free->next;
        sp4->next = NULL;
    }
    return (s32 *)sp4;
}

void func_800217F4(ALLink *arg0) {
    extern PoolFreeList *D_800411F4;

    arg0->next = D_800411F4->free;
    D_800411F4->free = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_800218C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021AD0.s")

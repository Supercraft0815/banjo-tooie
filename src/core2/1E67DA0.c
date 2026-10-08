#include "core2/1E67DA0.h"

s32 func_8008E4B0(void) {
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        self->unkC->unkC[i] = (s32)func_8009E138(self, i);
    }
    return self->unkC->unkC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6F0.s")

s32 func_8008E92C(void *arg0)
{
    return *(s32 *) ((u8 *) *(void **) ((u8 *) arg0 + 0xC) + 0x18);
}

s32 func_8008E938(void *arg0)
{
    return *(s32 *) *(void **) ((u8 *) arg0 + 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E974.s")

void func_8008E9A0(void *arg0, s32 arg1)
{
    ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1] = arg1;
}

s32 func_8008E9AC(void *arg0)
{
    return ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008ED70.s")

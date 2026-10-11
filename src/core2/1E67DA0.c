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

/* extern */

void func_8008E6BC(void *arg0) {
    s32 func_800EBFF4(s32);
    func_800EBFF4(*(*(s32 **)((s8 *)(arg0) + (0xC))));
    *(*(s32 **)((s8 *)(arg0) + (0xC))) = 0;
}

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

s32 func_8008E974(u8 *arg0) {
    struct Flags { unsigned int pad : 22; signed int flag : 1; unsigned int rest : 9; };
    return ((struct Flags *)((u8 *)**(u8 ***)((u8 *)arg0 + 0xC) + 0x28))->flag ? 1 : 0;
}

void func_8008E9A0(void *arg0, s32 arg1)
{
    ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1] = arg1;
}

s32 func_8008E9AC(void *arg0)
{
    return ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1];
}

s32 func_8008E9B8(PlayerState *arg0, s32 **arg1) {
    *arg1 = func_8008E4B8(arg0);
    return 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9E4.s")

extern u8 D_80117CAC[];

u8 *func_8008ED70(void)
{
    return D_80117CAC;
}

#include "core2/1E76360.h"

s32 func_8009CA70(PlayerState *arg0, s32 arg1, s32 arg2) {
    typedef struct { s32 flags; s32 pad[2]; } Entry;
    extern Entry D_80117F34[];
    s32 result = 0;
    return (D_80117F34[arg1].flags & arg2) ? 1 : result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76360/func_8009CAAC.s")

void (*func_8009CAF8(PlayerState *arg0, s32 arg1))(PlayerState *) {
    extern void (*(*D_80117F38[][3])(s32))(PlayerState *);
    void (*(*temp_v0)(s32))(PlayerState *);

    temp_v0 = D_80117F38[arg1][0];
    if (temp_v0 != NULL) {
        return temp_v0(1);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76360/func_8009CB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76360/func_8009CB90.s")

s16 func_8009CBDC(s32 arg0, s32 arg1) {
    extern s16 D_80117F32[];
    return *(s16 *)((u8 *)D_80117F32 + arg1 * 12);
}

void func_8009CBFC(void *arg0)
{
}

#include "common.h"

void func_800CD230(f32 arg0) {
    extern f32 D_8012B010;
    *(f32 *)((u8 *)&D_8012B010 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CDBA8.s")

s32 func_800CDFA8(s32 arg0, s32 *arg1) {
    extern u8 D_8012AF70[];
    *arg1 = D_8012AF70[arg0 + 0x80];
    return *(s32 *)(D_8012AF70 + (arg0 << 2));
}

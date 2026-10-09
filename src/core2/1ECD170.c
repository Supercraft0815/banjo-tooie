#include "core2/1ECD170.h"

void func_800F3880(s32 arg0)
{
    func_80098E64();
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F38A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3B90.s")

void func_800F3BB0()
{
    func_8009C128();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3BD0.s")

/* extern */

void func_800F3E84(s32 arg0, void *arg1) {
    f32 baroll_get(s32);
    f32 func_8009BFCC();
    f32 yaw_get(s32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_8009BFCC();
    (*(f32 *)((s8 *)(arg1) + (4))) = yaw_get(arg0);
    (*(f32 *)((s8 *)(arg1) + (8))) = baroll_get(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F40EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4200.s")

s32 func_800F4244(s32 *arg0) {
    return arg0[95];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F43A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F44DC.s")

void func_800F4524(s32 *arg0, s32 arg1) {
    arg0[96] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F452C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F457C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F45B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F45E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4648.s")

/* extern */

void func_800F468C(void *arg0) {
    s32 func_800991B0(void *);
    s32 func_800EA09C();
    if (((*(s32 *)((s8 *)(arg0) + (0x17C))) != 0) && ((*(s32 *)((s8 *)(arg0) + (0x180))) == 0) && (func_800EA09C() == 2)) {
        func_800991B0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F46D8.s")

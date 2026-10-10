#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB800.s")

s32 func_800EB854(void) {
    extern s16 D_80132E9C;

    return D_80132E9C;
}

void func_800EB860(s32 arg0, s32 arg1) {
    extern s32 D_80132EA0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x20))) = arg0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x24))) = arg1;
}

void func_800EB874(void)
{
    extern s32 D_80132EC0;

    D_80132EC0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB8C0.s")

s32 func_800EBB30(s32 *arg0, s32 *arg1) {
    extern s32 D_80132EA0;
    *arg0 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x14)));
    *arg1 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x18)));
    return (*(s32 *)((s8 *)(&D_80132EA0) + (0x1C)));
}

OSThread *func_800EBB50(void)
{
    extern u8 D_80123540[];

    return (OSThread *) D_80123540;
}

void func_800EBB5C(void) {
    extern s32 D_8013546C;
    D_8013546C = 0x6B7;
}

void func_800EBB6C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBB94.s")

void func_800EBC04(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBE24.s")

/* extern */

void func_800EBE74(s32 arg0, void *arg1, s32 arg2) {
    s32 func_800BDBC4(s32);
    s32 func_800BDC44();
    s32 func_800EBC0C(s32, s32, void *, s32);
    s32 var_v0;

    if ((*(s32 *)((s8 *)(arg1) + (0x10))) & 1) {
        var_v0 = func_800BDC44();
    } else {
        var_v0 = func_800BDBC4(arg0);
    }
    func_800EBC0C(var_v0, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBF8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBFD4.s")

/* extern */

void func_800EBFF4(void *arg0) {
    s32 func_800BDB9C(s16);
    s32 func_800E9AC0(s32, s32);
    s32 func_800EBE24(void *);
    func_800E9AC0(func_800BDB9C((*(s16 *)((s8 *)(arg0) + (0x1C)))), (*(s32 *)((s8 *)(arg0) + (0))));
    func_800EBE24(arg0);
}

void func_800EC030(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(*arg0) + (4))) = (s16) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s16 *)((s8 *)(*arg0) + (6))) = (s16) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s16 *)((s8 *)(*arg0) + (8))) = (s16) (*(s32 *)((s8 *)(arg1) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC0EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC340.s")

void func_800EC358(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

void func_800EC360(s16 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

void func_800EC368(s16 *arg0, s32 arg1) {
    arg0[11] = arg1;
}

void func_800EC370(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (*(s16 *)((s8 *)(*arg0) + (4)));
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (*(s16 *)((s8 *)(*arg0) + (6)));
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (*(s16 *)((s8 *)(*arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC398.s")

void func_800EC3C4(void *arg0) {
    (*(s32 (**)())((s8 *)(arg0) + (8)))();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC854.s")

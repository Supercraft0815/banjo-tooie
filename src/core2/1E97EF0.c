#include "common.h"

extern s32 D_801285B0;
extern s32 D_80128728;
extern s32 D_8012872C;
extern s32 D_80128760;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BE600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BE7F8.s")

/* extern */

void func_800BE9B0(void) {
    s32 _gcmapsects_entrypoint_17(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_17(&D_801285B0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BE9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEA64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEAAC.s")

/* extern */

void func_800BEAF4(void) {
    s32 _gcmapsects_entrypoint_8(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_8(&D_801285B0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEB28.s")

s32 func_800BEB4C()
{
    return D_80128760;
}

void func_800BEB58(s32 arg0) {
    *(s32 *)((u8 *)&D_80128760 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEB98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEBD4.s")

s32 func_800BEC10()
{
    return D_80128728;
}

s32 func_800BEC1C()
{
    return D_8012872C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEC28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEC4C.s")

f32 func_800BECCC(void) {
    extern s32 D_80128734;
    return (f32) D_80128734;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BECE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BED18.s")

void func_800BED50(s32 arg0)
{
    func_800BE600(arg0,0x1F00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BED70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF3E4.s")

void func_800BF420()
{
    _gcmapDll_entrypoint_4(&D_801285B0);
}

void func_800BF444(void) {
    s32 _gcmapDll_entrypoint_3(s32 *);
    s32 func_800C6A28(s32 *, s32 *, s32 *, s32 (*)());
    extern s32 func_800BEF00;
    extern s32 func_800BF0E0;
    extern s32 func_800BF228;
    _gcmapDll_entrypoint_3(&D_801285B0);
    func_800C6A28(&func_800BEF00, &func_800BF0E0, &func_800BF228, func_800BEB4C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF58C.s")

void func_800BF68C(void) {
    s32 _gcmapDll_entrypoint_1(s32 *);
    extern s8 D_80128634;
    _gcmapDll_entrypoint_1(&D_801285B0);
    D_80128634 = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF6B8.s")

void * func_800BF704(void) {
    return &D_801285B0;
}

/* extern */

void func_800BF710(void) {
    s32 _gcmapsects_entrypoint_9(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_9(&D_801285B0);
    }
}

void func_800BF744(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&D_801285B0)[arg0]) + (0x88))) = arg1;
    if ((*(s32 *)((s8 *)(&D_801285B0) + (0x88))) < arg0) {
        (*(s32 *)((s8 *)(&D_801285B0) + (0x88))) = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF7E0.s")

u32 func_800BF8B0(void) {
    extern u8 D_80128627;
    return *(u8 *)((u8 *)&D_80128627 + 0);
}

/* extern */

void func_800BF8BC(s32 arg0) {
    s32 _gcmapDll_entrypoint_6(s32 *, s32);
    _gcmapDll_entrypoint_6(&D_801285B0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BFA1C.s")

u8 func_800BFAA4(void) {
    return (*(u8 *)((s8 *)(func_800BF704()) + (0x77)));
}

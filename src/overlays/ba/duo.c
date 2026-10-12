#include "common.h"

s32 baduo_entrypoint_0() 
{
    return 0x14;
}

/* extern */

void func_80800008_baduo(s32 arg0, s32 arg1) {
    s32 func_800A4C88(s32);
    s32 func_801100E4(s32, s32);
    s32 sp18;
    volatile s32 sp1c;

    sp18 = func_800A4C88(arg1);
    sp1c = sp18;
    func_801100E4(sp1c, func_800A4C88(arg0));
}

u32 baduo_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_2.s")

u32 baduo_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 1);
}

u32 baduo_entrypoint_4(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 2);
}

void baduo_entrypoint_5(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_7.s")

/* extern */

void baduo_entrypoint_8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))) + 8);
}

void baduo_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 4) = arg1;
}

void baduo_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 1) = arg1;
}

void baduo_entrypoint_11(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 2) = arg1;
}

/* extern */

void baduo_entrypoint_12(s32 arg0) {
    s32 _bashoes_entrypoint_6(s32, s32);
    s32 func_8008E39C();
    s32 func_800F9A6C();
    if (func_8008E39C() != 0) {
        _bashoes_entrypoint_6(arg0, 2);
    }
    func_800F9A6C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_21.s")

/* extern */

void func_80800C78_baduo(s32 arg0, s32 arg1) {
    s32 _surestart_entrypoint_0(s32);
    s32 func_800A1658(s32);
    _surestart_entrypoint_0(arg1);
    func_800A1658(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/func_80800CA8_baduo.s")

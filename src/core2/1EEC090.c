#include "core2/1EEC090.h"

s32 func_801127A0() 
{
    return 0x24;
}

void func_801127A8(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801127C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801128D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112C3C.s")

void func_80112D08(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (4))) = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112D90.s")

void func_80112E50(void *arg0, f32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
    if (((*(s16 *)((s8 *)(temp_v0) + (0xC))) != 0) && (arg2 == (*(s16 *)((s8 *)(temp_v0) + (0xE))))) {
        (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x14))) + arg1);
    }
}

s32 func_80112E84(void *arg0) {
    return *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 96) + 12);
}

s32 func_80112E90() 
{
    return 0x80;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011309C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011337C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011347C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011349C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801134F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801135D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801137E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801138A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801138F4.s")

void func_8011396C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 40) + 20) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011413C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801143A4.s")

f32 func_80114444(void) {
    s32 func_800F5410();
    extern f32 D_801265E4;
    extern f32 D_801265E8;
    if (func_800F5410() == 0xD) {
        return D_801265E4;
    }
    return D_801265E8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011447C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011458C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011490C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114BD4.s")

void func_80114C7C(void* arg0) 
{
    heap_free(arg0);
}
void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (0x10)));
}

void func_80114CB0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    (*(f32 *)((s8 *)(arg0) + (8))) = arg1;
}

void func_80114CC0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 1;
    (*(f32 *)((s8 *)(arg0) + (8))) = arg1;
}

void* func_80114CD4(void* arg0) 
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114CF4.s")

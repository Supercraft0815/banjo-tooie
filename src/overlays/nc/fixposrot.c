#include "common.h"

void* ncfixposrot_entrypoint_0(void) {
    void func_800EFD24(f32 vec[3]);
    void* heap_alloc(s32 size);
    f32 *temp_v0;

    temp_v0 = heap_alloc(0x1C);
    func_800EFD24(temp_v0);
    func_800EFD24(temp_v0 + 3);
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    return temp_v0;
}

void ncfixposrot_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

void ncfixposrot_entrypoint_2(u8 *arg0, s32 arg1) {
    f32 func_800136E4(f32, u8 *);
    s32 func_800F18FC(s32, u8 *, s32, s32);
    func_800F18FC(arg1, arg0, arg0 + 0xC, arg1);
    (*(f32 *)((s8 *)(arg0) + (0xC))) = func_800136E4(-(*(f32 *)((s8 *)(arg0) + (0xC))), arg0);
    (*(f32 *)((s8 *)(arg0) + (0x14))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/fixposrot/ncfixposrot_entrypoint_3.s")

void ncfixposrot_entrypoint_4(f32 *arg0, f32 *arg1) {
    func_800EE7F8(arg0 + 3, arg1);
}

void ncfixposrot_entrypoint_5()
{
    func_800EE7F8();
}

/* extern */

void ncfixposrot_entrypoint_6(s32 arg0, s32 arg1) {
    s32 func_8010FE14(s32, s32, s32, s32);
    func_8010FE14(arg1, arg0, arg0 + 0xC, arg1);
}

/* extern */

void ncfixposrot_entrypoint_7(s32 arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(s32);
    s32 _cadbfunc_entrypoint_2(s32);
    s32 func_800A5800(s32);
    func_800A5800(arg1);
    _cadbfunc_entrypoint_0(arg0);
    _cadbfunc_entrypoint_2(arg0 + 0xC);
}

void ncfixposrot_entrypoint_8(s32 arg0, s32 arg1) {
    s32 func_8010F9C0(s32, s32);
    s32 func_8011001C(s32 *arg0);
    func_8010F9C0(arg0, 3);
    ncfixposrot_entrypoint_7(func_8011001C((s32 *) arg0), arg1);
}

void ncfixposrot_entrypoint_9(s32 *arg0) {
    s32 func_800C53EC(s32, s32);
    s32 func_8010F9C0(s32, s32);
    s32 func_8011001C(s32 *arg0);
    u8 *sp1C[2];
    u8 *temp_v0;

    temp_v0 = func_8011001C(arg0);
    if ((*(s16 *)((s8 *)(temp_v0) + (0x18))) != 0) {
        sp1C[1] = temp_v0;
        func_800C53EC(0, 0);
        temp_v0 = sp1C[1];
        (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    }
    func_8010F9C0((s32) arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/fixposrot/ncfixposrot_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/fixposrot/ncfixposrot_entrypoint_11.s")

void ncfixposrot_entrypoint_12(s32 arg0, s32 *arg1) { func_800EE7F8(arg1, (s32 *)arg0); }

void ncfixposrot_entrypoint_13(void *arg0, f32 *arg1) {
    func_800EE7F8(arg1, (u8 *)arg0 + 0xC);
}

/* extern */

void ncfixposrot_entrypoint_14(void *arg0) {
    s32 func_800C52F4(s32, s32);
    func_800C52F4(0, 0);
    (*(s16 *)((s8 *)(arg0) + (0x18))) = 1;
}

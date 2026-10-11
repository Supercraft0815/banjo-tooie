#include "core2/1E75920.h"

s32 func_8009C030() 
{
    return 0x30;
}

/* extern */

void func_8009C038(void *arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))));
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0xC);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0x18);
}

/* extern */

void func_8009C08C(void *arg0) {
    s32 func_8009C21C();
    s32 func_800EFD24(s32);
    func_8009C21C();
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0x24);
}

s32 func_8009C0BC(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(*(s32 *)((s8 *)arg0 + 0xE4));
    return func_800EE7F8(*(s32 *)((s8 *)arg0 + 0xE4) + 0xC, arg1);
}

/* extern */

void func_8009C0F8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xE4))));
}

void func_8009C118(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 228) + 4) = arg1;
}

void func_8009C128(PlayerState *arg0, f32 arg1[3]) {
    s32 func_800EE7F8();
    func_800EE7F8((s32)arg1, *(s32 *)((u8 *)arg0 + 0xE4));
}

f32 func_8009C150(PlayerState *arg0) {
    return (*(f32 **)((u8 *)arg0 + 0xE4))[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C15C.s")

void func_8009C188(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x18);
}

void func_8009C1B4(void *arg0, f32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xE4)));
    (*(f32 *)((s8 *)(temp_v0) + (4))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (4))) + arg1);
}

void func_8009C1CC(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x24);
}

/* extern */

void func_8009C1F8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0x24);
}

s32 func_8009C21C(u8 *arg0) {
    s32 func_800EE7F8();
    s32 temp;

    temp = *(s32 *)(arg0 + 0xE4);
    func_800EE7F8(temp + 0x18, temp + 0xC, temp);
    temp = *(s32 *)(arg0 + 0xE4);
    return func_800EE7F8(temp + 0xC, temp, temp);
}

/* extern */

void func_8009C25C(void *arg0) {
    s32 func_800EF04C(s32, s32);
    s32 func_800EFD24(s32);
    s32 temp_a0;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0xE4)));
    func_800EF04C(temp_a0, temp_a0 + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xE4))) + 0x24);
}

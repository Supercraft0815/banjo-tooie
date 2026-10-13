#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010A980.s")

void func_8010AA54(s32 *arg0) {
    void func_800EE7F8();
    extern s32 D_80136F30;
    func_800EE7F8(arg0, &D_80136F30);
}

void func_8010AA78(s32 *arg0) {
    void func_800EE7F8();
    extern s32 D_80136F20;
    func_800EE7F8(arg0, &D_80136F20);
}

void func_8010AA9C(s32 *arg0) {
    void func_800EE7F8();
    extern s32 D_80136F40;
    func_800EE7F8(arg0, &D_80136F40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AAC0.s")

/* extern */

s32 func_8010ACE0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AAC0(void *, s32, s32, s32);
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AAC0(arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AD4C.s")

/* extern */

s32 func_8010AE30(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AD4C(void *, s32, s32, s32);
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AD4C(arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AE9C.s")

/* extern */

s32 func_8010AF8C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AE9C(void *, s32, s32, s32);
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AE9C(arg0, arg1, arg2, arg3);
}

/* extern */

s32 func_8010AFF8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF214((f32 *)(arg0 + 4), (*(f32 *)((s8 *)(arg0) + (0x44))), (*(f32 *)((s8 *)(arg0) + (0x48))), func_8010C4AC(arg0));
    return 0;
}

/* extern */

s32 func_8010B040(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800EF1B8(s32, s32, f32, u8 *);
    f32 func_8010C4AC(void *);
    func_800EF1B8(arg0 + 4, (*(s32 *)((s8 *)(arg0) + (0x48))), func_8010C4AC(arg0), arg0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B0E0.s")

s32 func_8010B13C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF214((f32 *)(arg0 + 4), -(*(f32 *)(arg0 + 0x44)), *(f32 *)(arg0 + 0x48), func_8010C4AC(arg0));
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B514.s")

int func_8010B69C(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 func_800BED50(f32 *, Actor *);
    f32 y = func_800BED50(arg0->position, arg0) - 130.0f;
    arg0->position[1] = (arg0->position[1] < y) ? arg0->position[1] : y;
    return y == arg0->position[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B8A4.s")

/* extern */

s32 func_8010B910(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800EF04C(s32, s32, s32);
    func_800EF04C(arg0 + 4, arg0 + 0x28, arg0);
    return 0;
}

/* extern */

s32 func_8010B94C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 func_800D8FF8();
    s32 func_800EF174(s32, s32, f32);
    func_800EF174(arg0 + 4, arg0 + 0x28, func_800D8FF8());
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B990.s")

s32 func_8010B990(Actor *, s32);

s32 func_8010BA80(Actor *volatile arg0, volatile s32 arg1, s32 arg2) { 
    void func_800EE7F8(f32 *, f32 *);
    s32 result;
    f32 saved[3];
    f32 *position;
    s32 *arg2_ptr = &arg2;

    position = arg0->position;
    func_800EE7F8(saved, position);
    result = func_8010B990(arg0, arg1);
    if (result & arg2) {
        func_800EE7F8(position, saved);
    }
    return result;
}

s32 func_8010BAEC(Actor *volatile arg0, volatile s32 arg1, s32 arg2) { 
    void func_800EE7F8(f32 *, f32 *);
    s32 result;
    f32 saved[3];
    f32 *position;
    s32 *arg2_ptr = &arg2;
    position = arg0->position;
    func_800EE7F8(saved, position);
    result = func_8010B990(arg0, arg1);
    if ((result & *arg2_ptr) != *arg2_ptr) {
        func_800EE7F8(position, saved);
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BDB0.s")

/* extern */

void func_8010BF4C(Actor *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) { s32 func_80102844(Actor *, f32, s32, s32); *(f32 *)((s8 *)arg0 + 0x24) = arg2; func_80102844(arg0, (f32) arg3, -1, arg1); func_8010B990(arg0, arg4); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C2D8.s")

void func_8010C3A8(Actor *arg0, u32 arg1, f32 arg2) {
    f32 sp18[2];
    f32 temp_f0;

    temp_f0 = *(f32 *)((s8 *)arg0 + 0x24);
    sp18[0] = temp_f0;
    *(f32 *)((s8 *)arg0 + 0x24) = temp_f0 * arg2;
    func_8010B990(arg0, arg1);
    *(f32 *)((s8 *)arg0 + 0x24) = sp18[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C460.s")

/* extern */

f32 func_8010C4AC(void *arg0) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(8) != 0) {
        return (*(f32 *)((s8 *)(arg0) + (0x24))) * 1.5f;
    }
    return (*(f32 *)((s8 *)(arg0) + (0x24)));
}

#include "common.h"

s32 func_8010A980(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A624(Actor *);
    u32 func_8010A654(Actor *, s32);
    u32 func_8010A698(Actor *);
    extern f32 D_80136F20[3];
    extern f32 D_80136F30[3];
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    void *sp28;

    sp2C = func_8010A698(arg0);
    func_8010A624(arg0);
    sp3C[0] = arg1[0];
    sp3C[1] = arg1[1] + 4.0f;
    sp3C[2] = arg1[2];
    sp30[0] = arg0->position[0];
    sp30[1] = arg0->position[1] + 4.0f;
    sp30[2] = arg0->position[2];
    sp28 = func_800C6A7C(sp3C, sp30, D_80136F30, arg0->unk14);
    func_800EE7F8(D_80136F20, sp30);
    func_8010A654(arg0, sp2C);
    return sp28 ? 1 : 0;
}

void func_8010AA54(s32 *arg0) {
    void func_800EE7F8();
    extern f32 D_80136F30[3];
    func_800EE7F8(arg0, &D_80136F30);
}

void func_8010AA78(s32 *arg0) {
    void func_800EE7F8();
    extern f32 D_80136F20[3];
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
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF1B8((f32 *)(arg0 + 4), *(f32 *)(arg0 + 0x48), func_8010C4AC(arg0));
    return 0;
}

s32 func_8010B088(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_8010C4AC(void *);
    f32 sp18[2];

    sp18[0] = func_8010C4AC(arg0);
    func_800EF1B8((f32 *)(arg0 + 4), *(f32 *)(arg0 + 0x48), sp18[0] * func_800D8FF8());
    return 0;
}

s32 func_8010B0E0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_8010C4AC(void *);
    f32 sp18[2];

    sp18[0] = func_8010C4AC(arg0);
    func_800EF214((f32 *)(arg0 + 4), *(f32 *)(arg0 + 0x44), *(f32 *)(arg0 + 0x48), sp18[0] * func_800D8FF8());
    return 0;
}

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

typedef struct {
    s32 marker;
    f32 position[3];
    u8 pad10[0x60];
    u32 path_index : 7;
    u32 pad70_10 : 15;
    u32 path_node : 6;
    u32 pad70_0 : 4;
} ActorPath;

s32 func_8010B800(ActorPath *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    s32 func_800CC338(f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 result;

    if (arg0->path_index != 0) {
        result = func_800CC338(arg0->position, arg0->path_index - 1, arg0->path_node - 1);
        if (result == -1) {
            func_800EE7F8(arg0->position, arg1);
            return 1;
        }
        arg0->path_node = result + 1;
        return 0;
    }
    return 0;
}

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

/* extern */

s32 func_8010C3E8(Actor *arg0) {
    f32 func_800BECCC(void);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, s32);
    f32 temp_f12;
    s32 var_v0;

    temp_f12 = func_800BECCC() - 1000.0f;
    var_v0 = 0;
    if ((*(f32 *)((s8 *)(arg0) + (8))) < temp_f12) {
        (*(f32 *)((s8 *)(arg0) + (8))) = temp_f12;
        if (func_8010108C(arg0, 0x4D, 1) > 0) {
            return 0;
        }
        func_800FFAB0(arg0);
        var_v0 = 1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C460.s")

/* extern */

f32 func_8010C4AC(void *arg0) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(8) != 0) {
        return (*(f32 *)((s8 *)(arg0) + (0x24))) * 1.5f;
    }
    return (*(f32 *)((s8 *)(arg0) + (0x24)));
}

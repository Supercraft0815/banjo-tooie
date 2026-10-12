#include "core2/1EC2350.h"

void func_800E8A60(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8A68.s")

void func_800E8B04(void) {
    s32 freelist_free(s32);
    extern s32 D_8012D680;
    if (D_8012D680 != 0) {
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

void func_800E8B3C(void) {
    s32 freelist_defrag(s32);
    extern s32 D_8012D680;
    if (D_8012D680 != 0) {
        D_8012D680 = freelist_defrag(D_8012D680);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8B74.s")

void func_800E8C08(u8 arg0) {
    s32 freelist_erase(s32, s32);
    s32 freelist_free(s32);
    s32 freelist_used_count(s32);
    extern s32 D_8012D680;
    freelist_erase(D_8012D680, arg0);
    if (freelist_used_count(D_8012D680) == 0) {
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

s32 func_800E8C58(u8 arg0) {
    void *func_800E8CB0(u8);
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = func_800E8CB0(arg0);
    var_v1 = (s32) ((f32) *(s16 *)temp_v0 * *(f32 *)(temp_v0 + 0xC));
    if (var_v1 >= *(s16 *)temp_v0) {
        var_v1 = *(s16 *)temp_v0 - 1;
    }
    return var_v1;
}

void *func_800E8CB0(u8 arg0) {
    extern s32 D_8012D680;
    void *freelist_at(s32, s32);
    return freelist_at(D_8012D680, arg0);
}

void func_800E8CDC(u8 arg0) {
    void *func_800E8CB0(u8);
    extern s32 D_80123500;
    (*(f32 *)((s8 *)(func_800E8CB0(arg0)) + (4))) = 0.0f;
    func_800E8D28(arg0, 1.0f);
    func_800E8D5C(arg0, &D_80123500, 2U);
}

void func_800E8D28(u8 arg0, f32 arg1) {
    void *func_800E8CB0(u8);
    (*(f32 *)((s8 *)(func_800E8CB0(arg0)) + (8))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8DE4.s")

/* extern */

void func_800E8E3C(u8 *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    (*(f32 *)((s8 *)(arg0) + (0xC))) = func_800F3780((*(f32 *)((s8 *)(arg0) + (4))), arg0 + 0x10, (*(s16 *)((s8 *)(arg0) + (2))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8E70.s")

u8 *func_800E8F68(u8 *arg0) {
    if ((*(s32 *)((s8 *)(arg0) + (0x24))) != (*(s32 *)((s8 *)(arg0) + (0x20)))) {
        return arg0 + 0x20;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E8F8C.s")

s32 func_800E9048(void) {
    extern s16 D_80131CE0;

    return D_80131CE0;
}

s16 func_800E9054(s32 arg0) {
    extern s16 D_80131CF6;
    s32 index = arg0;
    index *= 9;
    index *= 2;
    return *(s16 *)((u8 *)&D_80131CF6 + index);
}

void func_800E9070(s32 arg0, s32 arg1) {
    extern s32 D_8012D690;
    s32 offset = arg0 - (s32)&D_8012D690;
    u8 *p = (u8 *)&D_8012D690 + ((offset - 0x3A8) / 216);
    *p = *p + 1;
}

void func_800E90A4(s32 arg0, s32 arg1) {
    extern s32 D_8012D690;
    s32 offset = arg0 - (s32)&D_8012D690;
    u8 *p = (u8 *)&D_8012D690 + ((offset - 0x3A8) / 216);
    *p = *p - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E90D8.s")

void func_800E9300(s32 arg0,s32 arg1)
{
    func_800E90D8(arg0,arg1,0x1);
}

void func_800E9320(s32 arg0, s32 arg1) {
    func_800E90D8(arg0, arg1, 0);
}

void func_800E9340(void *arg0, s32 arg1, s32 arg2) {
    void func_800E8E70(s32, void *, s32, s32);
    extern s32 D_8012D690;
    extern s32 unknown2_ROM_START;
    s32 temp_v0;
    temp_v0 = arg1 * 0x12;
    func_800E8E70((s32)arg0, (void *)((s32)&unknown2_ROM_START + temp_v0 + 8), 0x12, arg2);
    rare_memcpy((void *)((s32)&D_8012D690 + temp_v0 + 0x4658), arg0, 0x12);
}

void *func_800E93AC(s32 arg0) {
    extern s32 D_8012D690;
    return (void *) ((arg0 * 0x12) + 0x4658 + (s32) &D_8012D690);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E93CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E9438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E94E4.s")

void func_800E9574(void) {
    s32 func_800E93CC(s32);
    s32 func_800E9438(s32);
    s32 func_800E94E4();
    extern s32 D_80123510;
    func_800E94E4();
    func_800E93CC(0);
    func_800E9438(0);
    D_80123510 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2350/func_800E95AC.s")

/* extern */

void func_800E96B0(s32 arg0) {
    s32 func_800E95AC(s32, s32);
    func_800E95AC(200, arg0);
}

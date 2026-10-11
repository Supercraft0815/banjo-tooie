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

void func_801128D4(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8();
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    f32 unused;
    f32 sp38;
    f32 acceleration;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    sp30 = func_800D8FF8();
    sp38 = func_800F1DCC(arg0, *arg1);
    if (mlAbsF(sp38) < arg5) {
        *arg2 = func_800F1344(sp38, 0.0f, arg5, 10.0f, arg4);
    } else {
        acceleration = arg3 * sp30;
        if (sp38 < 0.0f) {
            acceleration = -acceleration;
        }
        *arg2 += acceleration;
        if (*arg2 < 0.0f) {
            if (*arg2 < -arg4) {
                *arg2 = -arg4;
            }
        } else if (arg4 < *arg2) {
            *arg2 = arg4;
        }
    }
    sp2C = *arg2 * sp30;
    sp28 = mlAbsF(sp2C);
    if ((mlAbsF(sp38) < sp28) && ((sp2C * sp38) > 0.0f)) {
        *arg2 = 0.0f;
        sp2C = 0.0f;
        *arg1 = arg0;
    }
    *arg1 = func_800136E4(*arg1 + sp2C);
}

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

/* extern */

void func_80113410(void *arg0) {
    s32 func_800E87E0(u8);
    s32 var_s0;
    u8 temp_a0;

    var_s0 = 0;
    do {
        temp_a0 = (*(u8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x28))) + var_s0)) + (0x34)));
        if (temp_a0 != 0) {
            func_800E87E0(temp_a0);
            (*(s8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x28))) + var_s0)) + (0x34))) = 0;
        }
        var_s0 += 1;
    } while (var_s0 != 4);
}

void func_8011347C(PlayerState *arg0) {
    void func_801107F0(PlayerState *, f32 *);
    func_801107F0(arg0, arg0->bounce);
}

s32 func_8011349C(f32 *start, f32 *end) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    f32 destination[3];
    f32 normal[3];
    func_800EE7F8(destination, end);
    if (func_800FAB50(start, destination, normal, 0x820020, 50.0f)) return 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801134F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801135D0.s")

void func_80113640(s32 unused, f32 *start, f32 *end) {
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    f32 normal[3];
    func_800FAB50(start, end, normal, 0x820020, 45.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801137E4.s")

s32 func_801138A0(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x28)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x14))) != 0) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(temp_v0) + (0xC))) >= 4) {
        (*(s16 *)((s8 *)(temp_v0) + (0xE))) = (s16) ((*(s16 *)((s8 *)(temp_v0) + (0xE))) + 1);
    } else {
        (*(s16 *)((s8 *)(temp_v0) + (0xE))) = 0;
    }
    return (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x28)))) + (0xE))) >= 5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_801138F4.s")

void func_8011396C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 40) + 20) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113D30.s")

s32 func_80113FF0(void *arg0) {
    typedef struct {
        s32 unk;
        f32 value;
        u8 active;
        u8 pad[3];
    } Entry;
    typedef struct {
        u8 pad[0x48];
        Entry entries[7];
    } Data;
    Data *data = arg0;
    s32 i;
    s32 best = -1;
    f32 value = -1.0f;
    f32 current;

    for (i = 0; i < 7; i++) {
        if (data->entries[i].active != 0) {
            current = data->entries[i].value;
            if (best == -1 || current < value) {
                value = current;
                best = i;
            }
        }
    }
    return best;
}

void func_8011413C(s32 camera, f32 rotation[3], f32 scale, s32 index) {
    void func_800CA740(s32, f32 *);
    void func_800CB0E8(s32, f32 *, s32);
    void func_800EF334(f32 *, f32);
    if (index != 0) {
        func_800CB0E8(camera, rotation, index - 1);
    } else {
        func_800CA740(camera, rotation);
    }
    func_800EF334(rotation, scale);
}

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

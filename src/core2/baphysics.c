#include "overlays/ba/physics.h"

s32 func_8009AD70() 
{
    return 0xF;
}

s32 func_8009AD78(void *arg0, s32 arg1) {
    return (*(u8 **)((u8 *)arg0 + 0xC4))[arg1];
}

void func_8009AD88(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009AD90.s")

void func_8009ADF0(void *arg0, s32 arg1, s32 arg2) {
    (*(u8 **)((u8 *)arg0 + 0xC4))[arg1] = arg2;
}

s32 func_8009AE00() 
{
    return 0xC4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009AE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B27C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B3B8.s")

void func_8009B414(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFB24(void *, void *, void *);
    f32 sp1C[3];
    s32 temp_v0;

    func_8009C128(arg0, sp1C);
    temp_v0 = *(s32 *)((u8 *)arg0 + 0xC8);
    func_800EFB24(temp_v0 + 0x28, temp_v0 + 4, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B450.s")

void func_8009B4D0(void *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xC8) + 0x28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B590.s")

void func_8009B7C0(PlayerState *arg0) {
    void *temp_v0;

    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x18))) = 0.0f;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_type.s")

void func_8009B94C(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8(s32);
    void func_800EFD24(f32 vec[3]);
    if (arg1 != 0) {
        func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x1C);
        return;
    }
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x1C);
}

/* extern */

void func_8009B98C(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 4);
}

void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x3C))) = vel;
}

/* extern */

void baphysics_set_target_yaw(PlayerState *arg0, f32 target_yaw) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x40))) = func_800136E4(target_yaw);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B9F0.s")

void baphysics_set_vertical_velocity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x14))) = arg1;
}

void baphysics_set_horizontal_velocity(PlayerState *arg0, f32 yaw, f32 vel) {
    void func_800EEB9C(f32[3], f32, f32);
    func_800EEB9C((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10, yaw, vel);
}

void func_8009BA9C(PlayerState *arg0, f32 *arg1) {
    s32 func_800EE7F8(s32);
    void func_800EFD24(f32 vec[3]);
    if (arg1 != NULL) {
        func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10);
        return;
    }
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10);
}

f32 func_8009BADC(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x34)));
}

f32 func_8009BAE8(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x38)));
}

s32 func_8009BAF4(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 0);
}

f32 baphysics_get_target_horizontal_velocity(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x3C)));
}

f32 func_8009BB0C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 32);
}

f32 func_8009BB18(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 64);
}

/* Single line: IDO schedules this prologue by source line. */
void func_8009BB24(PlayerState *arg0, f32 arg1[3]) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xC8) + 0x10); }

f32 baphysics_get_vertical_velocity(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x14)));
}

f32 func_8009BB5C(PlayerState *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (0x18)));
    temp_f2 = (*(f32 *)((s8 *)(temp_v0) + (0x10)));
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

/* extern */

f32 func_8009BB94(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    return func_800EEF94((f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xC8)) + 0x10));
}

f32 func_8009BBB8(PlayerState *arg0) {
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = func_8009BB5C(arg0);
    temp_f0 = baphysics_get_target_horizontal_velocity(arg0);
    if (sp1C < temp_f0) {
        var_f12 = sp1C / temp_f0;
    } else {
        var_f12 = 1.0f;
    }
    return var_f12;
}

void func_8009BC08(void *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xC8) + 0x4);
}

void func_8009BC34(PlayerState* arg0)
{
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}
void func_8009BC5C(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x44))) = arg1;
}

void baphysics_reset_gravity(PlayerState *arg0) {
    extern f32 D_80117EF0;
    baphysics_set_gravity(arg0, D_80117EF0);
}

void baphysics_reset_terminal_velocity(PlayerState *arg0) {
    extern f32 D_80117EF4;
    baphysics_set_terminal_velocity(arg0, D_80117EF4);
}

void baphysics_set_gravity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x34))) = arg1;
}

void baphysics_set_terminal_velocity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x38))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BCD4.s")

void func_8009BD18(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 80) = arg1;
}

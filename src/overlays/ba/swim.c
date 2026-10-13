#include "common.h"

s32 baswim_entrypoint_0() 
{
    return 0x8;
}

/* extern */

int baswim_entrypoint_1(void *arg0) {
    f32 func_800964DC(void *);
    f32 func_8009C150(void *);
    return (func_800964DC(arg0) - func_8009C150(arg0)) < 100.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_3.s")

void baswim_entrypoint_4()
{
    bastick_resetZones();
}

void baswim_entrypoint_5(struct player_state_s *arg0) {
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void baswim_entrypoint_9(void *, f32);
    void baswim_entrypoint_8(void *, f32);
    bastick_setZoneMax(arg0, 0, 0.03f);
    bastick_setZoneMax(arg0, 1, 1.0f);
    baswim_entrypoint_9(arg0, 0.0f);
    baswim_entrypoint_8(arg0, 0.0f);
}

void baswim_entrypoint_6(Actor *arg0, u32 arg1) {
    u32* baswim_entrypoint_7(Actor*, u32, u32);
    baswim_entrypoint_7(arg0, arg1, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_7.s")

void baswim_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 4) = arg1;
}

void baswim_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0) = arg1;
}

void baswim_entrypoint_10(void *arg0, f32 arg1) {
    f32 *temp_v0;

    temp_v0 = (*(f32 **)((s8 *)(arg0) + (0x134)));
    if (*temp_v0 < arg1) {
        *temp_v0 = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_11.s")

/* extern */

void func_808003B8_baswim(void *self) {
    f32 func_800EEF94(f32*);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    void func_8009BB24(void *, f32 *);
    f32 sp24[3];

    func_8009BB24(self, sp24);
    func_800F10B4(func_800EEF94(sp24), 50.0f, 200.0f, 0.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_13.s")

f32 baswim_entrypoint_14(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0);
}

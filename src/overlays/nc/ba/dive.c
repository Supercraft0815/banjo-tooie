#include "nc/ba/dive.h"

s32 ncbadive_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void ncbadive_entrypoint_1(void *arg0) {
    s32 func_800EFD24(void *);
    s32 func_801120CC(void *, s32, s32, s32);
    func_800EFD24((*(void **)((s8 *)(arg0) + (0x18))));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x18)))) + (0xC))) = 0.0f;
    func_801120CC(arg0, 0x45834000, 0x46034000, 0xC6034000);
}

void ncbadive_entrypoint_2(u8 *arg0) {
    s32 func_801120CC(void *, s32, s32, s32);
    func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);
}

void func_80800080_ncbadive(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void ncbadive_entrypoint_3(PlayerState *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, s32, s32);
    s32 func_80111FD4(void *, f32 *);
    void func_8011309C(void *, s32);
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 delta;
    f32 sp30;

    func_801107F0(arg0, sp44);
    func_80800080_ncbadive(arg0, sp74);
    func_800EFB24(sp5C, sp44, sp74);
    sp30 = func_800F10B4((*(f32 **)((u8 *)arg0 + 0x18))[3], 0.2f, 0.5f, func_800EEF94(sp5C), 300.0f);
    delta = func_800D8FF8();
    (*(f32 **)((u8 *)arg0 + 0x18))[3] += delta;
    func_800EFA20(sp50, *(f32 **)((u8 *)arg0 + 0x18), sp30);
    func_800EFB24(sp68, sp74, sp50);
    if (func_80111FD4(arg0, sp68)) {
        func_8011309C(arg0, 0);
    }
    func_80800080_ncbadive(arg0, sp74);
    func_80110A68(arg0, sp38, sp74);
    func_80110790(arg0, sp38);
}

/* extern */

void ncbadive_entrypoint_4(void *arg0) {
    s32 func_800EF410(s32);
    func_800EF410((*(s32 *)((s8 *)(arg0) + (0x18))));
}

#include "core2/camera_state_callbacks.h"
#include "nc/ba/dive.h"

s32 ncbadive_entrypoint_0() 
{
    return 0x10;
}    typedef struct { u8 pad0[0x18]; void * unk18; } Objdive_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void ncbadive_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(void *arg0)) {
    BT_NATIVE_ONLY(void * arg0 = (void *)camera;)
    s32 func_800EFD24(void *);
    BT_NATIVE_ONLY(void func_801120CC(s32 *, f32, f32, f32);) BT_IDO_ONLY(s32 func_801120CC(void *, s32, s32, s32);)
    func_800EFD24((((Objdive_arg0 *)arg0)->unk18));
    (*(f32 *)((s8 *)((((Objdive_arg0 *)arg0)->unk18)) + (0xC))) = 0.0f;
    BT_NATIVE_ONLY(func_801120CC((s32 *)arg0, 4200.0f, 8400.0f, -8400.0f);) BT_IDO_ONLY(func_801120CC(arg0, 0x45834000, 0x46034000, 0xC6034000);)
}

void ncbadive_entrypoint_2(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(u8 *arg0)) {
    BT_NATIVE_ONLY(u8 * arg0 = (u8 *)camera;)
    BT_NATIVE_ONLY(void func_801120CC(s32 *, f32, f32, f32);) BT_IDO_ONLY(s32 func_801120CC(void *, s32, s32, s32);)
    BT_NATIVE_ONLY(func_801120CC((s32 *)arg0, 2000.0f, 4000.0f, -4000.0f);) BT_IDO_ONLY(func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);)
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
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
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
    sp30 = func_800F10B4((arg0->unk18)[3], 0.2f, 0.5f, func_800EEF94(sp5C), 300.0f);
    delta = func_800D8FF8();
    (arg0->unk18)[3] += delta;
    func_800EFA20(sp50, arg0->unk18, sp30);
    func_800EFB24(sp68, sp74, sp50);
    if (func_80111FD4(arg0, sp68)) {
        func_8011309C(arg0, 0);
    }
    func_80800080_ncbadive(arg0, sp74);
    func_80110A68(arg0, sp38, sp74);
    func_80110790(arg0, sp38);
}

/* extern */

void ncbadive_entrypoint_4(void *arg0 BT_PASS2(, s32 bt_a0)) {
    s32 func_800EF410(s32);
    func_800EF410((*(s32 *)((s8 *)(arg0) + (0x18))));
}

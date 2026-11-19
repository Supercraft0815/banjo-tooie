#include "core2/camera_state_callbacks.h"
#include "nc/ba/bee.h"

/* extern */

void ncbabee_entrypoint_0(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(u8 *arg0)) {
    BT_NATIVE_ONLY(u8 * arg0 = (u8 *)camera;)
    BT_NATIVE_ONLY(void func_801120CC(s32 *, f32, f32, f32);) BT_IDO_ONLY(s32 func_801120CC(void *, s32, s32, s32);)
    s32 func_801124D0(BtIntPtr, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    BT_NATIVE_ONLY(void func_80111B8C(s32 *, f32, f32);) BT_IDO_ONLY(s32 func_80111B8C(u8 *, s32, s32);)
    BT_NATIVE_ONLY(func_801120CC((s32 *)arg0, 2000.0f, 4000.0f, -4000.0f);) BT_IDO_ONLY(func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);)
    BT_NATIVE_ONLY(func_80111B8C((s32 *)arg0, 4.0f, 8.0f);) BT_IDO_ONLY(func_80111B8C(arg0, 0x40800000, 0x41000000);)
    func_80115858(arg0, 0);
    func_80115870(arg0, 0.0f);
    func_801124D0((BtIntPtr) arg0, 1);
}

void ncbabee_entrypoint_1(struct player_state_s *arg0) {
}
void func_80800070_ncbabee(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0,arg1);
}

/* extern */

void ncbabee_entrypoint_2(PlayerState *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    BT_NATIVE_ONLY(s32) BT_IDO_ONLY(f32) func_800F5AE0(s32);
    void func_80110790(PlayerState *, f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110840(PlayerState *);
    void func_80110A68(PlayerState *, f32 *, f32 *);
    f32 func_801112B0(void *);
    s32 func_80111FD4(void *, f32 *);
    void func_801138F4(PlayerState *);
    void func_80115444(void *, f32 *, f32 *);
    f32 func_80115750(PlayerState *, f32);
    void func_80115828(void *, f32, f32);
    void func_8011607C(void *, s32);
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp48;
    f32 sp3C[3];
    f32 sp38;
    f32 sp2C[3];
    s32 sp28;
    f32 temp_f0;

    sp28 = func_80110840(arg0);
    func_8011607C(arg0, 1);
    func_801107F0(arg0, sp58);
    func_80800070_ncbabee(arg0, sp64);
    func_80115444(arg0, &sp48, &sp38);
    temp_f0 = func_80013728(BT_NATIVE_ONLY(((union { s32 i; f32 f; }){ func_800F5AE0(sp28) }).f) BT_IDO_ONLY(func_800F5AE0(sp28)));
    func_80115828(arg0, temp_f0, temp_f0);
    func_800EFB24(sp2C, sp58, sp64);
    func_800F1A88(sp2C, sp3C);
    sp3C[0] = func_80115750(arg0, sp3C[0]);
    sp3C[1] = func_800136E4(func_801112B0(arg0) + 180.0f);
    func_800EEBF0(sp2C, sp3C, sp48);
    func_800EE780(sp58, sp64, sp2C);
    if (func_80111FD4(arg0, sp58) != 0) {
        func_801138F4(arg0);
    }
    func_80112524(arg0, sp64);
    func_80110A68(arg0, sp4C, sp64);
    func_80110790(arg0, sp4C);
}

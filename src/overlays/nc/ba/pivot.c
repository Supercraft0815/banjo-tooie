#include "core2/camera_state_callbacks.h"
#include "nc/ba/pivot.h"

s32 ncbapivot_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbapivot(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbapivot_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(u8 *arg0)) {
    BT_NATIVE_ONLY(u8 * arg0 = (u8 *)camera;)
    BT_NATIVE_ONLY(void func_801120CC(s32 *, f32, f32, f32);) BT_IDO_ONLY(s32 func_801120CC(void *, s32, s32, s32);)
    s32 func_801124D0(BtIntPtr, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    BT_NATIVE_ONLY(void func_80111B8C(s32 *, f32, f32);) BT_IDO_ONLY(s32 func_80111B8C(u8 *, s32, s32);)
    BT_NATIVE_ONLY(func_801120CC((s32 *)arg0, 2000.0f, 4000.0f, -4000.0f);) BT_IDO_ONLY(func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);)
    BT_NATIVE_ONLY(func_80111B8C((s32 *)arg0, 4.0f, 8.0f);) BT_IDO_ONLY(func_80111B8C(arg0, 0x40800000, 0x41000000);)
    func_801124D0((BtIntPtr) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
}

void ncbapivot_entrypoint_2(struct player_state_s *arg0) {
}
/* extern */

void ncbapivot_entrypoint_3(PlayerState *arg0) {
    f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    void func_80111310(s32 *);
    s32 func_80111FD4(void *, f32 *);
    f32 func_801125E8(void *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(void *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(Actor *, f32);
    void func_8011607C(void *, s32);
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;
    f32 sp34[3];
    f32 sp28[3];

    func_8011607C(arg0, 1);
    func_80113978(arg0, 1, 0);
    func_80800008_ncbapivot(arg0, sp6C);
    func_801107F0(arg0, sp48);
    func_800EE7F8(sp28, sp6C);
    if (*(*(s32 **)((s8 *)(arg0) + (0x5C))) != 0) {
        sp40 = _ncbawaypoint_entrypoint_3(arg0, sp28, sp48);
    } else {
        sp40 = 0.0f;
    }
    func_800EFB24(sp54, sp48, sp28);
    sp34[2] = func_800EEF94(sp54) + sp40;
    func_800F1A88(sp54, sp34);
    sp44 = func_80115358(arg0, sp34[2]);
    sp34[0] = func_80115750(arg0, sp34[0]);
    sp34[1] = func_80112C3C(arg0, sp34[1]);
    sp34[1] += func_801125E8(arg0);
    sp44 -= sp40;
    func_800EEBF0(sp54, sp34, sp44);
    func_800EE780(sp48, sp28, sp54);
    if (func_80111FD4(arg0, sp48) != 0) {
        if (func_801138A0(arg0) != 0) {
            if (func_801138F4(arg0) != 0) {
                func_80110F44(arg0);
            }
        } else if (((func_80115580(arg0, sp28) != 0) || (func_80115580(arg0, sp6C) != 0)) && (func_801138F4(arg0) != 0)) {
            func_80110F44(arg0);
        }
    }
    func_80110A68(arg0, sp60, sp6C);
    func_80110790(arg0, sp60);
    if (sp40 != 0.0f) {
        func_80111310(arg0);
    }
}

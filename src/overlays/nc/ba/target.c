#include "core2/camera_state_callbacks.h"
#include "nc/ba/target.h"

s32 ncbatarget_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void func_80800008_ncbatarget(PlayerState *arg0, f32 *arg1) {
    s32 func_800EF174(f32 *, s32 *, s32);
    s32 func_800EFB24(s32 *, void *, f32 *);
    s32 sp1C[3];

    func_80112524(arg0, arg1);
    func_800EFB24(sp1C, (*(void **)((s8 *)(arg0) + (0x58))), arg1);
    func_800EF174(arg1, sp1C, (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x58)))) + (0xC))));
}

void func_80800058_ncbatarget(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}    typedef struct { u8 pad0[0x58]; void * unk58; } Objtarget_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void ncbatarget_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(void *arg0)) {
    BT_NATIVE_ONLY(void * arg0 = (void *)camera;)
    void func_800EFD24(f32 *);
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    void func_801124D0(BtIntPtr, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    void func_8011607C(void *, s32);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0((BtIntPtr) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_800EFD24((((Objtarget_arg0 *)arg0)->unk58));
    (*(f32 *)((s8 *)((((Objtarget_arg0 *)arg0)->unk58)) + (0xC))) = 0.5f;
    func_8011607C(arg0, 1);
}

void ncbatarget_entrypoint_2(struct player_state_s *arg0) {
}
void ncbatarget_entrypoint_3(PlayerState *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    s32 func_800EFB24(s32 *, void *, f32 *);
    void func_800F1A88(f32 *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    s32 func_80111FD4(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    void func_80112D08(void *, s32, f32, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80115358(void *, f32);
    f32 func_80115750(Actor *, f32);
    void func_8011607C(void *, s32);
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp28[2];
    f32 sp24;

    func_8011607C(arg0, 1);
    func_80800058_ncbatarget(arg0, sp58);
    func_80800008_ncbatarget(arg0, sp64);
    func_801107F0(arg0, sp40);
    func_800EFB24(sp4C, sp40, sp58);
    sp30 = func_800EEF94(sp4C);
    func_800F1A88(sp4C, sp28);
    sp30 = func_80115358(arg0, sp30);
    sp28[0] = func_80115750(arg0, sp28[0]);
    func_800F1E6C(*(f32 **)((u8 *)arg0 + 0x58), sp58, &sp24);
    func_80112D08(arg0, 5, sp24, sp24);
    sp28[1] = func_80112C3C(arg0, sp28[1]);
    func_800EEBF0(sp4C, sp28, sp30);
    func_800EE780(sp40, sp58, sp4C);
    if (func_80111FD4(arg0, sp40) && func_801138A0(arg0) && func_801138F4(arg0)) {
        func_80110F44(arg0);
    }
    func_80110A68(arg0, sp34, sp64);
    func_80110790(arg0, sp34);
}

void ncbatarget_entrypoint_4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objtarget_arg0 *)arg0)->unk58 + 12) = arg1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) ncbatarget_entrypoint_5(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32);
    BT_NATIVE_ONLY(return) func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))));
}

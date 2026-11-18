#include "common.h"
typedef struct { f32 position[3]; f32 rotation[3]; s16 letterbox; } FixedCamera;
void* ncfixposrot_entrypoint_0(void) {
    void func_800EFD24(f32 vec[3]);
    void* heap_alloc(s32 size);
    FixedCamera *temp_v0;

    temp_v0 = heap_alloc(sizeof(*temp_v0));
    func_800EFD24(temp_v0->position);
    func_800EFD24(temp_v0->rotation);
    temp_v0->letterbox = 0;
    return temp_v0;
}

void ncfixposrot_entrypoint_1(void* arg0)
{
    heap_free(arg0);
}
/* extern */

void ncfixposrot_entrypoint_2(FixedCamera *arg0, f32 *arg1) {
    f32 func_800136E4(f32);
    BT_IDO_ONLY(s32 func_800F18FC(f32 *, f32 *, f32 *, f32 *);) BT_NATIVE_ONLY(void func_800F18FC(f32 *, f32 *, f32 *);)
    BT_IDO_ONLY(func_800F18FC(arg1, arg0->position, arg0->rotation, arg1);) BT_NATIVE_ONLY(func_800F18FC(arg1, arg0->position, arg0->rotation);)
    arg0->rotation[0] = func_800136E4(-arg0->rotation[0]);
    arg0->rotation[2] = 0.0f;
}

void ncfixposrot_entrypoint_3(FixedCamera *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    arg0->rotation[2] = func_800136E4(arg1);
}

void ncfixposrot_entrypoint_4(FixedCamera *arg0, f32 *arg1) {
    func_800EE7F8(arg0->rotation, arg1);
}

void ncfixposrot_entrypoint_5(BT_PASS2(f32 *bt_a0, f32 *bt_a1))
{
    func_800EE7F8(BT_PASS2(bt_a0, bt_a1));
}

/* extern */

void ncfixposrot_entrypoint_6(FixedCamera *arg0, s32 *arg1) {
    BT_IDO_ONLY(s32 func_8010FE14(s32 *, f32 *, f32 *, s32 *);) BT_NATIVE_ONLY(void func_8010FE14(s32 *, f32 *, f32 *);)
    BT_IDO_ONLY(func_8010FE14(arg1, arg0->position, arg0->rotation, arg1);) BT_NATIVE_ONLY(func_8010FE14(arg1, arg0->position, arg0->rotation);)
}

/* extern */

void ncfixposrot_entrypoint_7(FixedCamera *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(f32 *arg0);
    s32 _cadbfunc_entrypoint_2(f32 *arg0);
    u8 *func_800A5800(s32 id);
    func_800A5800(arg1);
    _cadbfunc_entrypoint_0(arg0->position);
    _cadbfunc_entrypoint_2(arg0->rotation);
}

void ncfixposrot_entrypoint_8(BtIntPtr arg0, s32 arg1) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *arg0);
    func_8010F9C0(arg0, 3);
    ncfixposrot_entrypoint_7((FixedCamera *)func_8011001C((s32 *) arg0), arg1);
}

void ncfixposrot_entrypoint_9(s32 *arg0) {
    s32 func_800C53EC(s32, s32);
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *arg0);
    FixedCamera *sp1C[2];
    FixedCamera *temp_v0;

    temp_v0 = (FixedCamera *)func_8011001C(arg0);
    if (temp_v0->letterbox != 0) {
        sp1C[1] = temp_v0;
        func_800C53EC(0, 0);
        temp_v0 = sp1C[1];
        temp_v0->letterbox = 0;
    }
    func_8010F9C0((BtIntPtr) arg0, 2);
}

/* extern */
void ncfixposrot_entrypoint_10(BtIntPtr arg0, f32 *arg1, f32 *arg2) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *);
    FixedCamera *sp1C;
    func_8010F9C0(arg0, 3);
    sp1C = (FixedCamera *)func_8011001C((s32 *)arg0);
    func_800EE7F8(sp1C->position, arg1);
    func_800EE7F8(sp1C->rotation, arg2);
}

/* extern */
void ncfixposrot_entrypoint_11(BtIntPtr arg0, f32 *arg1, f32 *arg2) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *);
    FixedCamera *sp1C;

    func_8010F9C0(arg0, 3);
    sp1C = (FixedCamera *)func_8011001C((s32 *)arg0);
    func_800EE7F8(sp1C->position, arg1);
    ncfixposrot_entrypoint_2(sp1C, arg2);
}

void ncfixposrot_entrypoint_12(FixedCamera *arg0, f32 *arg1) { func_800EE7F8(arg1, arg0->position); }

void ncfixposrot_entrypoint_13(FixedCamera *arg0, f32 *arg1) {
    func_800EE7F8(arg1, arg0->rotation);
}

/* extern */

void ncfixposrot_entrypoint_14(FixedCamera *arg0) {
    s32 func_800C52F4(s32, s32);
    func_800C52F4(0, 0);
    arg0->letterbox = 1;
}

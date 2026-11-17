#include "common.h"

typedef struct { u8 pad0[0x18]; s16 unk18; } Objfixposrot_ncfixposrot_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ void* ncfixposrot_entrypoint_0(void) {
    void func_800EFD24(f32 vec[3]);
    void* heap_alloc(s32 size);
    f32 *temp_v0;

    temp_v0 = heap_alloc(0x1C);
    func_800EFD24(temp_v0);
    func_800EFD24(temp_v0 + 3);
    (((Objfixposrot_ncfixposrot_entrypoint_0_temp_v0 *)temp_v0)->unk18) = 0;
    return temp_v0;
}

void ncfixposrot_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}                    typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x4]; f32 unk14; s16 unk18; } Objfixposrot_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void ncfixposrot_entrypoint_2(u8 *arg0, s32 arg1) {
    f32 func_800136E4(f32);
    s32 func_800F18FC(BtIntPtr, u8 *, BtIntPtr, s32);
    func_800F18FC(arg1, arg0, arg0 + 0xC, arg1);
    (((Objfixposrot_arg0 *)arg0)->unkC) = func_800136E4(-(((Objfixposrot_arg0 *)arg0)->unkC));
    (((Objfixposrot_arg0 *)arg0)->unk14) = 0.0f;
}

void ncfixposrot_entrypoint_3(void *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (((Objfixposrot_arg0 *)arg0)->unk14) = func_800136E4(arg1);
}

void ncfixposrot_entrypoint_4(f32 *arg0, f32 *arg1) {
    func_800EE7F8(arg0 + 3, arg1);
}

void ncfixposrot_entrypoint_5(BT_PASS2(f32 *bt_a0, f32 *bt_a1))
{
    func_800EE7F8(BT_PASS2(bt_a0, bt_a1));
}

/* extern */

void ncfixposrot_entrypoint_6(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_8010FE14(BtIntPtr, BtIntPtr, BtIntPtr, BtIntPtr);
    func_8010FE14(arg1, arg0, arg0 + 0xC, arg1);
}

/* extern */

void ncfixposrot_entrypoint_7(BtIntPtr arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(f32 *arg0);
    s32 _cadbfunc_entrypoint_2(f32 *arg0);
    u8 *func_800A5800(s32 id);
    func_800A5800(arg1);
    _cadbfunc_entrypoint_0(arg0);
    _cadbfunc_entrypoint_2(arg0 + 0xC);
}

void ncfixposrot_entrypoint_8(BtIntPtr arg0, s32 arg1) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *arg0);
    func_8010F9C0(arg0, 3);
    ncfixposrot_entrypoint_7(func_8011001C((s32 *) arg0), arg1);
}    typedef struct { u8 pad0[0x18]; s16 unk18; } Objfixposrot_ncfixposrot_entrypoint_9_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void ncfixposrot_entrypoint_9(s32 *arg0) {
    s32 func_800C53EC(s32, s32);
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *arg0);
    u8 *sp1C[2];
    u8 *temp_v0;

    temp_v0 = func_8011001C(arg0);
    if ((((Objfixposrot_ncfixposrot_entrypoint_9_temp_v0 *)temp_v0)->unk18) != 0) {
        sp1C[1] = temp_v0;
        func_800C53EC(0, 0);
        temp_v0 = sp1C[1];
        (((Objfixposrot_ncfixposrot_entrypoint_9_temp_v0 *)temp_v0)->unk18) = 0;
    }
    func_8010F9C0((BtIntPtr) arg0, 2);
}

/* extern */
void ncfixposrot_entrypoint_10(BtIntPtr arg0, f32 *arg1, BtIntPtr arg2) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *);
    u8 *sp1C;
    func_8010F9C0(arg0, 3);
    sp1C = (u8 *)func_8011001C((s32 *)arg0);
    func_800EE7F8((f32 *)sp1C, arg1);
    func_800EE7F8((f32 *)(sp1C + 0xC), (f32 *)arg2);
}

/* extern */
void ncfixposrot_entrypoint_11(BtIntPtr arg0, f32 *arg1, s32 arg2) {
    void func_8010F9C0(BtIntPtr, s32);
    BtIntPtr func_8011001C(s32 *);
    u8 *sp1C;

    func_8010F9C0(arg0, 3);
    sp1C = (u8 *)func_8011001C((s32 *)arg0);
    func_800EE7F8((f32 *)sp1C, arg1);
    ncfixposrot_entrypoint_2(sp1C, arg2);
}

void ncfixposrot_entrypoint_12(BtIntPtr arg0, s32 *arg1) { func_800EE7F8(arg1, (s32 *)arg0); }

void ncfixposrot_entrypoint_13(void *arg0, f32 *arg1) {
    func_800EE7F8(arg1, (u8 *)arg0 + 0xC);
}

/* extern */

void ncfixposrot_entrypoint_14(void *arg0) {
    s32 func_800C52F4(s32, s32);
    func_800C52F4(0, 0);
    (((Objfixposrot_arg0 *)arg0)->unk18) = 1;
}

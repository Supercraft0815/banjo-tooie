#include "core2/camera_state_callbacks.h"
#include "common.h"

s32 ncbafixpos_entrypoint_0() 
{
    return 0x1C;
}    typedef struct { u8 pad0[0x20]; u8 * unk20; } Objfixpos_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void ncbafixpos_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(u8 *arg0)) {
    BT_NATIVE_ONLY(u8 * arg0 = (u8 *)camera;)
    void func_801124D0(BtIntPtr arg0, s32 arg1);
    (*(s8 *)((s8 *)((((Objfixpos_arg0 *)arg0)->unk20)) + (0x1A))) = 1;
    func_801124D0((BtIntPtr) arg0, 1);
}

void ncbafixpos_entrypoint_2(struct player_state_s *arg0) {
}
/* extern */

f32 func_8080003C_ncbafixpos(s32 *arg0) {
    BT_IDO_ONLY(f32 func_800F5628(BtIntPtr);) BT_NATIVE_ONLY(s32 func_800F5628(BtIntPtr);)
    f32 func_800F5E7C(BtIntPtr);
    s32 func_800F71D4(BtIntPtr);
    s32 func_80110840(s32 *);
    f32 func_80115460(void *);
    s32 sp1C;
    f32 var_f0;

    sp1C = func_80110840(arg0);
    func_800F5628(sp1C);
    if (func_800F71D4(sp1C) != 0) {
        var_f0 = func_800F5E7C(sp1C);
    } else {
        BT_IDO_ONLY(var_f0 = func_800F5628(sp1C);) BT_NATIVE_ONLY({ union { s32 i; f32 f; } bits; bits.i = func_800F5628(sp1C); var_f0 = bits.f; })
    }
    return func_80115460(arg0) + var_f0;
}

/* extern */

struct player_state_s;
void ncbafixpos_entrypoint_3(struct player_state_s *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80111AE0(struct player_state_s *, f32 *);
    void func_80112524(struct player_state_s *, f32 *);
    s32 func_8011329C(void *arg0);
    f32 func_8080003C_ncbafixpos();
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    u8 *temp_v0;

    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0x1A) == 0) {
        func_801107F0(arg0, sp40);
        func_800EE7F8(sp28, (f32 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0xC));
        sp40[0] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x20));
        sp40[2] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x20) + 8);
        temp_v0 = *(u8 **)((u8 *)arg0 + 0x20);
        if (*(u8 *)(temp_v0 + 0x18) != 0) {
            sp40[1] = *(f32 *)(temp_v0 + 4);
        } else {
            sp40[1] = func_8080003C_ncbafixpos(arg0);
        }
        func_80111AE0(arg0, sp40);
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0x19) != 0) {
            func_8011329C(arg0);
        }
        func_80112524(arg0, sp4C);
        func_80110A68((BtIntPtr)arg0, (BtIntPtr)sp34, (BtIntPtr)sp4C);
        func_80110790((BtIntPtr)arg0, sp34);
    }
}

/* extern */

void ncbafixpos_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    s32 _cadbfunc_entrypoint_4(u8 *);
    BT_NATIVE_ONLY(s32 _cadbfunc_entrypoint_6(f32 *, f32 *);) BT_IDO_ONLY(s32 _cadbfunc_entrypoint_6(s32 *, s32 *);)
    BT_NATIVE_ONLY(s32 _cadbfunc_entrypoint_8(f32 *, f32 *);) BT_IDO_ONLY(s32 _cadbfunc_entrypoint_8(s32 *, s32 *);)
    BT_IDO_ONLY(s32 func_800A5800(s32);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    BT_NATIVE_ONLY(void func_80111B8C(s32 *, f32, f32);) BT_IDO_ONLY(s32 func_80111B8C(u8 *, s32, s32);)
    BT_NATIVE_ONLY(void func_80112570(u8 *, BtIntPtr, f32);) BT_IDO_ONLY(s32 func_80112570(u8 *, u8 *, s32);)
    BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32) sp2C;
    BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32) sp28;
    s32 sp24;

    func_800A5800(arg1);
    _cadbfunc_entrypoint_29(2, &sp24);
    (*(s8 *)((s8 *)((((Objfixpos_arg0 *)arg0)->unk20)) + (0x18))) = (s8) sp24;
    _cadbfunc_entrypoint_29(1, &sp24);
    (*(s8 *)((s8 *)((((Objfixpos_arg0 *)arg0)->unk20)) + (0x19))) = (s8) sp24;
    _cadbfunc_entrypoint_4((((Objfixpos_arg0 *)arg0)->unk20) + 0xC);
    _cadbfunc_entrypoint_0((((Objfixpos_arg0 *)arg0)->unk20));
    _cadbfunc_entrypoint_6(&sp2C, &sp28);
    func_80111B8C(BT_NATIVE_ONLY((s32 *))arg0, sp2C, sp28);
    _cadbfunc_entrypoint_8(&sp2C, &sp28);
    (*(s8 *)((s8 *)((((Objfixpos_arg0 *)arg0)->unk20)) + (0x1A))) = 0;
    func_80112570(arg0, BT_NATIVE_ONLY((BtIntPtr))((((Objfixpos_arg0 *)arg0)->unk20) + 0xC), BT_DATA_FIELD(100.0f, 0x42C80000));
}

#include "common.h"

s32 ncbadolly_entrypoint_0() 
{
    return 0x2C;
}

void ncbadolly_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x21))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbadolly_entrypoint_2(s32 arg0) 
{
}
typedef struct player_state_s PlayerState;

void ncbadolly_entrypoint_3(PlayerState *arg0) {
    f32 func_800EEFFC(void *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, s32, s32);
    void func_80111AE0(void *, f32 *);
    void func_80112524(PlayerState *, f32 *);
    s32 func_8011329C(PlayerState *);
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 pad;
    f32 sp30[3];
    f32 distance;
    u8 *data;
    f32 length;

    if ((*(u8 **)((u8 *)arg0 + 0x1C))[0x21] == 0) {
        func_80112524(arg0, sp64);
        func_801107F0(arg0, sp58);
        func_800EFB24(sp30, sp58, sp64);
        sp30[1] = 0.0f;
        distance = func_800EEFFC(sp30);
        data = *(u8 **)((u8 *)arg0 + 0x1C);
        if (distance < *(f32 *)(data + 0x1C)) {
            distance = *(f32 *)(data + 0x1C);
        }
        if (*(f32 *)(data + 0x18) < distance) {
            distance = *(f32 *)(data + 0x18);
        }
        func_800EFB24(sp40, data, sp64);
        sp40[1] = 0.0f;
        length = func_800EEFFC(sp40);
        if (length < distance) {
            distance = length;
        }
        func_800EFA98(sp30, sp40, distance);
        func_800EF04C(sp30, sp64);
        sp30[1] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x1C) + 4);
        func_80111AE0(arg0, sp30);
        if ((*(u8 **)((u8 *)arg0 + 0x1C))[0x20] != 0) {
            func_8011329C(arg0);
        }
        func_80112524(arg0, sp64);
        func_80110A68((s32)arg0, (s32)sp4C, (s32)sp64);
        func_80110790((s32)arg0, sp4C);
    }
}

/* extern */

void ncbadolly_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_18(u8 *);
    s32 _cadbfunc_entrypoint_20(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    s32 _cadbfunc_entrypoint_4(u8 *);
    s32 _cadbfunc_entrypoint_6(f32 *, f32 *);
    s32 _cadbfunc_entrypoint_8(f32 *, f32 *);
    s32 func_800A5800(s32);
    void func_80111B8C(s32 *, f32, f32);
    void func_80112570(u8 *, s32, f32);
    f32 sp2C;
    f32 sp28;
    s32 sp24;

    func_800A5800(arg1);
    _cadbfunc_entrypoint_29(1, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x20))) = (s8) sp24;
    _cadbfunc_entrypoint_4((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0xC);
    _cadbfunc_entrypoint_0((*(u8 **)((s8 *)(arg0) + (0x1C))));
    _cadbfunc_entrypoint_6(&sp2C, &sp28);
    func_80111B8C((s32 *) arg0, sp2C, sp28);
    _cadbfunc_entrypoint_8(&sp2C, &sp28);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x24))) = sp2C;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x28))) = sp28;
    _cadbfunc_entrypoint_18((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0x1C);
    _cadbfunc_entrypoint_20((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0x18);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x21))) = 0;
    func_80112570(arg0, (s32) ((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0xC), 150.0f);
}

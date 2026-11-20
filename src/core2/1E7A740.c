#include "1E79FD0_types.h"
s32 func_800A0E50()
{
    return 0x14;
}

f32 func_800A0E58(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 8);
}

void func_800A0E64(PlayerState *arg0) {
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    void _fxripple_entrypoint_0(s32 arg0, BtIntPtr arg1);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) _fxsplash25d_entrypoint_0(f32 *);
    BtIntPtr _fxsplash_entrypoint_2(f32 *, f32);
    f32 func_800964DC(PlayerState *);
    s32 func_80096544(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DBF0(PlayerState *arg0, s32 arg1, f32 arg2);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 func_800DC178(f32, f32);

    f32 sp3C[3];
    BtIntPtr temp_s0;
    f32 sp34;

    if (func_80096544(arg0) != 0) {
        func_8009DBF0(arg0, 0x409, func_800DC178(0.65f, 0.75f));
        func_8009C128(arg0, sp3C);
        sp34 = func_800964DC(arg0);
        sp3C[1] = sp34;
        temp_s0 = _fxsplash_entrypoint_2(sp3C, 35.0f);
        _fxripple_entrypoint_0(3, sp3C);
        func_800BA930(temp_s0, -0x15E, 0x12C, -0x15E, 0x15E, 0x1F4, 0x15E);
        func_800BA22C(temp_s0, 0xA);
        func_800BA930(temp_s0, -0x96, 0x1F4, -0x96, 0x96, 0x320, 0x96);
        func_800BA22C(temp_s0, 0xA);
        _fxsplash25d_entrypoint_0(sp3C);
        sp3C[1] -= 30.0f;
        temp_s0 = _fxairbub_entrypoint_1(sp3C, 20.0f, sp34, 1.0f);
        func_800BA930(temp_s0, -0x3C, -0xFA, -0x3C, 0x3C, -0x96, 0x3C);
        func_800BA22C(temp_s0, 8);
    }
}

u32 func_800A0FCC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 2);
}

u32 func_800A0FD8(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 0);
}

u32 func_800A0FE4(void *arg0) {
    return *(u8 *)((u8 *)*&((Obj1E79FD0_arg0 *)arg0)->unk150 + 1);
}

void func_800A0FF0(void *arg0) {
    (*(s8 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (2))) = 1;
    (*(s8 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (0))) = 0;
    (*(s8 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (1))) = 0;
    (*(f32 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (4))) = 50.0f;
    (*(f32 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (8))) = 70.0f;
    (*(f32 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk150)) + (0xC))) = -1.0f;
}    typedef struct { u8 pad0[0x4]; f32 unk4; u8 pad8[0x4]; f32 unkC; } Obj1E79FD0_func_800A1040_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800A1040(PlayerState *arg0) {
    u8 *temp_v0;
    u8 *temp_v0_2;
    f32 *temp_f0;

    temp_v0 = (arg0->unk150);
    (((Obj1E79FD0_func_800A1040_temp_v0 *)temp_v0)->unk4) = (f32) (((Obj1E79FD0_func_800A1040_temp_v0 *)temp_v0)->unkC);
    temp_v0 = (u8 *)(arg0->unk150);
    temp_f0 = (f32 *)temp_v0;
    temp_f0[2] = temp_f0[4];
    (*(f32 *)((s8 *)((arg0->unk150)) + (0xC))) = -1.0f;
}    typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; f32 unkC; f32 unk10; } Obj1E79FD0_func_800A106C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800A106C(PlayerState *arg0, f32 arg1, f32 arg2) {
    void *temp_v0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x150)));
    (((Obj1E79FD0_func_800A106C_temp_v0 *)temp_v0)->unkC) = (f32) (((Obj1E79FD0_func_800A106C_temp_v0 *)temp_v0)->unk4);
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x150)));
    (((Obj1E79FD0_func_800A106C_temp_v0 *)temp_v0)->unk10) = (f32) (((Obj1E79FD0_func_800A106C_temp_v0 *)temp_v0)->unk8);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (4))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (8))) = arg2;
}

/* extern */

void func_800A10A0(PlayerState *arg0) {
    f32 baphysics_get_vertical_velocity(PlayerState *);
    f32 func_800964DC(PlayerState *);
    u32 func_80096518(PlayerState *);
    u32 func_80096524(PlayerState *);
    f32 func_8009C150(PlayerState *);
    s32 func_800F3ED0(void *);
    int player_isStable(PlayerState *);
    f32 sp2C;
    s32 sp28;
    s32 sp24;

    sp28 = (s32) *(arg0->unk150);
    sp2C = func_800964DC(arg0) - (*(f32 *)((s8 *)((arg0->unk150)) + (4)));
    if (sp28 != 0) {
        *(arg0->unk150) = func_80096524(arg0) && func_8009C150(arg0) < sp2C + 2.0f;
    } else {
        *(arg0->unk150) = func_80096524(arg0) && func_8009C150(arg0) < sp2C - 2.0f;
    }
    if ((sp28 == 0) && ((*(u8 *)((s8 *)((arg0->unk150)) + (0))) != 0) && (baphysics_get_vertical_velocity(arg0) < -40.0f)) {
        func_800A0E64(arg0);
    }
    sp24 = func_800F3ED0(arg0);
    if (func_800A0FD8(arg0) != 0) {
        (*(s8 *)((s8 *)((arg0->unk150)) + (1))) = 1;
    } else if ((player_isStable(arg0) != 0) || (sp24 == 0xA) || (sp24 == 5)) {
        (*(s8 *)((s8 *)((arg0->unk150)) + (1))) = 0;
    }
    (*(s8 *)((s8 *)((arg0->unk150)) + (2))) = func_80096518(arg0);
}

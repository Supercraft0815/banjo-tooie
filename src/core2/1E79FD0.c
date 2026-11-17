#include "core2/1E79FD0.h"

s32 func_800A06E0() 
{
    return 0x18;
}

/* extern */

void func_800A06E8(BtIntPtr arg0) {
    s32 func_80092B80();
    void func_800A0714(BtIntPtr, s32);
    func_800A0714(arg0, func_80092B80());
}

void func_800A0714(BtIntPtr arg0, s32 arg1) {
    s32 func_800A940C(s32);
    void func_800DF3E0(void);
    void func_800DF744(s32, s32);
    f32 func_800F1214(f32, f32, f32);
    extern u8 D_80119250[];
    extern u8 D_80119254[];
    s32 value;

    func_800DF3E0();
    switch (arg1) {
    case 0x607:
    case 0x608:
    case 0x61F:
    case 0x992:
        if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x17))) == 0) {
            func_800DF744(9, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x10))));
            func_800DF744(0xF, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x10))));
            func_800DF744(0xA, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xE))));
            func_800DF744(0x10, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xE))));
            func_800DF744(0xB, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xD))));
            func_800DF744(0x11, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xD))));
            value = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xF)));
            func_800DF744(0x22, value);
            func_800DF744(0x26, value);
            func_800DF744(0x23, value);
            func_800DF744(0x27, value);
            value = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x11))) + 1;
            func_800DF744(0x2A, value);
            func_800DF744(0x2E, value);
            func_800DF744(0x2B, value);
            func_800DF744(0x2F, value);
        }
        func_800DF744(3, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x12))));
        func_800DF744(4, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x12))));
        func_800DF744(7, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x12))));
        func_800DF744(0x12, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x12))));
        value = (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0))), 1.0f, 8.0f);
        func_800DF744(0x35, value);
        func_800DF744(0x39, value);
        value = (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 8.0f);
        func_800DF744(0x34, value);
        func_800DF744(0x38, value);
        return;
    case 0x61C:
    case 0x83A:
    case 0x993:
        if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x15))) != 0) {
            func_800DF744(3, 2U);
        } else {
            func_800DF744(3, 1U);
        }
        value = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xF)));
        func_800DF744(6, value);
        func_800DF744(7, value);
        value = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x11))) + 1;
        func_800DF744(4, value);
        func_800DF744(5, value);
        func_800DF744(0x33, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0))), 1.0f, 5.0f));
        func_800DF744(0x32, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 5.0f));
        return;
    case 0x665:
        func_800DF744(4, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x13))));
        func_800DF744(5, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x14))));
        func_800DF744(1, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 4.0f));
        return;
    case 0x60D:
        func_800DF744(1, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0))), 1.0f, 4.0f));
        func_800DF744(2, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 4.0f));
        return;
    case 0x609:
        func_800DF744(0x33, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0))), 1.0f, 4.0f));
        func_800DF744(0x32, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 4.0f));
        return;
    case 0x60B:
    case 0x60C:
    case 0x623:
    case 0x624:
    case 0x626:
    case 0x998:
        func_800DF744(0x33, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0))), 1.0f, 5.0f));
        func_800DF744(0x32, (s32) func_800F1214((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (4))), 1.0f, 5.0f));
        return;
    case 0x988:
        value = *(D_80119250 + func_800A940C((((PlayerState *)arg0)->unk184)));
        func_800DF744(5, value);
        func_800DF744(4, value);
        func_800DF744(3, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x16))));
        return;
    case 0x98D:
        func_800DF744(4, *(D_80119254 + func_800A940C((((PlayerState *)arg0)->unk184))));
        return;
    case 0x984:
    case 0x986:
        func_800DF744(1, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x16))));
        return;
    }
}

s32 func_800A0C20(PlayerState *self)
{
    return (self->unk138)[0x10];
}

f32 func_800A0C2C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 0);
}

f32 func_800A0C38(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 4);
}

void func_800A0C44(PlayerState *arg0) {
    void func_800A0CF4(PlayerState *, s32);
    void func_800A0D74(void *, f32);
    void func_800A0D84(void *, f32);
    void func_800A0DB8(void *, s32);
    void func_800A0DD0(PlayerState *, s32);
    void func_800A0CD0(void *, s32);
    void func_800A0DC4(PlayerState *, s32);

    func_800A0CF4(arg0, 0);
    func_800A0CE8(arg0, 0);
    func_800A0CDC(arg0, 0);
    func_800A0D74(arg0, 0.0f);
    func_800A0D84(arg0, 0.0f);
    func_800A0DB8(arg0, 1);
    func_800A0DD0(arg0, 0);
    func_800A0CD0(arg0, 1);
    func_800A0DC4(arg0, 0);
}

void func_800A0CD0(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 18) = arg1;
}

void func_800A0CDC(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 13) = arg1;
}

void func_800A0CE8(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 14) = arg1;
}

void func_800A0CF4(PlayerState* arg0, s32 arg1) 
{
    func_800A0D14(arg0, arg1, 0.0f);
}

void func_800A0D14(PlayerState *arg0, s32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (8))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xC))) = (s8) arg1;
    if (arg2 == 0.0f) {
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x10))) = (s8) arg1;
    }
}

void func_800A0D44(PlayerState *arg0, s32 arg1) {
    func_800A0D14(arg0, arg1, 0.2f);
}

void func_800A0D68(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 23) = arg1;
}

void func_800A0D74(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 0) = arg1;
}

void func_800A0D84(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 4) = arg1;
}                     typedef struct { u8 pad0[0x138]; void * unk138; u8 pad13C[0x14]; void * unk150; } Obj1E79FD0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_800A0D94(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1E79FD0_arg0 *)arg0)->unk138 + 22) = arg1;
}

s32 func_800A0DA0(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 20) = arg1; BT_NATIVE_ONLY(return 0;)
}

void func_800A0DAC(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 19) = arg1;
}

void func_800A0DB8(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 15) = arg1;
}

void func_800A0DC4(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 21) = arg1;
}

void func_800A0DD0(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 17) = arg1;
}    typedef struct { u8 pad0[0x8]; f32 unk8; u8 unkC; u8 padD[0x3]; u8 unk10; } Obj1E79FD0_func_800A0DDC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A0DDC(void *arg0) {
    f32 func_800D8FF8(void);
    f32 delta;
    void *temp_v0;

    if ((*(f32 *)((s8 *)((((Obj1E79FD0_arg0 *)arg0)->unk138)) + (8))) != 0.0f) {
        delta = func_800D8FF8();
        temp_v0 = (((Obj1E79FD0_arg0 *)arg0)->unk138);
        (((Obj1E79FD0_func_800A0DDC_temp_v0 *)temp_v0)->unk8) -= delta;
        temp_v0 = (((Obj1E79FD0_arg0 *)arg0)->unk138);
        if ((((Obj1E79FD0_func_800A0DDC_temp_v0 *)temp_v0)->unk8) <= 0.0f) {
            (((Obj1E79FD0_func_800A0DDC_temp_v0 *)temp_v0)->unk10) = (u8) (((Obj1E79FD0_func_800A0DDC_temp_v0 *)temp_v0)->unkC);
        }
    }
}

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
    s32 _fxsplash25d_entrypoint_0(f32 *);
    BtIntPtr _fxsplash_entrypoint_2(f32 *, f32);
    f32 func_800964DC(PlayerState *);
    s32 func_80096544(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DBF0(PlayerState *arg0, s32 arg1, f32 arg2);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 func_800DC178(f32, f32);
    extern f32 D_80125490;
    f32 sp3C[3];
    BtIntPtr temp_s0;
    f32 sp34;

    if (func_80096544(arg0) != 0) {
        func_8009DBF0(arg0, 0x409, func_800DC178(D_80125490, 0.75f));
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

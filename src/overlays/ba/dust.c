#include "common.h"

s32 badust_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_badust(BtIntPtr arg0) 
{
}
struct player_state_s;    typedef struct { u8 pad0[0x5C]; void * unk5C; } Objdust_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x9]; u8 unk9; } Objdust_func_80800010_badust_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */
void func_80800010_badust(void *arg0) {
    s32 _batimer_decrement(void *, s32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void func_800A2EEC(struct player_state_s *, s32);
    f32 func_8009BB18(void *);
    s32 badust_entrypoint_4(void *, f32, f32);
    void *temp_v0;
    u8 temp_v1;

    if (_batimer_decrement(arg0, 8) != 0) {
        func_800A2EEC(arg0, 0);
        _batimer_set(arg0, 8, 0.12f);
    }
    temp_v0 = ((Objdust_arg0 *)arg0)->unk5C;
    ((Objdust_func_80800010_badust_temp_v0 *)temp_v0)->unk9 = (((Objdust_func_80800010_badust_temp_v0 *)temp_v0)->unk9 + 1) % 2;
    temp_v1 = *(u8 *)((s8 *)*&((Objdust_arg0 *)arg0)->unk5C + 9);
    switch (temp_v1) {
        case 0:
            badust_entrypoint_4(arg0, (func_8009BB18(arg0) + 180.0f) - 70.0f, 20.0f);
            return;
        case 1:
            badust_entrypoint_4(arg0, (func_8009BB18(arg0) + 180.0f) - 10.0f, 20.0f);
            return;
        case 2:
            badust_entrypoint_4(arg0, func_8009BB18(arg0) + 180.0f + 50.0f, 20.0f);
            return;
    }
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Objdust_badust_entrypoint_1_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void badust_entrypoint_1(void *arg0) {
    s32 badust_entrypoint_4(void *, f32, f32);
    f32 func_800964DC(void *);
    s32 func_80096544();
    f32 func_8009BB18(void *);
    f32 func_8009BB5C(void *);
    f32 func_8009C150(void *);
    f32 sp24;
    void *temp_v0;

    if ((func_80096544() == 0) || (sp24 = func_800964DC(arg0), !(func_8009C150(arg0) < sp24))) {
        temp_v0 = (((Objdust_arg0 *)arg0)->unk5C);
        if ((((Objdust_badust_entrypoint_1_temp_v0 *)temp_v0)->unk4) != 0) {
            (((Objdust_badust_entrypoint_1_temp_v0 *)temp_v0)->unk4) = 0;
        } else {
            (((Objdust_badust_entrypoint_1_temp_v0 *)temp_v0)->unk4) = 1;
        }
        if (func_8009BB5C(arg0) > 100.0f) {
            if ((*(s32 *)((s8 *)((((Objdust_arg0 *)arg0)->unk5C)) + (4))) != 0) {
                badust_entrypoint_4(arg0, func_8009BB18(arg0) - 20.0f, 20.0f);
                return;
            }
            badust_entrypoint_4(arg0, func_8009BB18(arg0) + 20.0f, 20.0f);
        }
    }
}

/* extern */

typedef struct player_state_s PlayerState;
void badust_entrypoint_2(PlayerState *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    BtIntPtr _fxdlsmoke_entrypoint_0(f32 *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA450(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA5BC(void *, f32, f32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 temp_f0;
    s16 temp_f10;
    s16 temp_f18;
    s16 temp_f6;
    BtIntPtr temp_v0;

    temp_v0 = _fxdlsmoke_entrypoint_0(arg1);
    temp_f6 = arg2[0];
    temp_f10 = arg2[1];
    temp_f18 = arg2[2];
    func_800BA930(temp_v0, temp_f6, temp_f10, temp_f18, temp_f6, temp_f10, temp_f18);
    func_800BA450(temp_v0, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(temp_v0, arg3, arg3);
    func_800BA7FC(temp_v0, arg4, arg4);
    func_800BA8F8(temp_v0, arg5, arg5);
    temp_f0 = 19.0f / arg5;
    func_800BA5BC(temp_v0, temp_f0, temp_f0);
    func_800BA22C(temp_v0, 1);
}

/* extern */

void badust_entrypoint_3(PlayerState *arg0, f32 arg1, f32 arg2) {
    void badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    func_8009C128(arg0, sp20);
    sp20[1] += 12.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = 50.0f;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 1.0f);
}

s32 badust_entrypoint_4(void *arg0, f32 arg1, f32 arg2) {
    BtIntPtr _fxdlsmoke_entrypoint_0(f32 *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA450(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA5BC(void *, f32, f32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    BtIntPtr emitter;

    func_800EFA4C(sp34, 0.0f, 40.0f, 0.0f);
    func_8009C128(arg0, sp40);
    func_800EFCD8(sp4C, arg1, arg2);
    sp4C[1] = 15.0f;
    func_800EF04C(sp40, sp4C);
    emitter = _fxdlsmoke_entrypoint_0(sp40);
    func_800BA930(emitter, (s16)sp34[0], (s16)sp34[1], (s16)sp34[2],
                 (s16)sp34[0], (s16)sp34[1], (s16)sp34[2]);
    func_800BA450(emitter, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(emitter, 0.2f, 0.2f);
    func_800BA7FC(emitter, 0.7f, 0.75f);
    func_800BA8F8(emitter, 0.6f, 0.7f);
    func_800BA5BC(emitter, 19.0f, 19.0f);
    func_800BA22C(emitter, 1); BT_NATIVE_ONLY(return emitter;)
}

/* extern */

void badust_entrypoint_5(PlayerState *arg0, f32 arg1, f32 arg2) {
    void badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    func_8009C128(arg0, sp20);
    sp20[1] += 2.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = 50.0f;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 1.0f);
}

/* extern */

void badust_entrypoint_6(PlayerState *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    void badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg3 *= 0.51f;
    func_8009C128(arg0, sp20);
    sp20[1] += 12.0f + arg1;
    func_800EFCD8(sp2C, arg2, arg3);
    sp2C[1] = arg4;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 0.7f);
}

void badust_entrypoint_7(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFCD8(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800136E4(f32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    f32 yaw_get(PlayerState *);
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;

    func_8009C128(arg0, sp50);
    sp50[1] += 20.0f;
    (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 8))++;
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 8) >= 3) {
        *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 8) = 0;
    }
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 8) != 0) {
        sp40 = func_800136E4(yaw_get(arg0) + func_800DC178(70.0f, 90.0f));
        func_800EFCD8(sp44, sp40, func_800DC0C0() * 15.0f + 20.0f);
        sp44[1] = 0.0f;
    }
    switch (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 8)) {
        case 0:
            break;
        case 1:
            func_800EF334(sp44, -1.0f);
            func_800EF04C(sp50, sp44);
            break;
        case 2:
            func_800EF04C(sp50, sp44);
            break;
    }
    func_800EFCD8(sp5C, yaw_get(arg0), 40.0f);
    sp5C[1] = func_800DC178(50.0f, 90.0f);
    badust_entrypoint_2(arg0, sp50, sp5C, func_800DC178(0.4f, 0.5f), func_800DC178(0.7f, 0.9f), func_800DC178(0.8f, 1.3f));
}

void badust_entrypoint_8(struct player_state_s *self) {
    void badust_entrypoint_5(struct player_state_s *, f32, f32);
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        badust_entrypoint_5(self, angle, 230.0f);
    }
}

void badust_entrypoint_9(void *arg0) {
    s32 badust_entrypoint_4(void *, f32, f32);
    f32 func_8009BB18(void *);

    switch (*(s32 *)((u8 *)*&((Objdust_arg0 *)arg0)->unk5C + 4)) {
        case 0:
            badust_entrypoint_4(arg0, func_8009BB18(arg0) - 20.0f, 40.0f);
            break;
        case 1:
            badust_entrypoint_4(arg0, func_8009BB18(arg0) + 20.0f, 40.0f);
            break;
        case 2:
            badust_entrypoint_4(arg0, func_8009BB18(arg0), 30.0f);
            break;
    }
    (*(s32 *)((u8 *)*&((Objdust_arg0 *)arg0)->unk5C + 4))++;
    if (*(s32 *)((u8 *)*&((Objdust_arg0 *)arg0)->unk5C + 4) >= 3) {
        *(s32 *)((u8 *)*&((Objdust_arg0 *)arg0)->unk5C + 4) = 0;
    }
}

/* extern */

void badust_entrypoint_10(PlayerState *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    f32 var_f20;

    for (var_f20 = 0.0f; var_f20 < 359.0f; var_f20 += 60.0f) {
        badust_entrypoint_6(arg0, arg1, var_f20, 730.0f, 100.0f);
    }
    for (var_f20 = 0.0f; var_f20 < 359.0f; var_f20 += 60.0f) {
        badust_entrypoint_6(arg0, arg1, func_800136E4(var_f20 + 30.0f), 430.0f, 40.0f);
    }
}

/* extern */

void badust_entrypoint_11(void *arg0) {
    void badust_entrypoint_12(void *, s32);
    (*(s32 *)((s8 *)((((Objdust_arg0 *)arg0)->unk5C)) + (4))) = 0;
    (*(s8 *)((s8 *)((((Objdust_arg0 *)arg0)->unk5C)) + (8))) = 0;
    (*(s32 *)((s8 *)((((Objdust_arg0 *)arg0)->unk5C)) + (0))) = 0;
    badust_entrypoint_12(arg0, 1);
}

void badust_entrypoint_12(void *arg0, s32 arg1) {
    void func_8009ADF0(void *, s32, s32);
    void _batimer_set(struct player_state_s *, s32, f32);

    **(s32 **)((u8 *)arg0 + 0x5C) = arg1;
    switch (arg1) {
        case 2:
            func_8009ADF0(arg0, 3, 1);
            *((s8 *)*&((Objdust_arg0 *)arg0)->unk5C + 9) = 0;
            _batimer_set(arg0, 8, 0.01f);
            break;
        case 3:
            func_8009ADF0(arg0, 3, 1);
            break;
        case 1:
            func_8009ADF0(arg0, 3, 0);
            break;
    }
}

void badust_entrypoint_13(void *arg0) {
    void func_80800010_badust(void *);

    switch (**(s32 **)((u8 *)arg0 + 0x5C)) {
        case 2:
            func_80800010_badust(arg0);
            break;
        case 3:
            func_80800008_badust(arg0);
            break;
    }
}
/* data_to_c.py: from asm/data/overlays/ba/dust.data.s */
u8 D_80800CB0_badust[16] BT_DATA(4, overlays_ba_dust, 0x0) = { 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00 };

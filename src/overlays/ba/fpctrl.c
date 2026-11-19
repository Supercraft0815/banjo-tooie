#include "common.h"

s32 bafpctrl_entrypoint_0() 
{
    return 0x1C;
}

struct player_state_s;
s32 func_80800008_bafpctrl(void *arg0) {
    typedef struct player_state_s PlayerState;
    int bakey_pressed(PlayerState *, int);
    u32 bafpctrl_entrypoint_4(void *);
    u32 bafpctrl_entrypoint_6(void *);
    int func_8008DF8C(PlayerState *, s32);
    s32 func_8008FD48();
    s32 func_8008FF94();
    s32 player_inWater(PlayerState *);

    if (bakey_pressed(arg0, 0xC) && bafpctrl_entrypoint_6(arg0) && !(*(*(s32 **)((s8 *)arg0 + 0x90)) & 2)) {
        return 1;
    }
    if (player_inWater(arg0)) {
        if (func_8008FD48() == 1 && func_8008FF94() == 0) {
            return 1;
        }
    } else if (func_8008DF8C(arg0, 0x19) == 0) {
        if (bafpctrl_entrypoint_4(arg0) != 1) {
            return 0;
        }
        return 1;
    }
    return 0;
}

/* extern */

void func_808000DC_bafpctrl(void *arg0, f32 arg1, f32 arg2) {
    s32 func_800A4C68(BT_IDO_ONLY(f32) BT_NATIVE_ONLY(void *));
    s32 func_800C51A4(s32, f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x90)))) + (0x18))) = arg2;
    func_800C51A4(func_800A4C68(BT_IDO_ONLY(arg2) BT_NATIVE_ONLY(arg0)), arg1);
}

void func_80800114_bafpctrl(void *arg0) {
    int baflag_isTrue(struct player_state_s *, s32);
    s32 bakey_held(BtIntPtr, s32);
    f32 func_800139F8(f32);
    int func_800C6E38(s32);
    f32 angle;
    f32 scale;

    if (baflag_isTrue(arg0, 0x3A)) {
        return;
    }
    if (baflag_isTrue(arg0, 0x2E)) {
        return;
    }
    if (!func_800C6E38(0x2B)) {
        return;
    }
    angle = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x18);
    if (bakey_held((BtIntPtr)arg0, 0xA) && angle < 40.0f) {
        angle += 1.5f;
    }
    if (bakey_held((BtIntPtr)arg0, 0xD) && angle > 5.21f) {
        angle -= 1.5f;
    }
    scale = 0.3639702201f / func_800139F8(angle * 0.5f);
    func_808000DC_bafpctrl(arg0, scale, angle);
}

/* extern */

typedef struct player_state_s PlayerState;
PlayerState *func_800A4CA8(PlayerState *);
void _ncba1p_entrypoint_7(PlayerState *, f32[3]);

void func_8080022C_bafpctrl(PlayerState *arg0) {
    f32 baroll_get(PlayerState *);
    f32 func_8009BFCC(PlayerState *);
    void func_800F3E84(BtIntPtr, void *);
    f32 yaw_getIdeal(PlayerState *);
    f32 sp24[3];

    func_800F3E84(arg0, sp24);
    sp24[0] = -func_8009BFCC(arg0);
    sp24[1] = yaw_getIdeal(arg0) + 180.0f;
    sp24[2] = -baroll_get(arg0);
    _ncba1p_entrypoint_7(func_800A4CA8(arg0), sp24);
}

void func_808002A4_bafpctrl(PlayerState *arg0) {
    s32 _ncba1p_entrypoint_10();
    void _ncba1p_entrypoint_8(PlayerState *, f32[3]);
    int baflag_isTrue(struct player_state_s *, s32);
    f32 func_800D8FF8(void);
    f32 bafpctrl_entrypoint_3(u8 *);
    f32 bastick_getY(PlayerState *);
    f32 bastick_getX(PlayerState *);
    f32 _bsdronelook_entrypoint_2(f32);
    void yaw_setIdeal(PlayerState *, f32);
    f32 rotation[3];
    f32 delta;
    f32 speed;

    if (_ncba1p_entrypoint_10(func_800A4CA8(arg0)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(arg0), rotation);
        if (!baflag_isTrue(arg0, 0x25)) {
            delta = func_800D8FF8();
            speed = bafpctrl_entrypoint_3((u8 *)arg0) * 90.0f;
            rotation[0] -= bastick_getY(arg0) * speed * delta;
            rotation[1] -= bastick_getX(arg0) * speed * delta;
            rotation[2] = 0.0f;
            rotation[0] = _bsdronelook_entrypoint_2(rotation[0]);
        }
        _ncba1p_entrypoint_7(func_800A4CA8(arg0), rotation);
        yaw_setIdeal(arg0, rotation[1] + 180.0f);
    }
}

void func_808003BC_bafpctrl(PlayerState *arg0) {
    s32 _ncba1p_entrypoint_10();
    void _ncba1p_entrypoint_8(PlayerState *, f32[3]);
    void yaw_setIdeal(PlayerState *, f32);
    f32 sp1C[3];

    if (_ncba1p_entrypoint_10(func_800A4CA8(arg0)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(arg0), sp1C);
        yaw_setIdeal(arg0, sp1C[1] + 180.0f);
    }
}

s32 func_80800424_bafpctrl(PlayerState *arg0, s32 arg1) {
    s32 func_8009E674(PlayerState *, s32);
    s32 func_8009E71C(PlayerState *, s32);
    int func_800C6E38(s32);
    s32 func_8010D930();
    void _baeggaim_entrypoint_1(BtIntPtr arg0);
    void _baeggaim_entrypoint_2(BtIntPtr arg0);
    extern s32 D_808010C0_bafpctrl[4];
    extern s32 D_808010D0_bafpctrl[4];
    s32 old;
    s32 first;
    s32 second;
    s32 neither;
    s32 ability1;
    s32 ability2;
    s32 ability3;
    s32 enabled;

    old = (*(u8 **)((u8 *)arg0 + 0x90))[0x14];
    switch (old) {
        case 0:
            (*(u8 **)((u8 *)arg0 + 0x90))[0x16] = 0;
            break;
        case 2:
            if (arg1 == 1) {
                func_8010D930(0xC, func_8009E674(arg0, 2), 0, D_808010D0_bafpctrl);
            }
            _baeggaim_entrypoint_1(arg0);
            break;
    }
    (*(u8 **)((u8 *)arg0 + 0x90))[0x14] = arg1;
    switch (arg1) {
        case 2:
            if ((*(u8 **)((u8 *)arg0 + 0x90))[0x16]) {
                func_8010D930(0xC, func_8009E674(arg0, 2), 0, D_808010C0_bafpctrl);
            } else {
                (*(u8 **)((u8 *)arg0 + 0x90))[0x16]++;
            }
            _baeggaim_entrypoint_2(arg0);
            break;
        case 1:
            first = func_8009E71C(arg0, 9);
            second = func_8009E71C(arg0, 0xB);
            neither = !first && !second;
            ability1 = func_800C6E38(0x1B);
            ability2 = func_800C6E38(0x1F);
            ability3 = func_800C6E38(0x16);
            enabled = (first && ability1) || (second && ability2) || (neither && ability3);
            if (old == 0 && enabled && !(*(*(s32 **)((u8 *)arg0 + 0x90)) & 4)) {
                (*(u8 **)((u8 *)arg0 + 0x90))[0x15] = 1;
            } else {
                (*(u8 **)((u8 *)arg0 + 0x90))[0x15] = 0;
            }
            break;
    }
BT_NATIVE_ONLY(return 0;) }

/* extern */

void func_808005FC_bafpctrl(BtIntPtr arg0, f32 *arg1) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32[3], f32[3]);
    void func_800F3BD0(void *self, s32 arg1, f32 dst[3]);
    f32 yaw_get(BtIntPtr);
    f32 sp1C[3];

    func_800F3BD0((void *) arg0, 5, arg1);
    func_800EEB9C(sp1C, yaw_get(arg0), 5.0f);
    func_800EF04C(arg1, sp1C);
}

void func_8080064C_bafpctrl(PlayerState *arg0) {
    void baflag_clear(void *self, s32 id);
#if defined(BT_NATIVE) && defined(BT_ILP32)
    s32 func_8009CC68(PlayerState *);
#else
    s32 func_8009CC68();
#endif
    s32 func_8009E674(PlayerState *, s32);
    s32 func_8010D930(s32, s32, BtIntPtr, s32 *);
    void func_80110C2C(PlayerState *self);
    s32 func_80800424_bafpctrl(PlayerState *, s32);
    extern s32 D_808010B0_bafpctrl[4];
#if defined(BT_NATIVE) && defined(BT_ILP32)
    if (func_8009CC68(arg0) == 0) {
#else
    if (func_8009CC68() == 0) {
#endif
        func_8010D930(0xC, func_8009E674(arg0, 2), 0, D_808010B0_bafpctrl);
    }
    func_80110C2C(func_800A4CA8(arg0));
    baflag_clear(arg0, 0x24);
    baflag_clear(arg0, 0x25);
    baflag_clear(arg0, 0x2E);
    baflag_clear(arg0, 0x17);
    baflag_clear(arg0, 0x3A);
    func_80800424_bafpctrl(arg0, 0);
    func_808000DC_bafpctrl(arg0, 1.0f, 40.0f);
}

void func_80800704_bafpctrl(PlayerState *arg0) {
    void _ncba1p_entrypoint_6(f32 **arg0, f32 *arg1);
    void _badrone_entrypoint_33(PlayerState *, f32 *);
    void _ncba1p_entrypoint_12(PlayerState *, f32);
    int baflag_isTrue(struct player_state_s *, s32);
    void baflag_set(PlayerState *, s32);
    void func_80099A7C(PlayerState *, f32 *);
    s32 func_8009E674(PlayerState *, s32);
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800F3E84(BtIntPtr, void *);
    s32 func_8010D930(s32, s32, BtIntPtr, s32 *);
    void func_80110BF0(PlayerState *);
    void yaw_applyIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    extern s32 D_808010A0_bafpctrl[4];
    f32 position[3];
    f32 rotation[3];
    f32 drone[3];

    if (!(*(*(s32 **)((s8 *)arg0 + 0x90)) & 8)) {
        func_8010D930(0xC, func_8009E674(arg0, 2), 0, D_808010A0_bafpctrl);
    }
    func_80110BF0(func_800A4CA8(arg0));
    func_808005FC_bafpctrl((BtIntPtr)arg0, position);
    _ncba1p_entrypoint_6(func_800A4CA8(arg0), position);
    if (baflag_isTrue(arg0, 0x25)) {
        func_80099A7C(arg0, drone);
        _badrone_entrypoint_33(arg0, drone);
        func_800A516C(rotation, drone, position);
    } else {
        func_800F3E84((BtIntPtr)arg0, rotation);
        rotation[0] = 0.0f;
        rotation[2] = 0.0f;
        rotation[1] += 180.0f;
    }
    _ncba1p_entrypoint_7(func_800A4CA8(arg0), rotation);
    yaw_setIdeal(arg0, rotation[1] + 180.0f);
    if (*(*(s32 **)((s8 *)arg0 + 0x90)) & 8) {
        yaw_applyIdeal(arg0);
        _ncba1p_entrypoint_12(func_800A4CA8(arg0), 0.01f);
    }
    baflag_set(arg0, 0x17);
    *((s8 *)*(s32 **)((s8 *)arg0 + 0x90) + 0x14) = 0;
    func_80800424_bafpctrl(arg0, 1);
}

/* extern */

void func_80800880_bafpctrl(u8 *arg0) {
    if ((*(*(s32 **)((s8 *)arg0 + 0x90)) & 1) != 0) {
        _ncba1p_entrypoint_7(func_800A4CA8(arg0), (struct ba_flag_s **)(*(s32 **)((s8 *)arg0 + 0x90) + 1));
    }
}

/* extern */

void func_808008CC_bafpctrl(BtIntPtr arg0) {
    void func_808005FC_bafpctrl(BtIntPtr, f32 *);
    void _ncba1p_entrypoint_6(f32 **arg0, f32 *arg1);
    f32 sp1C[3];

    func_808005FC_bafpctrl(arg0, sp1C);
    _ncba1p_entrypoint_6(func_800A4CA8((void *)arg0), sp1C);
}

int func_80800904_bafpctrl(PlayerState *arg0) {
    int bakey_pressed(PlayerState *, int);
    int func_800C6E38(s32);
    u32 bafpctrl_entrypoint_6(void *);
    return bakey_pressed(arg0, 0xB) && func_800C6E38(0x16)
        && bafpctrl_entrypoint_6(arg0)
        && ((*(*(s32 **)((s8 *)arg0 + 0x90)) & 4) == 0);
}

s32 func_80800970_bafpctrl(PlayerState *arg0) {
    u32 _baeggcursor_entrypoint_2(void *);
    s32 _ncba1p_entrypoint_10();
    f32 _ncba1p_entrypoint_11(PlayerState *);
    int baflag_isTrue(struct player_state_s *, s32);
    u32 bafpctrl_entrypoint_6(void *);
    void func_80094AB4(void *);
    s32 result;

    result = 0;
    switch (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x14)) {
    case 1:
        if (func_80800904_bafpctrl(arg0) || baflag_isTrue(arg0, 0x24)) {
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x15) = 1;
        }
        if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x15)
            && _baeggcursor_entrypoint_2(arg0) == 1
            && _ncba1p_entrypoint_11(func_800A4CA8(arg0)) < 0.25f) {
            func_80800424_bafpctrl(arg0, 2);
        } else if (func_80800008_bafpctrl(arg0)
            && _ncba1p_entrypoint_10(func_800A4CA8(arg0)) == 2) {
            result = 1;
        } else if (bafpctrl_entrypoint_6(arg0)) {
            if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x11)) {
                func_8080022C_bafpctrl(arg0);
            } else {
                func_808002A4_bafpctrl(arg0);
            }
            func_80800880_bafpctrl((u8 *)arg0);
            func_808008CC_bafpctrl((BtIntPtr)arg0);
        }
        break;
    case 2:
        func_80094AB4(arg0);
        if (func_80800904_bafpctrl(arg0) && _baeggcursor_entrypoint_2(arg0) == 2) {
            if (baflag_isTrue(arg0, 0x24)) {
                result = 1;
            } else {
                func_80800424_bafpctrl(arg0, 1);
            }
        } else if (func_80800008_bafpctrl(arg0)) {
            result = 1;
        } else if (bafpctrl_entrypoint_6(arg0)) {
            if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 0x11)) {
                func_8080022C_bafpctrl(arg0);
            } else {
                func_808003BC_bafpctrl(arg0);
            }
            func_808008CC_bafpctrl((BtIntPtr)arg0);
            func_80800880_bafpctrl((u8 *)arg0);
            _baeggaim_entrypoint_3(arg0);
        }
        break;
    }
    func_80800114_bafpctrl(arg0);
    return result;
} typedef struct { u8 pad0[0x90]; union { void * unk90; s32 * unk90_s32p; u8 * unk90_u8p; }; u8 pad94[0xF0]; BtIntPtr unk184; } Objfpctrl_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

u32 bafpctrl_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 17);
}

u32 bafpctrl_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 18);
}

f32 bafpctrl_entrypoint_3(u8 *arg0) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    BT_NATIVE_ONLY(return) func_800F10B4((*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x90)))) + (0x18))), 10.0f, 40.0f, 0.2f, 1.0f);
}

u32 bafpctrl_entrypoint_4(void *arg0) {
    return *(u8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 16);
}

s32 bafpctrl_entrypoint_5(void *arg0) {
    return (*(u8 *)((s8 *)((((Objfpctrl_arg0 *)arg0)->unk90)) + (0x14))) == 2;
}

u32 bafpctrl_entrypoint_6(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 19);
}

void bafpctrl_entrypoint_7(BtIntPtr arg0) 
{
}
void bafpctrl_entrypoint_8(void *arg0) {
    void bafpctrl_entrypoint_9(void *, s32);
    void bafpctrl_entrypoint_10(void *, s32);
    void bafpctrl_entrypoint_13(void *, s32);
    void bafpctrl_entrypoint_14(void *, s32);
    void func_800EFD24(f32 *);

    *(s8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 0x10) = 0;
    bafpctrl_entrypoint_14(arg0, 1);
    func_800EFD24((f32 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 4));
    *(s32 *)*&((Objfpctrl_arg0 *)arg0)->unk90 = 0;
    bafpctrl_entrypoint_9(arg0, 0);
    bafpctrl_entrypoint_10(arg0, 0);
    bafpctrl_entrypoint_13(arg0, 1);
    *(f32 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 0x18) = 40.0f;
}

void bafpctrl_entrypoint_9(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 17) = arg1;
}

void bafpctrl_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objfpctrl_arg0 *)arg0)->unk90 + 18) = arg1;
}

void bafpctrl_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;
    s32 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (((Objfpctrl_arg0 *)arg0)->unk90_s32p);
        *temp_v0 |= arg1;
        return;
    }
    temp_v0_2 = (((Objfpctrl_arg0 *)arg0)->unk90_s32p);
    *temp_v0_2 &= ~arg1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) bafpctrl_entrypoint_12(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, f32 *bt_a1)) {
    BT_IDO_ONLY(s32 func_800EE7F8(s32);) BT_NATIVE_ONLY(void func_800EE7F8(f32 *, f32 *);)
    BT_IDO_ONLY(func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x90))) + 4);) BT_NATIVE_ONLY(func_800EE7F8((f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x90) + 4), bt_a1); return 0;)
}

/* extern */

void bafpctrl_entrypoint_13(void *arg0, s32 arg1) {
    BT_IDO_ONLY(s32 _baeggcursor_entrypoint_6(BT_PASS2(arg0, arg1));) BT_NATIVE_ONLY(void _baeggcursor_entrypoint_6(void *, s32);)
    (*(s8 *)((s8 *)((((Objfpctrl_arg0 *)arg0)->unk90)) + (0x13))) = arg1;
    _baeggcursor_entrypoint_6(BT_PASS2(arg0, arg1));
}    typedef struct { u8 pad0[0x10]; u8 unk10; } Objfpctrl_bafpctrl_entrypoint_14_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void bafpctrl_entrypoint_14(void *arg0, s32 arg1) {
    void func_8009ADF0(void *, s32, s32);
    void func_80800704_bafpctrl(PlayerState *);
    s32 *var_v1;

    var_v1 = *(s32 **)((s8 *)arg0 + 0x90);
    switch (((Objfpctrl_bafpctrl_entrypoint_14_var_v1 *)var_v1)->unk10) {
    case 1:
        if (arg1 == 1) {
            return;
        }
        goto block_6;
    case 3:
        func_8080064C_bafpctrl(arg0);
        var_v1 = *(s32 **)((s8 *)arg0 + 0x90);
    default:
block_6:
        *(s8 *)((s8 *)var_v1 + 0x10) = arg1;
        switch (arg1) {
        case 1:
            bafpctrl_entrypoint_9(arg0, 0);
            bafpctrl_entrypoint_10(arg0, 0);
            **(s32 **)((s8 *)arg0 + 0x90) = 0;
            func_8009ADF0(arg0, 7, 0);
            return;
        case 2:
            func_8009ADF0(arg0, 7, 1);
            return;
        case 3:
            func_8009ADF0(arg0, 7, 1);
            func_80800704_bafpctrl(arg0);
            return;
        }
        break;
    }
}

/* extern */

int func_80800E30_bafpctrl(PlayerState *arg0) {
    s32 _ncba1p_entrypoint_10();
    int bakey_pressed(PlayerState *, int);
    s32 func_800F6774(BtUIntPtr);

    return bakey_pressed(arg0, 0xC) && bafpctrl_entrypoint_6(arg0)
        && func_800F6774(*(u32 *)((s8 *)arg0 + 0x184))
        && _ncba1p_entrypoint_10(func_800A4CA8(arg0)) != 3;
}

void bafpctrl_entrypoint_15(PlayerState *arg0) {
    s32 func_80800970_bafpctrl();
    void bafpctrl_entrypoint_14(void *, s32);

    switch (*(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0x90) + 0x10)) {
    case 2:
        if (func_80800E30_bafpctrl(arg0) != 0) {
            bafpctrl_entrypoint_14(arg0, 3);
            return;
        }
    case 1:
        return;
    case 3:
        if (func_80800970_bafpctrl(arg0) != 0) {
            bafpctrl_entrypoint_14(arg0, 2);
        }
        break;
    }
}    typedef struct { u8 pad0[0x10]; u8 unk10; u8 pad11[0x2]; u8 unk13; } Objfpctrl_bafpctrl_entrypoint_16_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void bafpctrl_entrypoint_16(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1)) {
    void bafpctrl_entrypoint_14();
    void *temp_v0;

    temp_v0 = (((Objfpctrl_arg0 *)arg0)->unk90);
    if (((((Objfpctrl_bafpctrl_entrypoint_16_temp_v0 *)temp_v0)->unk13) != 0) && ((((Objfpctrl_bafpctrl_entrypoint_16_temp_v0 *)temp_v0)->unk10) != 3)) {
#ifdef BT_NATIVE
        bafpctrl_entrypoint_14(arg0, bt_a1);
#else
        bafpctrl_entrypoint_14();
#endif
    }
}

void bafpctrl_entrypoint_17(u8 *arg0) {
    void bafpctrl_entrypoint_14(void *, s32);
    if ((*(u8 *)((s8 *)((((Objfpctrl_arg0 *)arg0)->unk90_u8p)) + (0x13))) != 0) {
        bafpctrl_entrypoint_14(arg0, 1);
    }
}

void bafpctrl_entrypoint_18(void *arg0, s32 arg1) {
    void bafpctrl_entrypoint_14(void *, s32);
    void func_800947EC(struct player_state_s *, s32, s32);
    if (arg1 != 0) {
        bafpctrl_entrypoint_14(arg0, 2);
        bafpctrl_entrypoint_9(arg0, 1);
        bafpctrl_entrypoint_10(arg0, 1);
        func_800947EC(arg0, 1, 1);
        func_800947EC(arg0, 2, 1);
    } else {
        bafpctrl_entrypoint_14(arg0, 1);
        func_800947EC(arg0, 1, 0);
        func_800947EC(arg0, 2, 0);
    }
}

/* extern */

void bafpctrl_entrypoint_19(void *arg0) {
    void _plcamera_entrypoint_0(s32 *arg0);
    void bafpctrl_entrypoint_14(void *, s32);
    void func_8009337C(void *arg0, s32 arg1);
    void func_800A3544(void *arg0, s32 arg1);
    s32 func_800A4EC8(void *);
    if (bafpctrl_entrypoint_4(arg0) == 3) {
        bafpctrl_entrypoint_14(arg0, 1);
        func_800A3544(arg0, 0);
        func_8009337C(arg0, 1);
        func_800A4EC8(arg0);
        _plcamera_entrypoint_0((((Objfpctrl_arg0 *)arg0)->unk184));
    }
}
/* data_to_c.py: from asm/data/overlays/ba/fpctrl.data.s */
s32 D_808010A0_bafpctrl[4] BT_DATA(4, overlays_ba_fpctrl, 0x0) = { 1246343, 655667, 1453792, 0 };
s32 D_808010B0_bafpctrl[4] BT_DATA(4, overlays_ba_fpctrl, 0x10) = { 1246344, 655667, 1453792, 0 };
s32 D_808010C0_bafpctrl[4] BT_DATA(4, overlays_ba_fpctrl, 0x20) = { 1246315, 655718, 1451792, 0 };
s32 D_808010D0_bafpctrl[4] BT_DATA(4, overlays_ba_fpctrl, 0x30) = { 1246316, 655718, 1451792, 0 };

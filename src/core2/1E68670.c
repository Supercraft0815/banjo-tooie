#include "common.h"

s32 func_8008ED80(void)
{
	return 0x1;
}

void func_8008ED88(void *arg0, BtIntPtr arg1, Unk80132ED0 *arg2) {
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 func_8010D5DC;
    Actor *sp1C;

    sp1C = func_80106790(arg2);
    func_800F497C(*(s32 *)((s8 *)arg0 + 0x184));
    func_800F49A8(*(s32 *)((s8 *)arg0 + 0x184), 1);
    func_800F49D4(*(s32 *)((s8 *)arg0 + 0x184), &func_8010D5DC, (BtIntPtr)sp1C->unk0);
    func_800F4A58(*(s32 *)((s8 *)arg0 + 0x184), sp1C->position, 500.0f);
}

s32 func_8008EE04(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        return arg1;
    }
    return 0;
}

struct player_state_s;
typedef struct {
    u8 pad0[0x74];
    BT_BITFIELD_ORDER(u32 pad74_20 : 12, u32 pad74_0 : 16);
    BT_BITFIELD_ORDER(u32 unk74_19 : 1, u32 unk74_16 : 1);
    u32 pad74_17 : 2;
    BT_BITFIELD_ORDER(u32 unk74_16 : 1, u32 unk74_19 : 1);
    BT_BITFIELD_ORDER(u32 pad74_0 : 16, u32 pad74_20 : 12);
} Unk8008EE1C;

s32 func_8008EE1C(Unk8008EE1C *arg0, s32 arg1) {
    s32 bs_getCurrentState(struct player_state_s *);
    struct player_state_s *func_800F53D0(BtIntPtr);

    switch (bs_getCurrentState(func_800F53D0(arg1))) {
        case 15:
            return arg0->unk74_19 == 0;
        case 19:
            return arg0->unk74_16 == 0;
        default:
            return 1;
    }
}

void func_8008EE88(void *arg0, f32 arg1) {
    void func_8009C128(void *, f32[3]);
    void func_8008EEC4(void *, f32 *, f32, s32);
    f32 position[3];

    func_8009C128(arg0, position);
    func_8008EEC4(arg0, position, arg1, 0x270);
}

void func_8008EEC4(void *arg0, f32 *arg1, f32 arg2, s32 arg3) {
    BtIntPtr func_8008E938(void *);
    void func_800CB840(s32 kind, BtIntPtr context);
    void func_800CB870(void);
    void func_80109C4C(BtIntPtr arg0, f32 arg1, s32 arg2, BtIntPtr arg3, s32 arg4, BtIntPtr arg5, s32 arg6);
    func_800CB840(1, (*(s32 *)((s8 *)(arg0) + (0x184))));
    func_80109C4C(arg1, arg2, 2, &func_8008EE1C, (*(s32 *)((s8 *)(arg0) + (0x184))), func_8008E938(arg0), arg3);
    func_800CB870();
}

s32 func_8008EF3C(struct player_state_s *arg0, Unk80132ED0 *arg1) {
    s32 _bstrexlarge_entrypoint_7(struct player_state_s *, f32 *);
    s32 _bstrexsmall_entrypoint_7(struct player_state_s *, f32 *);
    int baflag_isTrue(struct player_state_s *, s32);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    s32 bs_getCurrentState(struct player_state_s *);
    int func_8008DAE8(struct player_state_s *, f32 *, f32);
    int func_8008DC90(struct player_state_s *, f32 *, f32);
    s32 func_8008E92C(void *);
    int func_800A3274(struct player_state_s *);
    Actor *func_80106790(Unk80132ED0 *);
    int player_isStable(struct player_state_s *);
    s32 unused;
    s32 sp20;
    s32 sp1C;
    s32 temp_t8;
    s32 temp_v0;
    s32 temp_v0_2;

    sp20 = bs_getCurrentState(arg0);
    temp_v0_2 = func_800A3274(arg0);
    switch (temp_v0_2) {
    case 2:
        return func_8008EE04(baflag_isTrue(arg0, 0x3C), 9);
    case 13:
        if (sp20 == 0xF7) {
            return func_8008EE04(baflag_isTrue(arg0, 0x2C), 0xF);
        }
        return 0;
    case 14:
        if (sp20 == 0xFC) {
            return func_8008EE04(baflag_isTrue(arg0, 0x2B), 0xE);
        }
        if (sp20 == 0xFB) {
            return func_8008EE04(baflag_isTrue(arg0, 0x2D), 0x10);
        }
        return 0;
    case 15:
        if (sp20 == 0x10E) {
            return func_8008EE04(baflag_isTrue(arg0, 0x32), 0x11);
        }
        return 0;
    case 16:
        return 0x12;
    case 11:
        switch (sp20) {
        case 0xC2:
        case 0xC4:
            return func_8008EE04(baflag_isTrue(arg0, 0x36), 0x15);
        case 0x18A:
        case 0x18B:
            return 0x19;
        default:
            if (baflag_isTrue(arg0, 0x35) != 0) {
                if (arg1 != 0) {
                    if (func_8008DC90(arg0, func_80106790(arg1)->position, 90.0f) != 0) {
                        return 0x14;
                    }
                    return 0;
                }
                return 0x14;
            }
            return 0;
        }
        break;
    case 9:
        sp1C = baflag_isTrue(arg0, 0x3B);
        temp_t8 = func_8008E92C(arg0) == 0;
        if ((sp1C != 0) && (temp_t8 != 0)) {
            return 0x16;
        }
        return 0;
    case 18:
        if ((arg1 != 0) && (_bstrexsmall_entrypoint_7(arg0, func_80106790(arg1)->position) != 0)) {
            return 0x18;
        }
        return 0;
    case 19:
        if ((arg1 != 0) && (_bstrexlarge_entrypoint_7(arg0, func_80106790(arg1)->position) != 0)) {
            return 0x17;
        }
        return 0;
    default:
        if (**(u8 **)((u8 *)arg0 + 0x18) != 0) {
            return 3;
        }
        switch (sp20) {
        case 0x189:
            return func_8008EE04(baflag_isTrue(arg0, 0x3E), 0xD);
        case 0xE4:
            return func_8008EE04(baflag_isTrue(arg0, 0x28), 0xC);
        case 0xA9:
            return 5;
        case 0xB6:
            return func_8008EE04(baflag_isTrue(arg0, 0x22), 0xB);
        case 0xF:
            return func_8008EE04(baflag_isTrue(arg0, 0x21), 1);
        case 0x13:
            return func_8008EE04(baflag_isTrue(arg0, 0x20), 2);
        case 0xB4:
            return func_8008EE04(baflag_isTrue(arg0, 0x20), 2);
        case 0x2A:
            return func_8008EE04(baflag_isTrue(arg0, 0x1C), 3);
        case 0x6:
            if ((arg1 != 0) && (func_8008DAE8(arg0, func_80106790(arg1)->position, 90.0f) == 0)) {
                return 0;
            }
            temp_v0 = func_8008EE04(baflag_isTrue(arg0, 0x1F), 4);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            return 8;
        case 0x11:
            if ((arg1 != 0) && (func_8008DAE8(arg0, func_80106790(arg1)->position, 60.0f) == 0)) {
                return 0;
            }
            return func_8008EE04(baflag_isTrue(arg0, 0x2A), 5);
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0xA4:
        case 0xA5:
            return 6;
        case 0x31:
            return func_8008EE04(baflag_isTrue(arg0, 0x29), 7);
        case 0x5:
        case 0x3D:
            if ((baphysics_get_vertical_velocity(arg0) < 0.0f) && (player_isStable(arg0) == 0)) {
                return 0xA;
            }
        case 0x2F:
            if ((baphysics_get_vertical_velocity(arg0) < -1400.0f) && (player_isStable(arg0) == 0)) {
                return 0xA;
            }
        case 0x124:
            return func_8008EE04(baflag_isTrue(arg0, 0x33), 0x13);
        case 0x18A:
            return 0x19;
        }
        break;
    }
    return 0;
}

/* extern */

s32 func_8008F4F0(struct player_state_s *arg0 BT_PASS2(, s32 bt_a1)) {
    int baflag_isTrue(struct player_state_s *, s32);
    s32 func_8008EF3C();
    s32 result;

#ifdef BT_NATIVE
    result = ((s32 (*)())func_8008EF3C)(arg0 BT_PASS2(, bt_a1));
#else
    result = func_8008EF3C(arg0);
#endif
    if (result == 0xB) {
        if (baflag_isTrue(arg0, 0x26) != 0) {
            return result;
        }
    }
    if (result == 1) {
        if (baflag_isTrue(arg0, 0x27) != 0) {
            return result;
        }
    }
    return 0;
}

/* extern */

s32 func_8008F568(BtIntPtr arg0, s32 arg1, Actor **arg2) {
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    void func_8008E9A0(void *, s32);
    void func_800904C8(s32);
    s32 func_800D1B34(s32);
    s32 func_800D1C38(s32);
    Actor *func_80106790(Unk80132ED0 *);
    Unk80132ED0 *sp24;
    Unk80132ED0 *sp20;
    Actor *sp1C;

    sp24 = (*arg2)->unk0;
    sp20 = _bahold_entrypoint_5(arg0);
    if (sp20 != 0) {
        sp1C = func_80106790(sp20);
    }
    if ((sp20 != 0) && (arg1 != sp1C->unk6C_9)) {
        return 0;
    }
    func_8008E9A0(arg0, arg1);
    if (func_800D1C38(func_800D1B34(arg1)) == 0) {
        func_800904C8(0x12);
    } else {
        return 0;
    }
    *arg2 = func_80106790(sp24);
    return 1;
}

/* extern */

void func_8008F62C(s32 arg0, u32 arg1) {
    void _bahold_entrypoint_6(void *arg0, BtIntPtr arg1);
    void bs_setState();
    void func_80092D44(struct player_state_s *, f32[3]);
    s32 func_8009E674(struct player_state_s *, s32);
    struct player_state_s *func_800F53D0(BtIntPtr);
    Actor *func_80108474(u32, f32 *, s32);
    f32 yaw_get(struct player_state_s *);
    struct player_state_s *temp_v0;
    Actor *temp_v0_2;
    f32 sp24[3];

    temp_v0 = func_800F53D0(arg0);
    func_80092D44(temp_v0, sp24);
    temp_v0_2 = func_80108474(arg1, sp24, (s32) yaw_get(temp_v0));
    temp_v0_2->unk64_23 = 1;
    _bahold_entrypoint_6(temp_v0, temp_v0_2->unk0);
    if (func_8009E674(temp_v0, 0x400) == 0) {
        bs_setState(temp_v0, 0x3A);
    }
}

struct player_state_s {
    u8 pad0[0x184];
    s32 unk184;
};

void func_8008F6B8(struct player_state_s *player, s32 actor_id) {
    Unk80132ED0 *_bahold_entrypoint_5();
    void _bahold_entrypoint_6(void *arg0, BtIntPtr arg1);
    s32 _chbaddiesetup_entrypoint_2(void (*)(s32, u32), s32, s32);
    s32 func_8008E9AC(void *);
    Actor *func_80106790(Unk80132ED0 *);
    Unk80132ED0 *marker;
    Actor *actor;

    marker = _bahold_entrypoint_5(player);
    if (marker) actor = func_80106790(marker);
    if (marker && actor_id == actor->unk6C_9) {
        _bahold_entrypoint_6(player, marker);
        return;
    }
    _chbaddiesetup_entrypoint_2(func_8008F62C, player->unk184, func_8008E9AC(player));
}

/* extern */

void func_8008F748(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(struct player_state_s *) arg0, s32 arg1, BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(Actor *) arg2) {
    void *_gccubesearch_entrypoint_0(s32 actor_id, Actor *actor);
    void _gspropctrl_entrypoint_11(void *arg0, void *arg1);
    BT_IDO_ONLY(s32 func_800A3514(s32, s32 *);) BT_NATIVE_ONLY(void func_800A3514(struct player_state_s *, f32 *);)
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32) sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(arg1, arg2), sp1C);
    func_800A3514(arg0, sp1C);
}

/* extern */

void func_8008F788(s32 arg0, s32 arg1) {
    void func_800D1844(s32 arg0);
    s32 func_800D1B34(s32);
    func_800D1844(func_800D1B34(arg1));
}

void func_8008F7B4(s32 player, s32 actor_id) {
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    Actor *func_80106790(Unk80132ED0 *);
    void _bahold_entrypoint_4(BtIntPtr arg0);
    s32 func_800D1B34(s32);
    void func_800D1804(s32 arg0);
    Unk80132ED0 *marker;
    Actor *actor;
    marker = _bahold_entrypoint_5(player);
    if (marker) actor = func_80106790(marker);
    if (marker && actor->unk6C_9 == actor_id) _bahold_entrypoint_4(player);
    func_800D1804(func_800D1B34(actor_id));
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_8008F828(s32 arg0, s32 arg1) {
    s32 func_800D1A04(s32);
    s32 func_800D1B34(s32);
    BT_NATIVE_ONLY(return) func_800D1A04(func_800D1B34(arg1));
}

/* extern */

void func_8008F854(s32 arg0, s32 arg1) {
    void func_800D1824(s32 arg0);
    s32 func_800D1B34(s32);
    func_800D1824(func_800D1B34(arg1));
}

void func_8008F880(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    func_800EE7F8(arg1, &(func_80106790(arg0))->position[0]);
}

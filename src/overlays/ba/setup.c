#ifdef BT_NATIVE
#include "core2/1ECD170.h"
#endif
#include "common.h"

s32 basetup_entrypoint_0() 
{
    return 0x4;
}

/* extern */

void func_80800008_basetup(BtIntPtr arg0) {
    void func_800A0FF0(void *arg0);
    s32 func_800DA298(s32);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    s32 func_800EA090();
    s32 sp1C;
    s32 sp18;

    sp1C = func_800EA05C();
    sp18 = func_800EA090();
    if ((func_800DB9B0() == 0) && (((sp1C == 0x13A) && (sp18 == 0xE)) || ((sp1C == 0x136) && (sp18 == 0x1B))) && (func_800DA298(0x327) != 0)) {
        func_800A0FF0(arg0);
    }
}

struct player_state_s;
void func_80800080_basetup(struct player_state_s *self) {
    s32 _bashoes_entrypoint_1(struct player_state_s *);
    int _bashoes_entrypoint_6(void *arg0, s32 arg1);
    int func_800A3274(struct player_state_s *);
    s32 func_800F40EC(struct player_state_s *);
    s32 shoes;

    shoes = _bashoes_entrypoint_1(self);
    if (func_800F40EC(self) != 0) {
        switch (func_800A3274(self)) {
        case 1:
            if ((shoes == 2) || (shoes == 3) || (shoes == 4) || (shoes == 5)) {
                _bashoes_entrypoint_6(self, 1);
                return;
            }
            break;
        case 11:
            if ((shoes == 3) || (shoes == 4) || (shoes == 5)) {
                _bashoes_entrypoint_6(self, 2);
            }
            break;
        }
    }
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objsetup_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800140_basetup(void *arg0) {
    void *func_800C6A7C(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 flags);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 sp24[3];
    s32 sp18[3];

    func_800EE7F8(sp18, arg0);
    (((Objsetup_arg0 *)arg0)->unk4) = (f32) ((((Objsetup_arg0 *)arg0)->unk4) - 1000.0f);
    func_800C6A7C(sp18, arg0, sp24, 0x420025);
}

/* extern */

struct player_state_s;

void func_80800194_basetup(struct player_state_s *self, void *arg1, void *arg2) {
    int func_800A3274(struct player_state_s *);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    s32 func_800EA090(void);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800A3274(self);
    sp20 = func_800EA05C();
    sp1C = func_800EA090();
    if ((func_800DB9B0() == 0) && (((sp20 == 0x112) && (sp1C == 0xF)) || ((sp20 == 0x116) && (sp1C == 2))) && (sp24 == 0x12)) {
        func_80800140_basetup(arg1);
        func_80800140_basetup(arg2);
    }
}

void basetup_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _badata_entrypoint_35(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    u32 func_8009E958(void);
    void func_800A3544(void *, s32);
    int func_800C6E38(s32);
    s32 func_800EA068(s32);
    struct player_state_s *func_800F53D0(BtIntPtr);
    struct player_state_s *self;
    s32 pad28;
    s32 flag;
    s32 pad20;
    struct player_state_s *player;
    u32 mode;
    s32 state;

    player = func_800F53D0(arg1);
    self = player;
    state = _badata_entrypoint_35(player);
    flag = func_800EA068(8);
    mode = func_8009E958();
    switch (mode) {
        case 1:
            if (flag != 0 && func_800C6E38(0x15) != 0) {
                state = 0xC8;
            }
            break;
        case 9:
            if (flag != 0) {
                state = 0xCB;
            } else {
                state = 0xC9;
            }
            break;
    }
    func_800A3544(self, 0);
    bs_setState(self, state);
}

/* extern */

void func_808002D4_basetup(BtIntPtr arg0) {
    s32 _badata_entrypoint_33(BtIntPtr);
    s32 _badata_entrypoint_35(BtIntPtr);
    void bastatetimer_set(void *self, s32 id, f32 arg2);
    void bs_setState(void *self, s32 nextState);
    f32 func_8009E97C();
    f32 func_8009E988();
    u8 func_8009EA20(void);
    s32 func_8009EA64();
    void func_80800080_basetup(struct player_state_s *);
    bastatetimer_set(arg0, 2, func_8009E97C());
    bastatetimer_set(arg0, 3, func_8009E988());
    if (func_8009EA64() != 0) {
        bs_setState(arg0, _badata_entrypoint_33(arg0));
    } else if (func_8009EA20() != 0) {
        bs_setState(arg0, 0x11E);
    } else {
        func_80800008_basetup(arg0);
        bs_setState(arg0, _badata_entrypoint_35(arg0));
    }
    func_80800080_basetup(arg0);
}

void func_80800394_basetup(struct player_state_s *self) {
    int func_800A3274(struct player_state_s *);
    s32 func_8008DAA8(void *);
    s32 func_8008E23C(struct player_state_s *);
    void func_800F457C(void *, s32);
    u32 func_800F54E4(void);
    s32 _badrone_entrypoint_29(struct player_state_s *);
    s32 bs_getCurrentState(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F8128(s32);
    u8 func_800F8B88(void);
    void func_800F8D50(s32, s32);
    s32 func_800F8DA8();
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 state;
    s32 flag;

    sp34 = func_800F8B88() == 3;
    sp30 = func_8008DAA8(self);
    sp2C = func_800A3274(self);
    state = bs_getCurrentState(self);
    sp28 = state == 0;
    sp20 = state == 0;
    if (sp30 != 0) {
        if (sp28) {
            func_808002D4_basetup(self);
        }
    } else if (sp20) {
        func_808002D4_basetup(self);
    }
    if (sp30 == 0) {
        sp24 = func_800A3274(self);
        if (func_800F64A4(func_800F54E4(), 0x10000)) {
            if (func_8008E23C(self) && sp24 == 0xA) {
                func_800F457C(self, 2);
            } else {
                bs_setState(self, _badrone_entrypoint_29(self));
            }
        } else if (sp34) {
            bs_setState(self, 0xED);
        } else {
            func_800F457C(self, 2);
        }
        if (func_800F8DA8(sp24)) {
            func_800F8D50(*(s32 *)((u8 *)self + 0x184), sp24);
        }
    } else {
        flag = 0;
        switch (sp2C) {
            case 11:
                if (sp34) {
                    flag = 1;
                }
                break;
            case 14:
            case 17:
                flag = 1;
                break;
        }
        if (flag) {
            func_800F8128(*(s32 *)((u8 *)self + 0x184));
        }
    }
}

s32 func_80800534_basetup(struct player_state_s *arg0) {
    u8 _glcutDll_entrypoint_1(void);
    void _plcamera_entrypoint_13(s32, f32);
    s32 func_8008DAA8(void *);
    s32 func_8008E23C(struct player_state_s *);
    s32 func_8009EA64(void);
    int func_800A3274(struct player_state_s *);
    s32 func_800DB9B0();
    BT_IDO_ONLY(void func_800F452C();)
    s32 func_800F89E4(s32, f32 *);
    f32 func_800F8A50(void);
    u8 func_800F8B7C(void);
    s32 func_800F99E8(void);
    s32 func_800F99FC(void);
    void yaw_applyIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 sp2C[3];

    if ((func_800DB9B0() != 0) || (_glcutDll_entrypoint_1() != 0)) {
        func_80800394_basetup(arg0);
        return 1;
    }
    if (func_8008DAA8(arg0) == 0) {
        func_80800394_basetup(arg0);
        if ((func_800F99FC() == 0) && (func_800F99E8() == 0) && (func_800F8B7C() != 0) && (func_8008E23C(arg0) != 0)) {
            _plcamera_entrypoint_13(*(s32 *)((u8 *)arg0 + 0x184), func_800F8A50());
        }
        return 1;
    }
    if (func_800F99FC() != 0) {
        if (func_800A3274(arg0) == 0xA) {
            func_808002D4_basetup((BtIntPtr)arg0);
        }
        return 1;
    }
    if (func_800F99E8() != 0) {
        func_80800394_basetup(arg0);
        return 1;
    }
    if ((func_800F8B7C() != 0) && (func_8008E23C(arg0) != 0)) {
        func_800F89E4(func_800A3274(arg0), sp2C);
        func_800F452C(arg0, sp2C);
        yaw_setIdeal(arg0, func_800F8A50());
        yaw_applyIdeal(arg0);
        _plcamera_entrypoint_13(*(s32 *)((u8 *)arg0 + 0x184), func_800F8A50());
        func_80800394_basetup(arg0);
        return 1;
    }
    if (func_8009EA64() != 0) {
        func_80800394_basetup(arg0);
        return 1;
    }
    return 0;
}

/* extern */

#ifdef BT_NATIVE
Prop *func_808006F0_basetup(s32 bt_a0) {
#else
Prop *func_808006F0_basetup() {
#endif
    void *_gccubesearch_entrypoint_14(s32 actor_id, s32 *position);
    s32 _gemarkersDll_entrypoint_1();
    BT_NATIVE_ONLY(return) _gccubesearch_entrypoint_14(_gemarkersDll_entrypoint_1(), 0);
}

Prop *func_8080071C_basetup(s32 arg0) {
    void *_gccubesearch_entrypoint_14(s32 actor_id, s32 *position);
    s32 func_800A9C98(void);
    s32 id = 0x52;

    if (func_800A9C98() != 0) {
        return NULL;
    }
    if ((arg0 > 0) && (arg0 < 0x29)) {
        id = arg0 + 0x52;
    }
    return _gccubesearch_entrypoint_14(id, 0);
}

/* extern */

s32 func_80800778_basetup(BtIntPtr arg0) {
    u32 func_8009E958(void);
    void func_8009E9D8(s32);
    void func_8009EB18(s32);
    int func_800C6E38(s32);
    s32 func_800EA05C();
    s32 func_800EA068(s32);
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    temp_v0 = func_8009E958();
    var_s0 = temp_v0;
    if (temp_v0 != 1) {
        if ((temp_v0 == 9) && (func_800EA05C() == 0x116)) {
            var_s0 = 1;
            func_8009EB18(0);
        }
    } else if ((func_800EA068(8) != 0) && (func_800C6E38(0x15) != 0)) {
        var_s0 = 9;
    }
    if (func_800EA068(0x40) != 0) {
        temp_v0_2 = func_800EA05C();
        switch (temp_v0_2) {
            case 0x182:
                var_s0 = 0xC;
                break;
            case 0x188:
                var_s0 = 6;
                break;
            default:
                var_s0 = 9;
                break;
        }
        func_8009E9D8(var_s0);
    }
    return var_s0;
}

void basetup_entrypoint_2(struct player_state_s *arg0) {
    extern u8 D_8012762C;
#ifndef BT_NATIVE
    void _basetup_entrypoint_1(s32);
#endif
    int _bashoes_entrypoint_6(void *arg0, s32 arg1);
    s32 _gclevel_entrypoint_4(s32);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _gspropctrl_entrypoint_13(Prop *);
    s32 _sudeathmatch_entrypoint_0(BtIntPtr, f32 *, f32 *);
    void func_80092778(struct player_state_s *);
    u32 func_8009E958(void);
    u32 func_8009E994(void);
    u32 func_8009EA4C(void);
    void func_8009EAD0(s32);
    void func_8009EB0C(f32);
    int func_800A3274(struct player_state_s *);
    void func_800A3410(struct player_state_s *, s32);
    void func_800A3544(void *, s32);
    int func_800C6E38(s32);
    s32 func_800EA068(s32);
    s32 func_800EA090(void);
    void func_800F44DC(void *, s32);
    BT_IDO_ONLY(void func_800F452C(struct player_state_s *, f32 *);)
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A8C(BtIntPtr, f32 *, f32);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    Prop *sp64;
    Prop *sp60;
    s32 sp5C;
    f32 sp50[3];
    f32 sp4C;
    f32 sp40[3];
    s32 sp3C;
    s32 pad38;
    f32 sp2C[3];
    f32 sp28;
    s32 var_a1;

    if ((func_800A3274(arg0) == 4) || (_gclevel_entrypoint_4(1) != 0)) {
        func_800F44DC(arg0, 0);
        return;
    }
    if (func_80800534_basetup(arg0) == 0) {
        sp5C = func_800EA090();
        sp64 = func_808006F0_basetup(sp5C);
        if (sp64 != NULL) {
            sp60 = func_8080071C_basetup(sp5C);
        } else {
            if (_sudeathmatch_entrypoint_0(*(s32 *)((u8 *)arg0 + 0x184), sp50, sp40) != 0) {
                sp4C = sp40[1];
            } else if (sp64 == NULL) {
                func_800F44DC(arg0, 0);
                return;
            }
            sp60 = NULL;
        }
        sp3C = func_80800778_basetup((BtIntPtr)arg0);
        if (sp3C == 9) {
            _bashoes_entrypoint_6(arg0, 1);
            func_8009EB0C(0.0f);
            if ((sp60 != NULL) && (func_8009E994() == 0)) {
                sp3C = func_8009E958();
            } else {
                var_a1 = D_8012762C == 0x1B ? 1 : 0;
                func_800A3544(arg0, var_a1);
            }
        }
        func_800A3410(arg0, sp3C);
        func_80092778(arg0);
        func_800F44DC(arg0, 0);
        if (sp64 != NULL) {
            _gspropctrl_entrypoint_11(sp64, sp50);
            sp4C = _gspropctrl_entrypoint_12(sp64);
        }
        func_800F44DC(arg0, 1);
        **(s32 **)((u8 *)arg0 + 0x100) = -1;
        if (func_8009EA4C() == 2) {
            if ((func_800EA068(8) != 0) && (func_800C6E38(0x15) != 0)) {
                func_8009EAD0(1);
            } else {
                sp4C += 180.0f;
            }
        }
        yaw_setIdeal(arg0, sp4C);
        yaw_applyIdeal(arg0);
        if (sp60 != NULL) {
            sp28 = 1.0f;
            if (func_800EA068(4) != 0) {
                sp28 = _gspropctrl_entrypoint_13(sp60) * 0.1f;
            }
            _gspropctrl_entrypoint_11(sp60, sp2C);
            func_80800194_basetup(arg0, sp2C, sp50);
            func_800F452C(arg0, sp2C);
            func_808002D4_basetup((BtIntPtr)arg0);
            func_800F497C(*(s32 *)((u8 *)arg0 + 0x184));
            func_800F49D4(*(s32 *)((u8 *)arg0 + 0x184), _basetup_entrypoint_1, *(s32 *)((u8 *)arg0 + 0x184));
            func_800F4A8C(*(s32 *)((u8 *)arg0 + 0x184), sp50, sp28);
            return;
        }
        func_800F452C(arg0, sp50);
        func_808002D4_basetup((BtIntPtr)arg0);
    }
}

void basetup_entrypoint_3(BtIntPtr arg0) 
{
}
void basetup_entrypoint_4(BtIntPtr arg0) 
{
}

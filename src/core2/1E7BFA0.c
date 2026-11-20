#include "core2/1E7BFA0.h"
#ifdef BT_NATIVE
#include "core2/anctrl.h"
AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
#endif
#include "player_contact_vectors.inc"
s32 func_800A26B0() 
{
    return 0xC;
}

void func_800A26B8(PlayerState *arg0) {
    BtIntPtr _fxsplash_entrypoint_2(f32[3], f32);
    void func_80095870(void *, f32 *, f32 *);
    f32 func_800964DC(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009FC34(PlayerState *, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, BT_NATIVE_ONLY(s16) BT_IDO_ONLY(s32)[]);
    BT_IDO_ONLY(extern s32 D_80119320[];)
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    func_8009C128(arg0, sp34);
    sp30 = func_800964DC(arg0);
    func_80095870(arg0, &sp2C, &sp28);
    if (!((sp2C + sp28) < (sp30 - sp34[1]))) {
        sp34[1] = sp30;
        func_8009FC34(arg0, 1);
        func_800BABB8(_fxsplash_entrypoint_2(sp34, 25.0f), 0, 0, 1.0f, BT_DATA_FIELD(player_form_data.splash_commands, D_80119320));
    }
}

/* extern */

void func_800A275C(PlayerState *arg0, s32 arg1) {
    BtIntPtr _fxsplash_entrypoint_2(f32[3], f32);
    void func_8008FE94(s32, f32 *);
    f32 func_800964DC(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009FC34(PlayerState *, s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 sp34[3];
    f32 sp30;
    BtIntPtr sp2C;

    func_8009FC34(arg0, 2);
    sp30 = func_800F10B4(func_8009BB5C(arg0), 0.0f, 500.0f, 70.0f, 250.0f);
    func_8008FE94((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x124)))) + (4))), sp34);
    if (arg1 == 0) {
        sp34[1] = func_800964DC(arg0);
    }
    sp2C = _fxsplash_entrypoint_2(sp34, 8.0f);
    func_800BA930(sp2C, (s16) -sp30, 0x12C, (s16) -sp30, (s16) sp30, 0x15E, (s16) sp30);
    func_800BA22C(sp2C, 5);
}

void func_800A2848(BtIntPtr arg0, s32 arg1, s32 arg2) {
    PlayerState *func_800F53D0(BtIntPtr);
    s32 player_inWater(PlayerState *);
    TransformationId func_8008FD48();
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void _bashake_entrypoint_0(struct player_state_s *arg0, s32 arg1, s32 arg2);
    s32 _bashoes_entrypoint_1(PlayerState *);
    s32 func_8009E674(PlayerState *, s32);
    void _fxstep_entrypoint_13(u8 *arg0, s32 arg1);
    s32 shoes;
    s32 water;
    s32 splash;
    PlayerState *player;

    player = func_800F53D0(arg2);
    splash = arg1 == 4 || arg1 == 11 || (s32)(arg1 == 21);
    water = player_inWater(player);
    if (splash) {
        func_800A275C(player, arg1 == 21);
    }
    switch (func_8008FD48()) {
        default:
            return;
        case 15:
            if (splash || water) {
                _fxstep_entrypoint_13(arg0, 14);
            } else {
                func_8009DB04(player, 0x448, 1.0f, 5000);
            }
            break;
        case 14:
            _bashake_entrypoint_0(player, 0, 0);
            _fxstep_entrypoint_13(arg0, 19);
            if (arg1 == 20) {
                _fxstep_entrypoint_13(arg0, 20);
            }
            break;
        case 19:
            _bashake_entrypoint_0(player, 0, 0);
            _fxstep_entrypoint_13(arg0, 22);
            break;
        case 1:
        case 11:
            if (func_8009E674(player, 0x80)) {
                shoes = _bashoes_entrypoint_1(player);
                switch (shoes) {
                    case 4:
                        _fxstep_entrypoint_13(arg0, 23);
                        break;
                    case 5:
                        _fxstep_entrypoint_13(arg0, 26);
                        break;
                }
            }
            break;
    }
}

void func_800A2A00(BtIntPtr arg0, s32 arg1, s32 arg2) {
    PlayerState *func_800F53D0(BtIntPtr);
    s32 player_inWater(PlayerState *);
    TransformationId func_8008FD48();
    f32 _basnowball_entrypoint_5(PlayerState *);
    void _basnowball_entrypoint_10(PlayerState *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void func_8009DBF0(PlayerState *, s32, f32);
    void func_8009DC98(PlayerState *, s32, f32, f32);
    void _bashake_entrypoint_0(struct player_state_s *arg0, s32 arg1, s32 arg2);
    void _fxstep_entrypoint_10(BtIntPtr, s32);
    void _fxstep_entrypoint_13(u8 *arg0, s32 arg1);
    void _bsvan_entrypoint_2(PlayerState *);
    void _bswasher_entrypoint_0(PlayerState *);
    s32 func_8009E674(PlayerState *, s32);
    s32 _bashoes_entrypoint_1(PlayerState *);
    PlayerState *self;
    s32 inWater;
    f32 sp34;
    s32 pad[2];
    f32 sp30;
    s32 sp2C;

    self = func_800F53D0(arg2);
    inWater = arg1 == 4 || arg1 == 11 || player_inWater(self);
    if (inWater) {
        func_800A26B8(self);
    }
    switch (func_8008FD48()) {
        case 2:
            sp34 = _basnowball_entrypoint_5(self);
            _basnowball_entrypoint_10(self);
            sp30 = func_800F10B4(sp34, 0.0f, 1.0f, 1.5f, 0.85f);
            sp2C = func_800F10B4(sp34, 0.0f, 1.0f, 8000.0f, 32767.0f);
            func_8009DB04(self, 0x56E, sp30, sp2C);
            if (sp34 == 1.0f) {
                _bashake_entrypoint_0(self, 1, 2);
            }
            break;
        case 14:
            _fxstep_entrypoint_10(arg0, 0x13);
            if (arg1 == 0x14) {
                _fxstep_entrypoint_13(arg0, 0x14);
            }
            _bashake_entrypoint_0(self, 3, 3);
            break;
        case 19:
            _fxstep_entrypoint_10(arg0, 0x16);
            _bashake_entrypoint_0(self, 3, 3);
            break;
        case 18:
            _bashake_entrypoint_0(self, 1, 2);
            break;
        case 16:
            func_8009DBF0(self, 0x4C7, 1.3f);
            _bashake_entrypoint_0(self, 1, 2);
            _bsvan_entrypoint_2(self);
            break;
        case 7:
            func_8009DC98(self, 0x4C1, 0.9f, 0.92f);
            _bashake_entrypoint_0(self, 1, 2);
            _bswasher_entrypoint_0(self);
            break;
        case 1:
        case 11:
            if (func_8009E674(self, 0x80)) {
                switch (_bashoes_entrypoint_1(self)) {
                    case 4:
                        _fxstep_entrypoint_10(arg0, 0x17);
                        break;
                    case 5:
                        _fxstep_entrypoint_10(arg0, 0x1A);
                        break;
                }
            }
            break;
    }
}

s32 func_800A2C84(PlayerState *arg0) {
    f32 func_800964DC(PlayerState *);
    s32 func_80096628(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    s32 _fxstep_entrypoint_5(s32, s32, f32);
    void _fxstep_entrypoint_6(BtIntPtr effect, f32 position[3]);
    f32 sp2C[3];
    s32 pad;
    s32 sp24;

    func_8009C128(arg0, sp2C);
    _fxstep_entrypoint_6(*(arg0->unk124), sp2C);
    sp24 = func_80096628(arg0);
    pad = 0;
    return _fxstep_entrypoint_5(*(arg0->unk124), sp24, func_800964DC(arg0)) + pad;
}

/* extern */

void func_800A2CE8(PlayerState *arg0, f32 arg1, s32 arg2) {
    BT_IDO_ONLY(s32 anctrl_isAt(BtIntPtr, f32);)
    BT_IDO_ONLY(s32 baanim_getAnimCtrlPtr();)
    void func_800A2EEC(PlayerState *, s32);
    if (anctrl_isAt(baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(arg0)), arg1) != 0) {
        func_800A2EEC(arg0, arg2);
    }
}

/* extern */

void func_800A2D2C(PlayerState *arg0, f32 arg1, s32 arg2) {
    BT_IDO_ONLY(s32 anctrl_isAt(BtIntPtr, f32);)
    BT_IDO_ONLY(s32 baanim_getAnimCtrlPtr();)
    s32 func_800A2FCC(PlayerState *, s32);
    if (anctrl_isAt(baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(arg0)), arg1) != 0) {
        func_800A2FCC(arg0, arg2);
    }
}    typedef struct { u8 pad0[0xA0]; void * unkA0; u8 padA4[0x80]; s32 * unk124; u8 pad128[0x5C]; s32 unk184; } Obj1E7BFA0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800A2D70(void *arg0) {
    void _fxstep_entrypoint_0(void *arg0);
    _fxstep_entrypoint_0(*(((Obj1E7BFA0_arg0 *)arg0)->unk124));
}

void func_800A2D94(void *arg0) {
    void *_fxstep_entrypoint_1(void);
    void _fxstep_entrypoint_3(s8 *arg0, s32 arg1);
    void _fxstep_entrypoint_4(void *arg0, BtIntPtr arg1, s32 arg2);
    void _fxstep_entrypoint_7(void *arg0, BtIntPtr arg1, s32 arg2);
    void func_800A2EDC(void *, f32);
    s32 func_800D3948(void);
    void func_800A2848(BtIntPtr, s32, s32);
    void func_800A2A00(BtIntPtr, s32, s32);

    *((Obj1E7BFA0_arg0 *)arg0)->unk124 = _fxstep_entrypoint_1();
    func_800A2EDC(arg0, 1.0f);
    _fxstep_entrypoint_3(*((Obj1E7BFA0_arg0 *)arg0)->unk124, func_800D3948() == 0);
    _fxstep_entrypoint_4(*((Obj1E7BFA0_arg0 *)arg0)->unk124, &func_800A2A00, ((Obj1E7BFA0_arg0 *)arg0)->unk184);
    _fxstep_entrypoint_7(*((Obj1E7BFA0_arg0 *)arg0)->unk124, &func_800A2848, ((Obj1E7BFA0_arg0 *)arg0)->unk184);
}    typedef struct { BtIntPtr unk0; u8 pad4[0x4]; f32 unk8; } Obj1E7BFA0_func_800A2E18_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { BtIntPtr unk0; u8 pad4[0x4]; f32 unk8; } Obj1E7BFA0_func_800A2E18_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

/* extern */

void func_800A2E18(PlayerState *arg0) {
    void _fxstep_entrypoint_8(u8 *arg0, f32 arg1, f32 arg2);
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    s16 func_8009CBDC(PlayerState *, s32);
    s32 sp24;
    void *temp_v0;
    void *temp_v0_2;

    sp24 = bs_getCurrentState(arg0);
    func_800A2C84(arg0);
    if ((func_8009CBDC(arg0, sp24) == 8) || (func_8009CA70(arg0, sp24, 0x40) != 0)) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x124)));
        _fxstep_entrypoint_8((((Obj1E7BFA0_func_800A2E18_temp_v0 *)temp_v0)->unk0), 0.2f, (((Obj1E7BFA0_func_800A2E18_temp_v0 *)temp_v0)->unk8));
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x124)));
    _fxstep_entrypoint_8((((Obj1E7BFA0_func_800A2E18_temp_v0_2 *)temp_v0_2)->unk0), 0.0f, (((Obj1E7BFA0_func_800A2E18_temp_v0_2 *)temp_v0_2)->unk8));
}

/* extern */

void func_800A2EAC(void *arg0) {
    void _fxstep_entrypoint_9(void *arg0);
    s32 func_800A2C84();
#ifdef BT_NATIVE
    ((s32 (*)())func_800A2C84)();
#else
    func_800A2C84();
#endif
    _fxstep_entrypoint_9(*(((PlayerState *)arg0)->unk124));
}

void func_800A2EDC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 292) + 8) = arg1;
}    typedef struct { u8 pad0[0x8]; f32 unk8; } Obj1E7BFA0_func_800A2EEC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x8]; f32 unk8; } Obj1E7BFA0_func_800A2EEC_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void func_800A2EEC(PlayerState *arg0, s32 arg1) {
    void _fxstep_entrypoint_11(u8 *arg0, f32 arg1, f32 arg2);
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    s16 func_8009CBDC(PlayerState *, s32);
    s32 sp24;
    void *temp_v0;
    void *temp_v0_2;

    sp24 = bs_getCurrentState(arg0);
    func_800A2C84(arg0);
    *(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x124) + 4) = arg1;
    if ((func_8009CBDC(arg0, sp24) == 8) || (func_8009CA70(arg0, sp24, 0x40) != 0)) {
        temp_v0 = *(void **)((s8 *)arg0 + 0x124);
        _fxstep_entrypoint_11(*(s32 *)temp_v0, 0.2f, ((Obj1E7BFA0_func_800A2EEC_temp_v0 *)temp_v0)->unk8);
        return;
    }
    temp_v0_2 = *(void **)((s8 *)arg0 + 0x124);
    _fxstep_entrypoint_11(*(s32 *)temp_v0_2, 0.0f, ((Obj1E7BFA0_func_800A2EEC_temp_v0_2 *)temp_v0_2)->unk8);
}

/* extern */

void func_800A2F90(void *arg0, s32 arg1) {
    void _fxstep_entrypoint_2(s8 *arg0, s32 arg1);
    void func_800A2EEC(PlayerState *, s32);
    _fxstep_entrypoint_2(*(((Obj1E7BFA0_arg0 *)arg0)->unk124), 0);
    func_800A2EEC(arg0, arg1);
}

s32 func_800A2FCC(PlayerState *arg0, s32 arg1) { func_800A2C84(arg0); (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x124)))) + (4))) = (s8) arg1; return _fxstep_entrypoint_12((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x124)))) + (0)))); }

/* extern */

void func_800A300C(void *arg0) {
    void* func_800BC3F0(void* arg0);
    *(((Obj1E7BFA0_arg0 *)arg0)->unk124) = func_800BC3F0(*(((Obj1E7BFA0_arg0 *)arg0)->unk124));
}

s32 func_800A3040() 
{
    return 0x58;
}

f32 func_800A3048(PlayerState *arg0) {
    s32 func_8008E40C(PlayerState *);
    s32 func_800D3E40(s32);
    BT_IDO_ONLY(extern f32 D_801194D0[];)
    if (func_800D3E40(7) == 0) {
        return 1.0f;
    }
    if (func_8008E40C(arg0) != 0) {
        return 1.2f;
    }
    return BT_DATA_FIELD(player_form_data.lookup.form.scale, D_801194D0)[*(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x29)];
}

void func_800A30B4(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    void func_800A3148(PlayerState *, f32 *, f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    func_800A3148(arg0, &sp24, &sp20, &sp1C);
    sp18 = sp1C * 0.5f;
    func_800EFA4C(arg1, -sp24, sp20 - sp18, -sp24);
    func_800EFA4C(arg2, sp24, sp20 + sp18, sp24);
}

void func_800A3148(PlayerState *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 _basnowball_entrypoint_4(PlayerState *);
    void _bsfirstp_entrypoint_6(PlayerState *, f32 *, f32 *, f32 *);
    BT_IDO_ONLY(extern f32 D_80119340[][3];)
    f32 temp_f0;
    s32 temp_v1;
    f32 *temp_v0;

    temp_v1 = *(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x29);
    temp_v0 = BT_DATA_FIELD(player_form_data.dimensions, D_80119340)[temp_v1];
    *arg1 = temp_v0[0];
    *arg2 = temp_v0[1];
    *arg3 = temp_v0[2];
    switch (temp_v1) {
        case 2:
            temp_f0 = _basnowball_entrypoint_4(arg0);
            *arg1 *= temp_f0;
            *arg2 *= temp_f0;
            *arg3 *= temp_f0;
            break;
        case 9:
            _bsfirstp_entrypoint_6(arg0, arg1, arg2, arg3);
            break;
    }
}

void func_800A3200(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    f32 _basnowball_entrypoint_4(PlayerState *);
    BT_IDO_ONLY(extern f32 D_80119430[][2];)
    f32 temp_f0;
    s32 temp_v0;
    f32 *temp_v1;

    temp_v0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x29)));
    temp_v1 = BT_DATA_FIELD(player_form_data.radii, D_80119430)[temp_v0];
    *arg1 = temp_v1[0];
    *arg2 = temp_v1[1];
    if (temp_v0 == 2) {
        temp_f0 = _basnowball_entrypoint_4(arg0);
        *arg1 *= temp_f0;
        *arg2 *= temp_f0;
    }
}

TransformationId func_800A3274(PlayerState *self) {
    return (*(u8 **)((u8 *)self + 0xA0))[0x29];
}

u32 func_800A3280(void *arg0) {
    return *(u8 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 42);
}

f32 func_800A328C(void *arg0) {
    return *(f32 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 72);
}

/* extern */

f32 func_800A3298(PlayerState *arg0) {
    f32 func_800964DC();
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x48))) - func_800964DC();
}

#ifndef BT_NATIVE
void func_800A32C4(PlayerState *arg0, f32 arg1[3]) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xA0)); }
#endif
u32 func_800A32EC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 43);
}

s32 func_800A32F8(void *arg0) {
    return *(s32 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 68);
}

/* extern */

s32 func_800A3304(PlayerState *arg0) {
    u8 func_800F8B88(void);
    return func_800F8B88() == 1;
}
#ifndef BT_NATIVE
void func_800A3328(void *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 0x2C);
}
#endif
u32 func_800A3354(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 84);
}

u32 func_800A3360(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 85);
}

u32 func_800A336C(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 60);
}

f32 func_800A3378(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 56) * (f32)1;
}

f32 func_800A3394(PlayerState *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 36);
}

#ifndef BT_NATIVE
void func_800A33A0(PlayerState *arg0, f32 arg1[3]) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xA0) + 0xC); }

void func_800A33CC(void *arg0, f32 *arg1) { s32 func_800EE7F8(); func_800EE7F8(arg1, (u8 *)*(void **)((u8 *)arg0 + 0xA0) + 0x18); }
#endif
u32 func_800A33F8(void *arg0) {
    return *(u8 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 40);
}

u32 func_800A3404(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 63);
}    typedef struct { u8 pad0[0x29]; u8 unk29; } Obj1E7BFA0_func_800A3410_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

void func_800A3410(PlayerState *arg0, s32 arg1) {
    void func_800947EC(PlayerState *, s32, s32);
    void func_800A0D68(void *, s32);
    void *var_v0;

    var_v0 = *(void **)((u8 *)arg0 + 0xA0);
    if (((Obj1E7BFA0_func_800A3410_var_v0 *)var_v0)->unk29 == 0xA) {
        func_800947EC(arg0, 1, 0);
        func_800A0D68(arg0, 0);
        var_v0 = *(void **)((u8 *)arg0 + 0xA0);
    }
    *(s8 *)((u8 *)var_v0 + 0x29) = arg1;
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xA0) + 0x29) == 0xA) {
        func_800947EC(arg0, 1, 1);
        func_800A0D68(arg0, 1);
    }
}

void func_800A34A0(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 42) = arg1;
}
#ifndef BT_NATIVE
void func_800A34AC(PlayerState *arg0, f32 arg1[3]) {
    s32 func_800EE7F8();
    func_800EE7F8(*(void **)((u8 *)arg0 + 0xA0), arg1);
}
#endif
void func_800A34CC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 43) = arg1;
}

void func_800A34D8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 68) = arg1;
}

void func_800A34E4(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 60) = arg1;
}

/* extern */
#ifndef BT_NATIVE
void func_800A34F0(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xA0))) + 0xC);
}

/* extern */

void func_800A3514(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xA0))) + 0x18);
}
#endif
void func_800A3538(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 40) = arg1;
}

void func_800A3544(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 63) = arg1;
}

void func_800A3550(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 80) = arg1;
}    typedef struct { u8 pad0[0x48]; f32 unk48; f32 unk4C; u8 unk50; } Obj1E7BFA0_func_800A355C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A355C(void *arg0) {
    s32 func_8008EF3C(struct player_state_s *arg0, Unk80132ED0 *arg1);
    BT_IDO_ONLY(f32 func_8009C150();) BT_NATIVE_ONLY(f32 func_8009C150(PlayerState *);)
    s32 func_800F3ED0(void *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    f32 sp24;
    s32 sp20;
    void *temp_v0;

    sp24 = func_8009C150(BT_NATIVE_ONLY((PlayerState *)arg0));
    sp20 = func_800F3ED0(arg0);
    if ((player_isStable(arg0) != 0) || (player_inWater(arg0) != 0) || ((sp20 == 0xA) && (func_8008EF3C(arg0, 0) != 3)) || (sp20 == 5)) {
        func_800A3550(arg0, 1);
    } else {
        func_800A3550(arg0, 2);
    }
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xA0)));
    if (((((Obj1E7BFA0_func_800A355C_temp_v0 *)temp_v0)->unk50) != 2) || !(sp24 <= (((Obj1E7BFA0_func_800A355C_temp_v0 *)temp_v0)->unk4C))) {
        (((Obj1E7BFA0_func_800A355C_temp_v0 *)temp_v0)->unk48) = (f32) (((Obj1E7BFA0_func_800A355C_temp_v0 *)temp_v0)->unk4C);
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x4C))) = sp24;
    }
}    typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x1]; u8 unk3D; } Obj1E7BFA0_func_800A3644_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

s32 func_800A3644(void *arg0) {
    s32 bastatetimer_set(void *, s32, f32);
    f32 func_800963E4(PlayerState *);
    s32 func_80096434(PlayerState *);
    s32 func_8009650C(PlayerState *);
    u32 func_80096518(PlayerState *);
    s32 func_80096628(PlayerState *);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    s32 player_inWater(PlayerState *);
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    s32 sp2C;
    void *temp_v1;

    sp34 = func_800D8FF8();
    sp38 = func_800963E4(arg0);
    sp30 = func_80096628(arg0);
    temp_v1 = *(void **)((s8 *)arg0 + 0xA0);
    if (((Obj1E7BFA0_func_800A3644_temp_v1 *)temp_v1)->unk3D != 0) {
        if (sp38 > 35.0f) {
            ((Obj1E7BFA0_func_800A3644_temp_v1 *)temp_v1)->unk38 = 1.0f;
        } else {
            ((Obj1E7BFA0_func_800A3644_temp_v1 *)temp_v1)->unk38 = 0.0f;
        }
    } else {
        sp3C = func_800F10B4(sp38, 20.0f, 60.0f, 0.6f, 1.3f);
        if ((func_80096518(arg0) == 0) && !(sp30 & 0x50)) {
            sp2C = func_80096434(arg0);
            if ((func_8009650C(arg0) != 0) && (sp2C & 0x50)) {
                sp30 = sp2C;
            }
        }
        if ((sp30 & 0x50) && (player_inWater(arg0) == 0)) {
            *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x38) = func_800F13F0(*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x38) + sp34 * sp3C, 1.0f);
        } else {
            *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x38) = 0.0f;
        }
        if (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x38) == 1.0f) {
            if (sp30 & 0x10) {
                bastatetimer_set(arg0, 5, 0.18f);
            } else if (sp30 & 0x40) {
                bastatetimer_set(arg0, 6, 0.18f);
            }
        }
    }
    *(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x3D) = 0; BT_NATIVE_ONLY(return 0;)
}

void func_800A380C(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x38))) = (f32) 0.98f;
}

/* extern */

void func_800A3820(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_8009C150(PlayerState *);
    u32 func_8009E958(void);
    void func_800EFD24(f32 *);
    f32 temp_f0;

    func_800EFD24((arg0->unkA0));
    func_800EFD24((arg0->unkA0) + 3);
    func_8009C128(arg0, (arg0->unkA0) + 11);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3D))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x38))) = 0.0f;
    func_800A380C(arg0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3C))) = 1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x40))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x50))) = 0;
    temp_f0 = func_8009C150(arg0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x48))) = temp_f0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x4C))) = temp_f0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x29))) = 0;
    func_800A3410(arg0, func_8009E958());
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x54))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x55))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3E))) = 1;
}

void func_800A38F0(PlayerState *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x54))) = (s8) arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x55))) = (s8) arg2;
}

void func_800A3904(PlayerState *arg0, s32 arg1) {
    (*(u8 **)((u8 *)arg0 + 0xA0))[0x3E] = arg1;
}

void func_800A3910(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1E7BFA0_arg0 *)arg0)->unkA0 + 61) = arg1;
}

void func_800A391C(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 36) = arg1;
}

void func_800A392C(PlayerState *arg0, s32 arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_800C05B8(s32, s32, f32*, Unk80132ED0*, BtIntPtr, s32, s16);
    f32 sp2C[3];

    func_8009C128(arg0, sp2C);
    func_800C05B8(arg1, 2, sp2C, NULL, 0, 0, 0);
}

s32 func_800A3970(PlayerState *arg0, s32 arg1) {
    s32 func_8009E7C8(PlayerState *, s32);
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0xA0);
    if (*(f32 *)(temp_v0 + 0x40) != 0.0f) {
        return 0;
    }
    *(f32 *)(temp_v0 + 0x40) = 10.0f;
    if (func_800A3274(arg0) == TRANSFORM_11_CLOCKWORK) {
        func_8009E7C8(arg0, 0x1F);
    }
    if (arg1 != 0) {
        func_800A392C(arg0, arg1);
    } else {
        switch (func_800A3274(arg0)) {
        case TRANSFORM_A_BANJO:
            func_800A392C(arg0, 0x1212);
            break;
        case TRANSFORM_B_KAZOOIE:
            func_800A392C(arg0, 0x1213);
            break;
        case TRANSFORM_D_MUMBO:
            func_800A392C(arg0, 0x1214);
            break;
        case TRANSFORM_11_CLOCKWORK:
            func_800A392C(arg0, 0x1216);
            break;
        default:
            func_800A392C(arg0, 0x1217);
            break;
        }
    }
}    typedef struct { u8 pad0[0x40]; f32 unk40; } Obj1E7BFA0_func_800A3A80_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A3A80(PlayerState *arg0) {
    void baflag_clear(void *self, s32 id);
    s32 func_80096568(void *, s32);
    void func_8009BD18(void *, f32);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_8009E71C(PlayerState *, s32);
    s32 func_800A3644(void *);
    s32 func_800D9078(f32 *arg0);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xA0)));
    if ((((Obj1E7BFA0_func_800A3A80_temp_v0 *)temp_v0)->unk40) != 0.0f) {
        func_800D9078((f32 *)(temp_v0 + 0x40));
    }
    if (player_isStable(arg0) != 0) {
        func_8009C128(arg0, (f32 *)((*(u8 **)((s8 *)(arg0) + (0xA0))) + 0x2C));
    }
    if ((player_isStable(arg0) != 0) || (func_8009E71C(arg0, 0xA) != 0)) {
        baflag_clear(arg0, 5);
        baflag_clear(arg0, 0x12);
    }
    if (player_inWater(arg0) != 0) {
        baflag_clear(arg0, 5);
        baflag_clear(arg0, 0x12);
    }
    func_800A3644(arg0);
    func_800A355C(arg0);
    if (func_80096568(arg0, 0x600) != 0) {
        func_8009BD18(arg0, 0.75f);
    }
}

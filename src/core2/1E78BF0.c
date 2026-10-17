#include "core2/1E78BF0.h"

s32 func_8009F300() 
{
    return 0x4;
}

f32 func_8009F308(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 *func_800A4C48(PlayerState *);
    s32 func_800CA7E4(f32 *, s32);
    s32 func_800F1E6C(f32[3], f32[3], f32 *target_yaw);
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    func_8009C128(arg0, sp2C);
    func_800CA7E4(func_800A4C48(arg0), (s32) sp20);
    func_800F1E6C(sp2C, sp20, &sp1C);
    return sp1C;
}

/* extern */

s32 func_8009F354(PlayerState *arg0) {
    s32 _badata_entrypoint_24(PlayerState *);
    int baflag_isTrue(PlayerState *, s32);
    s32 baflag_set(PlayerState *, s32);
    s32 bs_getCurrentState(PlayerState *);
    s32 sp1C;

    if (baflag_isTrue(arg0, 0xF) != 0) {
        return 0;
    }
    baflag_set(arg0, 0xF);
    sp1C = _badata_entrypoint_24(arg0);
    if (bs_getCurrentState(arg0) != sp1C) {
        return sp1C;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009F3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009F440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009F678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009F860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009FA20.s")

/* extern */

s32 func_8009FBB0(PlayerState *arg0, f32 *arg1, f32 arg2) {
    f32 func_800964DC(PlayerState *);
    s32 _fxairbub_entrypoint_1(f32 *, f32, f32, s32);
    return _fxairbub_entrypoint_1(arg1, arg2, func_800964DC(arg0), 0x3F800000);
}

void func_8009FBE8(PlayerState *arg0, u8 *arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 *func_800A4C48(PlayerState *);
    s32 func_800CA7E4(f32 *, s32);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp2C[3];
    s32 sp20[3];

    func_8009C128(arg0, sp2C);
    func_800CA7E4(func_800A4C48(arg0), (s32) sp20);
    func_800EFB24(arg1, sp20, sp2C);
}

/* extern */

void func_8009FC34(PlayerState *arg0, s32 arg1) {
    s32 _fxripple_entrypoint_1(s32, f32 *, s32);
    f32 func_800964DC(PlayerState *);
    s32 func_800966E0(void *);
    void func_8009C128(PlayerState *, f32[3]);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    sp1C[1] = func_800964DC(arg0);
    _fxripple_entrypoint_1(arg1, sp1C, func_800966E0(arg0));
}

void func_8009FC80(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    extern s32 D_80119220;
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    sp24[0] += func_800DC178(-30.0f, 30.0f);
    sp24[1] += func_800DC178(95.0f, 105.0f);
    sp24[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(sp24, NULL, 1.0f, 1, &D_80119220);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009FD24.s")

void func_8009FE58(PlayerState* arg0)
{
    func_800A2E18(arg0);
}

void func_8009FE78(PlayerState *arg0)
{
    **(s32 **)((u8 *)arg0 + 0x12C) = 0;
}

/* extern */

enum bs_state_e bs_getTypeOfJump(PlayerState *self) {
    int baflag_isTrue(PlayerState *, s32);
    int bakey_held(PlayerState *, s32);
    int func_8008D370(PlayerState *);
    int func_8008D3B0(PlayerState *);
    if ((bakey_held(self, 1) != 0) && (func_8008D370(self) != 0)) {
        return 0x12;
    }
    if (baflag_isTrue(self, 2) != 0) {
        return 5;
    } else {
        if (func_8008D3B0(self) != 0) {
            return 0x23;
        }
    }
    return 5;
}

/* extern */

void func_8009FF00(PlayerState *arg0) {
    s32 (*_badata_entrypoint_28(PlayerState *))(PlayerState *, f32);
    s32 (*sp1C)(PlayerState *, f32);

    sp1C = _badata_entrypoint_28(arg0);
    if (sp1C != NULL) {
        sp1C(arg0, func_8009BB5C(arg0));
    }
}

void func_8009FF44(PlayerState *arg0, enum asset_e arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    AnimCtrl *sp24;
    AnimCtrl *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    sp24 = temp_v0;
    if (anctrl_getIndex(temp_v0) != arg1) {
        anctrl_setIndex(sp24, arg1);
        anctrl_start(sp24);
    }
    func_8008CA4C(arg0, BAANIM_UPDATE_2_SCALE_HORZ);
    baanim_setDurationRange(arg0, 0.2345f, 3.9876f);
    func_8008C9F0(arg0, arg2, arg3, arg4, arg5);
}

/* extern */

void func_8009FFD8(PlayerState *arg0, enum baanim_update_type_e anim_update_type, enum yaw_type_e yaw_state, s32 arg2, enum ba_physics_type_e arg3) {
    s32 func_8009D2D8(PlayerState *, s32);
    func_8008CA4C(arg0, anim_update_type);
    yaw_setUpdateType(arg0, yaw_state);
    func_8009D2D8(arg0, arg2);
    baphysics_set_type(arg0, arg3);
}

/* extern */

void func_800A0024(PlayerState *arg0) {
    s32 func_8009CC18(PlayerState *self, f32[3]);
    s32 func_8009CC68(PlayerState *self);
    void func_800A0064(PlayerState *, f32 *);
    f32 sp1C[3];
    if (func_8009CC68(arg0) != 0) {
        if (func_8009CC18(arg0, sp1C) != 0) {
            func_800A0064(arg0, sp1C);
        }
    }
}

void func_800A0064(PlayerState *arg0, f32 *arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_8009BF5C(PlayerState *, f32);
    void baroll_setIdeal(PlayerState *, f32);
    f32 sp24[3];
    f32 sp18[3];

    func_8009C128(arg0, sp24);
    func_800F18FC(sp24, arg1, sp18);
    func_8009BF5C(arg0, -sp18[0]);
    yaw_setIdeal(arg0, sp18[1]);
    baroll_setIdeal(arg0, 0.0f);
}

 s32 func_800A00CC(PlayerState *arg0, f32 arg1[3]) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 sp24[3];
    s32 sp18[3];

    func_8009C128(arg0, sp24);
    func_800F18FC(sp24, arg1, sp18);
    yaw_setIdeal(arg0, *(f32 *)&sp18[1]);
}

/* extern */

void func_800A0110(AnimCtrl *arg0, AnimCtrl *arg1) {
    s32 _badata_entrypoint_3(AnimCtrl *, enum asset_e *, f32 *);
    f32 sp1C;
    enum asset_e sp18;

    _badata_entrypoint_3(arg0, &sp18, &sp1C);
    anctrl_setIndex(arg1, sp18);
    anctrl_setDuration(arg1, sp1C);
}

/* extern */

void func_800A0150(s32 arg0) {
    s32 func_800FC240(s32, s32);
    void func_800FC660(u32);
    func_800FC240(0, 0xFA0);
    func_800FC660(arg0);
}

/* extern */

void func_800A0180(PlayerState *arg0) {
    s32 _badata_entrypoint_16();
    int baflag_isTrue(PlayerState *, s32);
    s32 baflag_set(PlayerState *, s32);
    s32 func_800D395C();
    s32 func_800FCCD4(s32);
    s32 func_800FE4E4();
    s32 sp1C;

    sp1C = _badata_entrypoint_16();
    if (func_800D395C() != 0) {
        if (func_800FCCD4(sp1C) == 0) {
            func_800A0150(sp1C);
        }
    } else if (baflag_isTrue(arg0, 0x41) == 0) {
        baflag_set(arg0, 0x41);
        func_800A0150(sp1C);
        func_800FE4E4();
    }
}

BanjoStateId func_800A01F8(PlayerState *arg0, BanjoStateId arg1) { int baflag_isTrue(PlayerState *, s32); int bakey_pressed(PlayerState *, int); int bakey_held(PlayerState *, s32); int bainput_should_beak_barge(PlayerState *); s32 bainput_should_enter_first_person(); s32 _badrone_entrypoint_24(PlayerState *); s32 _badrone_entrypoint_25(PlayerState *); int func_8008E148(PlayerState *); s32 func_800A055C(PlayerState *, s32); if (baflag_isTrue(arg0, 0xF) != 0) { return arg1; } if (bakey_pressed(arg0, 8) != 0) { arg1 = bs_getTypeOfJump(arg0); } if (bakey_pressed(arg0, 9) != 0) { arg1 = func_800A055C(arg0, arg1); } if (bakey_held(arg0, 1) != 0 && bainput_should_beak_barge(arg0) != 0) { arg1 = 0x13; } if (bainput_should_enter_first_person(arg0) != 0) { arg1 = _badrone_entrypoint_24(arg0); } if (func_8008E148(arg0) != 0) { arg1 = _badrone_entrypoint_25(arg0); } return arg1; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A02DC.s")

/* extern */

void func_800A042C(PlayerState *arg0) {
    void baroll_setIdeal(PlayerState *, f32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009BFBC(void *arg0);
    s32 baroll_applyIdeal(PlayerState *);
    func_8009BF5C(arg0, 0.0f);
    func_8009BFBC(arg0);
    baroll_setIdeal(arg0, 0.0f);
    baroll_applyIdeal(arg0);
}

void func_800A046C(PlayerState *arg0) {
    void _bsjig_entrypoint_4(PlayerState *);
    void baflag_clear(PlayerState *, s32);
    int baflag_isFalse(PlayerState *, s32);
    int baflag_isTrue(PlayerState *, s32);
    void func_800FC660(u32);
    if (baflag_isFalse(arg0, 7) == 0) {
        if (baflag_isTrue(arg0, 0xF) != 0 && baflag_isFalse(arg0, 6) != 0 && baflag_isFalse(arg0, 0x14) != 0) {
            baflag_clear(arg0, 0xF);
        }
        baflag_clear(arg0, 7);
        _bsjig_entrypoint_4(arg0);
        func_800FC660(5);
    }
}

/* extern */

s32 func_800A04F4(PlayerState *arg0, s32 arg1) {
    int func_8008D568(PlayerState *);
    int func_8008D694(PlayerState *);
    s32 func_8008E23C(PlayerState *);
    if (func_8008E23C(arg0) != 0) {
        if (func_8008D568(arg0) != 0) {
            return 0xE4;
        }
        return arg1;
    } else {
        if (func_8008D694(arg0) != 0) {
            return 0x31;
        }
    }
    return arg1;
}

/* extern */

s32 func_800A055C(PlayerState *arg0, s32 arg1) {
    int func_8008D1B0(PlayerState *);
    int func_8008D568(PlayerState *);
    s32 func_8008E23C(PlayerState *);
    s32 func_8009EA2C(void);
    if (func_8008E23C(arg0) != 0) {
        if (func_8008D568(arg0) != 0) {
            return 0xE4;
        }
        return arg1;
    } else {
        if (func_8008D1B0(arg0) != 0) {
            if (func_8009EA2C() != 0) {
                return 0x18A;
            }
            return 6;
        }
    }
    return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A05DC.s")

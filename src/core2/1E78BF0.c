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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009F354.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009FC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_8009FD24.s")

void func_8009FE58(PlayerState* arg0)
{
    func_800A2E18(arg0);
}

void func_8009FE78(PlayerState *arg0)
{
    **(s32 **)((u8 *)arg0 + 0x12C) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/bs_getTypeOfJump.s")

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
    s32 func_800A0064(PlayerState *, f32 *);
    f32 sp1C[3];
    if (func_8009CC68(arg0) != 0) {
        if (func_8009CC18(arg0, sp1C) != 0) {
            func_800A0064(arg0, sp1C);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A0064.s")

 s32 func_800A00CC(PlayerState *arg0, f32 arg1[3]) {
    void func_8009C128(PlayerState *, f32[3]);
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
    s32 func_800FC660(s32);
    func_800FC240(0, 0xFA0);
    func_800FC660(arg0);
}

/* extern */

void func_800A0180(PlayerState *arg0) {
    s32 _badata_entrypoint_16();
    s32 baflag_isTrue(PlayerState *, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A01F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A02DC.s")

/* extern */

void func_800A042C(PlayerState *arg0) {
    s32 baroll_setIdeal(s32, f32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009BFBC(void *arg0);
    s32 baroll_applyIdeal(PlayerState *);
    func_8009BF5C(arg0, 0.0f);
    func_8009BFBC(arg0);
    baroll_setIdeal((s32) arg0, 0.0f);
    baroll_applyIdeal(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A046C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A04F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A055C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78BF0/func_800A05DC.s")

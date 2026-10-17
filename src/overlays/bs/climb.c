#include "common.h"

void func_80800000_bsclimb(void *arg0, s32 arg1) {
    u32 func_80098634(void *arg0);
    void func_8009DF94(void *, s32, f32, s32);
    extern s32 D_808008C0_bsclimb;
    u8 *temp_t0;
    u8 *temp_v1;
    u32 offset;

    offset = func_80098634(arg0) * 5;
    offset *= 4;
    temp_v1 = offset + (u8 *)&D_808008C0_bsclimb;
    temp_t0 = (u8 *)temp_v1 + (arg1 * 8);
    func_8009DF94(arg0, *(s16 *)((u8 *)temp_v1 - 0x12), *(f32 *)(temp_t0 - 0x10), *(s32 *)(temp_t0 - 0xC));
}

/* extern */

void func_8080005C_bsclimb(void *arg0) {
    struct player_state_s;
    f32 bastick_getY(struct player_state_s *);
    void func_8009B94C(u8 *, f32 *);
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    f32 sp2C[3];
    f32 sp28;
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = bastick_getY(arg0);
    sp28 = temp_f0;
    if (mlAbsF(temp_f0) < 0.03f) {
        var_f2 = 0.0f;
    } else {
        var_f2 = func_800F1344(sp28, 0.03f, 1.0f, 100.0f, 300.0f);
    }
    sp2C[0] = 0.0f;
    sp2C[1] = var_f2;
    sp2C[2] = 0.0f;
    func_8009B94C(arg0, sp2C);
}

struct player_state_s;
s32 func_808000E8_bsclimb(s32 arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    s32 baphysics_set_type(void *, s32);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    int func_8008E0E8(struct player_state_s *);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_800961AC(struct player_state_s *, s32);
    u32 func_8009861C(void *);
    void func_8009BC5C(struct player_state_s *, f32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_800A4DA4(struct player_state_s *, s32);
    s32 yaw_setUpdateType(void *, s32);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);

    if (func_8009861C(arg0) == 2) {
        func_8009D2D8(arg0, 3);
    } else {
        func_8009D2D8(arg0, 6);
    }
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 500.0f, 15.0f);
    bastick_setZoneMax(arg0, 0, 0.03f);
    bastick_setZoneMax(arg0, 1, 1.0f);
    baphysics_set_type(arg0, 10);
    func_8009BC5C(arg0, 10.0f);
    func_800961AC(arg0, 5);
    func_800959C8(arg0, 80.0f, 10.0f);
    func_800A4DA4(arg0, 12);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 4);
    }
}

struct player_state_s;
void func_808001D0_bsclimb(struct player_state_s *arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    s32 baphysics_set_type(void *, s32);
    void bastick_resetZones(struct player_state_s *);
    s32 func_8008CA4C(void *, s32);
    int func_8008E0E8(struct player_state_s *);
    void func_80095A40(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009E74C(struct player_state_s *, s32);
    void func_800A4E30(struct player_state_s *);

    if (func_8009E74C(arg0, 0xA) == 0) {
        func_800A4E30(arg0);
        bastick_resetZones(arg0);
        func_8008CA4C(arg0, 1);
        baphysics_set_type(arg0, 2);
        func_800961AC(arg0, 1);
        func_80095A40(arg0);
        if (func_8008E0E8(arg0) != 0) {
            _bapackctrl_entrypoint_5(arg0, 3);
        }
    }
}

/* extern */

void func_80800258_bsclimb(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800DC0C0();
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = (f32) ((func_800DC0C0() * arg2) + arg1);
}

/* extern */

struct player_state_s;

int func_80800298_bsclimb(struct player_state_s *arg0) {
    f32 func_8009BB0C(void *);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);

    return mlAbsF(func_8009BB0C(arg0)) > 0.0f
        || yaw_get(arg0) != yaw_getIdeal(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_1.s")

void bsclimb_entrypoint_2(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_3(s32 arg0) {
    extern s32 D_808008FC_bsclimb[];
    return ((s32 *)&D_808008FC_bsclimb)[arg0];
}

void bsclimb_entrypoint_4(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    s32 func_8008CA4C(void *, s32);

    baanim_playForDuration_loopSmooth(arg0, 0xA, 0x3F666666);
    func_8008CA4C(arg0, 3);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 100.0f, 300.0f, 0.6f, 0.4f);
    func_808000E8_bsclimb(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_5.s")

void bsclimb_entrypoint_6(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_7(s32 arg0) {
    extern s32 D_8080090C_bsclimb[];
    return ((s32 *)&D_8080090C_bsclimb)[arg0];
}

/* extern */

void bsclimb_entrypoint_8(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 baphysics_set_type(void *, s32);
    s32 func_8008CA4C(void *, s32);
    s32 func_808000E8_bsclimb(s32);
    baanim_playForDuration_loopSmooth(arg0, 0xB2, 0x4028F5C3);
    func_8008CA4C(arg0, 1);
    func_808000E8_bsclimb(arg0);
    baphysics_set_type(arg0, 7);
}

/* extern */

struct player_state_s;
enum bs_state_e;
void bs_setState(struct player_state_s *, enum bs_state_e);

void bsclimb_entrypoint_9(struct player_state_s *arg0) {
    s32 func_8009CC68();
    s32 var_a1;

    var_a1 = 0;
    if (func_8009CC68() == 0) {
        var_a1 = 0x4F;
    }
    bs_setState(arg0, var_a1);
}

void bsclimb_entrypoint_10(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_11(s32 arg0) {
    extern s32 D_8080091C_bsclimb[];
    return ((s32 *)&D_8080091C_bsclimb)[arg0];
}

/* extern */

void bsclimb_entrypoint_12(struct player_state_s *arg0) {
    void func_80099B94(struct player_state_s *);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    if (func_8009E6EC(arg0) == 0xC) {
        *(s32 *)((s8 *)arg0 + 0x160) = 1;
    } else {
        func_80099B94(arg0);
        return;
    }
    func_8009E830(arg0, 1);
    bs_setState(arg0, 0);
}

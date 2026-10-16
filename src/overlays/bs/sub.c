#include "common.h"

void func_80800000_bssub(s32 arg0) {
    func_8009FFD8(arg0, 0x1, 0x3, 0x3, 0xF);
}

f32 func_80800030_bssub(f32 arg0, f32 arg1) {
    return arg1 * 300.0f;
}

f32 func_80800048_bssub(f32 arg0, f32 arg1) {
    return -arg1 * 428.57144f;
}

/* extern */

void func_80800064_bssub(s32 arg0) {
    s32 _basub_entrypoint_15(s32, s32);
    s32 bs_setState(s32, s32);
    s32 func_800995B8(s32, s32);
    s32 func_80099A58(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
        case 0x85:
            _basub_entrypoint_15(arg0, func_80099A58(arg0));
            break;
        case 0x2D:
            func_800995B8(arg0, 3);
            func_8009E830(arg0, 2);
            bs_setState(arg0, 0x46);
            break;
        default:
            func_80099B94(arg0);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808000F0_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800254_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800634_bssub.s")

/* extern */

struct player_state_s;
void func_80800768_bssub(struct player_state_s *arg0) {
    f32 bastick_getY(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 player_inWater(struct player_state_s *);
    f32 temp_f0;
    f32 var_f2;
    f32 var_f16;

    if (player_inWater(arg0) != 0) {
        var_f2 = 275.0f;
        var_f16 = 85.0f;
    } else {
        var_f2 = 325.0f;
        var_f16 = 30.0f;
    }
    temp_f0 = bastick_getY(arg0);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(arg0, func_800F10B4(temp_f0, -1.0f, 0.0f, var_f2, 360.0f));
        return;
    }
    func_8009BF5C(arg0, func_800F10B4(temp_f0, 0.0f, 1.0f, 0.0f, var_f16));
}

void func_80800834_bssub(struct player_state_s *arg0) {
    void _basub_entrypoint_1(struct player_state_s *);
    void _basub_entrypoint_3(struct player_state_s *, f32, f32);
    void _basub_entrypoint_5(struct player_state_s *);
    void _basub_entrypoint_8(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    f32 func_8009BB94(struct player_state_s *);
    s32 func_800EA068(s32);
    if (bakey_pressed(arg0, 2) != 0) {
        _basub_entrypoint_1(arg0);
    }
    if (bakey_pressed(arg0, 1) != 0) {
        _basub_entrypoint_8(arg0, func_8009BB94(arg0));
    }
    if (bakey_pressed(arg0, 9) != 0) {
        if (func_800EA068(0x40) != 0) {
            _basub_entrypoint_3(arg0, 160.0f, 1.0f);
            return;
        }
        _basub_entrypoint_5(arg0);
    }
}

/* extern */

void func_808008D8_bssub(struct player_state_s *arg0) {
    s32 _bafpctrl_entrypoint_18(struct player_state_s *, s32);
    s32 _basub_entrypoint_9(struct player_state_s *);
    void baroll_resetAngularVelocity(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    void bastick_resetZones(struct player_state_s *);
    void func_800910BC(struct player_state_s *, s32);
    void func_80092864(struct player_state_s *, f32);
    void func_80093360(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_80095964(void *, s32);
    void func_80095A40(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC34(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009C000(struct player_state_s *);
    void func_8009E474(struct player_state_s *);
    s32 func_8009E74C(struct player_state_s *, s32);
    if (func_8009E74C(arg0, 0xF) == 0) {
        func_800947EC(arg0, 1, 0);
        func_800961AC(arg0, 1);
        func_8009BC34(arg0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_resetZones(arg0);
        func_80095A40(arg0);
        func_80095964(arg0, 0);
        func_80093360(arg0, 0.0f);
        _basub_entrypoint_9(arg0);
        func_800910BC(arg0, 1);
        _bafpctrl_entrypoint_18(arg0, 0);
        func_8009E474(arg0);
        func_80092864(arg0, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808009B0_bssub.s")

void func_80800AEC_bssub()
{
    _basub_entrypoint_14();
}

void func_80800B0C_bssub()
{
    _baspin_entrypoint_1();
}

/* extern */

struct player_state_s;

void func_80800B2C_bssub(s32 arg0) {
    void _bamovethrust_entrypoint_3(struct player_state_s *, f32);
    void _bamovethrust_entrypoint_4(struct player_state_s *, f32);
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    void _basub_entrypoint_11(s32, f32);
    void _basub_entrypoint_13(s32, f32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_800FC660(u32);
    baanim_playForDuration_loopSmooth(arg0, 0x12E, 6.0f);
    func_80800000_bssub(arg0);
    _bamovethrust_entrypoint_3(arg0, 0.0f);
    _bamovethrust_entrypoint_4(arg0, 0.9f);
    _basub_entrypoint_11(arg0, 0.6f);
    _basub_entrypoint_13(arg0, 1.0f);
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
    _batimer_set(arg0, 9, 1.8f);
    func_800FC660(0x19);
}

/* extern */

void func_80800BD8_bssub(void *arg0) {
    s32 _baspin_entrypoint_3();
    s32 _batimer_decrement(void *, s32);
    s32 func_80101180(s32, s32, s32);
    _baspin_entrypoint_3();
    if (_batimer_decrement(arg0, 9) != 0) {
        func_80101180(0x2C4, 0x71, (*(s32 *)((s8 *)(arg0) + (0x184))));
    }
}

/* extern */
void func_80800C1C_bssub(void *arg0) {
    s32 _basudie_entrypoint_8(void *);
    if (*(s32 *)((s8 *)arg0 + 0x15C)) {
        func_80800B0C_bssub(arg0);
    } else {
        _basudie_entrypoint_8(arg0);
    }
    func_808008D8_bssub(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800C60_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800E34_bssub.s")

/* extern */

void func_80800E98_bssub(void *arg0) {
    s32 _basudie_entrypoint_10(void *);
    func_80800AEC_bssub();
    if ((*(s32 *)((s8 *)(arg0) + (0x15C))) != 0) {
        func_80800BD8_bssub(arg0);
        return;
    }
    _basudie_entrypoint_10(arg0);
}

/* extern */

void func_80800EE0_bssub(s32 arg0) {
    s32 _basudie_entrypoint_11(s32);
    s32 bs_setState(s32, s32);
    s32 func_80093370(s32, s32);
    f32 func_80099A34(s32);
    s32 func_8009BDAC(s32, f32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x83) {
        func_8009BDAC(arg0, func_80099A34(arg0));
        func_80093370(arg0, 1);
        bs_setState(arg0, 0x131);
        func_8009E830(arg0, 2);
        return;
    }
    _basudie_entrypoint_11(arg0);
}

s32 bssub_entrypoint_0(s32 arg0) {
    extern s32 D_80801890_bssub[];
    return ((s32 *)&D_80801890_bssub)[arg0];
}

void func_80800F70_bssub(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808008D8_bssub(arg0);
}
void func_80800F98_bssub(s32 arg0)
{
    func_808009B0_bssub();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800FC0_bssub(s32 arg0)
{
    func_80800AEC_bssub();
    func_80800254_bssub(arg0);
    _bsdrone_entrypoint_1(arg0);
}

s32 bssub_entrypoint_1(s32 arg0) {
    extern s32 D_808018A0_bssub[];
    return ((s32 *)&D_808018A0_bssub)[arg0];
}

void func_80801004_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_8080102C_bssub(struct player_state_s *arg0) {
    int anctrl_getIndex(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA4C(struct player_state_s *, s32);
    f32 func_8009BB94(struct player_state_s *);
    struct anctrl_s *sp2C;
    s32 sp28;
    struct anctrl_s *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    sp2C = temp_v0;
    sp28 = anctrl_getIndex(temp_v0);
    func_8008CA4C(arg0, 2);
    if (func_8009BB94(arg0) < 300.0f) {
        if (sp28 != 0x12E) {
            baanim_playForDuration_loopSmooth(arg0, 0x12E, 6.0f);
            func_8008B1C8(sp2C, 0.4f);
        }
        func_8008C9F0(arg0, 0.0f, 900.0f, 6.0f, 6.0f);
        return;
    }
    if (sp28 != 0x12F) {
        baanim_playForDuration_loopSmooth(arg0, 0x12F, 0.45f);
        func_8008B1C8(sp2C, 0.4f);
    }
    func_8008C9F0(arg0, 0.0f, 900.0f, 1.5f, 0.45f);
}

/* extern */

void func_80801130_bssub(struct player_state_s *self) {
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);
    func_808009B0_bssub(self);
    func_8080102C_bssub(self);
    baanim_setDurationRange(self, 0.3f, 10.0f);
    func_8008CA30(self, 1.0f);
    func_800909CC(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80801188_bssub.s")

s32 bssub_entrypoint_2(s32 arg0) {
    extern s32 D_808018B0_bssub[];
    return ((s32 *)&D_808018B0_bssub)[arg0];
}

void func_8080121C_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_80801244_bssub(s32 arg0) {
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    func_808009B0_bssub();
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
}

/* extern */

void func_80801284_bssub(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 func_800914FC(s32, s32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 0x42200000, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_3(s32 arg0) {
    extern s32 D_808018C0_bssub[];
    return ((s32 *)&D_808018C0_bssub)[arg0];
}

void func_808012F0_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_80801318_bssub(s32 arg0) {
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    func_808009B0_bssub();
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
}

/* extern */

void func_80801358_bssub(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 func_800914FC(s32, s32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 0x42200000, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_4(s32 arg0) {
    extern s32 D_808018D0_bssub[];
    return ((s32 *)&D_808018D0_bssub)[arg0];
}

void func_808013C4_bssub(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_808013EC_bssub(s32 arg0) {
    s32 _babounce_entrypoint_4(s32, s32);
    s32 _babounce_entrypoint_5(s32, s32, s32);
    func_808009B0_bssub();
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x12E, 0x40C00000);
}

/* extern */

void func_80801428_bssub(s32 arg0) {
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 func_800914FC(s32, s32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 0x42200000, 0);
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_5(s32 arg0) {
    extern s32 D_808018E0_bssub[];
    return ((s32 *)&D_808018E0_bssub)[arg0];
}

void func_80801490_bssub(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808008D8_bssub(arg0);
}
void func_808014B8_bssub(s32 arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    func_808009B0_bssub();
    func_8009BF5C(arg0, 0.0f);
    _bsrest_entrypoint_16(arg0);
    func_8009B94C((u8 *)arg0, 0);
    func_8009BA9C(arg0, NULL);
    (*(f32 *)((s8 *)arg0 + 0x16C)) = 0.0f;
}

/* extern */

void func_80801518_bssub(s32 arg0) {
    s32 _badata_entrypoint_34(s32);
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_6(s32 arg0) {
    extern s32 D_808018F0_bssub[];
    return ((s32 *)&D_808018F0_bssub)[arg0];
}

void func_80801578_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808015A0_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80801618_bssub.s")

s32 bssub_entrypoint_7(s32 arg0) {
    extern s32 D_80801900_bssub[];
    return ((s32 *)&D_80801900_bssub)[arg0];
}

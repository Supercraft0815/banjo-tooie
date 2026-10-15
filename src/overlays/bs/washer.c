#include "common.h"
struct player_state_s;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800000_bswasher.s")

/* extern */

s32 func_80800064_bswasher(s32 arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(s32);
    s32 bainput_should_enter_first_person();
    s32 bakey_pressed(s32, s32);
    if (bainput_should_enter_first_person() != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x35;
    }
    return arg1;
}

/* extern */

void func_808000BC_bswasher(s32 arg0) {
    s32 yaw_setUpdateType(s32, s32);
    s32 yaw_setVelocityBounded(s32, s32, s32);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40C00000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808000F0_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808001A8_bswasher.s")

void bswasher_entrypoint_0(s32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_8009C128(struct player_state_s *, f32[3]);
    extern s32 D_80801D60_bswasher;
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(8);
    func_8009C128(arg0, sp24);
    func_800BABB8(sp20, sp24, NULL, 1.0f, &D_80801D60_bswasher);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800300_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_8080042C_bswasher.s")

void func_80800590_bswasher(s32 arg0)
{
    _basudie_entrypoint_6();
    func_808000F0_bswasher(arg0);
}
struct player_state_s;

void func_808005B8_bswasher(struct player_state_s *arg0) {
    void _basudie_entrypoint_2(struct player_state_s *, f32, f32, f32);
    s32 func_8080042C_bswasher(struct player_state_s *, s32);

    func_808001A8_bswasher();
    _basudie_entrypoint_2(arg0, *(f32 *)((s8 *)arg0 + 0x16C), 420.0f, -1200.0f);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
    *(f32 *)((s8 *)arg0 + 0x16C) = 250.0f;
    func_8080042C_bswasher(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800608_bswasher.s")

s32 bswasher_entrypoint_1(s32 arg0) {
    extern s32 D_80801E10_bswasher[];
    return ((s32 *)&D_80801E10_bswasher)[arg0];
}

void func_80800714_bswasher(s32 arg0) { if (_badrone_entrypoint_3(arg0) == 2) { _bafpctrl_entrypoint_10(arg0, 0); func_800947EC(arg0, 2, 0); } func_808000F0_bswasher(arg0); _bsdrone_entrypoint_2(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800770_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808007DC_bswasher.s")

s32 bswasher_entrypoint_2(s32 arg0) {
    extern s32 D_80801E20_bswasher[];
    return ((s32 *)&D_80801E20_bswasher)[arg0];
}

/* extern */

void func_808008BC_bswasher(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_808000F0_bswasher(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808008F4_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_8080099C_bswasher.s")

s32 bswasher_entrypoint_3(s32 arg0) {
    extern s32 D_80801E30_bswasher[];
    return ((s32 *)&D_80801E30_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800B08_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800C70_bswasher.s")

void func_80800E74_bswasher(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_808000F0_bswasher(arg0);
}

s32 bswasher_entrypoint_4(s32 arg0) {
    extern s32 D_80801E40_bswasher[];
    return ((s32 *)&D_80801E40_bswasher)[arg0];
}

/* extern */

void func_80800EC8_bswasher(u8 *arg0) {
    void bs_setState(struct player_state_s *, int);
    s32 func_80099A4C(void *);
    s32 func_80099B94(u8 *);
    s32 func_8009E6EC();
    if (func_8009E6EC(arg0) == 0x65) {
        (*(s32 *)((s8 *)(arg0) + (0x160))) = func_80099A4C(arg0);
        bs_setState((s32) arg0, 0x37);
    }
    func_80099B94(arg0);
}

void func_80800F1C_bswasher(s32 arg0) {
    s32 func_800C2FDC(u8 index);
    u8 temp;

    temp = ((u8 *)arg0)[0x165];
    if (temp != 0) {
        func_800C2FDC(temp);
        ((u8 *)arg0)[0x165] = 0;
    }
}

void func_80800F54_bswasher(void *arg0) {
    extern s32 D_80801E50_bswasher;
    (*(s8 *)((s8 *)(arg0) + (0x165))) = func_8009D454(arg0, 0, &D_80801E50_bswasher);
}

/* extern */

void func_80800F88_bswasher(struct player_state_s *arg0) {
    f32 func_8009BB5C(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad;
    f32 sp38;
    f32 sp2C[3];

    if ((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) {
        sp38 = func_8009BB5C(arg0);
        func_8009C128(arg0, sp2C);
        func_800C35E8((*(u8 *)((s8 *)(arg0) + (0x165))), sp2C);
        func_800C31DC((*(u8 *)((s8 *)(arg0) + (0x165))), func_800F10B4(sp38, 0.0f, 900.0f, 0.9f, 1.2f));
    }
}

void func_8080100C_bswasher(s32 arg0)
{
    func_80800F1C_bswasher(arg0);
    func_808000F0_bswasher(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801034_bswasher.s")

/* extern */

void func_808010DC_bswasher(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    s32 bakey_pressed(s32, s32);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    s32 func_80800000_bswasher(s32);
    s32 func_80800300_bswasher(s32);
    s32 var_s1;

    var_s1 = 0;
    func_80800F88_bswasher(arg0);
    func_8009D3A8(arg0, 0);
    func_80800000_bswasher(arg0);
    if (bastick_getZone(arg0) == 0) {
        var_s1 = 0x32;
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x36;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x35;
    }
    if (bakey_pressed(arg0, 1) != 0) {
        var_s1 = 0x38;
    }
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, var_s1);
}

s32 bswasher_entrypoint_5(s32 arg0) {
    extern s32 D_80801E60_bswasher[];
    return ((s32 *)&D_80801E60_bswasher)[arg0];
}

void func_808011B4_bswasher(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808000F0_bswasher(arg0);
}
void func_808011DC_bswasher(s32 arg0) { func_808001A8_bswasher(); _baspin_entrypoint_2(arg0, 0x358, 0x3FE66666, 2, 0); }

/* extern */

void func_80801218_bswasher(struct player_state_s *arg0) {
    s32 _baspin_entrypoint_3(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8009640C(struct player_state_s *);
    void func_800A2EAC(void *);
    s32 func_80800300_bswasher(s32);
    s32 sp24;
    struct player_state_s *self;

    self = arg0;
    sp24 = 0;
    func_80800300_bswasher(self);
    if (func_8009640C(self) != 0) {
        func_800A2EAC(self);
    }
    if (_baspin_entrypoint_3(self) == 2) {
        sp24 = 0x32;
    }
    bs_setState(self, sp24);
}

s32 bswasher_entrypoint_6(s32 arg0) {
    extern s32 D_80801E70_bswasher[];
    return ((s32 *)&D_80801E70_bswasher)[arg0];
}

void func_80801294_bswasher(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808000F0_bswasher(arg0);
}
/* extern */

void func_808012BC_bswasher(struct player_state_s *arg0) {
    struct anctrl_s;
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    func_808001A8_bswasher();
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x358, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_80801314_bswasher(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    void bs_setState(struct player_state_s *, int);
    s32 func_80800000_bswasher(s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800000_bswasher(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x32;
    }
    bs_setState(arg0, sp1C);
}

s32 bswasher_entrypoint_7(s32 arg0) {
    extern s32 D_80801E80_bswasher[];
    return ((s32 *)&D_80801E80_bswasher)[arg0];
}

void func_8080137C_bswasher(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808000F0_bswasher(arg0);
}
void func_808013A4_bswasher(s32 arg0)
{
    func_808001A8_bswasher();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808013CC_bswasher(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    void bs_setState(struct player_state_s *, int);
    s32 func_80800300_bswasher(s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, sp1C);
}

s32 bswasher_entrypoint_8(s32 arg0) {
    extern s32 D_80801E90_bswasher[];
    return ((s32 *)&D_80801E90_bswasher)[arg0];
}

void func_8080142C_bswasher(s32 arg0)
{
    func_808000F0_bswasher();
    func_80090A2C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801454_bswasher.s")

/* extern */

void func_808014C8_bswasher(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    s32 bakey_pressed(s32, s32);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 func_80800064_bswasher(s32, s32);
    s32 func_80800300_bswasher(s32);
    s32 var_s1;

    var_s1 = 0;
    func_8009D3A8(arg0, 0);
    if ((baanim_isAt(arg0, 0.1487f) != 0) || (baanim_isAt(arg0, 0.2737f) != 0)) {
        func_8009DEC0(arg0, 0x4A1, 0.9f, 1.1f, 0xBB8, 0xFA0);
    }
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x36;
    }
    if (bastick_getZone(arg0) != 0) {
        var_s1 = 0x33;
    }
    var_s1 = func_800A02DC(arg0, func_80800064_bswasher(arg0, var_s1));
    if (bakey_pressed(arg0, 1) != 0) {
        var_s1 = 0x38;
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, var_s1);
}

s32 bswasher_entrypoint_9(s32 arg0) {
    extern s32 D_80801EA0_bswasher[];
    return ((s32 *)&D_80801EA0_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808015EC_bswasher.s")

void func_80801744_bswasher(s32 arg0)
{
    func_808015EC_bswasher(arg0,0);
    func_808000F0_bswasher(arg0);
}

void func_80801770_bswasher(s32 arg0) { func_808001A8_bswasher(); *(s32 *)((u8 *)arg0 + 0x15C) = 0; func_808015EC_bswasher(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808017A0_bswasher.s")

s32 bswasher_entrypoint_10(s32 arg0) {
    extern s32 D_80801EC4_bswasher[];
    return ((s32 *)&D_80801EC4_bswasher)[arg0];
}

void func_80801B10_bswasher()
{
    func_808000F0_bswasher();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801B30_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801BA4_bswasher.s")

s32 bswasher_entrypoint_11(s32 arg0) {
    extern s32 D_80801ED4_bswasher[];
    return ((s32 *)&D_80801ED4_bswasher)[arg0];
}

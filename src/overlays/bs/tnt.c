#include "common.h"

void func_80800000_bstnt(void *arg0) {
    void func_8009DF94(void *, s32, f32, s32);
    func_8009DF94(arg0, 0x504, 1.0f, 0x7FFF);
}

void func_80800028_bstnt(s32 arg0) {
    s32 func_800C2FDC(u8 index);
    u8 index;

    index = *(u8 *)((s8 *)arg0 + 0x160);
    if (index != 0) {
        func_800C2FDC(index);
    }
    *(u8 *)((s8 *)arg0 + 0x160) = 0;
}

void func_80800060_bstnt(s32 arg0) 
{
}
void func_80800068_bstnt(void *arg0) {
    extern s32 D_80802230_bstnt;
    (*(s8 *)((s8 *)(arg0) + (0x160))) = func_8009D454(arg0, 0, &D_80802230_bstnt);
}

/* extern */

void func_8080009C_bstnt(void *arg0) {
    s32 func_800C2FDC(u8 index);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x160)));
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1);
    }
    (*(u8 *)((s8 *)(arg0) + (0x160))) = 0U;
}

/* extern */

void func_808000D4_bstnt(void *arg0, f32 arg1) {
    void _bapulse_entrypoint_3(void *, f32, f32);
    f32 _batimer_get(void *, s32);
    void _batimer_set(void *, s32, f32);
    void func_80092744(s32 *, s32);
    void func_80092750(void *, s32, s32, s32, s32);
    if (_batimer_get(arg0, 2) == 0.0f) {
        _bapulse_entrypoint_3(arg0, 0.0f, 0.15f);
        func_80092744(arg0, 1);
        func_80092750(arg0, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    _batimer_set(arg0, 2, arg1);
}

struct player_state_s;
void func_80800164_bstnt(struct player_state_s *arg0) {
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 600.0f));
}

/* extern */

struct player_state_s;

 s32 func_808001C8_bstnt(void *arg0, s32 arg1) {
    int bakey_pressed(struct player_state_s *, int);
    s32 bstnt_entrypoint_8(struct player_state_s *);

    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        arg1 = 0x10E;
    }
    return arg1;
}

/* extern */

s32 func_80800218_bstnt(void *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(void *);
    s32 bainput_should_enter_first_person();
    int bakey_pressed(struct player_state_s *, int);
    s32 bstnt_entrypoint_8(struct player_state_s *);
    int player_isStable(void *);
    s32 var_s1;

    var_s1 = arg1;
    if (bainput_should_enter_first_person() != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        var_s1 = 0x10E;
    }
    if (((*(u8 *)((s8 *)(arg0) + (0x168))) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x10D;
    }
    return var_s1;
}

void func_808002AC_bstnt(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_8080223C_bstnt;
    extern s32 D_80802284_bstnt;
    func_800BBCB8(arg1, 0, 0x3F800000, 8, &D_8080223C_bstnt);
    func_800BBCB8(arg1, 0, 0x3F800000, 0xC, &D_80802284_bstnt);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080030C_bstnt.s")

struct player_state_s;

void func_808004F8_bstnt(struct player_state_s *arg0, f32 *arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 *func_800A4C48(struct player_state_s *);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_808022FC_bstnt;
    f32 sp24[3];

    func_800EE7F8(sp24, arg1);
    func_800CA3F4(func_800A4C48(arg0), sp24, 80.0f);
    func_800BBCB8((s32) sp24, 0, 0x3F800000, 1, &D_808022FC_bstnt);
}

void func_80800554_bstnt(struct player_state_s *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    f32 *func_800A4C48(struct player_state_s *);
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_80802328_bstnt;
    extern s32 D_808023C8_bstnt;
    f32 sp2C[3];
    s32 sp28;
    s32 temp_v0;

    func_8009C128(arg0, sp2C);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 20.0f);
    temp_v0 = func_800B5BE4(8);
    sp28 = temp_v0;
    func_800BABB8(temp_v0, sp2C, NULL, 1.0f, &D_80802328_bstnt);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 45.0f);
    func_800BABB8(sp28, sp2C, NULL, 1.0f, &D_808023C8_bstnt);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808005F4_bstnt.s")

/* extern */

void func_80800668_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    func_8009E474();
    baflag_clear(arg0, 0x32);
}

void func_80800694_bstnt()
{
    func_8009E4AC();
}

/* extern */

void func_808006B4_bstnt(u8 *arg0, s32 arg1) {
    void baflag_set(void *, s32);
    void func_8009E55C(void *, s32, f32);
    (*(s8 *)((s8 *)(arg0) + (0x169))) = arg1;
    baflag_set(arg0, 0x32);
    func_8009E55C(arg0, 1, 200.0f);
}

/* extern */

void func_808006EC_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_8009E55C(void *, s32, f32);
    func_8009E55C(arg0, 1, 28.0f);
    baflag_clear(arg0, 0x32);
}

/* extern */

void func_80800720_bstnt(s32 arg0) {
    f32 func_800F0E00(f32, f32);
    (*(u8 *)((s8 *)(arg0) + (0x169))) = func_800F0E00((f32) ((*(u8 *)((s8 *)(arg0) + (0x169))) - 1), 0.0f);
    if (!(*(u8 *)((s8 *)(arg0) + (0x169)))) {
        func_808006EC_bstnt(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808007EC_bstnt.s")

/* extern */

void func_8080092C_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(s32, s32);
    func_80800668_bstnt(arg0);
    func_80800028_bstnt(arg0);
    func_808007EC_bstnt(arg0, 0);
}

/* extern */

void func_80800960_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(s32, s32);
    func_80800694_bstnt();
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808007EC_bstnt(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800998_bstnt.s")

s32 bstnt_entrypoint_0(s32 arg0) {
    extern s32 D_808023F8_bstnt[];
    return ((s32 *)&D_808023F8_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800B60_bstnt.s")

void func_800951B4(struct player_state_s *);

void func_80800CB0_bstnt(s32 arg0)
{
    func_80800028_bstnt(arg0);
    func_800951B4(arg0);
}
/* extern */

void func_80800CD8_bstnt(s32 arg0) {
    s32 func_80800B60_bstnt(s32, s32);
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_80800B60_bstnt(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800D08_bstnt.s")

s32 bstnt_entrypoint_1(s32 arg0) {
    extern s32 D_80802408_bstnt[];
    return ((s32 *)&D_80802408_bstnt)[arg0];
}

void bstnt_entrypoint_2(void *arg0) {
    typedef struct player_state_s PlayerState;
    void baroll_resetAngularVelocity(PlayerState *);
    void bastick_popZone(PlayerState *);
    void func_80092744(s32 *, s32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_8009C000(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 0xC) == 0) {
        func_800947EC(arg0, 1, 0);
        func_80092864(arg0, 1.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        func_80095A40(arg0);
        func_80092744(arg0, 0);
    }
}

void bstnt_entrypoint_3(void *arg0) {
    typedef struct player_state_s PlayerState;
    void _batimer_set(void *, s32, f32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 0xC) == 0) {
        *(s32 *)((u8 *)arg0 + 0x164) = 0;
        *(s8 *)((u8 *)arg0 + 0x168) = 0;
        *(s8 *)((u8 *)arg0 + 0x16A) = 0;
        _batimer_set(arg0, 2, 0.0f);
        func_80092864(arg0, 0.8999939f);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 85.0f, 38.0f);
        func_800947EC(arg0, 1, 1);
    }
}

/* extern */

void bstnt_entrypoint_4(void *arg0) {
    f32 _bapulse_entrypoint_1(void *);
    s32 _bapulse_entrypoint_2(void *);
    s32 _bapulse_entrypoint_4(void *);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    void func_80092744(s32 *, s32);
    void func_80092750(void *, s32, s32, s32, s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 temp_f8;

    if (_batimer_decrement(arg0, 2) != 0) {
        func_80092744(arg0, 0);
        _bapulse_entrypoint_2(arg0);
    } else if (_batimer_get(arg0, 2) > 0.0f) {
        _bapulse_entrypoint_4(arg0);
        temp_f8 = (s32) func_800F12D4(_bapulse_entrypoint_1(arg0), 0.0f, 1.0f, 0.0f, 255.0f);
        func_80092750(arg0, 0xFF, temp_f8, temp_f8, 0xFF);
    }
    (*(s8 *)((s8 *)(arg0) + (0x168))) = 0;
}

void func_80801058_bstnt(s32 arg0)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801080_bstnt.s")

void func_80801190_bstnt(s32 arg0)
{
    _basudie_entrypoint_10();
    bstnt_entrypoint_4(arg0);
}
s32 bstnt_entrypoint_5(s32 arg0) {
    extern s32 D_8080254C_bstnt[];
    return ((s32 *)&D_8080254C_bstnt)[arg0];
}

void func_808011CC_bstnt(s32 arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808011F4_bstnt(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstnt_entrypoint_4(arg0);
}
void func_8080121C_bstnt(s32 arg0)
{
    bstnt_entrypoint_2(arg0);
    _bsdrone_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_6(s32 arg0) {
    extern s32 D_8080255C_bstnt[];
    return ((s32 *)&D_8080255C_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801258_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808012F8_bstnt.s")

/* extern */

void func_80801464_bstnt(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_7(s32 arg0) {
    extern s32 D_8080256C_bstnt[];
    return ((s32 *)&D_8080256C_bstnt)[arg0];
}

/* extern */

s32 bstnt_entrypoint_8(struct player_state_s *arg0) {
    int bakey_pressed(struct player_state_s *, int);
    s32 func_800A1718(struct player_state_s *);
    void func_800FC660(u32);
    if (bakey_pressed(arg0, 9) == 0) {
        return 0;
    }
    if (func_800A1718(arg0) >= 2) {
        return 1;
    }
    func_800FC660(0xF);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080150C_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080166C_bstnt.s")

void func_808018D0_bstnt(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_9(s32 arg0) {
    extern s32 D_8080257C_bstnt[];
    return ((s32 *)&D_8080257C_bstnt)[arg0];
}

/* extern */

void bstnt_entrypoint_10(void *arg0) {
    s32 func_80099A4C(void *);
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    if (func_8009E6EC() == 0x42) {
        (*(s32 *)((s8 *)(arg0) + (0x164))) = func_80099A4C(arg0);
        (*(s8 *)((s8 *)(arg0) + (0x168))) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801980_bstnt.s")

void func_80801C0C_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); *(s32 *)((u8 *)arg0 + 0x15C) = 0; func_80801980_bstnt(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801C3C_bstnt.s")

void func_80801E20_bstnt(s32 arg0)
{
    func_80801980_bstnt(arg0,0);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_11(s32 arg0) {
    extern s32 D_8080258C_bstnt[];
    return ((s32 *)&D_8080258C_bstnt)[arg0];
}

void func_80801E60_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801EA0_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    s32 bs_setState(s32, s32);
    void func_800951B4(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    if (baanim_isAt(arg0, 0.5f) != 0) {
        func_800951B4(arg0);
    }
    if (_babounce_entrypoint_2(arg0) != 0) {
        func_80800164_bstnt(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp24 = 0x10C;
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp24);
}

void func_80801F20_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_12(s32 arg0) {
    extern s32 D_8080259C_bstnt[];
    return ((s32 *)&D_8080259C_bstnt)[arg0];
}

void func_80801F5C_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801F9C_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 sp24;
    struct player_state_s *self;

    self = arg0;
    sp24 = 0;
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800164_bstnt(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        sp24 = 0x10C;
    }
    bstnt_entrypoint_4(self);
    bs_setState(self, sp24);
}

void func_80802000_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_13(s32 arg0) {
    extern s32 D_808025AC_bstnt[];
    return ((s32 *)&D_808025AC_bstnt)[arg0];
}

void func_8080203C_bstnt(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstnt_entrypoint_2(arg0);
}
void func_80802064_bstnt(s32 arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_8080208C_bstnt(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp1C);
}

s32 bstnt_entrypoint_14(s32 arg0) {
    extern s32 D_808025BC_bstnt[];
    return ((s32 *)&D_808025BC_bstnt)[arg0];
}

void func_808020EC_bstnt(s32 arg0)
{
    bstnt_entrypoint_2(arg0);
    func_80090A2C(arg0);
}
void func_80802114_bstnt(void *arg0) {
    void *self;
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    bstnt_entrypoint_3(self);
    baanim_playForDuration_loopSmooth(self, 0xE5, 0x40D00000);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_8080217C_bstnt(struct player_state_s *arg0) {
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 player_inWater(struct player_state_s *);
    s32 next_state;

    next_state = 0;
    if (bastick_getZone(arg0) > 0) {
        next_state = 0x108;
    }
    if (player_inWater(arg0) != 0) {
        next_state = 0x111;
    }
    next_state = func_80800218_bstnt(arg0, next_state);
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, next_state);
}

s32 bstnt_entrypoint_15(s32 arg0) {
    extern s32 D_808025CC_bstnt[];
    return ((s32 *)&D_808025CC_bstnt)[arg0];
}

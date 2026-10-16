#include "core2/1E66990.h"

int func_8008D0A0(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(0) && func_800A3304(player);
}

int func_8008D0E0(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(1) && baflag_isFalse(player, 0x39)
        && (func_800A3304(player) || func_800A3274(player) == 0xB);
}

int func_8008D14C(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(2) && func_800A3304(player);
}

void func_8008D18C(s32 arg0)
{
    func_800C6E38(0x3);
}

int func_8008D1B0(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(4) && func_800A3304(player);
}

void func_8008D1F0(s32 arg0)
{
    func_800C6E38(0x5);
}

int func_8008D214(PlayerState *player) {
    int func_800C6E38(s32);
    f32 func_800964DC(PlayerState *);
    f32 func_80096364(PlayerState *);
    return func_800C6E38(0xF) && func_800964DC(player) - func_80096364(player) > 100.0f;
}

int func_8008D280(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    s32 func_800DA298(s32);
    s32 transformation;

    if (func_800C6E38(6) == 0) {
        return 0;
    }
    if (func_800DA298(0x6B6) != 0) {
        return 0;
    }
    transformation = func_800A3274(player);
    if (((transformation == 1) || (transformation == 0xA)) && (func_800A3304(player) == 0)) {
        return 0;
    }
    return 1;
}

int func_8008D304(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return baflag_isFalse(player, 0x12) && baflag_isFalse(player, 5)
        && func_800C6E38(7) && func_800A3304(player);
}

int func_8008D370(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(8) && func_800A3304(player);
}

int func_8008D3B0(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800F64A4(s32, s32);
    return baflag_isTrue(player, 1) && func_800C6E38(9) && func_800F64A4(player->unk184, 0x401);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008D40C.s")

s32 func_8008D544(PlayerState* arg0)
{
    return func_800C6E38(0xA);
}

int func_8008D568(PlayerState *player) {
    int func_800C6E38(s32);
    return func_800C6E38(0x29) && baflag_isFalse(player, 5) && baflag_isFalse(player, 0x12);
}

int func_8008D5C4(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return baflag_isFalse(player, 0x5) && baflag_isFalse(player, 18)
        && func_800C6E38(11) && func_800A3304(player);
}

int func_8008D630(PlayerState *player) {
    s32 bs_getCurrentState(PlayerState *);
    if (baflag_isTrue(player, 0x14) || baflag_isTrue(player, 0x19)) return 0;
    if (bs_getCurrentState(player) == 0x56) return 0;
    return 1;
}

int func_8008D694(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(12) && func_800A3304(player);
}

int func_8008D6D4(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(13) && func_800A3304(player);
}

int func_8008D714(PlayerState *arg0) {
    s32 _baduo_entrypoint_3();
    s32 func_800A3304(PlayerState *);

    return _baduo_entrypoint_3() && func_800A3304(arg0);
}

int func_8008D750(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(14) && func_800A3304(player);
}

int func_8008D790(PlayerState *player) {
    s32 _baduo_entrypoint_4(void);
    s32 func_800C954C(void);
    int func_800DB9B0(void);
    s32 func_800F6D24(s32);
    int func_800F8004(s32);
    return _baduo_entrypoint_4()
        && !func_8008E39C(player)
        && player_isStable(player)
        && !func_800C954C()
        && !func_800DB9B0()
        && !func_800F8004(player->unk184)
        && !func_800F6D24(player->unk184)
        && baflag_isFalse(player, 0x34);
}

int func_8008D850(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    s32 _bafpctrl_entrypoint_5(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_800EA05C();
    extern f32 D_80124AD4;
    f32 position[3];

    if (func_800C6E38(0x1E) && func_800A3304(player) && !_bafpctrl_entrypoint_5(player)) {
        func_8009C128(player, position);
        if (func_800EA05C() == 0x117 && position[2] < D_80124AD4) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int func_8008D8E4(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(16) && func_800A3304(player);
}

int func_8008D924(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(16) && func_800A3304(player);
}

int func_8008D964(PlayerState *player) {
    int func_800C6E38(s32);
    s32 func_800A3304(PlayerState *);
    return func_800C6E38(18) && func_800A3304(player);
}

int func_8008D9A4(PlayerState *player) {
    s32 _ncba1p_entrypoint_10();
    PlayerState *func_800A4CA8(PlayerState *);
    s32 func_800A4D40(void *);
    int player_isStable(PlayerState *);
    s32 player_inWater(PlayerState *);

    if (_ncba1p_entrypoint_10(func_800A4CA8(player)) == 3) {
        return 0;
    }
    if (!func_800A4D40(player)) {
        return 0;
    }
    if (!player_isStable(player) && !player_inWater(player)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008DA24.s")

/* extern */

void func_8008DAA8(void *arg0) {
    s32 func_800F65D0(s32);
    func_800F65D0((*(s32 *)((s8 *)(arg0) + (0x184))));
}

/* extern */

void func_8008DAC8(s32 arg0) {
    int func_800DB9B0(void);
    func_800DB9B0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008DAE8.s")

int func_8008DC90(PlayerState *player, f32 *target, f32 tolerance) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_8008FF40(f32[3]);
    void func_800F18FC(f32 *, f32 *, f32 *);
    int func_800F20BC(f32, f32, f32);
    f32 rotation[3];
    f32 position[3];
    f32 angles[2];

    func_8009C128(player, position);
    func_8008FF40(rotation);
    func_800F18FC(position, target, angles);
    return func_800F20BC(rotation[0], angles[0], tolerance) != 0 &&
           func_800F20BC(rotation[1], angles[1], tolerance) != 0;
}

/* extern */

int func_8008DD04(PlayerState *arg0) {
    f32 func_80096364(PlayerState *);
    f32 func_8009C150(PlayerState *);
    int player_isStable(PlayerState *);
    f32 sp1C;

    sp1C = func_8009C150(arg0);
    return (60.0f < sp1C - func_80096364(arg0)) && !player_isStable(arg0);
}

void func_8008DD70(s32 arg0)
{
    func_8009E71C(arg0,0x5);
}

s32 func_8008DD90(PlayerState *arg0) {
    s32 _badrone_entrypoint_1(PlayerState *);
    s32 func_8009E674(PlayerState *, s32);

    if (func_8009E674(arg0, 0x10) != 0) {
        return 1;
    }
    if (func_8009E674(arg0, 8) != 0) {
        return _badrone_entrypoint_1(arg0) == 0;
    }
    return 0;
}

s32 func_8008DDEC(PlayerState *player, f32 position[3], f32 radius) {
    void func_8009C128(PlayerState *, f32 *);
    s32 func_800F0064(f32 *, f32, f32 *);
    f32 player_position[3];
    func_8009C128(player, player_position);
    return func_800F0064(position, radius, player_position);
}

s32 func_8008DE24(PlayerState* arg0)
{
    func_80096568(arg0,0xE00);
}

s32 func_8008DE44(u8 arg0)
{
    return 0;
}

/* extern */

s32 func_8008DE50(void) {
    s32 func_80096694();
    return func_80096694() == 3;
}

/* extern */

void func_8008DE74(s32 arg0) {
    s32 bs_getCurrentState();
    s32 func_8009CA70(s32, s32, s32);
    func_8009CA70(arg0, bs_getCurrentState(), 0x4000);
}

int func_8008DEA4(PlayerState *player, f32 position[3], f32 range) {
    void func_8009C128(PlayerState *, f32 *);
    f32 plyr_pos[3];
    func_8009C128(player, plyr_pos);
    return ((position[1] - range) <= plyr_pos[1]) && (plyr_pos[1] <= position[1] + range);
}

int func_8008DF18(PlayerState *player) {
    s32 bastatetimer_isActive(PlayerState *, s32);
    f32 func_800A3378(PlayerState *);
    s32 func_8009659C(PlayerState *, s32);
    return bastatetimer_isActive(player, 6) || (func_800A3378(player) == 1.0f && func_8009659C(player, 0x40));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008DF8C.s")

int player_isStable(PlayerState *player) {
    s32 func_800A0FCC(void);
    f32 baphysics_get_vertical_velocity(PlayerState *);
    return func_800A0FCC() && baphysics_get_vertical_velocity(player) < 0.0f;
}

s32 func_8008E0C8(PlayerState *arg0)
{
    s32 _bapackctrl_entrypoint_1(PlayerState *);
    return _bapackctrl_entrypoint_1(arg0);
}

int func_8008E0E8(PlayerState *arg0) {
    return func_8008E23C(arg0) && !func_8008E0C8(arg0);
}

s32 func_8008E124(PlayerState *arg0) {
    s32 func_8009CC68(PlayerState *self);
    return func_8009CC68(arg0) != 0;
}

int func_8008E148(PlayerState *player) {
    s32 bastatetimer_isActive(PlayerState *, s32);
    f32 func_800A3378(PlayerState *);
    return bastatetimer_isActive(player, 5) || func_800A3378(player) == 1.0f;
}

/* extern */

s32 func_8008E1A0(void) {
    s32 func_80096694();
    return func_80096694() == 24;
}

int func_8008E1C4(PlayerState *player) {
    s32 func_8009659C(PlayerState *, s32);
    int sp1C;
    int sp18;
    sp1C = func_8009659C(player, 0x10) && baflag_isFalse(player, 3);
    sp18 = func_8009659C(player, 0x40) && baflag_isFalse(player, 4);
    if (sp1C || sp18) return 1;
    return 0;
}

/* extern */

s32 func_8008E23C(PlayerState *arg0) {
    s32 func_800F8B88();
    return func_800F8B88() == 2;
}

/* extern */

s32 func_8008E260(PlayerState *arg0) {
    s32 func_800954E8(PlayerState *, s32 *);
    int player_isStable();
    s32 sp1C;

    if (player_isStable() != 0) {
        return 0;
    }
    if (func_800954E8(arg0, &sp1C) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008E2AC.s")

int func_8008E300(PlayerState *player) {
    f32 yaw_getIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    return 135.0f < mlAbsF(func_800F1DCC(yaw_getIdeal(player), yaw_get(player)));
}

s32 player_inWater(PlayerState *player)
{
    s32 func_800A0FD8(PlayerState *);
    return func_800A0FD8(player);
}

void func_8008E37C()
{
    func_800A0FE4();
}

int func_8008E39C(PlayerState *arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    s32 temp_v0 = _bashoes_entrypoint_1(arg0);
    return !(temp_v0 == 1) && !(temp_v0 == 0) && !(temp_v0 == 2);
}

s32 func_8008E3E8(PlayerState *arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    return _bashoes_entrypoint_1(arg0) == 3;
}

/* extern */

s32 func_8008E40C(PlayerState *arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    return _bashoes_entrypoint_1(arg0) == 4;
}

/* extern */

s32 func_8008E430(PlayerState *arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    return _bashoes_entrypoint_1(arg0) == 5;
}

/* extern */

s32 func_8008E454(PlayerState *arg0) {
    s32 _gcmapsects_entrypoint_4(f32 *);
    void func_8009C128(PlayerState *, f32[3]);
    u8 func_800BFAA4(void);
    int func_800DB9B0(void);
    f32 sp1C[3];

    if ((func_800DB9B0() != 0) && (func_800BFAA4() != 0)) {
        func_8009C128(arg0, sp1C);
        return (_gcmapsects_entrypoint_4(sp1C) + 1) != 0;
    }
    return 1;
}

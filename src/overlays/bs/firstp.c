#include "bs/firstp.h"

struct player_state_s;
enum asset_e;

struct anctrl_s;
struct player_state_s;
enum asset_e;
enum asset_e;

/* extern */

u8 *func_80800000_bsfirstp(u8 *arg0) {
    s32 aligned8_memset(s32 dst, s32 value, s32 size);
    void _bastatemem_entrypoint_0(s32, s32);
    u8 *sp1C;
    s32 pad;

    _bastatemem_entrypoint_0((s32)arg0, 0x2A8);
    sp1C = (*(u8 **)((s8 *)(arg0) + (0x188)));
    aligned8_memset((s32)sp1C, 0, 0x2A8);
    return sp1C;
}

void func_80800040_bsfirstp()
{
    _bastatemem_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_1.s")

void func_80800190_bsfirstp(u8 *arg0) {
    s32 func_800EFD24(s32);
    s32 func_80800858_bsfirstp(s32, s32);
    u8 *sp1C;

    sp1C = (*(u8 **)((s8 *)(arg0) + (0x188)));
    func_80800858_bsfirstp((s32) arg0, 0);
    func_800EFD24((s32) (sp1C + 0x2C));
    (*(f32 *)((s8 *)(sp1C) + (0x50))) = 0.0f;
}

/* extern */

void func_808001D0_bsfirstp(s32 arg0) {
    s32 func_80800858_bsfirstp(s32, s32);
    void func_80808C48_bsfirstp(struct player_state_s *);
    func_80808C48_bsfirstp(arg0);
    func_80800858_bsfirstp(arg0, 0);
}

/* extern */

void func_808001FC_bsfirstp(struct player_state_s *arg0) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    anctrl_setPlaybackType(func_8008D04C(arg0), 3);
}

/* extern */

s32 func_80800228_bsfirstp(struct player_state_s *arg0) {
    s32 anctrl_getPlaybackType(s32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    s32 var_v1;

    if (anctrl_getPlaybackType(func_8008D04C(arg0)) == 3) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

void func_80800264_bsfirstp(s32 arg0, s32 arg1) {
    s32 func_8008B10C(s32, s32);
    struct anctrl_s *func_8008D04C();
    func_8008B10C(func_8008D04C(arg0), arg1);
}

/* extern */

void func_80800290_bsfirstp(struct player_state_s *arg0, s32 arg1, f32 arg2) {
    f32 baanim_getTimer();
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    baanim_playForDuration_loopStartingAt(arg0, arg1, arg2, baanim_getTimer());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808002CC_bsfirstp.s")

/* extern */

void func_80800340_bsfirstp(struct player_state_s *self, s32 arg1, f32 arg2, f32 arg3) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_8008D04C(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setStart(temp_v0, arg3);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
}

/* extern */

void func_808003B4_bsfirstp(struct player_state_s *self, s32 arg1, f32 arg2) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_8008D04C(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
}

/* extern */

void func_80800424_bsfirstp(struct player_state_s *self, s32 arg1, f32 arg2) {
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_8008D04C(self);
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
}

/* extern */

void func_80800488_bsfirstp(struct player_state_s *self, s32 arg1, f32 arg2) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_8008D04C(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setPlaybackType(temp_v0, 2);
    anctrl_start(temp_v0);
}

s32 func_808004F8_bsfirstp(u8 *arg0) {
    s32 func_800EEC70(u8 *, f32, f32, s32);
    f32 yaw_get(struct player_state_s *);
    u8 *sp1C;
    f32 sp18;
    sp1C = (*(u8 **)((s8 *)(arg0) + (0x188)));
    sp18 = (*(f32 *)((s8 *)(sp1C) + (0x20C)));
    return func_800EEC70(sp1C + 0x2C, sp18, yaw_get(arg0), 0x43160000);
}

/* extern */

void func_8080053C_bsfirstp(void *arg0) {
    s32 func_800EFD24(s32);
    s32 func_808004F8_bsfirstp();
    s32 sp1C;

    sp1C = (*(s32 *)((s8 *)(arg0) + (0x188)));
    func_808004F8_bsfirstp();
    func_800EFD24(sp1C + 0x38);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080056C_bsfirstp.s")

/* extern */

void func_808006DC_bsfirstp(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013970(f32);
    f32 mlAbsF(f32);
    f32 temp_f0;
    f32 var_f14;
    f32 var_f2;
    f32 var_f20;
    void *temp_s0;

    temp_s0 = (*(void **)((s8 *)(arg0) + (0x188)));
    temp_f0 = mlAbsF((*(f32 *)((s8 *)(temp_s0) + (0x44))));
    var_f14 = temp_f0;
    var_f2 = (*(f32 *)((s8 *)(temp_s0) + (0x48)));
    if ((*(s32 *)((s8 *)(temp_s0) + (0))) == 3) {
        var_f14 = temp_f0 * 1.333f;
        var_f2 *= 1.333f;
    }
    temp_f0 = var_f2 * 0.75f;
    if (temp_f0 < var_f14) {
        var_f20 = var_f14;
    } else {
        var_f20 = temp_f0;
    }
    if (var_f20 != 0.0f) {
        temp_f0 = func_800136E4((*(f32 *)((s8 *)(temp_s0) + (0x54))) + (var_f20 * 12.5f));
        (*(f32 *)((s8 *)(temp_s0) + (0x54))) = temp_f0;
        (*(f32 *)((s8 *)(temp_s0) + (0x58))) = (f32) (func_80013970(temp_f0) * var_f20);
    } else {
        (*(f32 *)((s8 *)(temp_s0) + (0x54))) = 0.0f;
        (*(f32 *)((s8 *)(temp_s0) + (0x58))) = 0.0f;
    }
    temp_f0 = var_f14 * 0.75f;
    if (temp_f0 < var_f2) {
        var_f20 = var_f2;
    } else {
        var_f20 = temp_f0;
    }
    if (var_f20 != 0.0f) {
        temp_f0 = func_800136E4((*(f32 *)((s8 *)(temp_s0) + (0x5C))) + (var_f20 * 25.0f));
        (*(f32 *)((s8 *)(temp_s0) + (0x5C))) = temp_f0;
        (*(f32 *)((s8 *)(temp_s0) + (0x60))) = (f32) (func_80013970(temp_f0) * var_f20);
        return;
    }
    (*(f32 *)((s8 *)(temp_s0) + (0x5C))) = 0.0f;
    (*(f32 *)((s8 *)(temp_s0) + (0x60))) = 0.0f;
}

void func_80800830_bsfirstp(s32 arg0)
{
    func_8080056C_bsfirstp();
    func_808006DC_bsfirstp(arg0);
}
s32 func_80800858_bsfirstp(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    (*(s32 *)((s8 *)(temp_v0) + (0x28))) = arg1;
    return (s32) temp_v0;
}

s32 func_80800864_bsfirstp(void *arg0) {
    s32 result;
    s32 *ptr;
    ptr = (s32 *)(*(void **)((s8 *)(arg0) + (0x188)));
    result = 0;
    return *(ptr + 10) != 0 ? 1 : result;
}

/* extern */

void func_80800888_bsfirstp(u8 *arg0, s32 arg1) {
    s32 func_80800900_bsfirstp(u8 *, f32);
    s32 *ptr;
    ptr = (s32 *)(*(void **)((s8 *)(arg0) + (0x188)));
    *(ptr + 35) = arg1;
    func_80800900_bsfirstp(arg0, 1.0f);
}

/* extern */

void func_808008B0_bsfirstp(u8 *arg0) {
    f32 func_800D9004();
    s32 func_80800900_bsfirstp(u8 *, f32);
    u8 *sp1C;
    f32 sp18;
    f32 sp14;

    sp1C = (*(u8 **)((s8 *)(arg0) + (0x188)));
    sp18 = func_800D9004() * 5.5f;
    sp14 = (*(f32 *)((s8 *)(sp1C) + (0x90))) - sp18;
    func_80800900_bsfirstp(arg0, sp14);
}

s32 func_80800900_bsfirstp(u8 *arg0, f32 arg1) {
    extern f32 D_8080A5B0_bsfirstp[][4];
    s32 var_a0;
    void *temp_a1;
    void *temp_v1;

    temp_v1 = (*(void **)((s8 *)(arg0) + (0x188)));
    if (arg1 <= 0.0f) {
        var_a0 = 0;
        arg1 = 0.0f;
    } else {
        var_a0 = 1;
    }
    (*(f32 *)((s8 *)(temp_v1) + (0x90))) = arg1;
    temp_a1 = D_8080A5B0_bsfirstp[*(s32 *)((s8 *)temp_v1 + 0x8C)];
    (*(f32 *)((s8 *)(temp_v1) + (0x18))) = (f32) ((*(f32 *)((s8 *)(temp_a1) + (0))) * arg1);
    (*(f32 *)((s8 *)(temp_v1) + (0x1C))) = (f32) ((*(f32 *)((s8 *)(temp_a1) + (4))) * arg1);
    (*(f32 *)((s8 *)(temp_v1) + (0x20))) = (f32) ((*(f32 *)((s8 *)(temp_a1) + (8))) * arg1);
    (*(f32 *)((s8 *)(temp_v1) + (0x24))) = (f32) ((*(f32 *)((s8 *)(temp_a1) + (0xC))) * arg1);
    return var_a0;
}

void func_80800978_bsfirstp(void *arg0, void *arg1, void *arg2, void *arg3) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f12;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (0xC8))) * 0.02712968f;
    temp_f2 = (*(f32 *)((s8 *)(temp_v0) + (0xCC))) * 0.017686592f;
    if (temp_f0 > 0.0f) {
        var_f12 = -(*(f32 *)((s8 *)(arg1) + (0x34)));
    } else {
        var_f12 = (*(f32 *)((s8 *)(arg1) + (0x38)));
    }
    temp_f0 *= var_f12;
    if (temp_f2 > 0.0f) {
        var_f12 = -(*(f32 *)((s8 *)(arg1) + (0x3C)));
    } else {
        var_f12 = (*(f32 *)((s8 *)(arg1) + (0x40)));
    }
    temp_f2 *= var_f12;
    (*(f32 *)((s8 *)(arg2) + (0))) = (f32) ((*(f32 *)((s8 *)(arg1) + (0x30))) * temp_f0);
    (*(f32 *)((s8 *)(arg3) + (0))) = (f32) ((*(f32 *)((s8 *)(arg1) + (0x30))) * temp_f2);
    (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (temp_f0 - (*(f32 *)((s8 *)(arg2) + (0))));
    (*(f32 *)((s8 *)(arg3) + (4))) = (f32) (temp_f2 - (*(f32 *)((s8 *)(arg3) + (0))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800A18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800B44_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800C88_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800D18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800F14_bsfirstp.s")

void func_80801000_bsfirstp(void *arg0) {
    f32 func_80013728(f32);
    void *func_80092AD8(void *);
    void func_800E0ACC(void *);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    f32 func_800F0DC0(f32, f32);
    f32 func_800F1214(f32, f32, f32);
    void func_80805380_bsfirstp(f32 *, f32, f32, f32);
    f32 func_80806130_bsfirstp(void *);
    f32 func_8080613C_bsfirstp(void *);
    u8 *sp84;
    void *temp_v0;
    f32 pitch[2];
    f32 yaw[2];
    f32 speed;
    f32 y;

    sp84 = *(u8 **)((u8 *)arg0 + 0x188);
    temp_v0 = func_80092AD8(arg0);
    func_800E0ACC(temp_v0);
    func_800E0AF0(temp_v0, 1.0f);
    pitch[0] = func_800F0DC0(func_80806130_bsfirstp(arg0), 80.0f);
    speed = func_800F1214(func_8080613C_bsfirstp(arg0), 360.0f, 720.0f);
    func_80805380_bsfirstp((f32 *)(sp84 + 0x50), pitch[0], speed, speed * 0.041666668f);
    pitch[0] = *(f32 *)(sp84 + 0x50);
    pitch[1] = func_80013728(*(f32 *)(sp84 + 0xCC) + pitch[0]);
    yaw[0] = *(f32 *)(sp84 + 0x20C);
    yaw[1] = func_80013728(*(f32 *)(sp84 + 0xC8) + *(f32 *)(sp84 + 0x20C));
    switch (*(u32 *)sp84) {
    case 1:
    case 5:
    {
        f32 x, z;
        x = 0.0f;
        y = pitch[0];
        z = 0.0f;
        func_800E0AFC(temp_v0, *(u32 *)sp84 == 1 ? 0x2B : 3, 1.0f, x, y, z);
        x = -yaw[0] * 0.4f;
        y *= -0.5f;
        func_800E0AFC(temp_v0, 1, 1.0f, x, y, z);
        x = -yaw[0] * 0.6f;
        func_800E0AFC(temp_v0, 0x12, 1.0f, x, y, z);
        y = (-0.25f * pitch[0]) + (pitch[1] * 0.125f);
        func_800E0AFC(temp_v0, 0x49, 1.0f, -yaw[1] * 0.1f, y, z);
        func_800E0AFC(temp_v0, 0x4B, 1.0f, -yaw[1] * 0.5f, y, z);
        x = 0.0f;
        y = pitch[1] * 0.125f;
        z = pitch[1] * 0.0625f;
        func_800E0AFC(temp_v0, 8, 1.0f, x, y, z);
        y = -yaw[1] * 0.0625f;
        z = yaw[1] * 0.125f;
        func_800E0AFC(temp_v0, 0xE, 1.0f, x, y, z);
        return;
    }
    case 4:
    {
        f32 x, z;
        f32 half_pitch;
        f32 limb_y;
        x = 0.0f;
        half_pitch = pitch[0] * 0.5f;
        z = 0.0f;
        if (half_pitch != 0.0f) {
            func_800E0AFC(temp_v0, 3, 1.0f, x, half_pitch, z);
            func_800E0AFC(temp_v0, 6, 1.0f, x, half_pitch, z);
            func_800E0AFC(temp_v0, 0x14, 1.0f, x, half_pitch, z);
        }
        x = -yaw[0] * 0.4f;
        y = -pitch[0] * 0.25f;
        func_800E0AFC(temp_v0, 1, 1.0f, x, y, z);
        x = -yaw[0] * 0.6f;
        func_800E0AFC(temp_v0, 0x12, 1.0f, x, y, z);
        x = 0.0f;
        limb_y = yaw[1] * 0.25f;
        y = (0.25f * pitch[1]) - (pitch[0] * 0.5f);
        func_800E0AFC(temp_v0, 0x1E, 1.0f, x, limb_y, y);
        func_800E0AFC(temp_v0, 0x3A, 1.0f, x, -limb_y, y);
        return;
    }
    case 2:
    case 3:
    {
        f32 y, z;
        f32 limb_z;
        func_800E0AFC(temp_v0, 3, 1.0f, 0.0f, pitch[0], 0.0f);
        func_800E0AFC(temp_v0, 1, 1.0f, -yaw[0] * 0.4f, -pitch[0] * 0.67f, 0.0f);
        func_800E0AFC(temp_v0, 0x12, 1.0f, -yaw[0] * 0.6f, -pitch[0] * 0.33f, 0.0f);
        y = yaw[1] * 0.25f;
        limb_z = (0.25f * pitch[1]) - (pitch[0] * 0.33f);
        func_800E0AFC(temp_v0, 0x1E, 1.0f, 0.0f, y, limb_z);
        func_800E0AFC(temp_v0, 0x3A, 1.0f, -y, limb_z, 0.0f);
        return;
    }
    case 0:
    {
        func_800E0AFC(temp_v0, 3, 1.0f, 0, pitch[0], 0);
        func_800E0AFC(temp_v0, 0x6C, 1.0f, -yaw[0], -pitch[0], 0);
        return;
    }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808015C0_bsfirstp.s")

int func_800A4C68(void *);

f32 func_80801640_bsfirstp(void *arg0)
{
    f32 func_800C517C(s32);

    return func_800C517C(func_800A4C68(arg0));
}

void func_80801668_bsfirstp(void *arg0, f32 arg1) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x188);
    *(f32 *)((u8 *)temp_v0 + 0x9C) = func_80801640_bsfirstp(arg0);
    *(f32 *)((u8 *)temp_v0 + 0x98) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808016A0_bsfirstp.s")

void func_8080175C_bsfirstp(void *arg0) {
    int func_800A4C68(void *);
    void func_800C5148(s32, f32);
    void *temp_v0;
    f32 value;

    temp_v0 = *(void **)((u8 *)arg0 + 0x188);
    value = *(f32 *)((u8 *)temp_v0 + 0x98);
    *(f32 *)((u8 *)temp_v0 + 0x9C) = value;
    func_800C5148(func_800A4C68(arg0), value);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_2.s")

void func_8080187C_bsfirstp(void *arg0) {
    void func_800A5004(void *);
    s32 func_800A5090(void *);
    void func_800CA6C0(void *, f32, f32);
    if (func_800A5090(arg0) == 0) {
        func_800A5004(arg0);
        func_800CA6C0(func_800A5090(arg0), 1.0f, 1000.0f);
        func_80801668_bsfirstp(arg0, func_80801640_bsfirstp(arg0));
    }
}

/* extern */

void func_808018E0_bsfirstp(s32 arg0) {
    s32 func_800A4C88(s32);
    s32 func_800A4CA8();
    void func_8010FD38(s32, f32);
    s32 func_800A5044(s32);
    s32 func_80110730(s32, s32);
    func_80110730(func_800A4CA8(), 0);
    func_8010FD38(func_800A4C88(arg0), 0.0f);
    func_800A5044(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801928_bsfirstp.s")

/* extern */

void func_808019B0_bsfirstp(s32 arg0) {
    s32 func_800A4C88(s32);
    s32 func_8010FD60(s32, s32);
    s32 *func_80802484_bsfirstp();
    s32 *sp1C;

    sp1C = func_80802484_bsfirstp();
    func_8010FD60(func_800A4C88(arg0), *sp1C);
}

/* extern */

void func_808019EC_bsfirstp(s32 arg0) {
    s32 func_800A4D40();
    s32 func_800A5090(void *);
    void func_8080175C_bsfirstp(void *);
    if ((func_800A4D40() != 0) && (func_800A5090(arg0) != 0)) {
        func_808019B0_bsfirstp(arg0);
        func_8080175C_bsfirstp(arg0);
    }
}

void func_80801A34_bsfirstp(s32 arg0)
{
    func_8080187C_bsfirstp(arg0);
    bsfirstp_entrypoint_2(arg0);
}
void func_80801A5C_bsfirstp(void *arg0) {
    void func_800A3544(void *, s32);
    func_8080187C_bsfirstp(arg0);
    func_800A3544(arg0, 1);
    bsfirstp_entrypoint_2(arg0);
    func_8080175C_bsfirstp(arg0);
}

/* extern */

s32 func_80801A98_bsfirstp(void) {
    s32 _ncba1p_entrypoint_10(s32);
    s32 func_800A4CA8();
    return _ncba1p_entrypoint_10(func_800A4CA8()) == 2;
}

void func_80801AC4_bsfirstp(s32 arg0) {
    int func_80801B64_bsfirstp(s32, s32);
    register s32 temp = *(s32 *)(arg0 + 0x188);
    *(s32 *)(temp + 0xA0) = 0;
    func_80801B64_bsfirstp(arg0, 0);
}

void func_80801AEC_bsfirstp(s32 arg0)
{
    func_80801B64_bsfirstp(arg0,0);
}

/* extern */

void func_80801B0C_bsfirstp(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 bainput_func_80097B28(s32);
    s32 func_800F424C();
    s32 temp_v0;

    if (func_800F424C() != 0) {
        temp_v0 = bainput_func_80097B28(arg0);
        *arg1 = temp_v0;
        *arg2 = temp_v0;
        return;
    }
    *arg1 = 0;
    *arg2 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801B64_bsfirstp.s")

/* extern */

void func_80801BDC_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    void func_80801D70_bsfirstp(u8 *);
    u8 *sp1C;

    sp1C = *(u8 **)((s8 *)arg0 + 0x188);
    _baeggcursor_entrypoint_7(arg0, 1);
    func_80801D70_bsfirstp(arg0);
    *(s32 *)((s8 *)sp1C + 0xA8) = 0;
}

/* extern */

void func_80801C18_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    u8 *sp1C;
    sp1C = *(u8 **)((s8 *)arg0 + 0x188);
    if ((*(s32 *)((s8 *)sp1C + 0xA8) != 0) && (*(s32 *)((s8 *)sp1C + 0xA8) != 2)) {
        _baeggcursor_entrypoint_7(arg0, 1);
        *(s32 *)((s8 *)sp1C + 0xAC) = *(s32 *)((s8 *)sp1C + 0xA8);
        *(s32 *)((s8 *)sp1C + 0xA8) = 2;
        *(s32 *)((s8 *)sp1C + 0xA4) = *(s32 *)((s8 *)sp1C + 0xA0);
        *(s32 *)((s8 *)sp1C + 0xA0) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801C74_bsfirstp.s")

/* extern */

void func_80801D30_bsfirstp(void *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    void func_80802438_bsfirstp(void *, s32);
    register void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 392);
    *(s32 *)((u8 *)temp_v0 + 168) = 1;
    *(s32 *)((u8 *)temp_v0 + 176) = 0;
    _baeggcursor_entrypoint_7(arg0, 1);
    func_80802438_bsfirstp(arg0, 0);
}

/* extern */

void func_80801D70_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_10(void *, f32, f32);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    (*(f32 *)((s8 *)(temp_v0) + (0xB8))) = 152.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0xBC))) = 114.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0xB4))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0xC0))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0xC4))) = 0.0f;
    _baeggcursor_entrypoint_10(arg0, 152.0f, 114.0f);
}

/* extern */

void func_80801DC0_bsfirstp(u8 *arg0) {
    s32 func_80801E18_bsfirstp(u8 *);
    s32 func_80801FD0_bsfirstp(u8 *, s32);
    s32 func_808023A0_bsfirstp(u8 *);
    u8 *temp_v0;
    s32 temp_v1;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    temp_v1 = (*(s32 *)((s8 *)(temp_v0) + (0xA8)));
    if ((temp_v1 == 1) || (temp_v1 == 2)) {
        func_80801E18_bsfirstp(arg0);
        func_80801FD0_bsfirstp(arg0, (*(s32 *)((s8 *)(temp_v0) + (0xC))));
        func_808023A0_bsfirstp(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801E18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801FD0_bsfirstp.s")

/* extern */

f32 func_8080222C_bsfirstp(f32 arg0, f32 arg1, f32 arg2) { s32 func_800D8FEC(); f32 func_800F0DC0(f32, f32); f32 mlAbsF(f32); f32 sp4C; f32 temp_f0; f32 var_f20; s32 var_s0; var_f20 = arg0;
    var_s0 = 0;
    if ((func_800D8FEC() * 5) > 0) {
        do {
            temp_f0 = func_800F0DC0((arg1 - var_f20) * 0.04f, arg2);
            var_s0 += 1;
            sp4C = temp_f0;
            var_f20 += temp_f0;
        } while (var_s0 < (func_800D8FEC() * 5));
    }
    if (mlAbsF(sp4C) < 0.02f) {
        var_f20 = arg1;
    }
    return var_f20;
}

/* extern */

f32 func_80802304_bsfirstp(f32 arg0, f32 arg1, f32 arg2) {
    f32 func_800F0DC0(f32, f32);
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f20;

    var_f20 = 0.0f;
    if (arg2) {
        temp_f0 = arg1 - arg2;
        temp_f2 = 1.0f / arg2;
        if (temp_f0 < arg0) {
            var_f20 = (arg0 - temp_f0) * temp_f2;
        } else if (arg0 < -temp_f0) {
            var_f20 = (arg0 + temp_f0) * temp_f2;
        }
        var_f20 = func_800F0DC0(var_f20, 1.0f);
    }
    return var_f20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808023A0_bsfirstp.s")

void func_80802438_bsfirstp(void *arg0, s32 arg1) {
    register void *target;
    target = *(void **)((u8 *)arg0 + 392);
    *(s32 *)((u8 *)target + 160) = arg1;
}

s32 func_80802444_bsfirstp(void *arg0) {
    register void *target;
    target = *(void **)((u8 *)arg0 + 392);
    return (*(s32 *)((u8 *)target + 160)) == 1;
}

void *func_80802458_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern void *D_8080ABF0_bsfirstp[];
    return D_8080ABF0_bsfirstp[func_800A3280(arg0)];
}

s32 *func_80802484_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern s32 *D_8080A890_bsfirstp[];
    return D_8080A890_bsfirstp[func_800A3280(arg0)];
}

void *func_808024B0_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern u8 D_8080AFFC_bsfirstp[];
    return &D_8080AFFC_bsfirstp[func_800A3280(arg0) * 8];
}

s32 func_808024DC_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern s32 D_8080AFB4_bsfirstp[];
    return D_8080AFB4_bsfirstp[func_800A3280(arg0)];
}

void *func_80802508_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern u8 D_8080AFCC_bsfirstp[];
    return &D_8080AFCC_bsfirstp[func_800A3280(arg0) * 8];
}

s16 func_80802534_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern s16 D_8080B02C_bsfirstp[];
    return D_8080B02C_bsfirstp[func_800A3280(arg0)];
}

void *func_80802560_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern u8 D_8080B038_bsfirstp[];
    return &D_8080B038_bsfirstp[func_800A3280(arg0) * 12];
}

void *func_80802594_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern u8 D_8080B080_bsfirstp[];
    return &D_8080B080_bsfirstp[func_800A3280(arg0) * 12];
}

void func_808025C8_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern u8 D_8080B1B8_bsfirstp[];
    extern u8 D_8080B1E0_bsfirstp[];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B1B8_bsfirstp + offset;
    *arg2 = D_8080B1E0_bsfirstp + offset;
}

void func_8080261C_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern u8 D_8080B208_bsfirstp[];
    extern u8 D_8080B230_bsfirstp[];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B208_bsfirstp + offset;
    *arg2 = D_8080B230_bsfirstp + offset;
}

void func_80802670_bsfirstp(void *arg0, u8 **arg1) {
    u32 func_800A3280(void *);
    extern u8 D_8080B258_bsfirstp[];
    s32 index;
    s32 offset;
    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B258_bsfirstp + offset;
}

void func_808026AC_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern u8 D_8080B0C8_bsfirstp[];
    extern u8 D_8080B0F0_bsfirstp[];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B0C8_bsfirstp + offset;
    *arg2 = D_8080B0F0_bsfirstp + offset;
}

void func_80802700_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern u8 D_8080B118_bsfirstp[];
    extern u8 D_8080B140_bsfirstp[];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B118_bsfirstp + offset;
    *arg2 = D_8080B140_bsfirstp + offset;
}

void func_80802754_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern u8 D_8080B168_bsfirstp[];
    extern u8 D_8080B190_bsfirstp[];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = D_8080B168_bsfirstp + offset;
    *arg2 = D_8080B190_bsfirstp + offset;
}

u8 *func_808027A8_bsfirstp(s32 arg0) {
    extern s32 D_8080AC24_bsfirstp;
    return (u8 *) &D_8080AC24_bsfirstp + ((arg0 << 4) - 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_3.s")

void bsfirstp_entrypoint_4(s32 arg0, s32 arg1) {
    s32 _badeathmatch_entrypoint_10(s32, s32, u8, u8);
    extern s32 D_8080AC94_bsfirstp;
    s32 var_s0;
    u8 *var_s1;

    var_s0 = 1; var_s1 = (u8 *)&D_8080AC94_bsfirstp; var_s1 += arg1 * 0xE + 2;
    do {
        _badeathmatch_entrypoint_10(arg0, var_s0, (*(u8 *)((s8 *)(var_s1) + (-2))), (*(u8 *)((s8 *)(var_s1) + (-1))));
        var_s0 += 1;
        var_s1 += 2;
    } while (var_s0 != 8);
}

void bsfirstp_entrypoint_5(u8 *arg0, s32 arg1, s32 arg2) {
    s32 pad[2];
    void func_800A18C8(void *arg0);
    s32 func_800A1870(u8 *, s32);
    extern s32 D_8080AC94_bsfirstp;
    s32 sp1C[1];

    arg1 = *((u8 *)&D_8080AC94_bsfirstp - 0x92 + ((arg2 * 5) + arg1));
    sp1C[0] = arg1;
    func_800A18C8(arg0);
    arg1 = sp1C[0];
    func_800A1870(arg0, arg1);
}

s32 func_80802A40_bsfirstp(u8 *arg0, s32 arg1) {
    u32 func_800A3280(void *arg0);
    extern s32 D_8080B45C_bsfirstp;
    s16 temp_a3;
    u8 *temp_v1;

    temp_v1 = *((u8 **)&D_8080B45C_bsfirstp + func_800A3280(arg0));
    temp_v1 += arg1 * 8;
    temp_a3 = (*(s16 *)((s8 *)(temp_v1) + (2)));
    if (temp_a3 == 0) {
        return 0;
    }
    func_8009DF18(arg0, (*(s16 *)((s8 *)(temp_v1) + (0))), (*(s32 *)((s8 *)(temp_v1) + (4))), temp_a3);
    return 1;
}

void func_80802AA8_bsfirstp(u8 *arg0, s16 arg1, u8 *arg2, u8 *arg3) {
    u32 func_800A3280(void *arg0);
    extern s32 D_8080ADF4_bsfirstp;
    extern s32 D_8080AE44_bsfirstp;
    s32 temp_t6;
    u32 temp_v0;
    u8 *temp_a0;
    u8 *temp_a1;
    u32 temp_offset;

    temp_v0 = func_800A3280(arg0);
    temp_t6 = arg1 * 2;
    temp_offset = (temp_v0 << 5) + (temp_t6 * 4);
    temp_a0 = (u8 *)&D_8080AE44_bsfirstp + temp_offset;
    temp_offset = (temp_v0 * 0x10) + (temp_t6 * 2);
    temp_a1 = (u8 *)&D_8080ADF4_bsfirstp + temp_offset;
    (*(s16 *)((s8 *)(arg2) + (0))) = (s16) (*(s32 *)((s8 *)(temp_a0) + (-0x20)));
    (*(s16 *)((s8 *)(arg2) + (2))) = (s16) (*(s16 *)((s8 *)(temp_a1) + (-0x10)));
    (*(s16 *)((s8 *)(arg3) + (0))) = (s16) (*(s32 *)((s8 *)(temp_a0) + (-0x1C)));
    (*(s16 *)((s8 *)(arg3) + (2))) = (s16) (*(s16 *)((s8 *)(temp_a1) + (-0xE)));
}

/* extern */

void bsfirstp_entrypoint_6(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 func_800D3948(void);
    void *temp_v0;

    temp_v0 = func_80802458_bsfirstp(arg0);
    *arg1 = (*(f32 *)((s8 *)(temp_v0) + (0x14)));
    *arg3 = (*(f32 *)((s8 *)(temp_v0) + (0x18)));
    *arg2 = (*(f32 *)((s8 *)(temp_v0) + (0x1C)));
    if (func_800D3948() == 0) {
        *arg1 *= 0.67f;
    }
}

void bsfirstp_entrypoint_7(void *arg0, f32 *arg1, f32 *arg2) {
    void *temp_v0;

    temp_v0 = func_80802458_bsfirstp(arg0);
    *arg1 = (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    *arg2 = (*(f32 *)((s8 *)(temp_v0) + (0x10)));
}

void func_80802BD8_bsfirstp(s32 arg0) 
{
}
void func_80802BE0_bsfirstp(s32 arg0) 
{
}
/* extern */

 s32 func_80802BE8_bsfirstp(s32 arg0, f32 arg1) {
    s32 _badeathmatch_entrypoint_8(s32, f32);
    s32 func_80094430(void *, f32);
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) == 0) {
        func_80094430(arg0, arg1);
        return;
    }
    _badeathmatch_entrypoint_8(arg0, arg1);
}

/* extern */

s32 func_80802C30_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_6();
    s32 func_80094510();
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) == 0) {
        return func_80094510();
    }
    return _badeathmatch_entrypoint_6();
}

void func_80802C6C_bsfirstp(s32 arg0)
{
    func_800FC660(0xF);
}

/* extern */

void func_80802C90_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_6();
    s32 _badeathmatch_entrypoint_9(void *, s32);
    s32 func_80094BC0();
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) == 0) {
        func_80094BC0();
        return;
    }
    _badeathmatch_entrypoint_9(arg0, _badeathmatch_entrypoint_6());
}

/* extern */

void func_80802CD8_bsfirstp(void *arg0, s32 arg1) {
    s32 func_80094C0C();
    s32 _badeathmatch_entrypoint_5(s32, s32, s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) == 0) {
        func_80094C0C();
        return;
    }
    _badeathmatch_entrypoint_5(arg0, arg1, -1);
}

/* extern */

void func_80802D14_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_0();
    s32 func_80094A10();
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) == 0) {
        func_80094A10();
        return;
    }
    _badeathmatch_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802D50_bsfirstp.s")

s32 func_80802E7C_bsfirstp(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = func_808027A8_bsfirstp((*(s16 *)((s8 *)(arg0) + (0xE8))));
    (*(s16 *)((s8 *)(arg0) + (0xE4))) = (*(s16 *)((s8 *)(arg0) + (0xE2)));
    (*(s16 *)((s8 *)(arg0) + (0xE0))) = 2;
    (*(s16 *)((s8 *)(arg0) + (0xE2))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0xE6))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0xD8))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0xDC))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    return (*(s32 *)((s8 *)(temp_v0) + (0)));
}

void func_80802ED4_bsfirstp(void *arg0) {
    void func_80803124_bsfirstp(void *arg0, s32 arg1);
    register u8 *temp_v0 = *(u8 **)((u8 *)arg0 + 0x188);
    *(s16 *)(temp_v0 + 0xE0) = 4;
    func_80803124_bsfirstp(arg0, 0);
}

void func_80802F00_bsfirstp(void *arg0)
{
    func_80802ED4_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802F20_bsfirstp.s")

void func_808030E0_bsfirstp(void *arg0, s32 arg1) {
    s32 func_80802C30_bsfirstp(void *);
    register u8 *temp_v1 = *(u8 **)((u8 *)arg0 + 0x188);
    *(s16 *)(temp_v1 + 0xD4) = 0;
    if (*(s16 *)(temp_v1 + 0xE2) < arg1) {
        *(s16 *)(temp_v1 + 0xE2) = arg1;
        *(s16 *)(temp_v1 + 0xE8) = func_80802C30_bsfirstp(arg0);
    }
}

void func_80803124_bsfirstp(void *arg0, s32 arg1) {
    void *p = *(void **)((s8 *)arg0 + 0x188);
    (*(s16 *)((s8 *)p + 0xE0)) = 0;
}

void func_80803134_bsfirstp(void *arg0) {
    s32 _baeggsetup_entrypoint_7(void *, s32 *);
    s32 baanim_playForDuration_onceSmooth(void *, s16, s32);
    void func_800A0D94(void *, s32);
    void func_80800424_bsfirstp(struct player_state_s *, s32, f32);
    void func_8080261C_bsfirstp(void *, void **, void **);
    s32 func_80807BB8_bsfirstp();
    s32 func_80808DB0_bsfirstp(void *);
    extern s32 _bsfirstp_entrypoint_10;
    void *sp2C;
    void *sp28;
    void *sp24;

    sp2C = (*(void **)((s8 *)(arg0) + (0x188)));
    func_80807BB8_bsfirstp();
    func_80808DB0_bsfirstp(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_8080261C_bsfirstp(arg0, &sp28, &sp24);
    func_80800424_bsfirstp(arg0, (*(s16 *)((s8 *)(sp28) + (0))), (*(f32 *)((s8 *)(sp28) + (4))));
    baanim_playForDuration_onceSmooth(arg0, (*(s16 *)((s8 *)(sp24) + (0))), (*(s32 *)((s8 *)(sp24) + (4))));
    _baeggsetup_entrypoint_7(arg0, &_bsfirstp_entrypoint_10);
    (*(s16 *)((s8 *)(sp2C) + (0xE0))) = 3;
    func_800A0D94(arg0, 1);
}

void func_808031D0_bsfirstp(void *arg0) {
    void func_800A0D94(void *, s32);
    int func_80807C8C_bsfirstp(void *);
    void *state = *(void **)((s8 *)arg0 + 0x188);

    *(s16 *)((s8 *)state + 0xE0) = 0;
    func_800A0D94(arg0, 0);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803204_bsfirstp.s")

s32 bsfirstp_entrypoint_8(s32 arg0) {
    extern s32 D_8080B474_bsfirstp[];
    return ((s32 *)&D_8080B474_bsfirstp)[arg0];
}

void func_808032C0_bsfirstp(struct player_state_s *self) {
    s32 func_80807BB8_bsfirstp();
    s32 func_80808DB0_bsfirstp(void *);
    s32 _baeggsetup_entrypoint_7(void *, s32 *);
    extern s32 _bsfirstp_entrypoint_10;
    u8 *sp24;

    func_80807BB8_bsfirstp(self);
    func_80808DB0_bsfirstp(self);
    func_80802670_bsfirstp(self, &sp24);
    func_80800424_bsfirstp(self, *(s16 *)sp24, *(f32 *)(sp24 + 4));
    _baeggsetup_entrypoint_7(self, &_bsfirstp_entrypoint_10);
}

void func_80803320_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803340_bsfirstp.s")

s32 bsfirstp_entrypoint_9(s32 arg0) {
    extern s32 D_8080B484_bsfirstp[];
    return ((s32 *)&D_8080B484_bsfirstp)[arg0];
}

/* extern */

void bsfirstp_entrypoint_10(s32 arg0) {
    s32 _baeggcursor_entrypoint_8(void *);
    s32 _baeggsetup_entrypoint_3(s32, s32, f32 *, f32 *, f32 *);
    void _bainvisible_entrypoint_7(Actor *, s32, f32, f32, f32);
    void func_8009E0AC(void *, s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF368(f32 *, f32);
    struct player_state_s *func_800F53D0(s32);
    s32 func_808035EC_bsfirstp(void *, f32 *, f32 *);
    f32 yaw_get(struct player_state_s *);
    void *temp_s2;
    void *temp_v0;
    u8 *sp5C;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];

    temp_v0 = func_800F53D0(arg0);
    temp_s2 = *(void **)((s8 *)temp_v0 + 0x188);
    sp5C = func_808027A8_bsfirstp(*(s16 *)((s8 *)temp_s2 + 0xE8));
    func_808035EC_bsfirstp(temp_v0, sp50, sp38);
    func_800EF368(sp38, 90.0f);
    func_800EE780(sp44, sp50, sp38);
    func_800EF368(sp38, *(f32 *)(sp5C + 4));
    func_800EF1B8(sp38, yaw_get(temp_v0) - 90.0f, *(f32 *)((s8 *)temp_s2 + 0x1D4) * 0.33f);
    func_8009E0AC(temp_v0, 0);
    func_80802A40_bsfirstp(temp_v0, *(s16 *)((s8 *)temp_s2 + 0xE8));
    func_8009E0AC(temp_v0, 1);
    _baeggcursor_entrypoint_8(temp_v0);
    _bainvisible_entrypoint_7(temp_v0, 3, 1.0f, 1.0f, 0.25f);
    _baeggsetup_entrypoint_3(arg0, *(s16 *)((s8 *)temp_s2 + 0xE8), sp50, sp44, sp38);
    func_80802CD8_bsfirstp(temp_v0, *(s16 *)((s8 *)temp_s2 + 0xE8));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808035EC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808036F0_bsfirstp.s")

void func_80803760_bsfirstp(s32 arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    _batimer_set(arg0, 0, 5.0f);
}

void func_80803784_bsfirstp(u8 *arg0) {
    void func_800A38F0(struct player_state_s *, s32, s32);
    s32 func_8010114C(s32, s32, s32);
    void *state;
    s32 temp_a3;

    state = *(void **)((s8 *)arg0 + 0x188);
    temp_a3 = *(s32 *)((s8 *)state + 0x114);
    if (temp_a3 != 0) {
        func_8010114C(temp_a3, 4, *(s32 *)((s8 *)arg0 + 0x184));
        *(s32 *)((s8 *)state + 0x114) = 0;
    }
    func_800A38F0(arg0, 1, 1);
    func_80807C8C_bsfirstp(arg0);
}

void func_808037E4_bsfirstp(u8 *arg0) {
    int _batimer_decrement(struct player_state_s *, s32);
    s32 bs_setState(void *, s32);
    s32 var_a2;

    var_a2 = 0;
    if (_batimer_decrement(arg0, 0) != 0) {
        var_a2 = 0xCA;
    }
    if (var_a2 != 0) {
        bs_setState(arg0, var_a2);
    }
}

/* extern */

void func_80803828_bsfirstp(s32 arg0) {
    void bsfirstp_entrypoint_26(s32);
    s32 func_8009E6EC();
    u8 *temp_v1;

    temp_v1 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    if (func_8009E6EC(arg0) == 0xF) {
        if ((*(s32 *)((s8 *)(temp_v1) + (0x114))) != 0) {
            (*(s32 *)((s8 *)(temp_v1) + (0x114))) = 0;
        }
    } else {
        bsfirstp_entrypoint_26(arg0);
    }
}

s32 bsfirstp_entrypoint_11(s32 arg0) {
    extern s32 D_8080B494_bsfirstp[];
    return ((s32 *)&D_8080B494_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_13.s")

void func_80803A84_bsfirstp(void *arg0) {
    void func_80803B58_bsfirstp(void *, f32);
    extern s32 _bsfirstp_entrypoint_13;
    s32 var_s0;
    register s32 *callback;
    register void *self;

    callback = &_bsfirstp_entrypoint_13;
    self = arg0;
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        func_8009E4E0(self, var_s0, (s32)callback);
    }
    func_8009E4E0(self, 2, 0);
    func_80803B58_bsfirstp(self, 0.0f);
}

/* extern */

void func_80803B04_bsfirstp(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_8009E4E0(arg0, var_s0, 0);
        var_s0 += 1;
    } while (var_s0 != 3);
}

void func_80803B58_bsfirstp(void *arg0, f32 arg1) {
    register void *ptr;
    ptr = *(void **)((u8 *)arg0 + 392);
    *(f32 *)((u8 *)ptr + 272) = arg1;
}

f32 func_80803B68_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = *(void **)((u8 *)arg0 + 392);
    return *(f32 *)((u8 *)ptr + 272);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803CD4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803E84_bsfirstp.s")

void func_808090D8_bsfirstp();

void func_80803F6C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp((void *)arg0);
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803F94_bsfirstp.s")

s32 bsfirstp_entrypoint_15(s32 arg0) {
    extern s32 D_8080B4D0_bsfirstp[];
    return ((s32 *)&D_8080B4D0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804104_bsfirstp.s")

/* extern */

void func_808041D0_bsfirstp(s32 arg0) {
    void func_80802700_bsfirstp(void *, void **, void **);
    s32 func_80804104_bsfirstp(s32, s32, s32);
    s32 func_80807BB8_bsfirstp();
    s32 sp1C;
    s32 sp18;

    func_80807BB8_bsfirstp();
    func_80802700_bsfirstp(arg0, &sp1C, &sp18);
    func_80804104_bsfirstp(arg0, sp1C, sp18);
}

void func_80804210_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
void func_80804238_bsfirstp(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    int _batimer_decrement(struct player_state_s *, s32);
    void _basudie_entrypoint_0(struct player_state_s *);
    void func_800A38F0(struct player_state_s *, s32, s32);
    s32 func_800D3948(void);
    s32 func_80101180(s32, s32, s32);

    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0))) {
            _batimer_set(arg0, 0, 3.0f);
            func_800A38F0(arg0, 0, 1);
            *(s32 *)((s8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(arg0, 0)) {
            if (func_800D3948()) {
                func_80101180(0x2C4, 0x71, *(s32 *)((s8 *)arg0 + 0x184));
            } else {
                _basudie_entrypoint_0(arg0);
            }
            *(s32 *)((s8 *)arg0 + 0x15C) = 2;
        }
        break;
    }
    func_80809198_bsfirstp(arg0);
    func_80807D48_bsfirstp((s32)arg0);
    func_80809250_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_16(s32 arg0) {
    extern s32 D_8080B4E0_bsfirstp[];
    return ((s32 *)&D_8080B4E0_bsfirstp)[arg0];
}

/* extern */

void func_8080432C_bsfirstp(s32 arg0) {
    void func_80802754_bsfirstp(void *, void **, void **);
    s32 func_80804104_bsfirstp(s32, s32, s32);
    s32 func_80807BB8_bsfirstp();
    s32 sp1C;
    s32 sp18;

    func_80807BB8_bsfirstp();
    func_80802754_bsfirstp(arg0, &sp1C, &sp18);
    func_80804104_bsfirstp(arg0, sp1C, sp18);
}

void func_8080436C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
void func_80804394_bsfirstp(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    int _batimer_decrement(struct player_state_s *, s32);
    void _basudie_entrypoint_0(struct player_state_s *);
    void func_800A38F0(struct player_state_s *, s32, s32);
    s32 func_800D3948(void);
    s32 func_80101180(s32, s32, s32);

    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0))) {
            _batimer_set(arg0, 0, 3.0f);
            func_800A38F0(arg0, 0, 1);
            *(s32 *)((s8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(arg0, 0)) {
            if (func_800D3948()) {
                func_80101180(0x2C4, 0x71, *(s32 *)((s8 *)arg0 + 0x184));
            } else {
                _basudie_entrypoint_0(arg0);
            }
            *(s32 *)((s8 *)arg0 + 0x15C) = 2;
        }
        break;
    }
    func_80809198_bsfirstp(arg0);
    func_80809250_bsfirstp((s32)arg0);
    func_80807D48_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_17(s32 arg0) {
    extern s32 D_8080B4F0_bsfirstp[];
    return ((s32 *)&D_8080B4F0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804488_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808045FC_bsfirstp.s")

/* extern */

void func_808047EC_bsfirstp(u8 *arg0) {
    s32 func_80804848_bsfirstp(u8 *, s32);
    u8 *sp1C;

    sp1C = (*(u8 **)((s8 *)(arg0) + (0x188)));
    bzero(sp1C + 0x12C, 0x38);
    bzero(sp1C + 0x164, 0x38);
    func_80804848_bsfirstp(arg0, (*(s32 *)((s8 *)(sp1C) + (0xC))));
}

void func_8080483C_bsfirstp(void *arg0, s32 arg1) {
    register void *temp_v0 = *(void **)((u8 *)arg0 + 392);
    *(s32 *)((u8 *)temp_v0 + 280) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804848_bsfirstp.s")

/* extern */

void bsfirstp_entrypoint_18(s32 arg0, s32 arg1) {
    s32 bs_setState(void *, s32);
    struct player_state_s *func_800F53D0(s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_800F53D0(arg1);
    sp1C = temp_v0;
    bs_setState(temp_v0, 0xC8);
    (*(s32 *)((s8 *)(sp1C) + (0x15C))) = 1;
}

void func_80804A34_bsfirstp(s32 arg0) 
{
}
/* extern */

void func_80804A3C_bsfirstp(void *arg0) {
    s32 func_80101238(s32, s32, void *);
    func_80101238(0x77, (*(s32 *)((s8 *)(arg0) + (0x184))), arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804A64_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804B10_bsfirstp.s")

void func_80804B84_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804BA4_bsfirstp.s")

s32 bsfirstp_entrypoint_19(s32 arg0) {
    extern s32 D_8080B500_bsfirstp[];
    return ((s32 *)&D_8080B500_bsfirstp)[arg0];
}

/* extern */

void func_80804D18_bsfirstp(struct player_state_s *arg0) {
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    s32 func_80807BB8_bsfirstp();
    s32 func_80807DD4_bsfirstp(s32);
    s32 func_808002CC_bsfirstp(s32, s32, s32, s32);
    func_80807BB8_bsfirstp(arg0);
    func_80807DD4_bsfirstp(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
    func_808002CC_bsfirstp(arg0, 0x311, 0x40000000, 0x3F00EBEE);
    func_80801A34_bsfirstp(arg0);
}

void func_80804D80_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804DA0_bsfirstp.s")

s32 bsfirstp_entrypoint_20(s32 arg0) {
    extern s32 D_8080B510_bsfirstp[];
    return ((s32 *)&D_8080B510_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804E1C_bsfirstp.s")

void func_80804EB4_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
void func_80804ED4_bsfirstp(s32 arg0) {
    s32 bs_setState(void *, s32);
    s32 func_800EA068(s32);

    func_80807D48_bsfirstp(arg0);
    bs_setState(arg0, func_800EA068(8) ? 0xCB : 0xC9);
}

s32 bsfirstp_entrypoint_21(s32 arg0) {
    extern s32 D_8080B520_bsfirstp[];
    return ((s32 *)&D_8080B520_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804F28_bsfirstp.s")

void func_80804FB4_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804FD4_bsfirstp.s")

s32 bsfirstp_entrypoint_22(s32 arg0) {
    extern s32 D_8080B530_bsfirstp[];
    return ((s32 *)&D_8080B530_bsfirstp)[arg0];
}

/* extern */

void func_80805058_bsfirstp(struct player_state_s *arg0) {
    s32 _bsdrone_entrypoint_0(s32);
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    s32 func_80807BB8_bsfirstp();
    s32 func_808002CC_bsfirstp(s32, s32, s32, s32);
    _bsdrone_entrypoint_0(arg0);
    func_80807BB8_bsfirstp(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
    func_808002CC_bsfirstp(arg0, 0x311, 0x40000000, 0x3F00EBEE);
}

void func_80809D24_bsfirstp(void *);

void func_808050B0_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808050D8_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_23(s32 arg0) {
    extern s32 D_8080B540_bsfirstp[];
    return ((s32 *)&D_8080B540_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080511C_bsfirstp.s")

void func_8080519C_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808051C4_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_24(s32 arg0) {
    extern s32 D_8080B550_bsfirstp[];
    return ((s32 *)&D_8080B550_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_25.s")

void func_808052A4_bsfirstp(f32 *arg0, f32 *arg1) {
    f32 temp_f0;
    f32 divisor = -2.0f;

    temp_f0 = *arg0 / -divisor;
    *arg0 = *arg1 + temp_f0;
    *arg1 = temp_f0;
}

f32 func_808052C8_bsfirstp(f32 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
  float new_var;
  f32 old;
  f32 time;
  f32 value;
  f32 *new_var2;
  f32 target;
  f32 total = 0.0f;
  new_var2 = arg0;
  if (arg3 != 0.0f)
  {
    target = arg1;
    old = *new_var2;
    if (target != old)
    {
      if (target < old)
      {
        arg2 = -arg2;
      }
      new_var = arg2 * arg3;
      time = (target - old) / arg2;
      if (time <= arg3)
      {
        value = target;
      }
      else
      {
        value = old;
        value = value + new_var;
        time = arg3;
      }
      total += ((old + value) * 0.5f) * time;
      *new_var2 = value;
      old = *arg0;
      arg3 -= time;
    }
    total += old * arg3;
  }
  return total;
}

/* extern */

void func_80805380_bsfirstp(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_80013728(f32);
    s32 func_800D8FEC();
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F212C(f32, f32);
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;
    s32 temp_v0;
    s32 var_s0;

    for (var_s0 = func_800D8FEC(); var_s0 != 0; var_s0--) {
            temp_f0 = func_80013728(arg1 - *arg0);
            var_f20 = temp_f0 * arg3;
            if (var_f20 != 0.0f) {
                var_f20 = (var_f20 < 0.0f)
                    ? func_800F0D50(var_f20, -arg2, -3.0f)
                    : func_800F0D50(var_f20, 3.0f, arg2);
            }
            *arg0 += func_800F212C(var_f20 * 0.016666668f, temp_f0);
    }
    *arg0 = func_80013728(*arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080549C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80805644_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808057C8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808058F0_bsfirstp.s")

void bsfirstp_entrypoint_26(s32 arg0) {
    s32 _badeathmatch_entrypoint_5(s32, s32, s32);
    s32 _baduo_entrypoint_14(s32, f32 *);
    s32 _gcegg_entrypoint_7(s32);
    s32 _suegg_entrypoint_6(s32, f32 *, s32 *);
    s32 _sueggmisc_entrypoint_2(f32 *, s32);
    s32 bs_getCurrentState(s32);
    s32 bs_setState(void *, s32);
    f32 func_80099A34(s32);
    s32 func_80099A4C(s32);
    s32 func_80099A58(s32);
    s32 func_80099A70(s32);
    s32 func_80099A7C(s32, f32 *);
    s32 func_80099B94(s32);
    s32 func_8009C15C(s32, f32 *);
    s32 func_8009E6EC();
    void func_8009E830(struct player_state_s *, s32);
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    s32 func_800EFD24(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F7E64(s32, s32);
    void func_80801A5C_bsfirstp(void *);
    s32 func_80802BE8_bsfirstp(s32, f32);
    s32 func_80803CD4_bsfirstp(s32, s32, s32, s32, f32 *);
    void func_80808678_bsfirstp(Actor *, volatile s32);
    void func_80807EEC_bsfirstp(s32);
    void func_80807F24_bsfirstp(s32);
    s32 next_state = 0;
    s32 event = func_8009E6EC(arg0);
    s32 handled = 1;

    switch (event) {
    default:
        func_80099B94(arg0);
        return;
    case 0x99:
        func_808019EC_bsfirstp(arg0);
        break;
    case 0x4C: {
        f32 position[3];
        func_80099A7C(arg0, position);
        _baduo_entrypoint_14(arg0, position);
        next_state = 0xD7;
        handled = 2;
        break;
    }
    case 0x4F:
        handled = 2;
        break;
    case 0x61:
        switch (func_80099A58(arg0)) {
        case 0:
            next_state = 0xCC;
            break;
        case 1:
            func_800A3544(arg0, 0);
            next_state = 0xC8;
            break;
        case 2:
            next_state = 0xC9;
            break;
        }
        func_800F7E64(*(s32 *)(arg0 + 0x184), 9);
        handled = 2;
        break;
    case 0x73:
        func_80807EEC_bsfirstp(arg0);
        func_80801A5C_bsfirstp(arg0);
        handled = 2;
        break;
    case 0x62:
        if (!func_800A3404(arg0)) {
            func_80807EEC_bsfirstp(arg0);
            handled = 2;
        }
        break;
    case 0x63:
        if (func_800A3404(arg0)) {
            func_80807F24_bsfirstp(arg0);
            handled = 2;
        }
        break;
    case 0x72:
        if (bs_getCurrentState(arg0) == 0xD2) {
            func_80808678_bsfirstp(arg0, func_80099A4C(arg0));
            handled = 2;
        }
        break;
    case 0x5F:
        func_80802BE8_bsfirstp(arg0, func_80099A34(arg0));
        handled = 2;
        break;
    case 0x47: {
        s32 unused;
        f32 position[3];
        s32 egg;
        s32 amount;
        s32 type;
        s32 state1;
        s32 state2;

        egg = _suegg_entrypoint_6(func_80099A4C(arg0), position, &type);
        amount = _gcegg_entrypoint_7(type);
        switch (type) {
        default:
            state2 = 0xDB;
            state1 = 0xDA;
            break;
        case 6:
            amount = 0;
        case 4:
        case 5:
            state1 = 0xDA;
            state2 = 0xDC;
            break;
        case 3:
            if (bs_getCurrentState(arg0) != 0xD9) {
                state1 = 0xD9;
                state2 = 0;
            } else {
                func_80803760_bsfirstp(arg0);
                state1 = 0;
                state2 = 0;
            }
            break;
        }
        egg = func_80803CD4_bsfirstp(arg0, event, egg, amount, position);
        if (egg != 0) {
            if (egg != 1) {
                if (egg == 2) {
                    next_state = state2;
                    handled = 2;
                }
            } else {
                next_state = state1;
                if (type == 6) {
                    _badeathmatch_entrypoint_5(arg0, 6, 1);
                    _sueggmisc_entrypoint_2(position, 6);
                }
                handled = 2;
            }
        }
        break;
    }
    case 0x6D: {
        f32 position[3];
        s32 object;
        s32 unused[2];
        object = func_80099A58(arg0);
        func_800F5A00(object, position);
        switch (func_80803CD4_bsfirstp(arg0, event, object, 1, position)) {
        case 1:
            next_state = 0xDA;
            handled = 2;
            break;
        case 2:
            next_state = 0xDB;
            handled = 2;
            break;
        }
        break;
    }
    case 0x4E: {
        s32 object;
        s32 amount;
        f32 position[3];
        s32 unused;
        object = func_80099A70(arg0);
        amount = func_80099A58(arg0);
        func_80099A7C(arg0, position);
        switch (func_80803CD4_bsfirstp(arg0, event, object, amount, position)) {
        case 1:
            next_state = 0xDA;
            handled = 2;
            break;
        case 2:
            next_state = 0xDC;
            handled = 2;
            break;
        }
        break;
    }
    case 0x20: {
        f32 position[3];
        s32 unused[3];
        func_80099A7C(arg0, position);
        switch (func_80803CD4_bsfirstp(arg0, event, -1, 1, position)) {
        case 1:
            next_state = 0xDA;
            handled = 2;
            break;
        case 2:
            next_state = 0xDB;
            handled = 2;
            break;
        }
        break;
    }
    case 0x51: {
        f32 position[3];
        s32 unused[3];
        func_8009C15C(arg0, position);
        switch (func_80803CD4_bsfirstp(arg0, event, -1, 1, position)) {
        case 1:
            next_state = 0xDA;
            handled = 2;
            break;
        case 2:
            next_state = 0xDC;
            handled = 2;
            break;
        }
        break;
    }
    case 0x45: {
        f32 position[3];
        s32 unused[5];
        func_800EFD24((s32)position);
        if (func_80803CD4_bsfirstp(arg0, event, -1, 8, position)) {
            next_state = 0xDB;
            handled = 2;
        }
        break;
    }
    case 0x21:
    case 0x24: {
        f32 position[3];
        func_800EFD24((s32)position);
        switch (func_80803CD4_bsfirstp(arg0, event, -1, 1, position)) {
        case 1:
            next_state = 0xDA;
            handled = 2;
            break;
        case 2:
            next_state = 0xDB;
            handled = 2;
            break;
        }
        break;
    }
    }
    func_8009E830(arg0, handled);
    bs_setState((void *)arg0, next_state);
}

void func_80805F48_bsfirstp(s32 arg0)
{
    func_808061AC_bsfirstp(arg0,0);
}

void func_80805F68_bsfirstp()
{
    func_8009B4FC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_27.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806000_bsfirstp.s")

f32 func_80806130_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = *(void **)((u8 *)arg0 + 392);
    return *(f32 *)((u8 *)ptr + 456);
}

f32 func_8080613C_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = *(void **)((u8 *)arg0 + 392);
    return *(f32 *)((u8 *)ptr + 452);
}

/* extern */

void func_80806148_bsfirstp(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    register f32 *temp = *(f32 **)((u8 *)arg0 + 0x188);
    func_800EE7F8(arg1, temp + 110);
}

/* extern */

void func_80806170_bsfirstp(void *arg0, f32 arg1) {
    f32 func_800F0DC0(f32, f32);
    void *func_80802458_bsfirstp(void *);
    arg1 /= *(f32 *)((s8 *)func_80802458_bsfirstp(arg0) + 0x2C);
    func_800F0DC0(arg1, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808061AC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080633C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080649C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806588_bsfirstp.s")

/* extern */

void func_80806774_bsfirstp(void *arg0) {
    void func_8009B7C0();
    struct {
        s32 pad;
        void *data;
    } local;

    local.data = *(void **)((s8 *)arg0 + 0x188);
    func_8009B7C0();
    *(f32 *)((s8 *)local.data + 0x1D8) = 0.0f;
    *(f32 *)((s8 *)local.data + 0x1CC) = 0.0f;
    *(f32 *)((s8 *)local.data + 0x1D4) = 0.0f;
}

void func_808067B0_bsfirstp(void *arg0) {
    f32 func_80809D94_bsfirstp(void *);
    struct {
        s32 pad;
        void *data;
    } local;

    local.data = *(void **)((u8 *)arg0 + 0x188);
    *(f32 *)((u8 *)local.data + 0x20C) = func_80809D94_bsfirstp(arg0);
    *(f32 *)((u8 *)local.data + 0x210) = 0.0f;
    *(f32 *)((u8 *)local.data + 0x214) = 0.0f;
}

/* extern */

void func_808067E8_bsfirstp(u8 *arg0) {
    void *func_80802458_bsfirstp(void *);
    void func_808067B0_bsfirstp(void *);
    struct {
        s32 pad;
        s32 data;
    } local;

    local.data = *(s32 *)((u8 *)arg0 + 0x188);
    bcopy((u8 *)func_80802458_bsfirstp(arg0) + 0x54, (u8 *)local.data + 0x1E8, 0x20);
    func_808067B0_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080682C_bsfirstp.s")

/* extern */

void func_808068E8_bsfirstp(s32 arg0) {
    f32 func_808069BC_bsfirstp(s32);
    s32 func_808069FC_bsfirstp(s32);
    s32 func_80809D6C_bsfirstp();
    if (func_80809D6C_bsfirstp() != 0) {
        func_808069BC_bsfirstp(arg0);
        return;
    }
    func_808069FC_bsfirstp(arg0);
}

/* extern */

f32 func_80806928_bsfirstp(void *arg0) {
    f32 func_80013728(f32);
    f32 func_80809D94_bsfirstp(void *);
    void *temp_v0;
    f32 var_f2;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    {
        f32 temp_f0 = -(*(f32 *)((s8 *)(temp_v0) + (0x184)));
        if (temp_f0 < 0.0f) {
            var_f2 = (*(f32 *)((s8 *)(temp_v0) + (0x1E8))) * temp_f0;
        } else {
            var_f2 = -(*(f32 *)((s8 *)(temp_v0) + (0x1EC))) * temp_f0;
        }
    }
    if ((*(s32 *)((s8 *)(temp_v0) + (0x10))) != 0) {
        var_f2 += func_80809D94_bsfirstp(arg0);
    }
    (*(f32 *)((s8 *)(temp_v0) + (0x208))) = var_f2;
    return func_80013728(var_f2 - (*(f32 *)((s8 *)(temp_v0) + (0x20C)))) / 12.0f;
}

f32 func_808069BC_bsfirstp(s32 arg0) {
    f32 func_80013728(f32);
    f32 func_80809D94_bsfirstp();
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    (*(f32 *)((s8 *)(temp_v0) + (0x208))) = func_80809D94_bsfirstp();
    return func_80013728((*(f32 *)((s8 *)(temp_v0) + (0x208))) - (*(f32 *)((s8 *)(temp_v0) + (0x20C)))) / 6.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808069FC_bsfirstp.s")

/* extern */

f32 func_80806AD0_bsfirstp(u8 *arg0, s32 arg1, f32 arg2) {
    f32 func_800D9004();
    f32 func_808057C8_bsfirstp(f32 *, s32, s32, f32, f32);
    f32 unused0;
    f32 unused1;
    f32 *temp_s0;
    f32 temp_f2;
    f32 sp34;
    f32 sp30;

    temp_s0 = (*(f32 **)((s8 *)(arg0) + (0x188)));
    temp_f2 = func_800D9004() - 0.033333335f;
    sp34 = func_808057C8_bsfirstp(temp_s0 + 0x84, arg1, (*(s32 *)((s8 *)(temp_s0) + (0x1F0))), 0.033333335f, arg2);
    if (temp_f2 != 0.0f) {
        sp30 = func_808057C8_bsfirstp(temp_s0 + 0x84, arg1, (*(s32 *)((s8 *)(temp_s0) + (0x1F0))), temp_f2, arg2);
    } else {
        sp30 = 0.0f;
    }
    func_808052A4_bsfirstp(&sp30, temp_s0 + 0x85);
    return sp34 + sp30;
}

void bsfirstp_entrypoint_28(void *arg0, void *arg1) {
    s32 *ptr0 = *(s32 **)((s8 *)arg0 + 0x188);
    s32 *ptr1 = *(s32 **)((s8 *)arg1 + 0x188);

    ptr0[0x64 / 4] = *(s32 *)((s8 *)arg1 + 0x184);
    ptr1[0x68 / 4] = *(s32 *)((s8 *)arg0 + 0x184);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806BA0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806C58_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806CC0_bsfirstp.s")

/* extern */

void func_80806D64_bsfirstp(Actor *arg0) {
    void func_8080633C_bsfirstp(Actor*, f32);
    s32 func_80801928_bsfirstp(Actor *);
    func_8080633C_bsfirstp(arg0, 1.0f);
    func_80801928_bsfirstp(arg0);
}

/* extern */

void func_80806D90_bsfirstp(struct player_state_s *arg0) {
    s32 bs_setState(void *, s32);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    s32 *sp1C;

    sp1C = *(s32 **)((s8 *)arg0 + 0x188);
    if (func_8009E6EC(arg0) == 0x4F) {
        sp1C[0x64 / 4] = -1;
        bs_setState(arg0, 0xCA);
        func_8009E830(arg0, 2);
        return;
    }
    bsfirstp_entrypoint_26(arg0);
}

s32 bsfirstp_entrypoint_29(s32 arg0) {
    extern s32 D_8080B560_bsfirstp[];
    return ((s32 *)&D_8080B560_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806E0C_bsfirstp.s")

void func_80806E9C_bsfirstp(s32 arg0)
{
    _bsbabykaz_entrypoint_3();
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806EC4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807024_bsfirstp.s")

s32 bsfirstp_entrypoint_30(s32 arg0) {
    extern s32 D_8080B570_bsfirstp[];
    return ((s32 *)&D_8080B570_bsfirstp)[arg0];
}

void func_808071D8_bsfirstp(s32 arg0)
{
    func_80091E6C();
    _bsbabykaz_entrypoint_3(arg0);
    func_80807C8C_bsfirstp(arg0);
}

/* extern */

void func_80807208_bsfirstp(s32 arg0) {
    s32 _bababykaz_entrypoint_9(s32);
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 _bsbabykaz_entrypoint_0(s32);
    s32 _bsbabykaz_entrypoint_4(s32);
    s32 func_80091E48(s32, s32);
    s32 func_80807BB8_bsfirstp();
    func_80807BB8_bsfirstp();
    _bsbabykaz_entrypoint_4(arg0);
    _bsbabykaz_entrypoint_0(arg0);
    _bababykaz_entrypoint_9(arg0);
    func_80091E48(arg0, 0x20);
    _batimer_set(arg0, 0, 0.5f);
}

/* extern */

void func_80807264_bsfirstp(u8 *arg0) {
    int _batimer_decrement(struct player_state_s *, s32);
    s32 _bababykaz_entrypoint_4(u8 *);
    s32 _batimer_isZero(u8 *, s32);
    s32 func_800F9AAC(s32, s32);
    _batimer_decrement(arg0, 0);
    if (_batimer_isZero(arg0, 0) != 0) {
        func_800F9AAC((*(s32 *)((s8 *)(arg0) + (0x184))), _bababykaz_entrypoint_4(arg0));
    }
}

s32 bsfirstp_entrypoint_31(s32 arg0) {
    extern s32 D_8080B580_bsfirstp[];
    return ((s32 *)&D_8080B580_bsfirstp)[arg0];
}

/* extern */

void func_808072C8_bsfirstp(void *arg0) {
    void func_8009337C(void *, s32);
    void func_800936E8(void *, s32);
    u32 func_800A3404(void *);
    int func_800DB9B0(void);
    s32 sp1C;

    if ((func_800A3404(arg0) != 0) && (func_800DB9B0() != 0)) {
        sp1C = 0;
    } else {
        sp1C = 1;
    }
    func_8009337C(arg0, 1);
    func_800936E8(arg0, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807328_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807394_bsfirstp.s")

void func_808074D0_bsfirstp(void *arg0) {
    void func_800936E8(void *, s32);
    int func_80807C8C_bsfirstp(void *);
    func_800936E8(arg0, 1);
    _bsrest_entrypoint_14(arg0);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807504_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080762C_bsfirstp.s")

s32 bsfirstp_entrypoint_32(s32 arg0) {
    extern s32 D_8080B590_bsfirstp[];
    return ((s32 *)&D_8080B590_bsfirstp)[arg0];
}

void func_808077AC_bsfirstp(s32 arg0) {
    int func_80801B64_bsfirstp(s32, s32);
    int func_80807C8C_bsfirstp(void *);
    func_80801B64_bsfirstp(arg0, 3);
    _bsrest_entrypoint_14(arg0);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808077E0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807864_bsfirstp.s")

s32 bsfirstp_entrypoint_33(s32 arg0) {
    extern s32 D_8080B5A0_bsfirstp[];
    return ((s32 *)&D_8080B5A0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808078F4_bsfirstp.s")

/* extern */

void func_80807A70_bsfirstp(void *arg0) {
    void func_8008CFF0(struct player_state_s *);
    void func_80093230(struct player_state_s *, f32);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    s32 func_8009359C(void *, s32);
    void func_800936CC(void *, s32);
    s32 *temp_v0;

    temp_v0 = (*(s32 **)((s8 *)(arg0) + (0x188)));
    if (*temp_v0 != -1) {
        func_800936CC(arg0, 0);
        func_8009359C(arg0, 0);
        func_80093230(arg0, 1.0f);
        func_8008CFF0(arg0);
        func_80093370(arg0, 1);
        func_8009337C(arg0, 1);
        *temp_v0 = -1;
    }
}

/* extern */

void func_80807AF8_bsfirstp(struct player_state_s *arg0) {
    s32 _gcstatusDll_entrypoint_13();
    s32 _gcstatusDll_entrypoint_3(s32, s32);
    s32 bainput_enable(void *, s32, s32);
    void func_8009B7C0(struct player_state_s *);
    void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void func_800A34A0(void *, s32);
    s32 func_800D3948(void);
    s32 func_800EA068(s32);
    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        u8 padC[0x58];
        s32 unk64;
        s32 unk68;
    } *temp_s1;
    s32 sp28;

    temp_s1 = *(void **)((s8 *)arg0 + 0x188);
    sp28 = 1;
    if (func_800D3948() != 0) {
        if (func_800EA068(0x4000) != 0) {
            sp28 = _gcstatusDll_entrypoint_13(*(s32 *)((s8 *)arg0 + 0x184));
        } else {
            _gcstatusDll_entrypoint_3(*(s32 *)((s8 *)arg0 + 0x184), 1);
        }
    }
    func_800A34A0(arg0, sp28);
    temp_s1->unk0 = sp28;
    temp_s1->unk64 = -1;
    temp_s1->unk68 = -1;
    temp_s1->unk8 = -1;
    func_8009B7C0(arg0);
    func_8009FFD8(arg0, 1, 0, 0, 0x10);
    bainput_enable(arg0, 3, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807BB8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807C8C_bsfirstp.s")

void func_80807D48_bsfirstp(s32 arg0)
{
    func_80802BE0_bsfirstp(arg0);
    func_8080800C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807D70_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807DD4_bsfirstp.s")

/* extern */

void func_80807EEC_bsfirstp(s32 arg0) {
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    s32 func_80807DD4_bsfirstp(s32);
    if (func_800A3404(arg0) == 0) {
        func_800A3544(arg0, 1);
        func_80807DD4_bsfirstp(arg0);
    }
}

/* extern */

void func_80807F24_bsfirstp(s32 arg0) {
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    s32 func_80807DD4_bsfirstp(s32);
    if (func_800A3404(arg0) != 0) {
        func_800A3544(arg0, 0);
        func_80807DD4_bsfirstp(arg0);
    }
}

/* extern */

void func_80807F5C_bsfirstp(s32 arg0) {
    s32 bs_setState(void *, s32);
    void func_800A3544(void *, s32);
    s32 func_80807DD4_bsfirstp(s32);
    void func_80801A5C_bsfirstp(void *);
    func_800A3544(arg0, 1);
    func_80807DD4_bsfirstp(arg0);
    func_80801A5C_bsfirstp(arg0);
    bs_setState((u8 *) arg0, 0xCA);
}

void func_80807FBC_bsfirstp(s32 arg0);
void func_808080A4_bsfirstp(void *, u8);
void func_808080B4_bsfirstp(s32, s16 *, u8);
void func_80808100_bsfirstp(s32, s16 *);

void func_80807F9C_bsfirstp(s32 arg0)
{
    func_80807FBC_bsfirstp(arg0);
}

void func_80807FBC_bsfirstp(s32 arg0) {
    void *volatile sp1C;
    volatile s32 sp18;
    s32 temp_a1;
    void *temp_v0;
    u8 temp_a2;

    temp_v0 = *(void **)((s8 *)arg0 + 0x188);
    temp_a1 = (s32)temp_v0 + 0x6C;
    sp18 = temp_a1;
    sp1C = temp_v0;
    func_80808100_bsfirstp(arg0, temp_a1);
    func_808080A4_bsfirstp((void *)arg0, 255);
    temp_a2 = *(u8 *)((s8 *)sp1C + 0x72);
    func_808080B4_bsfirstp(arg0, (s16 *)*(s32 *)&sp18, temp_a2);
}

void func_8080800C_bsfirstp(s32 arg0) {
    s16 sp28[3];
    s16 *var_v1;
    u8 *sp20;
    u8 *var_v0;

    sp20 = *(u8 **)((s8 *)arg0 + 0x188);
    func_80808100_bsfirstp(arg0, (s32)sp28);
    var_v0 = sp20;
    var_v1 = sp28;
    do {
        *(s16 *)(var_v0 + 0x6C) = (*(s16 *)(var_v0 + 0x6C) * 3 + *var_v1++) >> 2;
        var_v0 += 2;
    } while (((u32)var_v1 ^ (u32)&sp28[3]) != 0);
    func_808080B4_bsfirstp(arg0, (s16 *)(sp20 + 0x6C), *(u8 *)(sp20 + 0x72));
}

void func_80808084_bsfirstp(s32 arg0)
{
    func_80092744(arg0,0);
}

void func_808080A4_bsfirstp(void *arg0, u8 arg1) {
    s8 *ptr = *(s8 **)((s8 *)arg0 + 0x188);
    ptr[0x72] = arg1;
}

void func_808080B4_bsfirstp(s32 arg0, s16 *arg1, u8 arg2) {
    func_80092744((s32 *) arg0, 1);
    func_80092750((void *) arg0, arg1[0], arg1[1], arg1[2], arg2);
}

/* extern */

void func_80808100_bsfirstp(s32 arg0, s16 *arg1) {
    s32 func_80808148_bsfirstp(s32, s32 *);
    void func_808084AC_bsfirstp(f32 *, f32);
    void func_8080853C_bsfirstp(f32 *, f32);
    void func_808085A8_bsfirstp(f32 *, s16 *);
    f32 sp1C[3];

    func_80808148_bsfirstp(arg0, sp1C);
    func_8080853C_bsfirstp(sp1C, 20.0f);
    func_808084AC_bsfirstp(sp1C, 0.5f);
    func_808085A8_bsfirstp(sp1C, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808148_bsfirstp.s")

/* extern */

void func_808084AC_bsfirstp(f32 *arg0, f32 arg1) {
    f32 func_800F1214(f32, f32, f32);
    f32 *var_s0;
    f32 temp_f0;
    f32 temp_f20;
    s32 var_s1;

    var_s0 = arg0;
    var_s1 = 0;
    temp_f20 = (arg0[0] + arg0[1] + arg0[2]) * 0.33333334f;
    do {
        temp_f0 = func_800F1214(arg1, temp_f20, *var_s0);
        var_s1 += 1;
        var_s0++;
        var_s0[-1] = temp_f0;
    } while (var_s1 != 3);
}

void func_8080853C_bsfirstp(f32 *arg0, f32 arg1) {
    f32 scale = 1.0f - arg1 * 0.00390625f;
    s32 i;
    f32 *p;

    for (i = 0, p = arg0; i != 3; i++) {
        *p = *p * scale + arg1;
        p++;
    }
}

void func_808085A8_bsfirstp(f32 *arg0, s16 *arg1) {
    s32 i;
    f32 value;

    for (i = 0; i < 3; i++) {
        value = arg0[i];
        if (value < 0.0f) {
            arg1[i] = 0;
        } else if (value > 255.0f) {
            arg1[i] = 255;
        } else {
            arg1[i] = (s32)(value + 0.5f);
        }
    }
}

/* extern */

s32 func_80808630_bsfirstp(s32 arg0) {
    s32 bakey_pressed(s32, s32);
    s32 func_800C6E38(s32);
    if ((func_800C6E38(0x1A) != 0) && (bakey_pressed(arg0, 9) != 0)) {
        return 1;
    }
    return 0;
}

void func_808086B0_bsfirstp(Actor *, s32);

void func_80808678_bsfirstp(Actor *arg0, volatile s32 arg1) {
    void func_8080633C_bsfirstp(Actor *, f32);
    func_808086B0_bsfirstp(arg0, 3);
    func_8080633C_bsfirstp(arg0, 0.15f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808086B0_bsfirstp.s")

void func_80808848_bsfirstp(Actor *arg0) {
    void _bainvisible_entrypoint_7(Actor *, s32, f32, f32, f32);
    s32 func_80807BB8_bsfirstp();
    s32 func_80808DB0_bsfirstp(void *);
    func_80807BB8_bsfirstp();
    func_80808DB0_bsfirstp(arg0);
    _bainvisible_entrypoint_7(arg0, 3, 1.0f, 1.0f, 0.4f);
    func_808086B0_bsfirstp(arg0, 1);
}

void func_808088A4_bsfirstp(s32 arg0)
{
    func_808086B0_bsfirstp(arg0,0x3);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808088D0_bsfirstp.s")

s32 bsfirstp_entrypoint_34(s32 arg0) {
    extern s32 D_8080B5B0_bsfirstp[];
    return ((s32 *)&D_8080B5B0_bsfirstp)[arg0];
}

void func_80808A24_bsfirstp(struct player_state_s *arg0) {
    s32 func_80807BB8_bsfirstp();
    s32 func_80808DB0_bsfirstp(void *);
    s32 func_80808CAC_bsfirstp(struct player_state_s *, s32);
    void func_80808D80_bsfirstp(s32);
    void *sp24;

    sp24 = *(void **)((u8 *)arg0 + 0x188);
    func_80807BB8_bsfirstp(arg0);
    *(s32 *)((u8 *)sp24 + 8) = -1;
    func_80808DB0_bsfirstp(arg0);
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
    func_80808CAC_bsfirstp(arg0, 1);
    func_80800858_bsfirstp((s32)arg0, 1);
    func_80808D80_bsfirstp((s32)arg0);
}

void func_80808A8C_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808AAC_bsfirstp.s")

s32 bsfirstp_entrypoint_35(s32 arg0) {
    extern s32 D_8080B5C0_bsfirstp[];
    return ((s32 *)&D_8080B5C0_bsfirstp)[arg0];
}

/* extern */

s32 func_80808B24_bsfirstp(s32 arg0) {
    s32 func_80802D50_bsfirstp(s32, s32 *);
    s32 func_80809540_bsfirstp(s32, s32);
    s32 sp1C;

    if (func_80802D50_bsfirstp(arg0, &sp1C) != 0) {
        return sp1C;
    }
    if (func_80808630_bsfirstp(arg0) != 0) {
        return 0xD2;
    }
    if (func_80809540_bsfirstp(arg0, 0) != 0) {
        return 0xD1;
    }
    return 0;
}

/* extern */

void func_80808B8C_bsfirstp(struct player_state_s *arg0) {
    f32 func_800D9004(void);
    s32 func_80808CAC_bsfirstp(struct player_state_s *, s32);
    s32 temp_v0;

    if (func_80802444_bsfirstp(arg0) == 1) {
        if ((*(s32 *)((s8 *)(arg0) + (0x15C))) >= 2) {
            (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
            func_80808CAC_bsfirstp(arg0, 1);
        }
    } else {
        temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x15C)));
        if (temp_v0 != 0) {
            if (temp_v0 == 1) {
                (*(f32 *)((s8 *)(arg0) + (0x16C))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x16C))) - func_800D9004());
                if ((*(f32 *)((s8 *)(arg0) + (0x16C))) < 0.0f) {
                    func_80808CAC_bsfirstp(arg0, 1);
                }
            } else if (func_80800228_bsfirstp(arg0) != 0) {
                func_80808CAC_bsfirstp(arg0, 1);
            }
        }
    }
}

void func_80808C48_bsfirstp(struct player_state_s *arg0) {
    s32 func_80808CAC_bsfirstp(struct player_state_s *, s32);
    void func_80808D80_bsfirstp(s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void func_8008B304(struct anctrl_s *);

    *(s32 *)((s8 *)arg0 + 0x160) = 0;
    *(f32 *)((s8 *)arg0 + 0x16C) = 5.0f;
    func_80808CAC_bsfirstp(arg0, 0);
    func_80808D80_bsfirstp((s32)arg0);
    func_8008B304(baanim_getAnimCtrlPtr(arg0));
    func_8008B304(func_8008D04C(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808CAC_bsfirstp.s")

/* extern */

void func_80808D80_bsfirstp(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s16, s32);
    void *func_80802508_bsfirstp();
    void *temp_v0;

    temp_v0 = func_80802508_bsfirstp();
    baanim_playForDuration_loopSmooth(arg0, (*(s16 *)((s8 *)(temp_v0) + (0))), (*(s32 *)((s8 *)(temp_v0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808DB0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808E78_bsfirstp.s")

/* extern */

void func_80808EF0_bsfirstp(s32 arg0) {
    s32 bakey_pressed(s32, s32);
    void func_8009C128(s32, f32 *);
    s32 func_801013A8(f32 *, s32, s32);
    f32 sp18[3];

    if (bakey_pressed(arg0, 8) != 0) {
        func_8009C128(arg0, sp18 - 1);
        func_801013A8(sp18 - 1, 0x6F, (*(s32 *)((s8 *)(arg0) + (0x184))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808F38_bsfirstp.s")

/* extern */

void func_808090D8_bsfirstp(void *arg0) {
    s32 func_800F7F98(s32, u32);
    s32 func_80808DB0_bsfirstp(void *);
    s32 *ptr = *(s32 **)((s8 *)(arg0) + 0x188);
    ptr[2] = -1;
    func_80808DB0_bsfirstp(arg0);
    func_8008E95C(arg0);
    func_800F7F98(*(s32 *)((s8 *)(arg0) + 0x184), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080911C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809198_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809250_bsfirstp.s")

/* extern */

void func_80809334_bsfirstp(void *arg0) {
    s32 func_80807BB8_bsfirstp();
    s32 func_80808DB0_bsfirstp(void *);
    void func_80809900_bsfirstp(void *);
    func_80807BB8_bsfirstp(arg0);
    func_80808DB0_bsfirstp(arg0);
    func_80809900_bsfirstp(arg0);
    func_80800858_bsfirstp((s32)arg0, 1);
    func_80809684_bsfirstp(arg0, 0);
}

void func_80809384_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808093A4_bsfirstp.s")

s32 bsfirstp_entrypoint_36(s32 arg0) {
    extern s32 D_8080B5D0_bsfirstp[];
    return ((s32 *)&D_8080B5D0_bsfirstp)[arg0];
}

/* extern */

s32 func_808094A4_bsfirstp(s32 arg0) {
    s32 func_80802D50_bsfirstp(s32, s32 *);
    s32 sp1C;

    if (func_80802D50_bsfirstp(arg0, &sp1C) != 0) {
        return sp1C;
    }
    if (func_80808630_bsfirstp(arg0) != 0) {
        return 0xD2;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808094F4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809540_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809684_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809740_bsfirstp.s")

/* extern */

void func_80809900_bsfirstp(void *arg0) {
    void func_80800424_bsfirstp(struct player_state_s *, s32, f32);
    func_80800424_bsfirstp(arg0, func_80802534_bsfirstp(arg0), 1.0f);
    func_808001FC_bsfirstp(arg0);
}

f32 func_80809938_bsfirstp(void *arg0) {
    void *temp_v0;
    f32 result;

    temp_v0 = *(void **)((s8 *)arg0 + 0x188);
    result = *(f32 *)((s8 *)temp_v0 + 0x24C) * (1.0f / *(f32 *)((s8 *)temp_v0 + 0x230));
    return result;
}

/* extern */

void func_8080995C_bsfirstp(u8 *arg0) {
    void *func_80802458_bsfirstp(void *);
    struct {
        s32 pad;
        u8 *data;
    } local;

    local.data = *(u8 **)((s8 *)arg0 + 0x188);
    bcopy((u8 *)func_80802458_bsfirstp(arg0) + 0x74, local.data + 0x230, 0x18);
    *(s16 *)(local.data + 0x248) = 0;
    *(f32 *)(local.data + 0x24C) = 0.0f;
    *(f32 *)(local.data + 0x250) = 0.0f;
}

void func_808099A8_bsfirstp(void *arg0, s32 arg1) {
    void *state = *(void **)((u8 *)arg0 + 392);
    *(s16 *)((u8 *)state + 584) = arg1;
}

void func_808099B4_bsfirstp(void *arg0) {
    void func_80809A10_bsfirstp(void *);
    void func_80809A7C_bsfirstp(void *);
    void *data;
    s16 state;

    data = *(void **)((u8 *)arg0 + 0x188);
    state = *(s16 *)((u8 *)data + 0x248);
    switch (state) {
    case 0:
        return;
    case 1:
        func_80809A10_bsfirstp(arg0);
        return;
    case 2:
        func_80809A7C_bsfirstp(arg0);
        return;
    }
}

/* extern */

void func_80809A10_bsfirstp(void *arg0) {
    s32 func_80809AF8_bsfirstp(void *, f32, f32, f32);
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f2;
    struct {
        u8 pad0[0x168];
        f32 scale;
        f32 divisor;
        s32 flag;
        u8 pad174[0xBC];
        f32 value;
        f32 pad234;
        f32 numerator;
        f32 pad23C;
        f32 fallback;
    } *temp_v0;

    temp_v0 = *(void **)((s8 *)arg0 + 0x188);
    temp_f0 = temp_v0->value;
    temp_f12 = -temp_f0;
    temp_f12 *= temp_v0->scale;
    if (temp_v0->flag != 0) {
        var_f2 = temp_v0->numerator / (1.0f + temp_v0->divisor);
    } else {
        var_f2 = temp_v0->fallback;
    }
    func_80809AF8_bsfirstp(arg0, temp_f12, var_f2, temp_f0);
}

/* extern */

void func_80809A7C_bsfirstp(void *arg0) {
    f32 func_800F122C(f32, f32, f32);
    s32 func_80809AF8_bsfirstp(void *, f32, f32, f32);
    void *temp_v0;
    f32 temp_a1;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    temp_a1 = func_800F122C(-(*(f32 *)((s8 *)(temp_v0) + (0xC0))), 5.0f, (*(f32 *)((s8 *)(temp_v0) + (0x234))));
    func_80809AF8_bsfirstp(arg0, temp_a1,
        (*(f32 *)((s8 *)temp_v0 + 0xC0)) != 0.0f
            ? (*(f32 *)((s8 *)temp_v0 + 0x23C))
            : (*(f32 *)((s8 *)temp_v0 + 0x244)),
        (*(f32 *)((s8 *)temp_v0 + 0x234)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809AF8_bsfirstp.s")

void bsfirstp_entrypoint_37(void *arg0) {
    int func_800A4C68(void *);
    s32 func_800A89F8();
    void func_80809C30_bsfirstp(void *);
    s32 state;

    state = func_800A89F8();
    if (func_800A4C68(arg0) == state) {
        func_80809C30_bsfirstp(arg0);
    }
}

/* extern */

void func_80809C30_bsfirstp(void *arg0) {
    s32 func_8009239C(u8 **);
    u32 func_800936F4(void *);
    s32 func_80093DF4(void *, s32);
    s32 func_80093E18(void *, s32 *);
    s32 *func_800A7180(void);
    if ((func_80093DF4(arg0, 2) != 0) && (func_800936F4(arg0) != 0) && (func_8009239C(arg0) != 0)) {
        func_80093E18(arg0, func_800A7180());
    }
}

void func_80809C90_bsfirstp(s32 arg0) {
    s32 func_8009ADF0(void *, s32, s32);
    func_8009ADF0(arg0, 0xB, 1);
}

void func_80809CB4_bsfirstp(u8 *arg0) {
    s32 func_8009ADF0(void *, s32, s32);
    func_8009ADF0(arg0, 0xB, 0);
}

void func_80809CD8_bsfirstp()
{
    void func_80809CF8_bsfirstp();
    func_80809CF8_bsfirstp();
}

void func_80809CF8_bsfirstp(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x188);
    *(f32 *)((u8 *)temp_v0 + 0x29C) = 162.5f;
    *(f32 *)((u8 *)temp_v0 + 0x2A0) = 8.0f;
    *(s32 *)((u8 *)temp_v0 + 0x264) = 0;
    *(f32 *)((u8 *)temp_v0 + 0x25C) = 0.0f;
}

void func_8080A194_bsfirstp(void *arg0);
void func_80809F74_bsfirstp(struct player_state_s *arg0);

void func_80809D24_bsfirstp(void *arg0) {
    void func_80809DD0_bsfirstp(void *);
    func_80809DD0_bsfirstp(arg0);
    func_80809F74_bsfirstp(arg0);
    func_8080A03C_bsfirstp(arg0);
    func_8080A194_bsfirstp(arg0);
    func_8080A250_bsfirstp(arg0);
}

s32 func_80809D6C_bsfirstp(void *arg0) {
    s32 result;
    s32 *ptr;
    ptr = *(s32 **)((u8 *)arg0 + 0x188);
    result = 0;
    return ptr[0x254 / 4] == 1 ? 1 : result;
}

f32 func_80809D94_bsfirstp(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 392);
    return *(f32 *)((u8 *)temp_v0 + 604);
}

void func_80809DA0_bsfirstp(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    if (arg1 == 0) {
        if ((*(s32 *)((s8 *)(temp_v0) + (0x254))) < 0) {
            (*(s32 *)((s8 *)(temp_v0) + (0x254))) = arg1;
            (*(s32 *)((s8 *)(temp_v0) + (0x258))) = 0;
        }
    } else {
        (*(s32 *)((s8 *)(temp_v0) + (0x254))) = arg1;
        (*(s32 *)((s8 *)(temp_v0) + (0x258))) = 0;
    }
}

void func_80809DD0_bsfirstp(void *arg0) {
    f32 mlAbsF(f32);
    void *temp_v0;
    s32 var_v1;
    f32 var_f14;
    f32 sp18;

    temp_v0 = *(void **)((u8 *)arg0 + 0x188);
    var_v1 = 0;
    if (*(s32 *)((u8 *)temp_v0 + 0xA0) == 1) {
        var_f14 = *(f32 *)((u8 *)temp_v0 + 0xC4);
    } else {
        var_v1 = *(s32 *)((u8 *)temp_v0 + 0x10);
        var_f14 = *(f32 *)((u8 *)temp_v0 + 0x180);
    }
    switch (var_v1) {
    case 0:
        *(s32 *)((u8 *)temp_v0 + 0x254) = 0;
        break;
    case 1:
        sp18 = mlAbsF(*(f32 *)((u8 *)temp_v0 + 0x148));
        if (mlAbsF(var_f14) > 0.01f) {
            if (sp18 > 0.5f) {
                *(s32 *)((u8 *)temp_v0 + 0x258) = 1;
            } else {
                *(s32 *)((u8 *)temp_v0 + 0x258) = 0;
            }
            *(s32 *)((u8 *)temp_v0 + 0x254) = 0;
        } else if (*(s32 *)((u8 *)temp_v0 + 0x254) == 0) {
            if (*(s32 *)((u8 *)temp_v0 + 0x258) != 0) {
                if (sp18 < 0.25f) {
                    *(s32 *)((u8 *)temp_v0 + 0x254) = 1;
                }
            } else if (sp18 > 0.75f) {
                *(s32 *)((u8 *)temp_v0 + 0x254) = 1;
            }
        }
        break;
    }
}

/* extern */

void func_80809EF8_bsfirstp(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp1C[3];

    func_800EE7F8(sp1C, arg0);
    sp1C[1] += 300.0f;
    func_800EE7F8(arg1, arg0);
    arg1[1] += -300.0f;
    func_800BEF00(sp1C, arg1, arg2, 0x08020020);
}

/* extern */

void func_80809F74_bsfirstp(struct player_state_s *arg0) {
    void func_800963C0(struct player_state_s *, f32 *);
    s32 func_80096628(struct player_state_s *);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    f32 yaw_get(struct player_state_s *);
    s32 sp44[1];
    f32 sp34[4];
    f32 sp28[3];
    f32 sp24;
    s32 sp20;
    s32 temp_v0;
    s32 temp_v0_2;

    sp44[0] = (*(s32 *)((s8 *)(arg0) + (0x188)));
    sp20 = func_80096628(arg0);
    sp24 = yaw_get(arg0);
    func_800963C0(arg0, sp34);
    if ((func_800F1B78(sp28, sp34, sp24, 1.0f) != 0) && !(sp20 & 0x08000000)) {
        temp_v0 = sp44[0] + 0x254;
        (*(f32 *)((s8 *)(temp_v0) + (0x1C))) = -sp28[0];
        if (sp20 & 0x10000000) {
            (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 3;
            return;
        }
        (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 1;
        return;
    }
    temp_v0_2 = sp44[0] + 0x254;
    (*(f32 *)((s8 *)(temp_v0_2) + (0x1C))) = 0.0f;
    if (sp20 & 0x10000000) {
        (*(s32 *)((s8 *)(temp_v0_2) + (0x18))) = 2;
        return;
    }
    (*(s32 *)((s8 *)(temp_v0_2) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080A03C_bsfirstp.s")

void func_8080A194_bsfirstp(void *arg0) {
    int temp_a0;
    s32 temp_a1;
    int temp_a3;
    s32 temp_v1;
    int var_a2;
    u8 *temp_v0;
    s32 *temp_v1_2;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x188)));
    temp_v1 = (*(s32 *)((s8 *)(temp_v0) + (0x26C)));
    temp_a1 = (*(s32 *)((s8 *)(temp_v0) + (0x2A4)));
    var_a2 = temp_v1 == 3 || temp_v1 == 2;
    temp_a3 = temp_v1 == 3;
    temp_v1_2 = (s32 *)(temp_v0 + 0x254);
    temp_a0 = temp_a1 == 3;
    if ((temp_a0 != 0) && (var_a2 == 0)) {
        temp_v1_2[5] = 0;
    }
    var_a2 = temp_a1 == 3 || temp_a1 == 2;
    if ((var_a2 == 0) & temp_a3) {
        temp_v1_2[5] = 0;
    }
    if (temp_v1_2[5] != 0) {
        ((f32 *)temp_v1_2)[2] = ((f32 *)temp_v1_2)[17];
        return;
    }
    if ((25.0f == ((f32 *)temp_v1_2)[18]) && (temp_v1_2[3] >= 5)) {
        ((f32 *)temp_v1_2)[2] = ((f32 *)temp_v1_2)[7];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080A250_bsfirstp.s")

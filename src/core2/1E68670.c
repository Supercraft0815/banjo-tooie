#include "common.h"

s32 func_8008ED80(void)
{
	return 0x1;
}

void func_8008ED88(void *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void func_800F497C(s32);
    void func_800F49A8(s32, s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4A58(s32, s32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 func_8010D5DC;
    Actor *sp1C;

    sp1C = func_80106790(arg2);
    func_800F497C(*(s32 *)((s8 *)arg0 + 0x184));
    func_800F49A8(*(s32 *)((s8 *)arg0 + 0x184), 1);
    func_800F49D4(*(s32 *)((s8 *)arg0 + 0x184), &func_8010D5DC, (s32)sp1C->unk0);
    func_800F4A58(*(s32 *)((s8 *)arg0 + 0x184), (s32)sp1C->position, 500.0f);
}

s32 func_8008EE04(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        return arg1;
    }
    return 0;
}

struct player_state_s;
typedef struct {
    u8 pad0[0x74];
    u32 pad74_20 : 12;
    u32 unk74_19 : 1;
    u32 pad74_17 : 2;
    u32 unk74_16 : 1;
    u32 pad74_0 : 16;
} Unk8008EE1C;

s32 func_8008EE1C(Unk8008EE1C *arg0, s32 arg1) {
    s32 bs_getCurrentState(struct player_state_s *);
    struct player_state_s *func_800F53D0(s32);

    switch (bs_getCurrentState(func_800F53D0(arg1))) {
        case 15:
            return arg0->unk74_19 == 0;
        case 19:
            return arg0->unk74_16 == 0;
        default:
            return 1;
    }
}

void func_8008EE88(void *arg0, f32 arg1) {
    void func_8009C128(void *, f32[3]);
    void func_8008EEC4(void *, f32 *, f32, s32);
    f32 position[3];

    func_8009C128(arg0, position);
    func_8008EEC4(arg0, position, arg1, 0x270);
}

void func_8008EEC4(void *arg0, f32 *arg1, f32 arg2, s32 arg3) {
    s32 func_8008E938(void *);
    s32 func_800CB840(s32, s32);
    s32 func_800CB870();
    s32 func_80109C4C(f32 *, f32, s32, s32 (*)(Unk8008EE1C *, s32), s32, s32, s32);
    func_800CB840(1, (*(s32 *)((s8 *)(arg0) + (0x184))));
    func_80109C4C(arg1, arg2, 2, &func_8008EE1C, (*(s32 *)((s8 *)(arg0) + (0x184))), func_8008E938(arg0), arg3);
    func_800CB870();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008EF3C.s")

/* extern */

s32 func_8008F4F0(struct player_state_s *arg0) {
    int baflag_isTrue(struct player_state_s *, s32);
    s32 func_8008EF3C(struct player_state_s *);
    s32 result;

    result = func_8008EF3C(arg0);
    if (result == 0xB) {
        if (baflag_isTrue(arg0, 0x26) != 0) {
            return result;
        }
    }
    if (result == 1) {
        if (baflag_isTrue(arg0, 0x27) != 0) {
            return result;
        }
    }
    return 0;
}

/* extern */

s32 func_8008F568(s32 arg0, s32 arg1, Actor **arg2) {
    Unk80132ED0 *_bahold_entrypoint_5(s32);
    void func_8008E9A0(void *, s32);
    void func_800904C8(s32);
    s32 func_800D1B34(s32);
    s32 func_800D1C38(s32);
    Actor *func_80106790(Unk80132ED0 *);
    Unk80132ED0 *sp24;
    Unk80132ED0 *sp20;
    Actor *sp1C;

    sp24 = (*arg2)->unk0;
    sp20 = _bahold_entrypoint_5(arg0);
    if (sp20 != 0) {
        sp1C = func_80106790(sp20);
    }
    if ((sp20 != 0) && (arg1 != sp1C->unk6C_9)) {
        return 0;
    }
    func_8008E9A0(arg0, arg1);
    if (func_800D1C38(func_800D1B34(arg1)) == 0) {
        func_800904C8(0x12);
    } else {
        return 0;
    }
    *arg2 = func_80106790(sp24);
    return 1;
}

/* extern */

void func_8008F62C(s32 arg0, u32 arg1) {
    s32 _bahold_entrypoint_6(struct player_state_s *, Unk80132ED0 *);
    void bs_setState();
    void func_80092D44(struct player_state_s *, f32[3]);
    s32 func_8009E674(struct player_state_s *, s32);
    struct player_state_s *func_800F53D0(s32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 yaw_get(struct player_state_s *);
    struct player_state_s *temp_v0;
    Actor *temp_v0_2;
    f32 sp24[3];

    temp_v0 = func_800F53D0(arg0);
    func_80092D44(temp_v0, sp24);
    temp_v0_2 = func_80108474(arg1, sp24, (s32) yaw_get(temp_v0));
    temp_v0_2->unk64_23 = 1;
    _bahold_entrypoint_6(temp_v0, temp_v0_2->unk0);
    if (func_8009E674(temp_v0, 0x400) == 0) {
        bs_setState(temp_v0, 0x3A);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F6B8.s")

/* extern */

void func_8008F748(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_0(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32 *);
    s32 func_800A3514(s32, s32 *);
    s32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(arg1, arg2), sp1C);
    func_800A3514(arg0, sp1C);
}

/* extern */

void func_8008F788(s32 arg0, s32 arg1) {
    s32 func_800D1844(s32);
    s32 func_800D1B34(s32);
    func_800D1844(func_800D1B34(arg1));
}

void func_8008F7B4(s32 player, s32 actor_id) {
    Unk80132ED0 *_bahold_entrypoint_5(s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _bahold_entrypoint_4(s32);
    s32 func_800D1B34(s32);
    s32 func_800D1804(s32);
    Unk80132ED0 *marker;
    Actor *actor;
    marker = _bahold_entrypoint_5(player);
    if (marker) actor = func_80106790(marker);
    if (marker && actor->unk6C_9 == actor_id) _bahold_entrypoint_4(player);
    func_800D1804(func_800D1B34(actor_id));
}

/* extern */

void func_8008F828(s32 arg0, s32 arg1) {
    s32 func_800D1A04(s32);
    s32 func_800D1B34(s32);
    func_800D1A04(func_800D1B34(arg1));
}

/* extern */

void func_8008F854(s32 arg0, s32 arg1) {
    s32 func_800D1824(s32);
    s32 func_800D1B34(s32);
    func_800D1824(func_800D1B34(arg1));
}

void func_8008F880(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80106790(arg0) + 4));
}

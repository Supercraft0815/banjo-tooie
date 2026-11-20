#include "bs_script.h"
#include "bs/firstp.h"
#ifdef BT_NATIVE
#include "overlays/ba/yaw.h" // enums for the prototypes below
#include "overlays/ba/physics.h"
#endif
#include "overlays/ba/playerstate.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#include "overlays/ba/anim.h"
#endif
/* Per-state memory of the first-person state, allocated in player->state_mem. */
typedef struct bs_firstp_state_s {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    u8 pad14[0x4];
    /* 0x018 */ f32 offset[4];
    /* 0x028 */ s32 unk28;
    /* 0x02C */ f32 unk2C[3];
    /* 0x038 */ f32 smooth_velocity[3];
    /* 0x044 */ f32 speed_along; // smoothed velocity projected onto unk2C
    /* 0x048 */ f32 speed_across;
    /* 0x04C */ f32 unk4C;
    /* 0x050 */ f32 pitch;
    /* 0x054 */ f32 sway_phase;
    /* 0x058 */ f32 sway;
    /* 0x05C */ f32 bob_phase;
    /* 0x060 */ f32 bob;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s16 unk6C;
    u8 pad6E[0x4];
    /* 0x072 */ u8 unk72;
    u8 pad73[0x19];
    /* 0x08C */ s32 offset_preset; // index into D_8080A5B0_bsfirstp
    /* 0x090 */ f32 offset_strength;
    u8 pad94[0x4];
    /* 0x098 */ f32 unk98;
    /* 0x09C */ f32 unk9C;
    /* 0x0A0 */ s32 unkA0;
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ s32 unkAC;
    u8 padB0[0x4];
    /* 0x0B4 */ f32 unkB4;
    /* 0x0B8 */ f32 unkB8;
    /* 0x0BC */ f32 unkBC;
    /* 0x0C0 */ f32 unkC0;
    /* 0x0C4 */ f32 unkC4;
    /* 0x0C8 */ f32 yaw_offset;
    /* 0x0CC */ f32 pitch_offset;
    u8 padD0[0x4];
    /* 0x0D4 */ s16 unkD4;
    /* 0x0D6 */ s16 unkD6;
    /* 0x0D8 */ f32 unkD8;
    /* 0x0DC */ f32 unkDC;
    /* 0x0E0 */ s16 unkE0;
    /* 0x0E2 */ s16 unkE2;
    u8 padE4[0x2];
    /* 0x0E6 */ s16 unkE6;
    /* 0x0E8 */ s16 unkE8;
    u8 padEA[0x2];
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0;
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ f32 unkF8;
    u8 padFC[0xC];
    /* 0x108 */ s32 unk108;
    /* 0x10C */ f32 unk10C;
    u8 pad110[0x4];
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ f32 unk11C;
    u8 pad120[0x4];
    /* 0x124 */ f32 unk124;
    u8 pad128[0x20];
    /* 0x148 */ f32 unk148;
    u8 pad14C[0x1C];
    /* 0x168 */ f32 unk168;
    u8 pad16C[0x14];
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    u8 pad188[0x14];
    /* 0x19C */ s32 unk19C;
    u8 pad1A0[0x18];
    /* 0x1B8 */ f32 unk1B8;
    /* 0x1BC */ f32 unk1BC;
    u8 pad1C0[0xC];
    /* 0x1CC */ f32 unk1CC;
    u8 pad1D0[0x4];
    /* 0x1D4 */ f32 unk1D4;
    u8 pad1D8[0x10];
    /* 0x1E8 */ f32 unk1E8;
    /* 0x1EC */ f32 unk1EC;
    /* 0x1F0 */ f32 unk1F0;
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ f32 unk1F8;
    /* 0x1FC */ f32 unk1FC;
    /* 0x200 */ f32 unk200;
    /* 0x204 */ f32 unk204;
    /* 0x208 */ f32 unk208;
    /* 0x20C */ f32 yaw;
    u8 pad210[0x8];
    /* 0x218 */ u8 unk218;
    /* 0x219 */ u8 unk219;
    u8 pad21A[0x2];
    /* 0x21C */ f32 unk21C;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ f32 unk224;
    /* 0x228 */ f32 unk228;
    u8 pad22C[0x4];
    /* 0x230 */ f32 unk230;
    /* 0x234 */ f32 unk234;
    u8 pad238[0x4];
    /* 0x23C */ f32 unk23C;
    u8 pad240[0x4];
    /* 0x244 */ f32 unk244;
    /* 0x248 */ s16 unk248;
    u8 pad24A[0x2];
    /* 0x24C */ f32 unk24C;
    u8 pad250[0x4];
    /* 0x254 */ s32 unk254;
    /* 0x258 */ s32 unk258;
    /* 0x25C */ f32 unk25C;
    u8 pad260[0x4];
    /* 0x264 */ s32 unk264;
    u8 pad268[0x4];
    /* 0x26C */ s32 unk26C;
    u8 pad270[0x2C];
    /* 0x29C */ f32 unk29C;
    /* 0x2A0 */ f32 unk2A0;
    /* 0x2A4 */ s32 unk2A4;
} FirstpState;

/* Per-mode view/model config, see func_80802484_bsfirstp. */
typedef struct bs_firstp_config_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    f32 unkC;
    /* 0x10 */ f32 position[3];
    /* 0x1C */ f32 rotation[3];
    u8 pad28[3];
    /* 0x2B */ u8 bone1;
    u8 pad2C[3];
    /* 0x2F */ u8 bone2;
    /* 0x30 */ f32 split_ratio; // share of the turn applied to bone1
    /* 0x34 */ f32 yaw_scale[2];
    /* 0x3C */ f32 pitch_scale[2];
    f32 unk44, unk48;
} FirstpConfig;
#include "firstp_tables.h"
void func_808061AC_bsfirstp(void *, s32);
void func_8009E4E0(void *, s32, BtIntPtr);
struct player_state_s;
enum asset_e;

void func_80809198_bsfirstp(void *arg0);
void func_80809250_bsfirstp(void *arg0);
s32 func_8009E674(struct player_state_s *, s32);
s32 func_8009E6EC(struct player_state_s *);
f32 func_800D9004(void);
s32 func_800F1574(f32 *, f32);
extern f32 D_8080A650_bsfirstp[6][5];

struct anctrl_s;
struct player_state_s;
enum asset_e;
enum asset_e;

/* extern */

FirstpState *func_80800000_bsfirstp(PlayerState *player) {
    void aligned8_memset(void *dst, u32 value, u32 n);
    void _bastatemem_entrypoint_0(BtIntPtr, s32);
    FirstpState *firstp;
    s32 pad;

    _bastatemem_entrypoint_0((BtIntPtr)player, sizeof(FirstpState));
    firstp = player->state_mem;
    aligned8_memset((BtIntPtr)firstp, 0, sizeof(FirstpState));
    return firstp;
}

#ifdef BT_NATIVE
void func_80800040_bsfirstp(void *bt_a0)
#else
void func_80800040_bsfirstp()
#endif
{
    BT_NATIVE_ONLY(void _bastatemem_entrypoint_1(void *);) _bastatemem_entrypoint_1(BT_NATIVE_ONLY(bt_a0));
}

void bsfirstp_entrypoint_0(PlayerState *player, f32 *position, f32 *rotation) {
    FirstpConfig *func_80802484_bsfirstp(void *);
    FirstpState *firstp;
    FirstpConfig *config;

    firstp = player->state_mem;
    config = func_80802484_bsfirstp(player);
    rotation[0] = config->rotation[0];
    rotation[1] = config->rotation[1];
    rotation[2] = config->rotation[2];
    position[0] = config->position[0] + firstp->offset[0];
    position[1] = config->position[1] + firstp->offset[1];
    position[2] = config->position[2];
    func_8080800C_bsfirstp((BtIntPtr)player);
}

void bsfirstp_entrypoint_1(struct player_state_s *player, s32 arg1) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void func_8008B304(struct anctrl_s *);
#ifndef BT_NATIVE
    s32 func_8008B4D4(struct anctrl_s *);
#endif
    void func_800DF41C(BtIntPtr);
    s32 func_80800864_bsfirstp(PlayerState *);
    void func_80800F14_bsfirstp(void *);
    void func_80801000_bsfirstp(void *);
    struct anctrl_s *control;

    switch (arg1) {
    case 0:
        control = baanim_getAnimCtrlPtr(player);
        func_80801000_bsfirstp(player);
        func_8008B304(control);
        func_800DF41C(func_8008B4D4(control));
        break;
    case 1:
        control = func_8008D04C(player);
        if (func_80800864_bsfirstp(player)) {
            func_80800F14_bsfirstp(player);
        }
        func_8008B304(control);
        func_800DF41C(func_8008B4D4(control));
        break;
    }
}

void func_80800190_bsfirstp(PlayerState *player) {
    s32 func_800EFD24(s32);
    BtIntPtr func_80800858_bsfirstp(PlayerState *, s32);
    FirstpState *firstp;

    firstp = player->state_mem;
    func_80800858_bsfirstp(player, 0);
    func_800EFD24((BtIntPtr) firstp->unk2C);
    firstp->pitch = 0.0f;
}

/* extern */

void func_808001D0_bsfirstp(PlayerState *player) {
    BtIntPtr func_80800858_bsfirstp(PlayerState *, s32);
    void func_80808C48_bsfirstp(struct player_state_s *);
    func_80808C48_bsfirstp(player);
    func_80800858_bsfirstp(player, 0);
}

/* extern */

void func_808001FC_bsfirstp(struct player_state_s *player) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    anctrl_setPlaybackType(func_8008D04C(player), 3);
}

/* extern */

s32 func_80800228_bsfirstp(struct player_state_s *player) {
#ifndef BT_NATIVE
    s32 anctrl_getPlaybackType(s32);
#endif
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    s32 result;

    if (anctrl_getPlaybackType(func_8008D04C(player)) == 3) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* extern */

void func_80800264_bsfirstp(BtIntPtr player, s32 arg1) {
#ifndef BT_NATIVE
    s32 func_8008B10C(s32, s32);
#endif
    struct anctrl_s *func_8008D04C();
    func_8008B10C(func_8008D04C(player), arg1);
}

/* extern */

void func_80800290_bsfirstp(struct player_state_s *player, s32 anim, f32 duration) {
    f32 baanim_getTimer(BT_NATIVE_ONLY(struct player_state_s *));
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
#ifdef BT_NATIVE
    baanim_playForDuration_loopStartingAt(player, anim, duration, baanim_getTimer(player));
#else
    baanim_playForDuration_loopStartingAt(player, anim, duration, baanim_getTimer());
#endif
}

void anctrl_reset(struct anctrl_s *);
void anctrl_setDuration(struct anctrl_s *, f32);
void anctrl_setIndex(struct anctrl_s *, enum asset_e);
void anctrl_setPlaybackType(struct anctrl_s *, s32);
void anctrl_setStart(struct anctrl_s *, f32);
void anctrl_start(struct anctrl_s *);

void func_808002CC_bsfirstp(struct player_state_s *self, s32 anim, f32 duration, f32 start) {
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *control;

    control = func_8008D04C(self);
    anctrl_reset(control);
    anctrl_setIndex(control, anim);
    anctrl_setDuration(control, duration);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
}

/* extern */

void func_80800340_bsfirstp(struct player_state_s *self, s32 anim, f32 duration, f32 start) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *control;

    control = func_8008D04C(self);
    anctrl_reset(control);
    anctrl_setIndex(control, anim);
    anctrl_setDuration(control, duration);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
}

/* extern */

void func_808003B4_bsfirstp(struct player_state_s *self, s32 anim, f32 duration) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *control;

    control = func_8008D04C(self);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, anim);
    anctrl_setDuration(control, duration);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
}

/* extern */

void func_80800424_bsfirstp(struct player_state_s *self, s32 anim, f32 duration) {
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *control;

    control = func_8008D04C(self);
    anctrl_reset(control);
    anctrl_setIndex(control, anim);
    anctrl_setDuration(control, duration);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
}

/* extern */

void func_80800488_bsfirstp(struct player_state_s *self, s32 anim, f32 duration) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    struct anctrl_s *control;

    control = func_8008D04C(self);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, anim);
    anctrl_setDuration(control, duration);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
}

s32 func_808004F8_bsfirstp(PlayerState *player) {
    s32 func_800EEC70(f32 *, f32, f32, s32);
    f32 yaw_get(struct player_state_s *);
    FirstpState *firstp;
    f32 yaw;
    firstp = player->state_mem;
    yaw = firstp->yaw;
    return func_800EEC70(firstp->unk2C, yaw, yaw_get(player), 0x43160000); // 150.0f
}

/* extern */

void func_8080053C_bsfirstp(PlayerState *player) {
    s32 func_800EFD24(s32);
    FirstpState *firstp;

    firstp = player->state_mem;
    func_808004F8_bsfirstp(player);
    func_800EFD24((BtIntPtr) firstp->smooth_velocity);
}

void func_8080056C_bsfirstp(PlayerState *player) {
    void func_8009B4D0(void *, BtIntPtr);
    f32 func_800EEFFC(void *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    f32 func_800F0DC0(f32, f32);
    f32 func_800F1CF0(f32 *, f32 *);
    f32 func_80806170_bsfirstp(void *, f32);
    f32 func_80809938_bsfirstp(void *);
    f32 sqrtf(f32);
    FirstpState *firstp;
    f32 velocity[3];
    f32 tmp;
    f32 speed;
    f32 cos_angle;
    f32 sin_angle;

    firstp = player->state_mem;
    tmp = func_800D9004();
    func_8009B4D0(player, (BtIntPtr)velocity);
    func_800EF3DC(velocity, firstp->unk2C);
    func_808004F8_bsfirstp(player);
    func_800EF04C(velocity, firstp->unk2C);
    func_800EF334(velocity, 1.0f / tmp);
    firstp->smooth_velocity[0] += (velocity[0] - firstp->smooth_velocity[0]) * 0.2f;
    firstp->smooth_velocity[2] += (velocity[2] - firstp->smooth_velocity[2]) * 0.2f;
    speed = func_80806170_bsfirstp(player, func_800EEFFC(firstp->smooth_velocity));
    cos_angle = func_800F1CF0(firstp->smooth_velocity, firstp->unk2C);
    sin_angle = sqrtf(1.0f - cos_angle * cos_angle);
    firstp->speed_along = func_800F0DC0(speed * cos_angle, 1.0f);
    firstp->speed_across = func_800F0DC0(speed * sin_angle, 1.0f);
    tmp = func_800F0DC0(func_80809938_bsfirstp(player), 1.0f);
    firstp->unk4C += (tmp - firstp->unk4C) * 0.2f;
}

/* extern */

void func_808006DC_bsfirstp(PlayerState *player) {
    f32 func_800136E4(f32);
    f32 func_80013970(f32);
    f32 mlAbsF(f32);
    f32 t;
    f32 along;
    f32 across;
    f32 amount;
    FirstpState *firstp;

    firstp = player->state_mem;
    t = mlAbsF(firstp->speed_along);
    along = t;
    across = firstp->speed_across;
    if (firstp->unk0 == 3) {
        along = t * 1.333f;
        across *= 1.333f;
    }
    t = across * 0.75f;
    if (t < along) {
        amount = along;
    } else {
        amount = t;
    }
    if (amount != 0.0f) {
        t = func_800136E4(firstp->sway_phase + (amount * 12.5f));
        firstp->sway_phase = t;
        firstp->sway = (f32) (func_80013970(t) * amount);
    } else {
        firstp->sway_phase = 0.0f;
        firstp->sway = 0.0f;
    }
    t = along * 0.75f;
    if (t < across) {
        amount = across;
    } else {
        amount = t;
    }
    if (amount != 0.0f) {
        t = func_800136E4(firstp->bob_phase + (amount * 25.0f));
        firstp->bob_phase = t;
        firstp->bob = (f32) (func_80013970(t) * amount);
        return;
    }
    firstp->bob_phase = 0.0f;
    firstp->bob = 0.0f;
}

void func_80800830_bsfirstp(PlayerState *player)
{
    func_8080056C_bsfirstp(player);
    func_808006DC_bsfirstp(player);
}
BtIntPtr func_80800858_bsfirstp(PlayerState *player, s32 value) {
    FirstpState *firstp;

    firstp = player->state_mem;
    firstp->unk28 = value;
    return (BtIntPtr) firstp;
}

s32 func_80800864_bsfirstp(PlayerState *player) {
    s32 result;
    FirstpState *firstp;
    firstp = player->state_mem;
    result = 0;
    return firstp->unk28 != 0 ? 1 : result;
}

/* extern */

void func_80800888_bsfirstp(PlayerState *player, s32 preset) {
    s32 func_80800900_bsfirstp(PlayerState *, f32);
    FirstpState *firstp;
    firstp = player->state_mem;
    firstp->offset_preset = preset;
    func_80800900_bsfirstp(player, 1.0f);
}

/* extern */

s32 func_808008B0_bsfirstp(PlayerState *player) {
    f32 func_800D9004();
    s32 func_80800900_bsfirstp(PlayerState *, f32);
    FirstpState *firstp;
    f32 decay;
    f32 strength;

    firstp = player->state_mem;
    decay = func_800D9004() * 5.5f;
    strength = firstp->offset_strength - decay;
    return func_80800900_bsfirstp(player, strength);
}

s32 func_80800900_bsfirstp(PlayerState *player, f32 strength) {
    extern f32 D_8080A5B0_bsfirstp[][4];
    s32 active;
    f32 *preset;
    FirstpState *firstp;

    firstp = player->state_mem;
    if (strength <= 0.0f) {
        active = 0;
        strength = 0.0f;
    } else {
        active = 1;
    }
    firstp->offset_strength = strength;
    preset = D_8080A5B0_bsfirstp[firstp->offset_preset];
    firstp->offset[0] = (f32) (preset[0] * strength);
    firstp->offset[1] = (f32) (preset[1] * strength);
    firstp->offset[2] = (f32) (preset[2] * strength);
    firstp->offset[3] = (f32) (preset[3] * strength);
    return active;
}

/* Splits the view turn between config->bone1 ([0]) and config->bone2 ([1]). */
void func_80800978_bsfirstp(PlayerState *player, FirstpConfig *config, f32 *yaw_split, f32 *pitch_split) {
    f32 yaw;
    f32 pitch;
    f32 scale;
    FirstpState *firstp;

    firstp = player->state_mem;
    yaw = firstp->yaw_offset * 0.02712968f;
    pitch = firstp->pitch_offset * 0.017686592f;
    if (yaw > 0.0f) {
        scale = -config->yaw_scale[0];
    } else {
        scale = config->yaw_scale[1];
    }
    yaw *= scale;
    if (pitch > 0.0f) {
        scale = -config->pitch_scale[0];
    } else {
        scale = config->pitch_scale[1];
    }
    pitch *= scale;
    yaw_split[0] = (f32) (config->split_ratio * yaw);
    pitch_split[0] = (f32) (config->split_ratio * pitch);
    yaw_split[1] = (f32) (yaw - yaw_split[0]);
    pitch_split[1] = (f32) (pitch - pitch_split[0]);
}

void func_80800A18_bsfirstp(PlayerState *player, void *model) {
    FirstpConfig *func_80802484_bsfirstp(void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    FirstpConfig *config;
    f32 yaw_split[2];
    f32 pitch_split[2];
    FirstpState *firstp;
    f32 lean;
    f32 bob;

    config = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, config, yaw_split, pitch_split);
    func_800E0AFC(model, config->bone1, 1.0f, yaw_split[0], pitch_split[0], 0.0f);
    func_800E0AFC(model, config->bone2, 1.0f, 0.0f, pitch_split[1], -yaw_split[1]);
    firstp = player->state_mem;
    lean = firstp->speed_along * 20.0f;
    bob = firstp->bob * -15.0f;
    func_800E0AFC(model, 0x2D, 1.0f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x2E, 1.0f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x2F, 1.0f, 0.0f, lean, bob);
}

void func_80800B44_bsfirstp(PlayerState *player, void *model) {
    FirstpConfig *func_80802484_bsfirstp(void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    FirstpConfig *config;
    f32 yaw_split[2];
    f32 pitch_split[2];
    FirstpState *firstp;
    f32 lean;
    f32 bob;

    config = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, config, yaw_split, pitch_split);
    func_800E0AFC(model, config->bone1, 1.0f, yaw_split[0], pitch_split[0], 0.0f);
    func_800E0AFC(model, config->bone2, 1.0f, yaw_split[1], pitch_split[1], 0.0f);
    firstp = player->state_mem;
    lean = firstp->speed_along * 20.0f;
    bob = firstp->bob * -15.0f;
    func_800E0AFC(model, 0x2B, 0.5f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x2C, 0.5f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x2D, 0.5f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x2E, 0.5f, 0.0f, lean, bob);
}

void func_80800C88_bsfirstp(PlayerState *player, void *model) {
    FirstpConfig *func_80802484_bsfirstp(void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    FirstpConfig *config;
    f32 yaw_split[2];
    f32 pitch_split[2];

    config = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, config, yaw_split, pitch_split);
    func_800E0AFC(model, config->bone1, 1.0f, yaw_split[0], pitch_split[0], 0.0f);
    func_800E0AFC(model, config->bone2, 1.0f, 0.0f, pitch_split[1], -yaw_split[1]);
}

void func_80800D18_bsfirstp(PlayerState *player, void *model) {
    FirstpConfig *func_80802484_bsfirstp(void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    FirstpConfig *config;
    f32 yaw_split[2];
    f32 pitch_split[2];
    FirstpState *firstp;
    f32 lean;
    f32 bob;
    f32 neg_bob;

    config = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, config, yaw_split, pitch_split);
    func_800E0AFC(model, config->bone1, 1.0f, -yaw_split[0], pitch_split[0], 0.0f);
    func_800E0AFC(model, config->bone2, 1.0f, -yaw_split[1], pitch_split[1], 0.0f);
    firstp = player->state_mem;
    lean = firstp->speed_along * -20.0f;
    bob = firstp->bob * -15.0f;
    func_800E0AFC(model, 0x3C, 0.5f, 0.0f, lean, neg_bob = -bob);
    func_800E0AFC(model, 0x3E, 0.5f, 0.0f, lean, neg_bob);
    func_800E0AFC(model, 0x3F, 0.5f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x40, 0.5f, 0.0f, lean, bob);
    func_800E0AFC(model, 0x54, 0.5f, bob, lean, 0.0f);
    func_800E0AFC(model, 0x5A, 0.5f, bob, lean, 0.0f);
    func_800E0AFC(model, 0x5B, 0.5f, bob, lean, 0.0f);
    func_800E0AFC(model, 0x5C, 0.5f, bob, lean, 0.0f);
    func_800E0AFC(model, 0x5D, 0.5f, bob, lean, 0.0f);
}

void func_80800F14_bsfirstp(void *arg0) {
    void *func_8009370C(u8 *);
    u32 func_800A3280(void *);
    void func_800E0ACC(void *);
    void func_800E0AF0(void *, f32);
    void func_80800D18_bsfirstp(PlayerState *, void *);
    FirstpState *firstp;
    void *model;

    firstp = ((PlayerState *)arg0)->state_mem;
    model = func_8009370C(arg0);
    func_800E0ACC(model);
    func_800E0AF0(model, 1.0f);
    firstp->offset[0] = firstp->sway * 0.02f;
    firstp->offset[1] = firstp->bob * 0.03f;
    switch (func_800A3280(arg0)) {
        case 1:
        case 6:
            func_80800A18_bsfirstp(arg0, model);
            break;
        case 4:
            func_80800B44_bsfirstp(arg0, model);
            break;
        case 5:
            func_80800C88_bsfirstp(arg0, model);
            break;
        case 2:
        case 3:
            func_80800D18_bsfirstp(arg0, model);
            break;
    }
}

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
    FirstpState *firstp;
    void *temp_v0;
    f32 pitch[2];
    f32 yaw[2];
    f32 speed;
    f32 y;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_v0 = func_80092AD8(arg0);
    func_800E0ACC(temp_v0);
    func_800E0AF0(temp_v0, 1.0f);
    pitch[0] = func_800F0DC0(func_80806130_bsfirstp(arg0), 80.0f);
    speed = func_800F1214(func_8080613C_bsfirstp(arg0), 360.0f, 720.0f);
    func_80805380_bsfirstp(&firstp->pitch, pitch[0], speed, speed * 0.041666668f);
    pitch[0] = firstp->pitch;
    pitch[1] = func_80013728(firstp->pitch_offset + pitch[0]);
    yaw[0] = firstp->yaw;
    yaw[1] = func_80013728(firstp->yaw + firstp->yaw_offset);
    switch (*(u32 *)firstp) {
    case 1:
    case 5:
    {
        f32 x, z;
        x = 0.0f;
        y = pitch[0];
        z = 0.0f;
        func_800E0AFC(temp_v0, *(u32 *)firstp == 1 ? 0x2B : 3, 1.0f, x, y, z);
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

void func_808015C0_bsfirstp(struct player_state_s *arg0, f32 arg1[3], f32 arg2[3]) {
    void func_8009C128(struct player_state_s *, f32[3]);
    FirstpConfig *func_80802484_bsfirstp(void *);
    f32 yaw_get(struct player_state_s *);
    FirstpConfig *sp1C;

    sp1C = func_80802484_bsfirstp(arg0);
    func_8009C128(arg0, arg1);
    arg1[1] += sp1C->unk8;
    arg2[0] = 0.0f;
    arg2[1] = yaw_get(arg0) + 180.0f;
    arg2[2] = 0.0f;
}

int func_800A4C68(void *);

f32 func_80801640_bsfirstp(void *arg0)
{
    f32 func_800C517C(s32);

    return func_800C517C(func_800A4C68(arg0));
}

void func_80801668_bsfirstp(void *arg0, f32 arg1) {
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    firstp->unk9C = func_80801640_bsfirstp(arg0);
    firstp->unk98 = arg1;
}

void func_808016A0_bsfirstp(void *arg0) {
    void func_800C5148(s32, f32);
    f32 func_800F2108(f32);
    f32 mlAbsF(f32);
    FirstpState *firstp;
    f32 magnitude;
    f32 current;
    f32 step;
    f32 sign;
    f32 difference;

    firstp = ((PlayerState *)arg0)->state_mem;
    magnitude = firstp->unk98;
    current = firstp->unk9C;
    if (magnitude != current) {
        difference = magnitude - current;
        sign = func_800F2108(difference);
        magnitude = mlAbsF(difference);
        step = magnitude * 0.5f;
        if (step < 0.5f) {
            if (magnitude > 0.5f) {
                step = 0.5f;
            } else {
                step = magnitude;
            }
        }
        current += step * sign;
        firstp->unk9C = current;
        func_800C5148(func_800A4C68(arg0), current);
    }
}

void func_8080175C_bsfirstp(void *arg0) {
    int func_800A4C68(void *);
    void func_800C5148(s32, f32);
    FirstpState *firstp;
    f32 value;

    firstp = ((PlayerState *)arg0)->state_mem;
    value = firstp->unk98;
    firstp->unk9C = value;
    func_800C5148(func_800A4C68(arg0), value);
}

void bsfirstp_entrypoint_2(struct player_state_s *arg0) {
    void _ncba1p_entrypoint_2(struct player_state_s *);
    void _ncba1p_entrypoint_4(void *arg0, s32 arg1);
    void _ncba1p_entrypoint_6(struct player_state_s *, f32[3]);
    void _ncba1p_entrypoint_7(struct player_state_s *, f32[3]);
    u32 func_800A3404(void *);
    s16 *func_800A4C88(void *);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void func_8010FD60(BtIntPtr, f32);
    void func_80110730(BtIntPtr, s32);
    void func_80111590(void *, f32, f32, f32, f32);
    FirstpConfig *func_80802484_bsfirstp(void *);
    FirstpConfig *sp4C;
    s32 pad;
    f32 sp3C[3];
    f32 sp30[3];
    struct player_state_s *camera;

    sp4C = func_80802484_bsfirstp(arg0);
    camera = func_800A4CA8(arg0);
    func_80111590(camera, 0.0f, 0.0f, 360.0f, 360.0f);
    func_80110730(camera, 1);
    func_808015C0_bsfirstp(arg0, sp3C, sp30);
    _ncba1p_entrypoint_6(camera, sp3C);
    _ncba1p_entrypoint_7(camera, sp30);
    if (func_800A3404(arg0) != 0) {
        _ncba1p_entrypoint_2(camera);
        _ncba1p_entrypoint_4(camera, 0);
    }
    func_8010FD60(func_800A4C88(arg0), *(f32 *)sp4C);
    func_80801668_bsfirstp(arg0, ((f32 *)sp4C)[1]);
}

void func_8080187C_bsfirstp(void *arg0) {
    BT_IDO_ONLY(void func_800A5004(void *);) BT_NATIVE_ONLY(void func_800A5004(PlayerState *);)
    BtIntPtr func_800A5090(void *);
    void func_800CA6C0(void *, f32, f32);
    if (func_800A5090(arg0) == 0) {
        func_800A5004(arg0);
        func_800CA6C0(func_800A5090(arg0), 1.0f, 1000.0f);
        func_80801668_bsfirstp(arg0, func_80801640_bsfirstp(arg0));
    }
}

/* extern */

void func_808018E0_bsfirstp(BtIntPtr arg0) {
    s16 *func_800A4C88(void *);
    struct player_state_s *func_800A4CA8();
    void func_8010FD38(BtIntPtr, f32);
    BT_IDO_ONLY(void func_800A5044(u8 *arg0);) BT_NATIVE_ONLY(void func_800A5044(PlayerState *arg0);)
    void func_80110730(BtIntPtr, s32);
    func_80110730(func_800A4CA8(BT_NATIVE_ONLY((void *)arg0)), 0);
    func_8010FD38(func_800A4C88(arg0), 0.0f);
    func_800A5044(BT_IDO_ONLY((u8 *)arg0) BT_NATIVE_ONLY((PlayerState *)arg0));
}

void func_80801928_bsfirstp(struct player_state_s *arg0) {
    void _ncba1p_entrypoint_6(struct player_state_s *, f32[3]);
    void _ncba1p_entrypoint_7(struct player_state_s *, f32[3]);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    BtIntPtr func_800A5090(void *);
    void func_808019B0_bsfirstp(BtIntPtr);
    FirstpState *firstp;
    f32 sp30[3];
    f32 sp24[3];

    if (func_800A5090(arg0) != 0) {
        firstp = arg0->state_mem;
        func_808015C0_bsfirstp(arg0, sp30, sp24);
        sp24[0] = firstp->yaw;
        _ncba1p_entrypoint_6(func_800A4CA8(arg0), sp30);
        _ncba1p_entrypoint_7(func_800A4CA8(arg0), sp24);
        func_808019B0_bsfirstp((BtIntPtr)arg0);
    }
    func_808016A0_bsfirstp(arg0);
}

/* extern */

void func_808019B0_bsfirstp(BtIntPtr arg0) {
    s16 *func_800A4C88(void *);
    void func_8010FD60(BtIntPtr, f32);
    FirstpConfig *func_80802484_bsfirstp(BT_NATIVE_ONLY(void *));
    FirstpConfig *sp1C;

    sp1C = func_80802484_bsfirstp(BT_NATIVE_ONLY((void *)arg0));
    func_8010FD60(func_800A4C88(arg0), *(f32 *)sp1C);
}

/* extern */

void func_808019EC_bsfirstp(BtIntPtr arg0) {
    s32 func_800A4D40();
    BtIntPtr func_800A5090(void *);
    void func_8080175C_bsfirstp(void *);
    if ((func_800A4D40(BT_NATIVE_ONLY((void *)arg0)) != 0) && (func_800A5090(arg0) != 0)) {
        func_808019B0_bsfirstp(arg0);
        func_8080175C_bsfirstp(arg0);
    }
}

void func_80801A34_bsfirstp(BtIntPtr arg0)
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

s32 func_80801A98_bsfirstp(BtIntPtr arg0) {
    s32 _ncba1p_entrypoint_10(BtIntPtr);
    struct player_state_s *func_800A4CA8();
    return _ncba1p_entrypoint_10(func_800A4CA8((struct player_state_s *)arg0)) == 2;
}

void func_80801B64_bsfirstp(u8 *, s32);     

void func_80801AC4_bsfirstp(BtIntPtr arg0) {
    register BtIntPtr temp = *(s32 *)(arg0 + 0x188);
    *(s32 *)(temp + 0xA0) = 0;
    func_80801B64_bsfirstp(arg0, 0);
}

void func_80801AEC_bsfirstp(BtIntPtr arg0)
{
    func_80801B64_bsfirstp(arg0,0);
}

/* extern */

void func_80801B0C_bsfirstp(BtIntPtr arg0, s32 *arg1, s32 *arg2) {
    s32 bainput_func_80097B28(BtIntPtr);
    s32 func_800F424C(BT_NATIVE_ONLY(void *));
    s32 temp_v0;

    if (func_800F424C(BT_NATIVE_ONLY((void *)arg0)) != 0) {
        temp_v0 = bainput_func_80097B28(arg0);
        *arg1 = temp_v0;
        *arg2 = temp_v0;
        return;
    }
    *arg1 = 0;
    *arg2 = 0;
}

void func_80801B64_bsfirstp(u8 *arg0, s32 arg1) {
    void func_80801BDC_bsfirstp(u8 *);
    void func_80801C18_bsfirstp(u8 *);
    void func_80801C74_bsfirstp(u8 *);
    void func_80801D30_bsfirstp(void *);

    switch (arg1) {
    case 0:
        func_80801BDC_bsfirstp(arg0);
        return;
    case 1:
        func_80801D30_bsfirstp(arg0);
        return;
    case 2:
        func_80801C18_bsfirstp(arg0);
        return;
    case 3:
        func_80801C74_bsfirstp(arg0);
        return;
    }
}

/* extern */

void func_80801BDC_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    void func_80801D70_bsfirstp(u8 *);
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    _baeggcursor_entrypoint_7(arg0, 1);
    func_80801D70_bsfirstp(arg0);
    firstp->unkA8 = 0;
}

/* extern */

void func_80801C18_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    FirstpState *firstp;
    firstp = ((PlayerState *)arg0)->state_mem;
    if ((firstp->unkA8 != 0) && (firstp->unkA8 != 2)) {
        _baeggcursor_entrypoint_7(arg0, 1);
        firstp->unkAC = firstp->unkA8;
        firstp->unkA8 = 2;
        firstp->unkA4 = firstp->unkA0;
        firstp->unkA0 = 0;
    }
}

void func_80801C74_bsfirstp(u8 *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    void func_80801D70_bsfirstp(u8 *);
    void func_80802438_bsfirstp(void *, s32);
    FirstpState *firstp;
    s32 temp_v0;

    firstp = ((PlayerState *)arg0)->state_mem;
    if (firstp->unkA8 == 2) {
        temp_v0 = firstp->unkAC;
        switch (temp_v0) {
        case 0:
            firstp->unkA8 = 0;
            break;
        case 1:
            firstp->unkA8 = 1;
            func_80801D70_bsfirstp(arg0);
            temp_v0 = firstp->unkA4;
            if (temp_v0 != 0) {
                if (temp_v0 == 1) {
                    _baeggcursor_entrypoint_7(arg0, 2);
                    func_80802438_bsfirstp(arg0, 1);
                }
            } else {
                _baeggcursor_entrypoint_7(arg0, 1);
                func_80802438_bsfirstp(arg0, 0);
            }
            break;
        }
    }
} typedef struct { f32 unk0; f32 unk4; f32 unk8; s32 unkC; f32 unk10; f32 unk14; f32 unk18; u8 pad1C[0x13C]; s32 unk158; s32 unk15C; u8 pad160[0x24]; s32 unk184; union { void * unk188; f32 * unk188_f32p; s32 * unk188_s32p; s8 * unk188_s8p; u8 * unk188_u8p; }; } Objfirstp_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0xA8]; s32 unkA8; u8 padAC[0x4]; s32 unkB0; } Objfirstp_func_80801D30_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80801D30_bsfirstp(void *arg0) {
    s32 _baeggcursor_entrypoint_7(void *, s32);
    void func_80802438_bsfirstp(void *, s32);
    register void *temp_v0;

    temp_v0 = ((Objfirstp_arg0 *)arg0)->unk188;
    ((Objfirstp_func_80801D30_bsfirstp_temp_v0 *)temp_v0)->unkA8 = 1;
    ((Objfirstp_func_80801D30_bsfirstp_temp_v0 *)temp_v0)->unkB0 = 0;
    _baeggcursor_entrypoint_7(arg0, 1);
    func_80802438_bsfirstp(arg0, 0);
}

/* extern */

void func_80801D70_bsfirstp(u8 *arg0) {
    void _baeggcursor_entrypoint_10(void *, f32, f32);
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    (firstp->unkB8) = 152.0f;
    (firstp->unkBC) = 114.0f;
    (firstp->unkB4) = 0.0f;
    (firstp->unkC0) = 0.0f;
    (firstp->unkC4) = 0.0f;
    _baeggcursor_entrypoint_10(arg0, 152.0f, 114.0f);
}

/* extern */

void func_80801DC0_bsfirstp(u8 *arg0) {
    void func_80801E18_bsfirstp(u8 *);
    void func_80801FD0_bsfirstp(u8 *, s32);
    void func_808023A0_bsfirstp(u8 *);
    FirstpState *firstp;
    s32 temp_v1;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_v1 = (firstp->unkA8);
    if ((temp_v1 == 1) || (temp_v1 == 2)) {
        func_80801E18_bsfirstp(arg0);
        func_80801FD0_bsfirstp(arg0, (firstp->unkC));
        func_808023A0_bsfirstp(arg0);
    }
}

void func_80801E18_bsfirstp(u8 *arg0) {
    void _baeggcursor_entrypoint_10(void *arg0, f32 arg1, f32 arg2);
    u32 _baeggcursor_entrypoint_2(void *arg0);
    s32 _baeggcursor_entrypoint_7(void *arg0, s32 arg1);
    s32 _baeggcursor_entrypoint_9(void *arg0);
    s32 func_8010D930(s32 arg0, s32 arg1, f32 *arg2, s32 *arg3);
    void func_80802438_bsfirstp(void *arg0, s32 arg1);
    extern s16 D_8080A630_bsfirstp[8];
    extern s16 D_8080A640_bsfirstp[8];
    struct CursorState {
        u8 pad[0xB0];
        s32 state;
        u8 padB4[4];
        f32 x, y;
    };
    struct CursorState *cursor;
    s32 pressed;
    s32 held;

    cursor = *(void **)(arg0 + 0x188);
    func_80801B0C_bsfirstp((BtIntPtr)arg0, &pressed, &held);
    /* Separate case exits keep IDO's player pointer in a caller-saved register. */
    switch (cursor->state) {
    case 0:
        if (pressed != 0) {
            cursor->state = 1U;
            _baeggcursor_entrypoint_10(arg0, cursor->x, cursor->y);
            _baeggcursor_entrypoint_7(arg0, 3);
            func_8010D930(0xC, -1, 0, (s32 *)D_8080A630_bsfirstp);
            return;
        } else {
            return;
        }
    case 1:
        if (_baeggcursor_entrypoint_9(arg0) != 0) {
            cursor->state = 2U;
            func_80802438_bsfirstp(arg0, 1);
        } else if (held == 0) {
            cursor->state = 3U;
        }
        break;
    case 2:
        if (held == 0) {
            cursor->state = 5U;
            _baeggcursor_entrypoint_7(arg0, 4);
            func_8010D930(0xC, -1, 0, (s32 *)D_8080A640_bsfirstp);
            return;
        } else {
            return;
        }
    case 3:
        if (_baeggcursor_entrypoint_9(arg0) != 0) {
            cursor->state = 4U;
            func_80802438_bsfirstp(arg0, 1);
        }
        break;
    case 4:
        cursor->state = 5U;
        _baeggcursor_entrypoint_7(arg0, 4);
        func_8010D930(0xC, -1, 0, (s32 *)D_8080A640_bsfirstp);
        break;
    case 5:
        if (_baeggcursor_entrypoint_2(arg0) != 4) {
            cursor->state = 0U;
            func_80802438_bsfirstp(arg0, 0);
        }
        break;
    }
}

void func_80801FD0_bsfirstp(u8 *player, s32 preset) {
    void _baeggcursor_entrypoint_10(void *, f32, f32);
    f32 func_8080222C_bsfirstp(f32, f32, f32);
    f32 func_80802304_bsfirstp(f32, f32, f32);
    extern f32 D_8080A5D0_bsfirstp[][12];
    FirstpState *firstp;
    f32 bound;
    f32 scale[2];
    f32 limit[2];
    f32 speed[2];
    f32 blend;
    f32 dt;
    f32 *cursor;
    f32 *rotation;
    f32 target[2];
    f32 input[2];
    f32 *parameters;

    firstp = ((PlayerState *)player)->state_mem;
    blend = firstp->unkB4;
    cursor = &firstp->unkB8;
    dt = func_800D9004();
    switch (firstp->unkA0) {
    case 0:
        bound = 0;
        blend -= dt * 4.0f;
        if (blend < bound) {
            blend = bound;
        }
        break;
    case 1:
        bound = 1;
        blend += dt * 4.0f;
        if (blend >= bound) {
            blend = bound;
        }
        break;
    }
    parameters = D_8080A5D0_bsfirstp[preset];
    firstp->unkB4 = blend;
    scale[0] = parameters[0] + (parameters[6] - parameters[0]) * blend;
    scale[1] = parameters[1] + (parameters[7] - parameters[1]) * blend;
    limit[0] = parameters[2] + (parameters[8] - parameters[2]) * blend;
    limit[1] = parameters[3] + (parameters[9] - parameters[3]) * blend;
    speed[0] = parameters[4] + (parameters[10] - parameters[4]) * blend;
    speed[1] = parameters[5] + (parameters[11] - parameters[5]) * blend;
    if (firstp->unkA8 == 1) {
        input[0] = firstp->unk168;
        input[1] = firstp->unk184;
    } else {
        input[0] = 0.0f;
        input[1] = 0.0f;
    }
    target[0] = input[0] * scale[0] + 152.0f;
    target[1] = input[1] * scale[1] + 114.0f;
    cursor[0] = func_8080222C_bsfirstp(cursor[0], target[0], speed[0]);
    cursor[1] = func_8080222C_bsfirstp(cursor[1], target[1], speed[1]);
    _baeggcursor_entrypoint_10(player, cursor[0], cursor[1]);
    rotation = &firstp->unkC0;
    rotation[0] = func_80802304_bsfirstp(cursor[0] - 152.0f, scale[0], limit[0]);
    rotation[1] = func_80802304_bsfirstp(cursor[1] - 114.0f, scale[1], limit[1]);
}

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
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objfirstp_func_808023A0_bsfirstp_sp18; /* offsets.py genstruct: fields from raw offsets on sp18; rename once understood */ typedef struct { u8 pad0[0xC8]; f32 unkC8; f32 unkCC; } Objfirstp_func_808023A0_bsfirstp_sp34; /* offsets.py genstruct: fields from raw offsets on sp34; rename once understood */

void func_808023A0_bsfirstp(u8 *arg0) {
    f32 func_80013728(f32);
    f32 func_80013B7C(f32, f32);
    f32 func_800A8AF0(s32);
    void *volatile sp34;
    s32 pad[6];
    void *sp18;
    register f32 scale;
    f32 angle;

    sp34 = *(void **)(arg0 + 0x188);
    scale = func_800A8AF0(func_800A4C68(arg0));
    scale *= 0.75f;
    sp18 = (u8 *)sp34 + 0xB8;
    angle = 152.0f - *(f32 *)sp18;
    angle *= scale;
    ((Objfirstp_func_808023A0_bsfirstp_sp34 *)sp34)->unkCC = func_80013728(func_80013B7C(angle, 152.0f));
    ((Objfirstp_func_808023A0_bsfirstp_sp34 *)sp34)->unkC8 = func_80013728(func_80013B7C(114.0f - ((Objfirstp_func_808023A0_bsfirstp_sp18 *)sp18)->unk4, 114.0f));
}    typedef struct { u8 pad0[0xA0]; s32 unkA0; } Objfirstp_func_80802438_bsfirstp_target; /* offsets.py genstruct: fields from raw offsets on target; rename once understood */

void func_80802438_bsfirstp(void *arg0, s32 arg1) {
    register void *target;
    target = ((Objfirstp_arg0 *)arg0)->unk188;
    ((Objfirstp_func_80802438_bsfirstp_target *)target)->unkA0 = arg1;
}    typedef struct { u8 pad0[0xA0]; s32 unkA0; } Objfirstp_func_80802444_bsfirstp_target; /* offsets.py genstruct: fields from raw offsets on target; rename once understood */

s32 func_80802444_bsfirstp(void *arg0) {
    register void *target;
    target = ((PlayerState *)arg0)->state_mem;
    return (((Objfirstp_func_80802444_bsfirstp_target *)target)->unkA0) == 1;
}

void *func_80802458_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpEquipment D_8080ABF0_bsfirstp;
    return D_8080ABF0_bsfirstp.parameters[func_800A3280(arg0)];
}

FirstpConfig *func_80802484_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpConfig *D_8080A890_bsfirstp[];
    return D_8080A890_bsfirstp[func_800A3280(arg0)];
}

void *func_808024B0_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern f32 D_8080AFFC_bsfirstp[6][2];
    return &D_8080AFFC_bsfirstp[func_800A3280(arg0)];
}

BtIntPtr func_808024DC_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpAnimation *D_8080AFB4_bsfirstp[6];
    return (BtIntPtr)D_8080AFB4_bsfirstp[func_800A3280(arg0)];
}

void *func_80802508_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080AFCC_bsfirstp[6];
    return &D_8080AFCC_bsfirstp[func_800A3280(arg0)];
}

s16 func_80802534_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern s16 D_8080B02C_bsfirstp[];
    return D_8080B02C_bsfirstp[func_800A3280(arg0)];
}

void *func_80802560_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpAnimationScale D_8080B038_bsfirstp[6];
    return &D_8080B038_bsfirstp[func_800A3280(arg0)];
}

void *func_80802594_bsfirstp(void *arg0) {
    u32 func_800A3280(void *);
    extern FirstpAnimationScale D_8080B080_bsfirstp[6];
    return &D_8080B080_bsfirstp[func_800A3280(arg0)];
}

void func_808025C8_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B1B8_bsfirstp[5];
    extern FirstpAnimation D_8080B1E0_bsfirstp[5];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B1B8_bsfirstp + offset;
    *arg2 = (u8 *)D_8080B1E0_bsfirstp + offset;
}

void func_8080261C_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B208_bsfirstp[5];
    extern FirstpAnimation D_8080B230_bsfirstp[5];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B208_bsfirstp + offset;
    *arg2 = (u8 *)D_8080B230_bsfirstp + offset;
}

void func_80802670_bsfirstp(void *arg0, u8 **arg1) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B258_bsfirstp[5];
    s32 index;
    s32 offset;
    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B258_bsfirstp + offset;
}

void func_808026AC_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B0C8_bsfirstp[5];
    extern FirstpAnimation D_8080B0F0_bsfirstp[5];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B0C8_bsfirstp + offset;
    *arg2 = (u8 *)D_8080B0F0_bsfirstp + offset;
}

void func_80802700_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B118_bsfirstp[5];
    extern FirstpAnimation D_8080B140_bsfirstp[5];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B118_bsfirstp + offset;
    *arg2 = (u8 *)D_8080B140_bsfirstp + offset;
}

void func_80802754_bsfirstp(void *arg0, void **arg1, void **arg2) {
    u32 func_800A3280(void *);
    extern FirstpAnimation D_8080B168_bsfirstp[5];
    extern FirstpAnimation D_8080B190_bsfirstp[5];
    s32 index;
    s32 offset;

    index = func_800A3280(arg0) - 1;
    offset = index << 3;
    *arg1 = (u8 *)D_8080B168_bsfirstp + offset;
    *arg2 = (u8 *)D_8080B190_bsfirstp + offset;
}

u8 *func_808027A8_bsfirstp(s32 arg0) {
    extern FirstpEggConfig D_8080AC24_bsfirstp[7];
    return (u8 *)&D_8080AC24_bsfirstp[arg0 - 1];
}
typedef struct { u16 values[7]; } Entry;
u32 bsfirstp_entrypoint_3(s32 arg0, s32 arg1, s32 arg2) {

    extern Entry D_8080ACF8_bsfirstp[];
    extern Entry D_8080AD4C_bsfirstp[];
    extern Entry D_8080ADA0_bsfirstp[];
    Entry data;
    s32 part;
    s32 index;
    u32 result;
    if (arg1 == 0) {
        return 0;
    }
    part = arg2 & 3;
    switch (arg0) {
    case 0x165:
        data = D_8080AD4C_bsfirstp[arg1 - 1];
        break;
    case 0x164:
        data = D_8080ADA0_bsfirstp[arg1 - 1];
        break;
    case 0x166:
        data = D_8080ACF8_bsfirstp[arg1 - 1];
        break;
    }
    index = arg2 >> 2;
    switch (part) {
    case 0:
        result = (u32)data.values[index] >> 12;
        break;
    case 1:
        result = ((u8 *)data.values)[index * 2] & 0xF;
        break;
    case 2:
        result = (u32)((u8 *)data.values)[index * 2 + 1] >> 4;
        break;
    case 3:
        result = data.values[index] & 0xF;
        break;
    }
    return result;
}

void bsfirstp_entrypoint_4(BtIntPtr arg0, s32 arg1) {
    void _badeathmatch_entrypoint_10(void *arg0, s32 arg1, s32 arg2, s32 arg3);
    extern FirstpScores D_8080AC94_bsfirstp;
    s32 var_s0;
    u8 *var_s1;

    var_s0 = 1; var_s1 = (u8 *)D_8080AC94_bsfirstp.scores[arg1]; var_s1 += 2;
    do {
        _badeathmatch_entrypoint_10(arg0, var_s0, (*(u8 *)((s8 *)(var_s1) + (-2))), (*(u8 *)((s8 *)(var_s1) + (-1))));
        var_s0 += 1;
        var_s1 += 2;
    } while (var_s0 != 8);
}

void bsfirstp_entrypoint_5(u8 *arg0, s32 arg1, s32 arg2) {
    s32 pad[2];
    void func_800A18C8(void *arg0);
    void func_800A1870(PlayerState *arg0, s32 arg1);
    extern FirstpEquipment D_8080ABF0_bsfirstp;
    s32 sp1C[1];

    arg1 = D_8080ABF0_bsfirstp.equipment[(arg2 - 1) * 5 + (arg1 - 1)];
    sp1C[0] = arg1;
    func_800A18C8(arg0);
    arg1 = sp1C[0];
    func_800A1870(arg0, arg1);
}    typedef struct { s16 unk0; s16 unk2; s32 unk4; } Objfirstp_func_80802A40_bsfirstp_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

s32 func_80802A40_bsfirstp(u8 *arg0, s32 arg1) {
    u32 func_800A3280(void *arg0);

    s16 temp_a3;
    u8 *temp_v1;

    temp_v1 = (u8 *)D_8080B400_bsfirstp.sets[func_800A3280(arg0) - 1];
    temp_v1 += arg1 * 8;
    temp_a3 = (((Objfirstp_func_80802A40_bsfirstp_temp_v1 *)temp_v1)->unk2);
    if (temp_a3 == 0) {
        return 0;
    }
    func_8009DF18(arg0, (((Objfirstp_func_80802A40_bsfirstp_temp_v1 *)temp_v1)->unk0), (((Objfirstp_func_80802A40_bsfirstp_temp_v1 *)temp_v1)->unk4), temp_a3);
    return 1;
}                                                                                                  typedef struct { s16 unk0; s16 unk2; } Objfirstp_arg3; /* offsets.py genstruct: fields from raw offsets on arg3; rename once understood */ typedef struct { s16 unk0; s16 unk2; f32 unk4; } Objfirstp_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

void func_80802AA8_bsfirstp(u8 *arg0, s16 arg1, u8 *arg2, u8 *arg3) {
    u32 func_800A3280(void *arg0);
    extern s16 D_8080ADF4_bsfirstp[5][4][2];
    extern s32 D_8080AE44_bsfirstp[5][4][2];
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
    (((Objfirstp_arg2 *)arg2)->unk0) = (s16) (*(s32 *)((s8 *)(temp_a0) + (-0x20)));
    (((Objfirstp_arg2 *)arg2)->unk2) = (s16) (*(s16 *)((s8 *)(temp_a1) + (-0x10)));
    (((Objfirstp_arg3 *)arg3)->unk0) = (s16) (*(s32 *)((s8 *)(temp_a0) + (-0x1C)));
    (((Objfirstp_arg3 *)arg3)->unk2) = (s16) (*(s16 *)((s8 *)(temp_a1) + (-0xE)));
}    typedef struct { u8 pad0[0x14]; f32 unk14; f32 unk18; f32 unk1C; } Objfirstp_bsfirstp_entrypoint_6_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void bsfirstp_entrypoint_6(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 func_800D3948(void);
    void *temp_v0;

    temp_v0 = func_80802458_bsfirstp(arg0);
    *arg1 = (((Objfirstp_bsfirstp_entrypoint_6_temp_v0 *)temp_v0)->unk14);
    *arg3 = (((Objfirstp_bsfirstp_entrypoint_6_temp_v0 *)temp_v0)->unk18);
    *arg2 = (((Objfirstp_bsfirstp_entrypoint_6_temp_v0 *)temp_v0)->unk1C);
    if (func_800D3948() == 0) {
        *arg1 *= 0.67f;
    }
}    typedef struct { u8 pad0[0xC]; f32 unkC; f32 unk10; } Objfirstp_bsfirstp_entrypoint_7_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void bsfirstp_entrypoint_7(void *arg0, f32 *arg1, f32 *arg2) {
    void *temp_v0;

    temp_v0 = func_80802458_bsfirstp(arg0);
    *arg1 = (((Objfirstp_bsfirstp_entrypoint_7_temp_v0 *)temp_v0)->unkC);
    *arg2 = (((Objfirstp_bsfirstp_entrypoint_7_temp_v0 *)temp_v0)->unk10);
}

void func_80802BD8_bsfirstp(BtIntPtr arg0) 
{
}
void func_80802BE0_bsfirstp(BtIntPtr arg0) 
{
}
/* extern */

 s32 func_80802BE8_bsfirstp(BtIntPtr arg0, f32 arg1) {
    void _badeathmatch_entrypoint_8(void *arg0, f32 arg1);
    void func_80094430(PlayerState *arg0, f32 arg1);
    if ((((PlayerState *)arg0)->unk158) == 0) {
        func_80094430(arg0, arg1);
        return BT_NATIVE_ONLY(0);
    }
    _badeathmatch_entrypoint_8(arg0, arg1); BT_NATIVE_ONLY(return 0;)
}

/* extern */

s32 func_80802C30_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_6(BT_NATIVE_ONLY(void *));
    s32 func_80094510(BT_NATIVE_ONLY(PlayerState *));
    if (BT_DATA_FIELD(((PlayerState *)arg0)->unk158, ((Objfirstp_arg0 *)arg0)->unk158) == 0) {
        return func_80094510(BT_NATIVE_ONLY((PlayerState *)arg0));
    }
    return _badeathmatch_entrypoint_6(BT_NATIVE_ONLY(arg0));
}

void func_80802C6C_bsfirstp(BtIntPtr arg0)
{
    void func_800FC660(u32);
    func_800FC660(0xF);
}

/* extern */

s32 func_80802C90_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_6(BT_NATIVE_ONLY(void *));
    s32 _badeathmatch_entrypoint_9(void *, s32);
    s32 func_80094BC0(BT_NATIVE_ONLY(PlayerState *));
    if (BT_DATA_FIELD(((PlayerState *)arg0)->unk158, ((Objfirstp_arg0 *)arg0)->unk158) == 0) {
        return func_80094BC0(BT_NATIVE_ONLY((PlayerState *)arg0));
    }
    return _badeathmatch_entrypoint_9(arg0, _badeathmatch_entrypoint_6(BT_NATIVE_ONLY(arg0)));
}

/* extern */

void func_80802CD8_bsfirstp(void *arg0, s32 arg1) {
    BT_NATIVE_ONLY(void func_80094C0C(PlayerState *, s32);) BT_IDO_ONLY(s32 func_80094C0C();)
    s32 _badeathmatch_entrypoint_5(BtIntPtr, s32, s32);
    if (BT_DATA_FIELD(((PlayerState *)arg0)->unk158, ((Objfirstp_arg0 *)arg0)->unk158) == 0) {
        BT_NATIVE_ONLY(func_80094C0C((PlayerState *)arg0, arg1);) BT_IDO_ONLY(func_80094C0C();)
        return;
    }
    _badeathmatch_entrypoint_5(arg0, arg1, -1);
}

/* extern */

s32 func_80802D14_bsfirstp(void *arg0) {
    s32 _badeathmatch_entrypoint_0(BT_NATIVE_ONLY(u8 *));
    s32 func_80094A10(BT_NATIVE_ONLY(PlayerState *));
    if (BT_DATA_FIELD(((PlayerState *)arg0)->unk158, ((Objfirstp_arg0 *)arg0)->unk158) == 0) {
        return func_80094A10(BT_NATIVE_ONLY((PlayerState *)arg0));
    }
    return _badeathmatch_entrypoint_0(BT_NATIVE_ONLY((u8 *)arg0));
}

s32 func_80802D50_bsfirstp(BtIntPtr arg0, s32 *arg1) {
    s32 func_80802C90_bsfirstp(void *arg0);
    s32 func_80802D14_bsfirstp(void *arg0);
    s32 func_80802E7C_bsfirstp(u8 *arg0);
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    s32 active;

    if (func_80802C90_bsfirstp((void *)arg0)) {
        active = 1;
    } else {
        active = 0;
    }
    switch (firstp->unkE2) {
    case 0:
        return 0;
    case 1:
        if (!active) {
            firstp->unkE2 = 0;
            if (firstp->unkE6 == 0) {
                firstp->unkE6 = 1;
                func_80802C6C_bsfirstp(arg0);
            }
            return 0;
        }
        break;
    case 2:
        if (!active) {
            firstp->unkE2 = 0;
            switch (firstp->unkE6) {
            case 0:
                firstp->unkE6 = 1;
                func_80802C6C_bsfirstp(arg0);
                break;
            case 1:
                firstp->unkE8 = func_80802D14_bsfirstp((void *)arg0);
                func_80802E7C_bsfirstp(firstp);
                break;
            }
            return 0;
        }
        break;
    }
    switch (func_80802E7C_bsfirstp(firstp)) {
    case 0:
        *arg1 = 0xD8;
        break;
    case 1:
        *arg1 = 0xD6;
        break;
    }
    return 1;
}    typedef struct { s32 unk0; u8 pad4[0x4]; f32 unk8; f32 unkC; } Objfirstp_func_80802E7C_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_80802E7C_bsfirstp(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = func_808027A8_bsfirstp((((FirstpState *)arg0)->unkE8));
    (*(s16 *)((s8 *)(arg0) + (0xE4))) = (((FirstpState *)arg0)->unkE2);
    (((FirstpState *)arg0)->unkE0) = 2;
    (((FirstpState *)arg0)->unkE2) = 0;
    (((FirstpState *)arg0)->unkE6) = 0;
    (((FirstpState *)arg0)->unkD8) = (f32) (((Objfirstp_func_80802E7C_bsfirstp_temp_v0 *)temp_v0)->unk8);
    (((FirstpState *)arg0)->unkDC) = (f32) (((Objfirstp_func_80802E7C_bsfirstp_temp_v0 *)temp_v0)->unkC);
    return (((Objfirstp_func_80802E7C_bsfirstp_temp_v0 *)temp_v0)->unk0);
}

void func_80802ED4_bsfirstp(void *arg0) {
    void func_80803124_bsfirstp(void *arg0, s32 arg1);
    register FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    firstp->unkE0 = 4;
    func_80803124_bsfirstp(arg0, 0);
}

void func_80802F00_bsfirstp(void *arg0)
{
    func_80802ED4_bsfirstp(arg0);
}

s32 func_80802F20_bsfirstp(struct player_state_s *arg0) {
    int bakey_pressed(struct player_state_s *, int);
    int bakey_held(struct player_state_s *, s32);
    void func_808030E0_bsfirstp(void *, s32);
    void func_80803124_bsfirstp(void *, s32);
    register FirstpState *firstp = arg0->state_mem;
    f32 delta;

    do {
        if (!func_8009E674(arg0, 0x10000)) {
            if (firstp->unkE0 != 4) {
                func_80803124_bsfirstp(arg0, 4);
            }
            break;
        }
        if (firstp->unkE0 == 4) {
            func_80803124_bsfirstp(arg0, 0);
        }
        if (bakey_pressed(arg0, 1)) {
            firstp->unkD4 = 1;
        }
        if (bakey_held(arg0, 1)) {
            firstp->unkD6 = 1;
        } else {
            firstp->unkD6 = 0;
        }
        delta = func_800D9004();
        switch (firstp->unkE0) {
            case 0:
                if (firstp->unkD4) {
                    func_808030E0_bsfirstp(arg0, 2);
                } else if (firstp->unkD6) {
                    func_808030E0_bsfirstp(arg0, 1);
                }
                break;
            case 1:
                if (func_800F1574(&firstp->unkDC, delta)) {
                    firstp->unkE0 = 0;
                }
                if (firstp->unkD4) {
                    func_808030E0_bsfirstp(arg0, 2);
                }
                break;
            case 2:
                if (func_800F1574(&firstp->unkD8, delta)) {
                    firstp->unkE0 = 1;
                }
                if (func_800F1574(&firstp->unkDC, delta)) {
                    firstp->unkE0 = 0;
                }
                break;
            case 3:
                func_800F1574(&firstp->unkD8, delta);
                func_800F1574(&firstp->unkDC, delta);
                firstp->unkD4 = 0;
                break;
        }
    } while (0);
BT_NATIVE_ONLY(return 0;) }

void func_808030E0_bsfirstp(void *arg0, s32 arg1) {
    s32 func_80802C30_bsfirstp(void *);
    register FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    firstp->unkD4 = 0;
    if (firstp->unkE2 < arg1) {
        firstp->unkE2 = arg1;
        firstp->unkE8 = func_80802C30_bsfirstp(arg0);
    }
}

void func_80803124_bsfirstp(void *arg0, s32 arg1) {
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    (firstp->unkE0) = 0;
}    typedef struct { s16 unk0; u8 pad2[0x2]; f32 unk4; } Objfirstp_func_80803134_bsfirstp_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */ typedef struct { s16 unk0; u8 pad2[0x2]; f32 unk4; } Objfirstp_func_80803134_bsfirstp_sp28; /* offsets.py genstruct: fields from raw offsets on sp28; rename once understood */

void func_80803134_bsfirstp(void *arg0) {
    void _baeggsetup_entrypoint_7(u8 *arg0, s32 *arg1);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_800A0D94(void *, s32);
    void func_80800424_bsfirstp(struct player_state_s *, s32, f32);
    void func_8080261C_bsfirstp(void *, void **, void **);
    void func_80807BB8_bsfirstp(void *);
    void func_80808DB0_bsfirstp(void *);
#ifdef BT_NATIVE
    void bsfirstp_entrypoint_10(s32 arg0);
#else
    extern s32 _bsfirstp_entrypoint_10;
#endif
    FirstpState *firstp;
    void *sp28;
    void *sp24;

    firstp = ((PlayerState *)arg0)->state_mem;
    func_80807BB8_bsfirstp(arg0);
    func_80808DB0_bsfirstp(arg0);
    (((Objfirstp_arg0 *)arg0)->unk15C) = 0;
    func_8080261C_bsfirstp(arg0, &sp28, &sp24);
    func_80800424_bsfirstp(arg0, (((Objfirstp_func_80803134_bsfirstp_sp28 *)sp28)->unk0), (((Objfirstp_func_80803134_bsfirstp_sp28 *)sp28)->unk4));
    baanim_playForDuration_onceSmooth(arg0, (((Objfirstp_func_80803134_bsfirstp_sp24 *)sp24)->unk0), (((Objfirstp_func_80803134_bsfirstp_sp24 *)sp24)->unk4));
    _baeggsetup_entrypoint_7(arg0, &_bsfirstp_entrypoint_10);
    (firstp->unkE0) = 3;
    func_800A0D94(arg0, 1);
}

void func_80807C8C_bsfirstp();

void func_808031D0_bsfirstp(void *arg0) {
    void func_800A0D94(void *, s32);
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;

    firstp->unkE0 = 0;
    func_800A0D94(arg0, 0);
    func_80807C8C_bsfirstp(arg0);
}

void func_80803204_bsfirstp(void *arg0) {
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 bs_setState(void *, s32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void func_8080633C_bsfirstp(Actor *, f32);
    void func_80808E78_bsfirstp(BtIntPtr);

    func_80807D48_bsfirstp(arg0);
    func_80808E78_bsfirstp(arg0);
    func_8080633C_bsfirstp(arg0, 1.0f);
    switch (((Objfirstp_arg0 *)arg0)->unk15C) {
        case 0:
            if (anctrl_isAt(func_8008D04C(arg0), 0.6f)) {
                func_80803124_bsfirstp(arg0, 0);
                ((Objfirstp_arg0 *)arg0)->unk15C = 1;
            }
            break;
        case 1:
            if (func_80800228_bsfirstp(arg0)) {
                bs_setState(arg0, 0xCA);
            }
            break;
    }
}

BsScript bsfirstp_entrypoint_8(BsScriptType arg0) {
    extern BtFnWord D_8080B474_bsfirstp[4];
    return (BsScript)D_8080B474_bsfirstp[arg0];
}

void func_808032C0_bsfirstp(struct player_state_s *self) {
    void func_80807BB8_bsfirstp(void *);
    void func_80808DB0_bsfirstp(void *);
    void _baeggsetup_entrypoint_7(u8 *arg0, s32 *arg1);
#ifdef BT_NATIVE
    void bsfirstp_entrypoint_10(s32 arg0);
#else
    extern s32 _bsfirstp_entrypoint_10;
#endif
    u8 *sp24;

    func_80807BB8_bsfirstp(self);
    func_80808DB0_bsfirstp(self);
    func_80802670_bsfirstp(self, &sp24);
    func_80800424_bsfirstp(self, *(s16 *)sp24, *(f32 *)(sp24 + 4));
    _baeggsetup_entrypoint_7(self, &_bsfirstp_entrypoint_10);
}

void func_80803320_bsfirstp(BT_PARAM_OR_VOID(void *bt_a0))
{
    func_80807C8C_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}    typedef struct { s16 unk0; u8 pad2[0x2]; f32 unk4; } Objfirstp_func_80803340_bsfirstp_sp34; /* offsets.py genstruct: fields from raw offsets on sp34; rename once understood */
void func_80803340_bsfirstp(u8 *arg0) {
    void _baeggsetup_entrypoint_7(u8 *arg0, s32 *arg1);
    s32 bs_setState(void *, s32);
    s32 func_80800228_bsfirstp(struct player_state_s *arg0);
    void func_80800424_bsfirstp(struct player_state_s *self, s32 arg1, f32 arg2);
    void func_80802670_bsfirstp(void *arg0, u8 **arg1);
    s32 func_80802D50_bsfirstp(BtIntPtr arg0, s32 *arg1);
    void func_8080633C_bsfirstp(Actor *arg0, f32 arg1);
    void func_80807D48_bsfirstp(BtIntPtr arg0);
    void func_80808D80_bsfirstp(void *arg0);
    void func_80808E78_bsfirstp(BtIntPtr arg0);
    s32 func_808094F4_bsfirstp(BtIntPtr arg0);
    s32 func_80809540_bsfirstp(BtIntPtr arg0, s32 arg1);
    void func_80809684_bsfirstp(struct player_state_s *arg0, s32 arg1);
    void func_80809740_bsfirstp(struct player_state_s *arg0);
#ifdef BT_NATIVE
    void bsfirstp_entrypoint_10(s32 arg0);
#else
    extern s32 _bsfirstp_entrypoint_10;
#endif
    s32 sp3C;
    s32 sp38;
    void *sp34;
    FirstpState *firstp;
    s16 temp_v0;

    sp3C = 0;
    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80808E78_bsfirstp(arg0);
    func_8080633C_bsfirstp(arg0, 1.0f);
    if (func_80802D50_bsfirstp(arg0, &sp38) != 0) {
        func_80802670_bsfirstp(arg0, &sp34);
        func_80800424_bsfirstp(arg0, (((Objfirstp_func_80803340_bsfirstp_sp34 *)sp34)->unk0), (((Objfirstp_func_80803340_bsfirstp_sp34 *)sp34)->unk4));
        _baeggsetup_entrypoint_7(arg0, &_bsfirstp_entrypoint_10);
    }
    firstp = ((PlayerState *)arg0)->state_mem;
    temp_v0 = func_80809540_bsfirstp(arg0, (firstp->unk218));
    switch (temp_v0) {
    case 0:
        if ((firstp->unk218) != 0) {
            func_80808D80_bsfirstp(arg0);
            (firstp->unk218) = 0U;
        }
        break;
    case 1:
        if ((firstp->unk218) != 1) {
            func_80809684_bsfirstp(arg0, 1);
        }
        func_80809740_bsfirstp(arg0);
        break;
    case 2:
        if ((firstp->unk218) != 2) {
            func_80809684_bsfirstp(arg0, 2);
        }
        func_80809740_bsfirstp(arg0);
        break;
    }
    if (func_80800228_bsfirstp(arg0) != 0) {
        sp3C = func_808094F4_bsfirstp(arg0);
    }
    if (sp3C != 0) {
        bs_setState(arg0, sp3C);
    }
}

BsScript bsfirstp_entrypoint_9(BsScriptType arg0) {
    extern BtFnWord D_8080B484_bsfirstp[4];
    return (BsScript)D_8080B484_bsfirstp[arg0];
}

/* extern */

void bsfirstp_entrypoint_10(s32 arg0) {
    void _baeggcursor_entrypoint_8(void *arg0);
    s32 _baeggsetup_entrypoint_3(s32, s32, f32 *, f32 *, f32 *);
    void _bainvisible_entrypoint_7(Actor *, s32, f32, f32, f32);
    void func_8009E0AC(void *, s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF368(f32 *, f32);
    struct player_state_s *func_800F53D0(BtIntPtr);
    void func_808035EC_bsfirstp(void *, f32 *, f32 *);
    f32 yaw_get(struct player_state_s *);
    FirstpState *firstp;
    void *temp_v0;
    u8 *sp5C;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];

    temp_v0 = func_800F53D0(arg0);
    firstp = ((PlayerState *)temp_v0)->state_mem;
    sp5C = func_808027A8_bsfirstp(firstp->unkE8);
    func_808035EC_bsfirstp(temp_v0, sp50, sp38);
    func_800EF368(sp38, 90.0f);
    func_800EE780(sp44, sp50, sp38);
    func_800EF368(sp38, *(f32 *)(sp5C + 4));
    func_800EF1B8(sp38, yaw_get(temp_v0) - 90.0f, firstp->unk1D4 * 0.33f);
    func_8009E0AC(temp_v0, 0);
    func_80802A40_bsfirstp(temp_v0, firstp->unkE8);
    func_8009E0AC(temp_v0, 1);
    _baeggcursor_entrypoint_8(temp_v0);
    _bainvisible_entrypoint_7(temp_v0, 3, 1.0f, 1.0f, 0.25f);
    _baeggsetup_entrypoint_3(arg0, firstp->unkE8, sp50, sp44, sp38);
    func_80802CD8_bsfirstp(temp_v0, firstp->unkE8);
}

void func_808035EC_bsfirstp(void *arg0, f32 *arg1, f32 *arg2) {
    void _baeggcursor_entrypoint_3(void *, f32 *, f32 *);
    void func_8009C15C(u8 *, f32 *);
    int func_800A4C68(void *);
    void func_800A4CE8(struct player_state_s *, f32 *);
    void func_800C4E58(s32, f32 *, f32 *);
    void func_800C5008(s32, f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    FirstpConfig *func_80802484_bsfirstp(void *);
    f32 sp5C;
    f32 sp58;
    f32 sp50[2];
    f32 sp44[3];
    f32 sp38[3];
    FirstpConfig *sp34;

    sp34 = func_80802484_bsfirstp(arg0);
    _baeggcursor_entrypoint_3(arg0, &sp58, &sp5C);
    func_800C5008(func_800A4C68(arg0), &sp58, sp50);
    func_800EFA4C(sp38, sp50[0], sp50[1], 100.0f);
    func_800C4E58(func_800A4C68(arg0), sp38, sp44);
    func_800A4CE8(arg0, arg1);
    func_800EFB24(arg2, sp44, arg1);
    func_8009C15C(arg0, arg1);
    arg2[1] += (*(f32 *)((u8 *)sp34 + 0x48) * 2.5f) / func_800EEF94(arg2);
    arg1[1] += *(f32 *)((u8 *)sp34 + 0x48);
    func_800EF368(arg2, 1.0f);
}

void func_808036F0_bsfirstp(struct player_state_s *arg0) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void func_800A38F0(struct player_state_s *, s32, s32);
    void func_80807BB8_bsfirstp(void *);
#ifdef BT_NATIVE
    void bsfirstp_entrypoint_12(s32 arg0);
#else
    extern s32 _bsfirstp_entrypoint_12;
#endif
    func_80807BB8_bsfirstp(arg0);
    func_800A38F0(arg0, 0, 1);
    func_808061AC_bsfirstp(arg0, 0);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(arg0), 3);
    func_808001FC_bsfirstp(arg0);
    _chbaddiesetup_entrypoint_1(&_bsfirstp_entrypoint_12, arg0->unk184);
}

void func_80803760_bsfirstp(BtIntPtr arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    _batimer_set(arg0, 0, 5.0f);
}

void func_80803784_bsfirstp(u8 *arg0) {
    void func_800A38F0(struct player_state_s *, s32, s32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    FirstpState *firstp;
    s32 temp_a3;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_a3 = firstp->unk114;
    if (temp_a3 != 0) {
        func_8010114C(temp_a3, 4, ((Objfirstp_arg0 *)arg0)->unk184);
        firstp->unk114 = 0;
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

void func_80803828_bsfirstp(BtIntPtr arg0) {
    void bsfirstp_entrypoint_26(BtIntPtr);
    s32 func_8009E6EC();
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    if (func_8009E6EC(arg0) == 0xF) {
        if ((firstp->unk114) != 0) {
            (firstp->unk114) = 0;
        }
    } else {
        bsfirstp_entrypoint_26(arg0);
    }
}

BsScript bsfirstp_entrypoint_11(BsScriptType arg0) {
    extern BtFnWord D_8080B494_bsfirstp[4];
    return (BsScript)D_8080B494_bsfirstp[arg0];
}

void bsfirstp_entrypoint_12(s32 arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 _ch1pfreeze_entrypoint_1(s32);
    s32 bs_getCurrentState(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32[3]);
    struct player_state_s *func_800F53D0(BtIntPtr);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s16 D_8080B4A4_bsfirstp[4];
    struct player_state_s *sp2C;
    FirstpState *firstp;
    f32 sp1C[3];

    sp2C = func_800F53D0(arg0);
    if (bs_getCurrentState(sp2C) == 0xD9) {
        firstp = ((PlayerState *)sp2C)->state_mem;
        firstp->unk114 = _ch1pfreeze_entrypoint_1(arg0);
        func_8009C128(sp2C, sp1C);
        func_8010D930(7, -1, sp1C, (s32 *)D_8080B4A4_bsfirstp);
        _batimer_set(sp2C, 0, 5.0f);
    }
}

void bsfirstp_entrypoint_13(struct player_state_s *arg0, f32 *arg1, s16 arg2) {
    int baflag_isTrue(struct player_state_s *, s32);
    f32 func_8009BFCC(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_80803B68_bsfirstp(void *);
    f32 yaw_get(struct player_state_s *);
    extern f32 D_8080B4AC_bsfirstp[];
    extern f32 D_8080B4B8_bsfirstp[];
    extern f32 D_8080B4C4_bsfirstp[];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    if (baflag_isTrue(arg0, 0x3B)) {
        switch (arg2) {
            case 1: arg2 = 3; break;
            case 3: arg2 = 1; break;
        }
    }
    if (func_8009E674(arg0, 0x20)) {
        arg2 = 2;
    }
    switch (arg2) {
        case 1:
            func_800EE7F8(arg1, D_8080B4AC_bsfirstp);
            break;
        case 2:
            func_800EE7F8(arg1, D_8080B4B8_bsfirstp);
            break;
        case 3:
            func_800EE780(sp30, D_8080B4AC_bsfirstp, D_8080B4B8_bsfirstp);
            func_800EF334(sp30, 0.5f);
            func_800EFB24(sp24, D_8080B4C4_bsfirstp, sp30);
            func_800EF334(sp24, func_80803B68_bsfirstp(arg0));
            func_800EE780(arg1, sp30, sp24);
            break;
    }
    func_8009C128(arg0, sp3C);
    func_800EF8BC(arg1, arg1, func_8009BFCC(arg0));
    func_800EF934(arg1, arg1, yaw_get(arg0));
    func_800EF04C(arg1, sp3C);
}

void func_80803A84_bsfirstp(void *arg0) {
    void func_80803B58_bsfirstp(void *, f32);
#ifndef BT_NATIVE
    extern s32 _bsfirstp_entrypoint_13;
#endif
    s32 var_s0;
    register s32 *callback;
    register void *self;

    callback = &_bsfirstp_entrypoint_13;
    self = arg0;
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        func_8009E4E0(self, var_s0, (BtIntPtr)callback);
    }
    func_8009E4E0(self, 2, 0);
    func_80803B58_bsfirstp(self, 0.0f);
}

/* extern */

void func_80803B04_bsfirstp(BtIntPtr arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_8009E4E0(arg0, var_s0, 0);
        var_s0 += 1;
    } while (var_s0 != 3);
}    typedef struct { u8 pad0[0x110]; f32 unk110; } Objfirstp_func_80803B58_bsfirstp_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

void func_80803B58_bsfirstp(void *arg0, f32 arg1) {
    register void *ptr;
    ptr = ((PlayerState *)arg0)->state_mem;
    ((Objfirstp_func_80803B58_bsfirstp_ptr *)ptr)->unk110 = arg1;
}    typedef struct { u8 pad0[0x110]; f32 unk110; } Objfirstp_func_80803B68_bsfirstp_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

f32 func_80803B68_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = ((PlayerState *)arg0)->state_mem;
    return *&((Objfirstp_func_80803B68_bsfirstp_ptr *)ptr)->unk110;
}

void bsfirstp_entrypoint_14(register struct player_state_s *self) {
    typedef struct player_state_s PlayerState;
    void func_8009E154(PlayerState *, BtIntPtr, f32 *);
    f32 func_8009E138(PlayerState *, s32);
    PlayerState *func_800F53E4(s32);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F5898(void);
    int func_800F7C58(BtIntPtr, s32, s32);
    f32 sp58;
    f32 sp54;
    f32 sp84[3];
    f32 sp80;
    f32 sp7C;
    f32 sp70[3];
    f32 sp6C;
    f32 sp68;
    f32 sp5C[3];
    register s32 i;
    register s32 owner;

    owner = self->unk184;
    func_8009E154(self, 0, sp84);
    sp80 = func_8009E138(self, 0);
    for (i = 0; i < func_800F5898(); i++) {
        if (i == owner) {
            continue;
        }
        self = func_800F53E4(i);
        if (self == NULL) {
            continue;
        }
        sp7C = sp80 * sp80;
        func_8009E154(self, 2, sp70);
        func_8009E154(self, 1, sp5C);
        sp6C = func_8009E138(self, 2);
        sp58 = func_8009E138(self, 1);
        sp54 = sp58 * sp58 + sp7C;
        sp68 = func_800EEB40(sp84, sp70);
        if (sp68 < sp6C * sp6C + sp7C || func_800EEB40(sp84, sp5C) < sp54) {
            func_800F7C58(i, 0x6D, owner);
        }
    }
}

s32 func_80803CD4_bsfirstp(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4) {
    void _bamotor_entrypoint_0(void *, f32, f32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_14(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_15(void);
    s32 _gcstatusDll_entrypoint_20(void);
    s32 bs_getCurrentState(struct player_state_s *);
    s32 func_8009BD44(void *);
    s32 func_8009CA70(void *, s32, s32);
    s32 func_800A1718(void *);
    void func_800A17A8(void *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    FirstpState *firstp;
    s32 emitEvent;
    s32 pad; /* Preserve the original IDO spill layout. */
    s32 result;

    firstp = ((PlayerState *)arg0)->state_mem;
    if (func_8009CA70(arg0, bs_getCurrentState(arg0), 4) != 0) {
        return 0;
    }
    if (func_8009BD44(arg0) == 3) {
        return 0;
    }
    if (_gcstatusDll_entrypoint_20() == 1) {
        if (_gcstatusDll_entrypoint_14() == 5) {
            if (_gcstatusDll_entrypoint_15() == (((Objfirstp_arg0 *)arg0)->unk184)) {
                arg3 = 0;
                emitEvent = 1;
                result = 1;
            } else if (arg3 != 0) {
                emitEvent = 1;
                result = 2;
            } else {
                emitEvent = 0;
                result = 1;
            }
        } else {
            arg3 = 0;
            emitEvent = 1;
            result = 1;
        }
    } else {
        func_800A17A8(arg0, -arg3);
        if (func_800A1718(arg0) != 0) {
            emitEvent = 0;
            result = 1;
        } else {
            emitEvent = 1;
            result = 2;
        }
    }
    if (emitEvent != 0) {
        func_80101180(0x2C4, 0x70, ((((Objfirstp_arg0 *)arg0)->unk184) * 0x10) | arg2);
    }
    _bamotor_entrypoint_0(arg0, func_800F10B4((f32) arg3, 0, 8.0f, 0.8f, 1.4f), 0.25f);
    (firstp->unkEC) = arg1;
    (firstp->unkF0) = arg2;
    (firstp->unkF4) = arg3;
    func_800EE7F8(&firstp->unkF8, arg4);
    return result;
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objfirstp_func_80803E84_bsfirstp_sp2C; /* offsets.py genstruct: fields from raw offsets on sp2C; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Objfirstp_func_80803E84_bsfirstp_sp28; /* offsets.py genstruct: fields from raw offsets on sp28; rename once understood */

void func_80803E84_bsfirstp(struct player_state_s *arg0) {
    void _bainvisible_entrypoint_7(Actor *, s32, f32, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_8009BDAC(struct player_state_s *, f32);
    void func_8009D89C(struct player_state_s *, f32);
    void func_80807BB8_bsfirstp(void *);
    void func_80808F38_bsfirstp(struct player_state_s *);
    FirstpState *firstp;
    struct anctrl_s *sp30;
    void *sp2C;
    void *sp28;

    firstp = arg0->state_mem;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_80807BB8_bsfirstp(arg0);
    func_808026AC_bsfirstp(arg0, &sp2C, &sp28);
    func_80800424_bsfirstp(arg0, *(s16 *)sp2C, ((Objfirstp_func_80803E84_bsfirstp_sp2C *)sp2C)->unk4);
    baanim_playForDuration_onceSmooth(arg0, *(s16 *)sp28, ((Objfirstp_func_80803E84_bsfirstp_sp28 *)sp28)->unk4);
    anctrl_setSubrange(sp30, 0.0f, 0.43f);
    if (func_80802A40_bsfirstp((u8 *)arg0, 0xA) == 0) {
        func_8009D89C(arg0, 1.0f);
    }
    _bainvisible_entrypoint_7(arg0, 3, 1.0, 1.0, 0.5f);
    func_80808F38_bsfirstp(arg0);
    firstp->unk4 = 0;
    func_8009BDAC(arg0, 1.25f);
}

void func_808090D8_bsfirstp(BT_NATIVE_ONLY(void *));

void func_80803F6C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp((void *)arg0);
    func_80807C8C_bsfirstp(arg0);
}
void func_80803F94_bsfirstp(struct player_state_s *arg0) {
    s32 func_80802F20_bsfirstp(struct player_state_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int baanim_isStopped(struct player_state_s *);
    s32 bs_setState(void *, s32);
    int func_8008DF8C(struct player_state_s *, s32);
    s32 func_800F7F98(BtIntPtr, u32);
    void func_80804848_bsfirstp(u8 *, s32);
    void func_8080682C_bsfirstp(void *);
    void func_80808EF0_bsfirstp(BtIntPtr);
    s32 func_808094F4_bsfirstp(BtIntPtr);
    void func_808099B4_bsfirstp(void *);
    void func_80809D24_bsfirstp(void *);
    int player_isStable(struct player_state_s *);
    FirstpState *firstp;
    s32 sp28;
    struct anctrl_s *sp24;

    firstp = arg0->state_mem;
    sp28 = 0;
    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80804848_bsfirstp((u8 *)arg0, firstp->unkC);
    func_80801928_bsfirstp(arg0);
    func_80801DC0_bsfirstp((u8 *)arg0);
    func_80808EF0_bsfirstp((BtIntPtr)arg0);
    func_80802F20_bsfirstp(arg0);
    func_80809198_bsfirstp(arg0);
    switch (firstp->unk4) {
        case 0:
            if (func_8008DF8C(arg0, 0x5A)) {
                sp24 = baanim_getAnimCtrlPtr(arg0);
                anctrl_setSubrange(sp24, 0.0f, 1.0f);
                anctrl_setPlaybackType(sp24, 1);
                firstp->unk4 = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                firstp->unk4 = 2;
                func_800F7F98(arg0->unk184, 0);
            }
            break;
        case 2:
            func_80809D24_bsfirstp(arg0);
            func_8080682C_bsfirstp(arg0);
            func_808099B4_bsfirstp(arg0);
            sp28 = func_808094F4_bsfirstp((BtIntPtr)arg0);
            if (sp28 == 0xCA && !baanim_isStopped(arg0)) {
                sp28 = 0;
            }
            break;
    }
    bs_setState(arg0, sp28);
}

BsScript bsfirstp_entrypoint_15(BsScriptType arg0) {
    extern BtFnWord D_8080B4D0_bsfirstp[4];
    return (BsScript)D_8080B4D0_bsfirstp[arg0];
}                                                                                                  typedef struct { u8 pad0[0x4]; f32 unk4; u8 pad8[0x17C]; s32 unk184; s32 * unk188; } Objfirstp_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_80804104_bsfirstp(struct player_state_s *arg0, void *arg1, void *arg2) {
    void _bainvisible_entrypoint_3(struct player_state_s *);
    void _basudie_entrypoint_1(struct player_state_s *);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009D89C(struct player_state_s *, f32);
    s32 func_800D3948(void);
    s32 func_800EA068(s32);
    void func_800F7E64(s32, s32);
    void func_800FC660(u32);
    void func_80808F38_bsfirstp(struct player_state_s *);
    s16 temp_a3;

    temp_a3 = *(s16 *)arg1;
    if (temp_a3 != 0) {
        func_80800424_bsfirstp(arg0, temp_a3, ((Objfirstp_arg1 *)arg1)->unk4);
    }
    baanim_playForDuration_onceSmooth(arg0, *(s16 *)arg2, ((Objfirstp_arg2 *)arg2)->unk4);
    func_800FC660(0xB);
    if (func_80802A40_bsfirstp((u8 *)arg0, 0xB) == 0) {
        func_8009D89C(arg0, 1.0f);
    }
    _bainvisible_entrypoint_3(arg0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    arg0->unk15C.word = 0;
    func_80808F38_bsfirstp(arg0);
    if (func_800D3948() == 0) {
        _basudie_entrypoint_1(arg0);
    }
    if (func_800EA068(8) == 0) {
        func_800F7E64(arg0->unk184, 1);
    }
}

/* extern */

void func_808041D0_bsfirstp(BtIntPtr arg0) {
    void func_80802700_bsfirstp(void *, void **, void **);
    void func_80804104_bsfirstp(struct player_state_s *, void *, void *);
    void func_80807BB8_bsfirstp(void *);
    BtIntPtr sp1C;
    BtIntPtr sp18;

    func_80807BB8_bsfirstp(arg0);
    func_80802700_bsfirstp(arg0, &sp1C, &sp18);
    func_80804104_bsfirstp(arg0, sp1C, sp18);
}

void func_80804210_bsfirstp(BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(s32) arg0)
{
    func_808090D8_bsfirstp(BT_NATIVE_ONLY((void *)arg0));
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
    s32 func_80101180(s32, s32, BtIntPtr);

    switch (arg0->unk15C.word) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0))) {
            _batimer_set(arg0, 0, 3.0f);
            func_800A38F0(arg0, 0, 1);
            arg0->unk15C.word = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(arg0, 0)) {
            if (func_800D3948()) {
                func_80101180(0x2C4, 0x71, arg0->unk184);
            } else {
                _basudie_entrypoint_0(arg0);
            }
            arg0->unk15C.word = 2;
        }
        break;
    }
    func_80809198_bsfirstp(arg0);
    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80809250_bsfirstp(arg0);
}

BsScript bsfirstp_entrypoint_16(BsScriptType arg0) {
    extern BtFnWord D_8080B4E0_bsfirstp[4];
    return (BsScript)D_8080B4E0_bsfirstp[arg0];
}

/* extern */

void func_8080432C_bsfirstp(BtIntPtr arg0) {
    void func_80802754_bsfirstp(void *, void **, void **);
    void func_80804104_bsfirstp(struct player_state_s *, void *, void *);
    void func_80807BB8_bsfirstp(void *);
    BtIntPtr sp1C;
    BtIntPtr sp18;

    func_80807BB8_bsfirstp(arg0);
    func_80802754_bsfirstp(arg0, &sp1C, &sp18);
    func_80804104_bsfirstp(arg0, sp1C, sp18);
}

void func_8080436C_bsfirstp(BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(s32) arg0)
{
    func_808090D8_bsfirstp(BT_NATIVE_ONLY((void *)arg0));
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
    s32 func_80101180(s32, s32, BtIntPtr);

    switch (arg0->unk15C.word) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0))) {
            _batimer_set(arg0, 0, 3.0f);
            func_800A38F0(arg0, 0, 1);
            arg0->unk15C.word = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(arg0, 0)) {
            if (func_800D3948()) {
                func_80101180(0x2C4, 0x71, arg0->unk184);
            } else {
                _basudie_entrypoint_0(arg0);
            }
            arg0->unk15C.word = 2;
        }
        break;
    }
    func_80809198_bsfirstp(arg0);
    func_80809250_bsfirstp((BtIntPtr)arg0);
    func_80807D48_bsfirstp(arg0);
}

BsScript bsfirstp_entrypoint_17(BsScriptType arg0) {
    extern BtFnWord D_8080B4F0_bsfirstp[4];
    return (BsScript)D_8080B4F0_bsfirstp[arg0];
}

void func_80804488_bsfirstp(struct player_state_s *arg0, s32 arg1, s32 arg2, f32 *arg3) {
    int bakey_held(struct player_state_s *, s32);
    f32 mlAbsF(f32);
    s32 buttons;
    f32 target;
    f32 step;

    buttons = bakey_held(arg0, arg1) ? 1 : 0;
    buttons += bakey_held(arg0, arg2) ? 2 : 0;
    switch (buttons) {
    case 0:
    case 3:
        target = 0.0f;
        break;
    case 1:
        target = -1.0f;
        break;
    case 2:
        target = 1.0f;
        break;
    }
    if (target == -arg3[1]) {
        step = 0.667f;
    } else if (target == 0.0f) {
        step = 0.5f;
    } else {
        step = 0.333f;
    }
    if (mlAbsF(target - arg3[0]) < step) {
        arg3[0] = target;
        arg3[1] = target;
    } else if (arg3[0] < target) {
        arg3[0] += step;
    } else {
        arg3[0] -= step;
    }
}

void func_808045FC_bsfirstp(u8 *arg0, f32 arg1) {
    f32 func_800F2108(f32);
    f32 temp_f0;
    f32 temp_f2;
    f32 square;
    s32 temp_v0;

    temp_v0 = (((Objfirstp_arg0 *)arg0)->unkC);
    switch (temp_v0) {
    case -1:
        if (arg1 < (((Objfirstp_arg0 *)arg0)->unk0)) {
            (((Objfirstp_arg0 *)arg0)->unk14) = arg1;
        }
        if ((arg1 == (((Objfirstp_arg0 *)arg0)->unk0)) && (arg1 == 0.0f)) {
            (((Objfirstp_arg0 *)arg0)->unkC) = 0;
        }
        if (((((Objfirstp_arg0 *)arg0)->unk0) < arg1) && ((((Objfirstp_arg0 *)arg0)->unk10) < arg1)) {
            (((Objfirstp_arg0 *)arg0)->unk18) = arg1;
            (((Objfirstp_arg0 *)arg0)->unkC) = 1;
        }
        break;
    case 0:
        if (arg1 < 0.0f) {
            (((Objfirstp_arg0 *)arg0)->unkC) = -1;
            (((Objfirstp_arg0 *)arg0)->unk14) = arg1;
            (((Objfirstp_arg0 *)arg0)->unk18) = 0.0f;
        } else if (arg1 > 0.0f) {
            (((Objfirstp_arg0 *)arg0)->unkC) = 1;
            (((Objfirstp_arg0 *)arg0)->unk14) = 0.0f;
            (((Objfirstp_arg0 *)arg0)->unk18) = arg1;
        }
        break;
    case 1:
        if ((((Objfirstp_arg0 *)arg0)->unk0) < arg1) {
            (((Objfirstp_arg0 *)arg0)->unk18) = arg1;
        }
        if ((arg1 == (((Objfirstp_arg0 *)arg0)->unk0)) && (arg1 == 0.0f)) {
            (((Objfirstp_arg0 *)arg0)->unkC) = 0;
        }
        if ((arg1 < (((Objfirstp_arg0 *)arg0)->unk0)) && (arg1 < (((Objfirstp_arg0 *)arg0)->unk10))) {
            (((Objfirstp_arg0 *)arg0)->unk14) = arg1;
            (((Objfirstp_arg0 *)arg0)->unkC) = -1;
        }
        break;
    }
    (((Objfirstp_arg0 *)arg0)->unk10) = (((Objfirstp_arg0 *)arg0)->unk0);
    (((Objfirstp_arg0 *)arg0)->unk0) = arg1;
    (((Objfirstp_arg0 *)arg0)->unk8) = (f32) ((((Objfirstp_arg0 *)arg0)->unk18) - (((Objfirstp_arg0 *)arg0)->unk14));
    temp_f0 = func_800F2108(arg1);
    temp_f2 = (arg1 * temp_f0) + 1.0f;
    square = temp_f2 * temp_f2;
    (((Objfirstp_arg0 *)arg0)->unk4) = (f32) (((temp_f2 * square) - 1.0f) * (temp_f0 / 7.0f));
}    typedef struct { u8 pad0[0xC]; s32 unkC; } Objfirstp_func_808047EC_bsfirstp_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_808047EC_bsfirstp(u8 *arg0) {
    void func_80804848_bsfirstp(u8 *, s32);
    u8 *sp1C;

    sp1C = (((Objfirstp_arg0 *)arg0)->unk188_u8p);
    bzero(sp1C + 0x12C, 0x38);
    bzero(sp1C + 0x164, 0x38);
    func_80804848_bsfirstp(arg0, (((Objfirstp_func_808047EC_bsfirstp_sp1C *)sp1C)->unkC));
}    typedef struct { u8 pad0[0x118]; s32 unk118; } Objfirstp_func_8080483C_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8080483C_bsfirstp(void *arg0, s32 arg1) {
    register void *temp_v0 = ((Objfirstp_arg0 *)arg0)->unk188;
    ((Objfirstp_func_8080483C_bsfirstp_temp_v0 *)temp_v0)->unk118 = arg1;
}    typedef struct { u8 pad0[0x118]; s32 unk118; f32 unk11C; u8 pad120[0x4]; f32 unk124; } Objfirstp_func_80804848_bsfirstp_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

void func_80804848_bsfirstp(u8 *arg0, s32 arg1) {
    f32 bastick_getX(struct player_state_s *);
    f32 bastick_getY(struct player_state_s *);
    void func_80804488_bsfirstp(struct player_state_s *arg0, s32 arg1, s32 arg2, f32 *arg3);
    void func_808045FC_bsfirstp(u8 *, f32);
    u8 *temp_s0;
    f32 var_f2;
    f32 sp24;
    f32 var_f0;

    temp_s0 = (((PlayerState *)arg0)->state_mem);
    func_80804488_bsfirstp((struct player_state_s *)arg0, 0xA, 0xD, (f32 *)(temp_s0 + 0x11C));
    func_80804488_bsfirstp(arg0, 0xB, 0xC, temp_s0 + 0x124);
    switch (arg1) {
    case -1:
        func_808045FC_bsfirstp(temp_s0 + 0x12C, 0.0f);
        func_808045FC_bsfirstp(temp_s0 + 0x148, 0.0f);
        func_808045FC_bsfirstp(temp_s0 + 0x164, 0.0f);
        func_808045FC_bsfirstp(temp_s0 + 0x180, 0.0f);
        return;
    case 0:
        if ((((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk118) != 0) {
            var_f2 = 0.0f;
        } else {
            var_f2 = bastick_getY(arg0);
        }
        if ((((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk118) != 0) {
            sp24 = bastick_getY(arg0);
        } else {
            sp24 = (((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk124);
        }
        func_808045FC_bsfirstp(temp_s0 + 0x12C, (((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk11C));
        func_808045FC_bsfirstp(temp_s0 + 0x148, var_f2);
        func_808045FC_bsfirstp(temp_s0 + 0x164, bastick_getX(arg0));
        func_808045FC_bsfirstp(temp_s0 + 0x180, sp24);
        return;
    case 1:
        if ((((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk118) != 0) {
            var_f0 = 0.0f;
        } else {
            var_f0 = (((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk124);
        }
        func_808045FC_bsfirstp(temp_s0 + 0x12C, (((Objfirstp_func_80804848_bsfirstp_temp_s0 *)temp_s0)->unk11C));
        func_808045FC_bsfirstp(temp_s0 + 0x148, var_f0);
        func_808045FC_bsfirstp(temp_s0 + 0x164, bastick_getX(arg0));
        func_808045FC_bsfirstp(temp_s0 + 0x180, bastick_getY(arg0));
        return;
    }
}    typedef struct { u8 pad0[0x15C]; s32 unk15C; } Objfirstp_bsfirstp_entrypoint_18_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void bsfirstp_entrypoint_18(s32 arg0, s32 arg1) {
    s32 bs_setState(void *, s32);
    struct player_state_s *func_800F53D0(BtIntPtr);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_800F53D0(arg1);
    sp1C = temp_v0;
    bs_setState(temp_v0, 0xC8);
    (((Objfirstp_bsfirstp_entrypoint_18_sp1C *)sp1C)->unk15C) = 1;
}

void func_80804A34_bsfirstp(s32 arg0) 
{
}
/* extern */

void func_80804A3C_bsfirstp(void *arg0) {
    s32 func_80101238(s32, s32, void *);
    func_80101238(0x77, (((PlayerState *)arg0)->unk184), arg0);
}

void func_80804A64_bsfirstp(BtIntPtr arg0) {
    s32 func_8009E6EC();
    s32 bs_getCurrentState(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    u32 func_800A3404(void *);
    void func_80807EEC_bsfirstp(BtIntPtr);
    void bsfirstp_entrypoint_26(BtIntPtr);
    s32 sp24;

    sp24 = 1;
    if (func_8009E6EC(arg0) == 0x62) {
        if (func_800A3404(arg0) == 0) {
            func_80807EEC_bsfirstp(arg0);
            if (bs_getCurrentState(arg0) == 0xC8) {
                func_80800888_bsfirstp(arg0, 1);
            } else {
                func_80800888_bsfirstp(arg0, 0);
            }
            sp24 = 2;
        }
    } else {
        bsfirstp_entrypoint_26(arg0);
        return;
    }
    func_8009E830(arg0, sp24);
}

void func_80804B10_bsfirstp(struct player_state_s *arg0) {
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_800936E8(void *, s32);
    void func_800A3410(struct player_state_s *, s32);
    void func_80807BB8_bsfirstp(void *);
    void func_80807DD4_bsfirstp(BtIntPtr);

    func_80807BB8_bsfirstp(arg0);
    func_800A3410(arg0, 9);
    func_80807DD4_bsfirstp(arg0);
    func_800936E8(arg0, 0);
    baanim_playForDuration_onceSmooth(arg0, 0x30C, 2.0f);
    func_808003B4_bsfirstp(arg0, 0x310, 2.0f);
    func_80804A34_bsfirstp(1);
    (arg0->unk15C.word) = 0;
}

void func_80804B84_bsfirstp(BT_PARAM_OR_VOID(void *bt_a0))
{
    func_80807C8C_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}
void func_80804BA4_bsfirstp(struct player_state_s *arg0) {
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    s32 bs_setState(void *, s32);
    void func_800936E8(void *, s32);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_8009DE38(struct player_state_s *, s32, f32);
    u32 func_800A3404(void *);
    void func_80809D24_bsfirstp(void *);

    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80809D24_bsfirstp(arg0);
    if (func_800A3404(arg0) == 0) {
        if (baanim_isAt(arg0, 0.1081f)) {
            func_800936E8(arg0, 1);
        }
        if (baanim_isAt(arg0, 0.25f)) {
            func_8009DE38(arg0, 0x442E, 1.117f);
        }
        if ((arg0->unk15C.word == 0) && baanim_isAt(arg0, 0.4f)) {
            func_80801A34_bsfirstp((BtIntPtr)arg0);
        }
        if (baanim_isAt(arg0, 0.5f)) {
            func_8009DB04(arg0, 0x4639, 1.0f, 0x4E20);
        }
        if (baanim_isAt(arg0, 0.61f)) {
            func_8009DB04(arg0, 0x463A, 1.0f, 0x4E20);
        }
        if (arg0->unk15C.word == 1) {
            if (baanim_isStopped(arg0)) {
                func_80804A3C_bsfirstp(arg0);
                arg0->unk15C.word = 2;
            }
            func_80801928_bsfirstp(arg0);
        }
    } else {
        func_80801928_bsfirstp(arg0);
        if (func_808008B0_bsfirstp((u8 *)arg0) == 0) {
            bs_setState(arg0, 0xCA);
            func_80804A3C_bsfirstp(arg0);
        }
    }
}

BsScript bsfirstp_entrypoint_19(BsScriptType arg0) {
    extern BtFnWord D_8080B500_bsfirstp[4];
    return (BsScript)D_8080B500_bsfirstp[arg0];
}

/* extern */

void func_80804D18_bsfirstp(struct player_state_s *arg0) {
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_80807BB8_bsfirstp(void *);
    void func_80807DD4_bsfirstp(BtIntPtr);
    void func_808002CC_bsfirstp(struct player_state_s *, s32, f32, f32);
    func_80807BB8_bsfirstp(arg0);
    func_80807DD4_bsfirstp(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
    func_808002CC_bsfirstp(arg0, 0x311, 2.0f, 0.5036f);
    func_80801A34_bsfirstp(arg0);
}

void func_80804D80_bsfirstp(BT_PARAM_OR_VOID(void *bt_a0))
{
    func_80807C8C_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}
void func_80804DA0_bsfirstp(struct player_state_s *arg0) {
    s32 bs_setState(void *, s32);
    u32 func_800A3404(void *);
    void func_80809D24_bsfirstp(void *);

    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
    if (func_800A3404(arg0) != 0) {
        func_80801928_bsfirstp(arg0);
        if (func_808008B0_bsfirstp((u8 *)arg0) == 0) {
            bs_setState(arg0, 0xCA);
            func_80804A3C_bsfirstp(arg0);
        }
    }
}

BsScript bsfirstp_entrypoint_20(BsScriptType arg0) {
    extern BtFnWord D_8080B510_bsfirstp[4];
    return (BsScript)D_8080B510_bsfirstp[arg0];
}

void func_80804E1C_bsfirstp(struct player_state_s *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _glcutDll_entrypoint_1();
    u32 func_800A3404(void *);
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_80807BB8_bsfirstp(void *);
    void func_80807DD4_bsfirstp(BtIntPtr);
    void func_80807F5C_bsfirstp(BtIntPtr);

    if (func_800A3404(arg0) != 0 || _glcutDll_entrypoint_1() != 0) {
        func_80807BB8_bsfirstp(arg0);
        func_80807F5C_bsfirstp((BtIntPtr)arg0);
        return;
    }
    func_80807BB8_bsfirstp(arg0);
    func_80807DD4_bsfirstp((BtIntPtr)arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
    func_808002CC_bsfirstp(arg0, 0x311, 2.0f, 0.5036f);
}

void func_80804EB4_bsfirstp(BT_PARAM_OR_VOID(void *bt_a0))
{
    func_80807C8C_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}
void func_80804ED4_bsfirstp(BtIntPtr arg0) {
    s32 bs_setState(void *, s32);
    s32 func_800EA068(s32);

    func_80807D48_bsfirstp(arg0);
    bs_setState(arg0, func_800EA068(8) ? 0xCB : 0xC9);
}

BsScript bsfirstp_entrypoint_21(BsScriptType arg0) {
    extern BtFnWord D_8080B520_bsfirstp[4];
    return (BsScript)D_8080B520_bsfirstp[arg0];
}

void func_80804F28_bsfirstp(struct player_state_s *arg0) {
    void func_80807BB8_bsfirstp(void *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmoothStartingAt(void *, s32, f32, f32);)
    void func_8008B188(struct anctrl_s *, s32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    func_80807BB8_bsfirstp(arg0);
    baanim_playForDuration_onceSmoothStartingAt(arg0, 0x30C, 2.0f, 0.375f);
    func_8008B188(baanim_getAnimCtrlPtr(arg0), 0);
    func_80800340_bsfirstp(arg0, 0x310, 2.0f, 0.375f);
    func_8008B188(func_8008D04C(arg0), 0);
    func_80804A34_bsfirstp(0);
    func_808061AC_bsfirstp(arg0, 0);
}

void func_80804FB4_bsfirstp(BT_PARAM_OR_VOID(void *bt_a0))
{
    func_80807C8C_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}
void func_80804FD4_bsfirstp(struct player_state_s *arg0) {
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    s32 bs_setState(void *, s32);
    void func_8009DBF0(struct player_state_s *, s32, f32);
    void func_800A3410(struct player_state_s *, s32);

    func_80807D48_bsfirstp(arg0);
    if (baanim_isAt(arg0, 0.3f) != 0) {
        func_8009DBF0(arg0, 0x45A5, 1.0f);
    }
    if (baanim_isStopped(arg0) != 0) {
        func_800A3410(arg0, 1);
        bs_setState(arg0, 1);
    }
}

BsScript bsfirstp_entrypoint_22(BsScriptType arg0) {
    extern BtFnWord D_8080B530_bsfirstp[4];
    return (BsScript)D_8080B530_bsfirstp[arg0];
}

/* extern */

void func_80805058_bsfirstp(struct player_state_s *arg0) {
    s32 _bsdrone_entrypoint_0(BtIntPtr);
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_80807BB8_bsfirstp(void *);
    void func_808002CC_bsfirstp(struct player_state_s *, s32, f32, f32);
    _bsdrone_entrypoint_0(arg0);
    func_80807BB8_bsfirstp(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
    func_808002CC_bsfirstp(arg0, 0x311, 2.0f, 0.5036f);
}

void func_80809D24_bsfirstp(void *);

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_808050B0_bsfirstp(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(s32) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_80807C8C_bsfirstp(arg0);
} BT_NATIVE_ONLY(struct player_state_s; void _bsdrone_entrypoint_1(struct player_state_s *); void func_80807D48_bsfirstp(BtIntPtr);)
void func_808050D8_bsfirstp(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_1(BT_NATIVE_ONLY(arg0));
    func_80807D48_bsfirstp(BT_NATIVE_ONLY((BtIntPtr))arg0);
    func_80809D24_bsfirstp(arg0);
}

BsScript bsfirstp_entrypoint_23(BsScriptType arg0) {
    extern BtFnWord D_8080B540_bsfirstp[4];
    return (BsScript)D_8080B540_bsfirstp[arg0];
}

void func_8080511C_bsfirstp(struct player_state_s *arg0) {
    s32 _bsdrone_entrypoint_0(BtIntPtr);
    void func_80807BB8_bsfirstp(void *);
    u32 func_800A3404(void *);
    void func_80807F24_bsfirstp(BtIntPtr);
    BT_IDO_ONLY(void baanim_playForDuration_loop(struct player_state_s *, s32, f32);)
    void func_8008C990(struct player_state_s *, f32);

    _bsdrone_entrypoint_0((BtIntPtr)arg0);
    func_80807BB8_bsfirstp(arg0);
    if (func_800A3404(arg0) != 0) {
        func_80807F24_bsfirstp((BtIntPtr)arg0);
    }
    baanim_playForDuration_loop(arg0, 0x30E, 1.5f);
    func_8008C990(arg0, 0.5f);
    func_80800488_bsfirstp(arg0, 0x312, 1.5f);
    func_80800264_bsfirstp((BtIntPtr)arg0, 0x3F000000);
}

void func_8080519C_bsfirstp(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(s32) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_80807C8C_bsfirstp(arg0);
}
void func_808051C4_bsfirstp(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_1(BT_NATIVE_ONLY(arg0));
    func_80807D48_bsfirstp(BT_NATIVE_ONLY((BtIntPtr))arg0);
    func_80809D24_bsfirstp(arg0);
}

BsScript bsfirstp_entrypoint_24(BsScriptType arg0) {
    extern BtFnWord D_8080B550_bsfirstp[4];
    return (BsScript)D_8080B550_bsfirstp[arg0];
}

void bsfirstp_entrypoint_25(struct player_state_s *self, f32 speed) {
    f32 mlAbsF(f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    f32 duration;
    f32 one = 1.0f;
    f32 ratio;
    struct anctrl_s *ctrl;

    ratio = mlAbsF(speed) * 0.0033333334f;
    if (ratio > one) {
        ratio = one;
    }
    ctrl = baanim_getAnimCtrlPtr(self);
    duration = (0.75f - one) * ratio + one;
    anctrl_setDuration(ctrl, duration);
    anctrl_setDuration(func_8008D04C(self), duration);
}

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

f32 func_8080549C_bsfirstp(f32 *arg0, f32 arg1, f32 arg2, f32 *arg3, f32 arg4) {
    f32 func_80013AA0(f32);
    f32 func_80013798(f32);
    f32 func_800138BC(f32);
    f32 func_800137C4(void);
    f32 start;
    f32 remaining;
    f32 scale;
    f32 magnitude;
    f32 limit;
    f32 pad[2];
    f32 end;
    f32 area;
    f32 sine;
    scale = arg4 * 0.6366198063f;
    remaining = *arg3 / scale;
    magnitude = *arg0 > 0.0f ? arg2 : -arg2;
    limit = arg1 / magnitude;
    end = *arg0 / magnitude;
    if (limit < 0) {
        limit = 0;
    }
    start = func_80013AA0(1.0f - end);
    end = func_80013AA0(1.0f - limit);
    if (remaining < end - start) {
        end = start + remaining;
    }
    remaining -= end - start;
    if (remaining < 0.000001f) {
        remaining = 0.0f;
    }
    sine = func_80013798(end);
    area = (end + sine) - (func_800138BC(start) + start);
    if (area < 0.000001f) {
        area = 0.0f;
    }
    end = 1.0f - func_800137C4();
    if (end < limit + 0.000001f) {
        end = limit;
    }
    *arg3 = scale * remaining;
    *arg0 = magnitude * end;
    return scale * magnitude * area;
}

f32 func_80805644_bsfirstp(f32 *arg0, f32 arg1, f32 arg2, f32 *arg3, f32 arg4) {
    f32 func_80013A5C(f32);
    f32 func_800137D4(f32);
    f32 func_8001395C(f32);
    f32 func_80013788();
    f32 start;
    f32 remaining;
    f32 scale;
    f32 limit;
    f32 pad[3];
    f32 end;
    f32 area;
    f32 sine;
    scale = arg4 * 0.6366198063f;
    remaining = *arg3 / scale;
    end = *arg0 / arg2;
    start = func_80013A5C(1.0f - end);
    limit = arg1 / arg2;
    end = func_80013A5C(1.0f - limit);
    if (remaining < end - start) {
        end = start + remaining;
    }
    remaining -= end - start;
    if (remaining < 0.000001f) {
        remaining = 0.0f;
    }
    sine = func_800137D4(end);
    area = (end - sine) - (start - func_8001395C(start));
    if (area < 0.000001f) {
        area = 0.0f;
    }
    end = 1.0f - func_80013788();
    if (limit - 0.000001f < end) {
        end = limit;
    }
    *arg3 = scale * remaining;
    *arg0 = arg2 * end;
    return scale * arg2 * area;
}

f32 func_808057C8_bsfirstp(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 area = 0.0f;
    f32 sign;
    f32 value;
    f32 limit;
    f32 *target = &arg1;

    if (*arg0 * (*target - *arg0) < 0.0f) {
        area = func_8080549C_bsfirstp(arg0, *target, arg2, &arg3, arg4);
    }
    if (arg3 != 0.0f) {
        sign = *target >= 0.0f ? 1.0f : -1.0f;
        value = *arg0 * sign;
        limit = *target * sign;
        if (value < limit) {
            area += sign * func_80805644_bsfirstp(&value, limit, arg2, &arg3, arg4);
            *arg0 = sign * value;
        }
    }
    area += *arg0 * arg3;
    return area;
}

void func_808058F0_bsfirstp(void *arg0) {
    typedef struct player_state_s PlayerState;
    s32 bs_setState(void *, s32);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    void func_800936E8(void *, s32);
    void func_8009BDAC(PlayerState *, f32);
    s32 func_8009E6EC();
    void func_8009E830(PlayerState *, s32);
    void func_80807D70_bsfirstp(BtIntPtr);
    s32 sp2C;
    s32 event;
    s32 sp24;

    sp2C = 0;
    event = func_8009E6EC(arg0);
    sp24 = 1;
    if (event == 0x83) {
        sp24 = 2;
        sp2C = 0xCA;
        func_8009BDAC(arg0, 1.5f);
        func_80807D70_bsfirstp(arg0);
        func_80801A5C_bsfirstp(arg0);
        func_8009337C(arg0, 0);
        func_800936E8(arg0, 1);
        func_80093370(arg0, 1);
    }
    func_8009E830(arg0, sp24);
    bs_setState(arg0, sp2C);
}

void bsfirstp_entrypoint_26(BtIntPtr arg0) {
    s32 _badeathmatch_entrypoint_5(BtIntPtr, s32, s32);
    BT_IDO_ONLY(s32 _baduo_entrypoint_14(BtIntPtr, f32 *);) BT_NATIVE_ONLY(void _baduo_entrypoint_14(void *, f32 *);)
    s32 _gcegg_entrypoint_7(s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) _suegg_entrypoint_6(BtIntPtr, f32 *, s32 *);
    s32 _sueggmisc_entrypoint_2(f32 *, s32);
    s32 bs_getCurrentState(struct player_state_s *);
    s32 bs_setState(void *, s32);
    f32 func_80099A34(BtIntPtr);
    BtIntPtr func_80099A4C(BtIntPtr);
    s32 func_80099A58(BtIntPtr);
    s32 func_80099A70(BtIntPtr);
    s32 func_80099A7C(BtIntPtr, f32 *);
    s32 func_80099B94(BtIntPtr);
    void func_8009C15C(u8 *, f32 *);
    s32 func_8009E6EC();
    void func_8009E830(struct player_state_s *, s32);
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    s32 func_800EFD24(s32);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F7E64(s32, s32);
    void func_80801A5C_bsfirstp(void *);
    s32 func_80802BE8_bsfirstp(BtIntPtr, f32);
    s32 func_80803CD4_bsfirstp(void *, s32, s32, s32, f32 *);
    void func_80808678_bsfirstp(Actor *, volatile BtIntPtr);
    void func_80807EEC_bsfirstp(BtIntPtr);
    void func_80807F24_bsfirstp(BtIntPtr);
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
        func_800EFD24((BtIntPtr)position);
        if (func_80803CD4_bsfirstp(arg0, event, -1, 8, position)) {
            next_state = 0xDB;
            handled = 2;
        }
        break;
    }
    case 0x21:
    case 0x24: {
        f32 position[3];
        func_800EFD24((BtIntPtr)position);
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

void func_80805F48_bsfirstp(BtIntPtr arg0)
{
    func_808061AC_bsfirstp(arg0,0);
}

void func_80805F68_bsfirstp(struct player_state_s *arg0)
{
    void func_8009B4FC(struct player_state_s *);
    func_8009B4FC(arg0);
}

void bsfirstp_entrypoint_27(void *arg0) {
    void func_80806000_bsfirstp(void *);
    void func_8080649C_bsfirstp(void *);
    void func_80806588_bsfirstp(void *);
    void func_80806774_bsfirstp(void *);
    FirstpState *firstp;
    int state;

    firstp = ((PlayerState *)arg0)->state_mem;
    state = firstp->unk19C;
    switch (state) {
    case 1:
        break;
    default:
        func_80806774_bsfirstp(arg0);
        break;
    case 2:
        func_8080649C_bsfirstp(arg0);
        break;
    case 3:
        func_80806588_bsfirstp(arg0);
        break;
    }
    func_80806000_bsfirstp(arg0);
}    typedef struct { u8 pad0[0x2C]; f32 unk2C; } Objfirstp_func_80806000_bsfirstp_sp48; /* offsets.py genstruct: fields from raw offsets on sp48; rename once understood */

void func_80806000_bsfirstp(void *arg0) {
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    f32 func_80013728(f32);
    f32 func_80013B7C(f32, f32);
    f32 func_8009BB18(void *);
    f32 func_800EEFFC(void *);
    void func_800EF934(f32 *, f32 *, f32);
    f32 func_800F0E00(f32, f32);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    FirstpState *firstp;
    void *sp48;
    f32 pad[2];
    f32 sp3C;
    f32 magnitude;
    f32 angle;
    f32 sp30;
    f32 scale;
    f32 *vec;
    f32 sp24;
    f32 spare;

    firstp = ((PlayerState *)arg0)->state_mem;
    sp48 = func_80802458_bsfirstp(arg0);
    firstp->unk1B8 = firstp->unk1D4;
    firstp->unk1BC = 0.0f;
    vec = &firstp->unk1B8;
    vec[2] = baphysics_get_target_horizontal_velocity(arg0);
    sp24 = func_8009BB18(arg0);
    func_800EF934(vec, vec, -func_80013728(sp24 - yaw_get(arg0)));
    magnitude = func_800EEFFC(vec);
    sp3C = magnitude;
    scale = 1.0f / func_800F0E00(((Objfirstp_func_80806000_bsfirstp_sp48 *)sp48)->unk2C, magnitude);
    vec[0] *= scale;
    vec[2] *= scale;
    vec[3] = sp3C * scale;
    sp30 = mlAbsF(vec[0]);
    angle = func_80013B7C(sp30, mlAbsF(vec[2]));
    if (vec[0] < 0.0f) {
        vec[4] = angle;
    } else {
        vec[4] = -angle;
    }
}    typedef struct { u8 pad0[0x1C8]; f32 unk1C8; } Objfirstp_func_80806130_bsfirstp_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

f32 func_80806130_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = ((Objfirstp_arg0 *)arg0)->unk188;
    return *&((Objfirstp_func_80806130_bsfirstp_ptr *)ptr)->unk1C8;
}    typedef struct { u8 pad0[0x1C4]; f32 unk1C4; } Objfirstp_func_8080613C_bsfirstp_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

f32 func_8080613C_bsfirstp(void *arg0) {
    register void *ptr;
    ptr = ((PlayerState *)arg0)->state_mem;
    return *&((Objfirstp_func_8080613C_bsfirstp_ptr *)ptr)->unk1C4;
}

/* extern */

void func_80806148_bsfirstp(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    register f32 *temp = *(f32 **)((u8 *)arg0 + 0x188);
    func_800EE7F8(arg1, temp + 110);
}

/* extern */

f32 func_80806170_bsfirstp(void *arg0, f32 arg1) {
    f32 func_800F0DC0(f32, f32);
    void *func_80802458_bsfirstp(void *);
    arg1 /= *(f32 *)((s8 *)func_80802458_bsfirstp(arg0) + 0x2C);
    BT_NATIVE_ONLY(return) func_800F0DC0(arg1, 1.0f);
}

void func_808061AC_bsfirstp(void *arg0, s32 arg1) {
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
#ifndef BT_NATIVE
    s32 baphysics_set_type(void *, s32);
#endif
    f32 func_80013728(f32);
    f32 func_800138D0(f32);
    f32 func_8009BB5C(struct player_state_s *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F3BB0(struct player_state_s *, f32 *);
    void func_80806774_bsfirstp(void *);
    f32 yaw_get(struct player_state_s *);
    s32 pad;
    struct FirstpConfig {
        u8 pad0[0x20];
        f32 gravity;
        f32 airGravity;
        u8 pad28[0x1C];
        f32 scale;
    } *config;
    f32 speed;
    f32 angle;
    struct FirstpData {
        u8 pad0[0x12C];
        f32 motion;
        u8 pad130[0x6C];
        s32 mode;
        f32 position[3];
        f32 previous[3];
        u8 pad1B8[0x1C];
        f32 velocity;
        f32 acceleration;
        f32 timer;
        f32 forward;
        f32 sideways;
    } *data;
    struct FirstpRotation {
        u8 pad0[0x40];
        f32 angle;
    };
    struct FirstpPlayer {
        u8 pad0[0xC8];
        struct FirstpRotation *rotation;
        u8 padCC[0xBC];
        struct FirstpData *data;
    };

    data = ((struct FirstpPlayer *)arg0)->data;
    config = func_80802458_bsfirstp(arg0);
    switch (arg1) {
        case 0:
            baphysics_set_gravity(arg0, config->gravity);
            func_80806774_bsfirstp(arg0);
            baphysics_set_type(arg0, 0);
            break;
        case 1:
            baphysics_set_gravity(arg0, config->gravity);
            baphysics_set_type(arg0, 16);
            baphysics_set_target_horizontal_velocity(arg0, 0.0);
            break;
        case 2:
            baphysics_set_gravity(arg0, config->airGravity);
            data->acceleration = 0.0f;
            data->velocity = 0.0f;
            baphysics_set_type(arg0, 16);
            break;
        case 3:
            baphysics_set_gravity(arg0, config->airGravity);
            if (data->mode != 3) {
                func_800F3BB0(arg0, data->position);
                func_800EE7F8(data->previous, data->position);
                data->timer = 0.0f;
                speed = func_8009BB5C(arg0);
                angle = yaw_get(arg0);
                angle = func_80013728(((struct FirstpPlayer *)arg0)->rotation->angle - angle - 90.0f);
                data->sideways = -func_800138D0(angle) * speed;
                data->forward = data->motion * config->scale;
            }
            baphysics_set_type(arg0, 17);
            break;
    }
    data->mode = arg1;
}

void func_8080633C_bsfirstp(Actor *arg0, f32 arg1) {
    f32 func_80809938_bsfirstp(void *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 func_800F122C(f32, f32, f32);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    s32 pad[4];
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 temp_f2;
    f32 var_f0;
    struct FirstpMotion {
        f32 value;
        f32 unused;
        f32 scale;
        s32 active;
    };
    struct {
        u8 pad0[0x12C];
        struct FirstpMotion motion;
        u8 pad13C[0xC];
        f32 input;
        u8 pad14C[0x80];
        volatile f32 speed;
        f32 limit;
    } *temp_s1;
    u8 *temp_s2;
    volatile struct FirstpMotion *temp_v0;
    void *player = arg0;

    temp_s1 = *(void **)((u8 *)arg0 + 0x188);
    temp_v0 = &temp_s1->motion;
    temp_s2 = func_80802458_bsfirstp(arg0);
    sp34 = 1.0f - *(f32 *)(temp_s2 + 0x30) * mlAbsF(func_80809938_bsfirstp(arg0));
    sp30 = 1.0f - *(f32 *)(temp_s2 + 0x40) * mlAbsF(func_80809938_bsfirstp(arg0));
    sp28 = func_800F122C(temp_s1->input, *(f32 *)(temp_s2 + 0x28), *(f32 *)(temp_s2 + 0x2C)) * (sp34 * arg1);
    sp2C = yaw_get(player);
    baphysics_set_target_horizontal_velocity(player, sp28);
    baphysics_set_target_yaw(player, sp2C);
    temp_s1->speed = *(f32 *)(temp_s2 + 0x34) * temp_v0->value;
    temp_s1->speed = temp_s1->speed * (sp30 * arg1);
    if (temp_v0->active != 0) {
        temp_f2 = temp_v0->scale;
        temp_s1->limit = *(f32 *)(temp_s2 + 0x38) * (temp_f2 > 1.0f ? temp_f2 : 1.0f);
    } else {
        temp_s1->limit = *(f32 *)(temp_s2 + 0x3C);
    }
}

/* extern */

void func_8080649C_bsfirstp(void *arg0) {
    void func_8009B98C(void *, f32 *);
    void func_8009BC08(void *, f32 *);
    f32 func_800D9004(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 yaw_get(struct player_state_s *);
    u8 *volatile sp54;
    /* Keep angle separate to preserve IDO's temporary stack layout. */
    f32 angle;
    struct {
        f32 sp24[3];
        f32 sp30[3];
        f32 unused3C;
        f32 sp40;
        f32 unused44;
        f32 sp48;
        f32 sp4C;
    } local;
    register f32 *temp_v0;

    sp54 = ((Objfirstp_arg0 *)arg0)->unk188_u8p;
    local.sp40 = func_800D9004() - 0.033333335f;
    temp_v0 = (f32 *)(sp54 + 0x1CC);
    local.sp4C = func_808052C8_bsfirstp(temp_v0 + 2, temp_v0[0], temp_v0[1], 0.033333335f);
    local.sp48 = func_808052C8_bsfirstp(temp_v0 + 2, temp_v0[0], temp_v0[1], local.sp40);
    func_808052A4_bsfirstp(&local.sp48, temp_v0 + 3);
    angle = yaw_get(arg0);
    func_800EFCD8(local.sp30, angle - 90.0f, local.sp4C + local.sp48);
    local.sp30[1] = 0.0f;
    func_8009BC08(arg0, local.sp24);
    func_800EF04C(local.sp24, local.sp30);
    func_8009B98C(arg0, local.sp24);
}    typedef struct { u8 pad0[0xC8]; u8 * unkC8; u8 padCC[0xBC]; struct MotionState * unk188; } Objfirstp_func_80806588_bsfirstp_player; /* offsets.py genstruct: fields from raw offsets on player; rename once understood */

void func_80806588_bsfirstp(void *player) {
    void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel);
    void baphysics_set_target_yaw(PlayerState *arg0, f32 target_yaw);
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    f32 func_80013B70(f32, f32, f32);
    f32 func_800D9004(void);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 func_800EEFFC(void *arg0);
    void func_800EF04C(f32 *arg0, f32 *arg1);
    void func_800EF3DC(f32 dst[3], f32 src[3]);
    void func_800EFA20(void *arg0, void *arg1, f32 arg2);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    void *func_80802458_bsfirstp(void *);
    f32 mlAbsF(f32);
    f32 yaw_get(PlayerState *self);

    struct MotionState {
        u8 unknown0[0x1A0];
        f32 previous[3];
        f32 next[3];
        u8 unknown1B8[0x24];
        f32 smoothing[3];
        u8 unknown1E8[0x64];
        f32 turnRate;
    } *state;
    f32 *parameters;
    f32 targetYaw;
    f32 targetSpeed;
    f32 dt;
    f32 *position;
    f32 *scratch;
    f32 *displacement;
    f32 *velocity;
    f32 *nextPosition;
    f32 cosine;
    f32 sine;
    f32 radius;

    state = ((Objfirstp_func_80806588_bsfirstp_player *)player)->unk188;
    nextPosition = state->next;
    parameters = func_80802458_bsfirstp(player);
    dt = func_800D9004();
    scratch = state->previous;
    position = (f32 *)(((Objfirstp_func_80806588_bsfirstp_player *)player)->unkC8 + 4);
    displacement = (f32 *)(((Objfirstp_func_80806588_bsfirstp_player *)player)->unkC8 + 0x28);
    velocity = (f32 *)(((Objfirstp_func_80806588_bsfirstp_player *)player)->unkC8 + 0x10);
    func_800EF04C(scratch, position);
    scratch = state->smoothing;
    func_800EF3DC(state->previous, nextPosition);
    scratch[1] = parameters[17] * *(f32 *)((u8 *)state + 0x12C);
    scratch[0] += func_800FF060(scratch[1] - scratch[0], scratch + 2,
                              parameters[19], parameters[20], parameters[18], dt);
    radius = scratch[0];
    targetYaw = yaw_get(player);
    targetSpeed = 6.283185f * radius * (state->turnRate * 0.0027777778f);
    cosine = func_800137AC(targetYaw);
    sine = func_800137C4();
    state->next[0] = state->previous[0] - radius * cosine;
    state->next[1] = position[1];
    state->next[2] = state->previous[2] + radius * sine;
    func_800EFB24(displacement, nextPosition, position);
    func_800EE7F8(position, nextPosition);
    func_800EFA20(velocity, displacement, 1.0f / dt);
    if (mlAbsF(scratch[2]) > 30.0f) {
        targetSpeed = func_800EEFFC(velocity);
        targetYaw = func_80013B70(velocity[0], velocity[2], targetSpeed);
    }
    baphysics_set_target_horizontal_velocity(player, targetSpeed);
    baphysics_set_target_yaw(player, targetYaw);
}

/* extern */

void func_80806774_bsfirstp(void *arg0) {
    BT_NATIVE_ONLY(void func_8009B7C0(PlayerState *);) BT_IDO_ONLY(void func_8009B7C0();)
    struct {
        s32 pad;
        void *data;
    } local;

    local.data = BT_DATA_FIELD(((PlayerState *)arg0)->state_mem, ((Objfirstp_arg0 *)arg0)->unk188);
#ifdef BT_NATIVE
    func_8009B7C0((PlayerState *)arg0);
#else
    func_8009B7C0();
#endif
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

    local.data = BT_DATA_FIELD(((PlayerState *)arg0)->state_mem, ((Objfirstp_arg0 *)arg0)->unk188);
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
        BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(s32) data;
    } local;

    local.data = BT_DATA_FIELD((BtIntPtr)((PlayerState *)arg0)->state_mem, *(s32 *)((u8 *)arg0 + 0x188));
    bcopy((u8 *)func_80802458_bsfirstp(arg0) + 0x54, (u8 *)local.data + 0x1E8, 0x20);
    func_808067B0_bsfirstp(arg0);
}

f32 func_808068E8_bsfirstp(BtIntPtr);

void func_8080682C_bsfirstp(void *arg0) {
    f32 func_80013728(f32);
    f32 func_80806928_bsfirstp(void *);
    f32 func_80809D94_bsfirstp(void *);
    struct {
        f32 delta;
        s32 pad;
    } local;
    f32 upper;
    f32 lower;
    u8 *data;

    data = BT_DATA_FIELD(((PlayerState *)arg0)->state_mem, *(u8 **)((u8 *)arg0 + 0x188));
    switch (*(s32 *)(data + 0xC)) {
        case 0:
            local.delta = func_808068E8_bsfirstp((BtIntPtr)arg0);
            break;
        case 1:
            local.delta = func_80806928_bsfirstp(arg0);
            break;
    }
    *(f32 *)(data + 0x20C) = func_80013728(*(f32 *)(data + 0x20C) + local.delta);
    lower = func_80809D94_bsfirstp(arg0) + *(f32 *)(data + 0x1EC);
    upper = *(f32 *)(data + 0x1E8);
    if (*(f32 *)(data + 0x20C) < lower) {
        *(f32 *)(data + 0x20C) = lower;
    }
    if (upper < *(f32 *)(data + 0x20C)) {
        *(f32 *)(data + 0x20C) = upper;
    }
}

/* extern */

f32 func_808068E8_bsfirstp(BtIntPtr arg0) {
    f32 func_808069BC_bsfirstp(BtIntPtr);
    f32 func_808069FC_bsfirstp(BtIntPtr);
    s32 func_80809D6C_bsfirstp(BT_NATIVE_ONLY(void *));
    if (func_80809D6C_bsfirstp(BT_NATIVE_ONLY((void *)arg0)) != 0) {
        return func_808069BC_bsfirstp(arg0);
    }
    return func_808069FC_bsfirstp(arg0);
}

/* extern */

f32 func_80806928_bsfirstp(void *arg0) {
    f32 func_80013728(f32);
    f32 func_80809D94_bsfirstp(void *);
    FirstpState *firstp;
    f32 var_f2;

    firstp = ((PlayerState *)arg0)->state_mem;
    {
        f32 temp_f0 = -(firstp->unk184);
        if (temp_f0 < 0.0f) {
            var_f2 = (firstp->unk1E8) * temp_f0;
        } else {
            var_f2 = -(firstp->unk1EC) * temp_f0;
        }
    }
    if ((firstp->unk10) != 0) {
        var_f2 += func_80809D94_bsfirstp(arg0);
    }
    (firstp->unk208) = var_f2;
    return func_80013728(var_f2 - (firstp->yaw)) / 12.0f;
}

f32 func_808069BC_bsfirstp(BtIntPtr arg0) {
    f32 func_80013728(f32);
    f32 func_80809D94_bsfirstp(BT_NATIVE_ONLY(void *));
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    (firstp->unk208) = func_80809D94_bsfirstp(BT_NATIVE_ONLY((void *)arg0));
    return func_80013728((firstp->unk208) - (firstp->yaw)) / 6.0f;
}    typedef struct { u8 pad0[0xA8]; s32 unkA8; u8 padAC[0x18]; f32 unkC4; u8 padC8[0x128]; f32 unk1F0; f32 unk1F4; f32 unk1F8; f32 unk1FC; f32 unk200; f32 unk204; } Objfirstp_func_808069FC_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

f32 func_808069FC_bsfirstp(BtIntPtr arg0) {
    f32 func_800F122C(f32, f32, f32);
    f32 func_80806AD0_bsfirstp(u8 *, f32, f32);
    void *temp_v0;
    volatile struct { f32 x, y, z; s32 active; } *temp_v1;
    f32 var_f2;
    f32 var_f0;

    temp_v0 = ((Objfirstp_arg0 *)arg0)->unk188;
    if (((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unkA8 == 0) {
        temp_v1 = (void *)((s8 *)temp_v0 + 0x180);
        var_f2 = func_800F122C(-temp_v1->x, 0.0f, ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk1F0);
        if (temp_v1->active != 0) {
            var_f0 = ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk1F8 / (1.0f + temp_v1->z);
        } else {
            var_f0 = ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk200;
        }
    } else {
        var_f2 = func_800F122C(-((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unkC4, 0.0f, ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk1F4);
        if (((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unkC4 != 0.0f) {
            var_f0 = ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk1FC;
        } else {
            var_f0 = ((Objfirstp_func_808069FC_bsfirstp_temp_v0 *)temp_v0)->unk204;
        }
    }
    return func_80806AD0_bsfirstp((u8 *)arg0, var_f2, var_f0);
}

/* extern */

f32 func_80806AD0_bsfirstp(u8 *arg0, f32 arg1, f32 arg2) {
    f32 func_800D9004();
    f32 func_808057C8_bsfirstp(f32 *, f32, f32, f32, f32);
    f32 unused0;
    f32 unused1;
    f32 *temp_s0;
    f32 temp_f2;
    f32 sp34;
    f32 sp30;

    temp_s0 = (((Objfirstp_arg0 *)arg0)->unk188_f32p);
    temp_f2 = func_800D9004() - 0.033333335f;
    sp34 = func_808057C8_bsfirstp(temp_s0 + 0x84, arg1, temp_s0[0x7C], 0.033333335f, arg2);
    if (temp_f2 != 0.0f) {
        sp30 = func_808057C8_bsfirstp(temp_s0 + 0x84, arg1, temp_s0[0x7C], temp_f2, arg2);
    } else {
        sp30 = 0.0f;
    }
    func_808052A4_bsfirstp(&sp30, temp_s0 + 0x85);
    return sp34 + sp30;
}

void bsfirstp_entrypoint_28(void *arg0, void *arg1) {
    s32 *ptr0 = ((Objfirstp_arg0 *)arg0)->unk188_s32p;
    s32 *ptr1 = ((Objfirstp_arg1 *)arg1)->unk188;

    ptr0[0x64 / 4] = ((Objfirstp_arg1 *)arg1)->unk184;
    ptr1[0x68 / 4] = ((Objfirstp_arg0 *)arg0)->unk184;
}

void func_80806BA0_bsfirstp(struct player_state_s *arg0) {
    void func_80808D80_bsfirstp(void *);
    s32 func_80809540_bsfirstp(BtIntPtr, s32);
    void func_80809684_bsfirstp(struct player_state_s *, s32);
    void func_80809740_bsfirstp(struct player_state_s *);
    FirstpState *firstp;

    firstp = arg0->state_mem;
    switch (func_80809540_bsfirstp(arg0, firstp->unk218)) {
        default:
        case 0:
            if (firstp->unk218 != 0) {
                func_80808D80_bsfirstp(arg0);
                firstp->unk218 = 0;
            }
            break;
        case 1:
            if (firstp->unk218 != 1) {
                func_80809684_bsfirstp(arg0, 1);
            }
            goto update;
        case 2:
            if (firstp->unk218 != 2) {
                func_80809684_bsfirstp(arg0, 2);
            }
        update:
            func_80809740_bsfirstp(arg0);
            break;
    }
}

void func_80806C58_bsfirstp(void *arg0) {
    void func_8009337C(void *, s32);
    void func_800936E8(void *, s32);
    void func_8009B7C0();
    void func_800A16BC(s32);
    void func_80807BB8_bsfirstp(void *);
    func_80807BB8_bsfirstp(arg0);
    func_800936E8(arg0, 0);
    func_8009337C(arg0, 1);
    func_8009B7C0(arg0);
    func_80801B64_bsfirstp(arg0, 2);
    func_808061AC_bsfirstp(arg0, 0);
    func_800A16BC(1);
}

void func_80806CC0_bsfirstp(void *arg0) {
    s32 _bababykaz_entrypoint_9(struct player_state_s *);
    void func_8009337C(void *, s32);
    void func_800936E8(void *, s32);
    void func_800A16BC(s32);
    void func_800F7B9C(BtIntPtr, u32);
    void func_80808DB0_bsfirstp(void *);
    FirstpState *firstp;
    s32 temp_a2;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_a2 = firstp->unk64;
    if (temp_a2 >= 0) {
        func_800F7B9C(temp_a2, 0x4F);
        firstp->unk64 = -1;
    }
    func_8080175C_bsfirstp(arg0);
    func_800936E8(arg0, 1);
    func_8009337C(arg0, 0);
    func_80801B64_bsfirstp(arg0, 3);
    firstp->unk8 = -1;
    func_80808DB0_bsfirstp(arg0);
    func_80807C8C_bsfirstp(arg0);
    func_800A16BC(0);
    _bababykaz_entrypoint_9(arg0);
}

/* extern */

void func_80806D64_bsfirstp(Actor *arg0) {
    void func_8080633C_bsfirstp(Actor*, f32);
    void func_80801928_bsfirstp(struct player_state_s *);
    func_8080633C_bsfirstp(arg0, 1.0f);
    func_80801928_bsfirstp(arg0);
}

/* extern */

void func_80806D90_bsfirstp(struct player_state_s *arg0) {
    s32 bs_setState(void *, s32);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    FirstpState *firstp;

    firstp = arg0->state_mem;
    if (func_8009E6EC(arg0) == 0x4F) {
        firstp->unk64 = -1;
        bs_setState(arg0, 0xCA);
        func_8009E830(arg0, 2);
        return;
    }
    bsfirstp_entrypoint_26(arg0);
}

BsScript bsfirstp_entrypoint_29(BsScriptType arg0) {
    extern BtFnWord D_8080B560_bsfirstp[4];
    return (BsScript)D_8080B560_bsfirstp[arg0];
}

void func_80806E0C_bsfirstp(void *arg0) {
    void _bsbabykaz_entrypoint_4(struct player_state_s *arg0);
    void func_800936CC(void *, s32);
    void func_800A34A0(void *, s32);
    void func_800A34E4(void *, s32);
    void func_80807BB8_bsfirstp(void *);
    FirstpState *firstp;

    func_80807BB8_bsfirstp(arg0);
    firstp = ((PlayerState *)arg0)->state_mem;
    func_800A34E4(arg0, 0);
    func_800A34A0(arg0, 0);
    firstp->unk0 = 0;
    firstp->unk4 = 0;
    func_800936CC(arg0, 3);
    func_808061AC_bsfirstp(arg0, 1);
    firstp->unk218 = 0xFF;
    func_80806BA0_bsfirstp(arg0);
    _bsbabykaz_entrypoint_4((BtIntPtr)arg0);
    func_80801A34_bsfirstp((BtIntPtr)arg0);
}

void func_80806E9C_bsfirstp(BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(s32) arg0)
{
    _bsbabykaz_entrypoint_3(BT_NATIVE_ONLY((PlayerState *)arg0));
    func_80807C8C_bsfirstp(arg0);
}
void func_80806EC4_bsfirstp(u8 *arg0) {
    s32 _bababykaz_entrypoint_12(void *);
    s32 _bababykaz_entrypoint_3(void *);
    void _bsbabykaz_entrypoint_13(struct player_state_s *);
    void _bsbabykaz_entrypoint_5(void *);
    int bakey_pressed(struct player_state_s *, int);
    s32 bs_setState(void *, s32);
    void func_8009337C(void *, s32);
    void func_800936E8(void *, s32);
    s32 func_800D3948();
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80801928_bsfirstp(struct player_state_s *arg0);
    s32 func_80801A98_bsfirstp(BtIntPtr);
    void func_80801DC0_bsfirstp(u8 *arg0);
    void func_80804848_bsfirstp(u8 *, s32);
    void func_8080633C_bsfirstp(Actor *arg0, f32 arg1);
    void func_8080682C_bsfirstp(void *arg0);
    void func_80806BA0_bsfirstp(struct player_state_s *arg0);
    void func_8080800C_bsfirstp(BtIntPtr arg0);
    void func_80808DB0_bsfirstp(void *arg0);
    void func_80808EF0_bsfirstp(BtIntPtr arg0);
    void func_808099B4_bsfirstp(void *arg0);
    void func_80809D24_bsfirstp(void *arg0);
    FirstpState *firstp;
    s32 sp20;
    s32 temp_v0;

    firstp = ((PlayerState *)arg0)->state_mem;
    _bsbabykaz_entrypoint_5(arg0);
    func_8080800C_bsfirstp(arg0);
    if (func_800D3948() != 0) {
        sp20 = (firstp->unk68);
        func_80101180(0x2C4, 0x75, (_bababykaz_entrypoint_12(arg0) << 0x10) | (sp20 & 0xFFFF));
    }
    if (_bababykaz_entrypoint_3(arg0) != 0) {
        bs_setState(arg0, 0xA1);
        return;
    }
    temp_v0 = (firstp->unk4);
    switch (temp_v0) {
    case 0:
        if (func_80801A98_bsfirstp(arg0) != 0) {
            func_800936E8(arg0, 1);
            func_8009337C(arg0, 1);
            func_80808DB0_bsfirstp(arg0);
            (firstp->unk4) = (s32) ((firstp->unk4) + 1);
        }
        break;
    case 1:
        func_80804848_bsfirstp(arg0, (firstp->unkC));
        func_80801DC0_bsfirstp(arg0);
        func_80809D24_bsfirstp(arg0);
        func_8080682C_bsfirstp(arg0);
        func_808099B4_bsfirstp(arg0);
        func_8080633C_bsfirstp(arg0, 1.0f);
        func_80808EF0_bsfirstp(arg0);
        if (bakey_pressed(arg0, 9) != 0) {
            _bsbabykaz_entrypoint_13(arg0);
        }
        break;
    }
    func_80801928_bsfirstp(arg0);
    func_80806BA0_bsfirstp(arg0);
}

void func_80807024_bsfirstp(struct player_state_s *arg0) {
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    s32 func_80099B94(BtIntPtr);
    s32 func_80099A58(BtIntPtr);
    s32 func_80099A64(struct player_state_s *);
    f32 func_80099A34(BtIntPtr);
    struct player_state_s *func_800F53D0(BtIntPtr);
    s32 _badeathmatch_entrypoint_4(s32);
    s32 _badeathmatch_entrypoint_5(BtIntPtr, s32, s32);
    void _bsbabykaz_entrypoint_13(struct player_state_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 bs_setState(void *, s32);
    s32 state;
    u8 *data;
    struct player_state_s *player;
    s32 death;
    s32 value;
    u8 *sp28;
    struct player_state_s *sp24;
    f32 sp20;

    state = func_8009E6EC(arg0);
    switch (state) {
        case 0x1F:
        case 0x21:
        case 0x24:
        case 0x47:
        case 0x4E:
            _bsbabykaz_entrypoint_13(arg0);
            func_8009E830(arg0, 2);
            break;
        case 0x4F:
            _bsbabykaz_entrypoint_13(arg0);
            func_8009E830(arg0, 2);
            _batimer_set(arg0, 0, 0.0f);
            break;
        case 0x8E:
            arg0->unk160.word = 0;
            bs_setState(arg0, 0xA1);
            func_8009E830(arg0, 2);
            _batimer_set(arg0, 0, 0.0f);
            break;
        case 0x7D:
            if (arg0->unk158) {
                data = *(u8 **)((u8 *)arg0 + 0x188);
                player = func_800F53D0(*(s32 *)(data + 0x68));
                death = _badeathmatch_entrypoint_4(func_80099A58((BtIntPtr)arg0));
                value = func_80099A64(arg0);
                _badeathmatch_entrypoint_5((BtIntPtr)player, death, value);
            } else {
                func_80099B94((BtIntPtr)arg0);
            }
            break;
        case 0x5F:
            if (arg0->unk158) {
                sp28 = *(u8 **)((u8 *)arg0 + 0x188);
                sp24 = func_800F53D0(*(s32 *)(sp28 + 0x68));
                sp20 = func_80099A34((BtIntPtr)arg0);
                func_80802BE8_bsfirstp((BtIntPtr)sp24, sp20);
            }
            break;
        default:
            func_80099B94((BtIntPtr)arg0);
            break;
    }
}

BsScript bsfirstp_entrypoint_30(BsScriptType arg0) {
    extern BtFnWord D_8080B570_bsfirstp[4];
    return (BsScript)D_8080B570_bsfirstp[arg0];
}

void func_808071D8_bsfirstp(BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(s32) arg0)
{
    BT_NATIVE_ONLY(void func_80091E6C(void *);) func_80091E6C(BT_NATIVE_ONLY((void *)arg0));
    _bsbabykaz_entrypoint_3(arg0);
    func_80807C8C_bsfirstp(arg0);
}

/* extern */

void func_80807208_bsfirstp(BtIntPtr arg0) {
    s32 _bababykaz_entrypoint_9(struct player_state_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _bsbabykaz_entrypoint_0(u8 *arg0);
    void _bsbabykaz_entrypoint_4(struct player_state_s *arg0);
    s32 func_80091E48(BtIntPtr, s32);
    void func_80807BB8_bsfirstp(void *);
    func_80807BB8_bsfirstp(arg0);
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
        func_800F9AAC((((Objfirstp_arg0 *)arg0)->unk184), _bababykaz_entrypoint_4(arg0));
    }
}

BsScript bsfirstp_entrypoint_31(BsScriptType arg0) {
    extern BtFnWord D_8080B580_bsfirstp[4];
    return (BsScript)D_8080B580_bsfirstp[arg0];
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

void func_80807328_bsfirstp(struct player_state_s *arg0) {
    void func_80804848_bsfirstp(u8 *, s32);
    void func_80808DB0_bsfirstp(void *);
    void func_80809D24_bsfirstp(void *);
    void func_808099B4_bsfirstp(void *);

    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80804848_bsfirstp((u8 *)arg0, -1);
    func_80801928_bsfirstp(arg0);
    func_80801DC0_bsfirstp((u8 *)arg0);
    func_80808DB0_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
    func_8080682C_bsfirstp(arg0);
    func_808099B4_bsfirstp(arg0);
    func_80800830_bsfirstp((BtIntPtr)arg0);
}

void func_80807394_bsfirstp(struct player_state_s *arg0) {
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    u32 func_800A3404(void *);
    s32 func_800D3948(void);
    s32 func_80099A58(BtIntPtr);
    s32 _ncpoddialog_entrypoint_10(s32);
    s32 bs_setState(void *, s32);
    void func_80807EEC_bsfirstp(BtIntPtr);
    void func_80807F24_bsfirstp(BtIntPtr);
    BT_IDO_ONLY(void baanim_playForDuration_loop(struct player_state_s *, s32, f32);)
    s32 pad;
    s32 sp20;
    s32 state;

    sp20 = 1;
    state = func_8009E6EC(arg0);
    switch (state) {
    case 0x62:
        if (func_800A3404(arg0) == 0) {
            func_80807EEC_bsfirstp((BtIntPtr)arg0);
            sp20 = 2;
        }
        break;
    case 0x64:
        if (func_800A3404(arg0) != 0 && func_800D3948() == 0) {
            func_80807F24_bsfirstp((BtIntPtr)arg0);
            baanim_playForDuration_loop(arg0, 0x30D, 2.0f);
            func_80800488_bsfirstp(arg0, 0x311, 2.0f);
            sp20 = 2;
        }
        if (_ncpoddialog_entrypoint_10(func_80099A58((BtIntPtr)arg0)) != 0) {
            arg0->unk15C.word = 1;
            sp20 = 2;
        }
        break;
    case 0x63:
        if (func_800A3404(arg0) != 0) {
            func_80807F24_bsfirstp((BtIntPtr)arg0);
            sp20 = 2;
        }
        break;
    default:
        bsfirstp_entrypoint_26((BtIntPtr)arg0);
        return;
    }
    func_8009E830(arg0, sp20);
    bs_setState(arg0, 0);
}

void func_808074D0_bsfirstp(void *arg0) {
    void func_800936E8(void *, s32);
    func_800936E8(arg0, 1);
    _bsrest_entrypoint_14(arg0);
    func_80807C8C_bsfirstp(arg0);
}

void func_80807504_bsfirstp(struct player_state_s *arg0) {
    void func_80807BB8_bsfirstp(void *);
    u32 func_800A3404(void *);
    int func_800DB9B0(void);
    s32 bs_getPreviousState(struct player_state_s *);
    s32 _bsrest_entrypoint_16(void *);
    BT_IDO_ONLY(void baanim_playForDuration_loop(struct player_state_s *, s32, f32);)
    void func_800936E8(void *, s32);
    void func_8009337C(void *, s32);
    s32 state;

    if (func_800A3404(arg0) != 0) {
        if (func_800DB9B0() != 0) {
            arg0->unk15C.word = 2;
        } else {
            arg0->unk15C.word = 0;
        }
    } else if (bs_getPreviousState(arg0) == 0xC8) {
        arg0->unk15C.word = 3;
    } else {
        arg0->unk15C.word = 1;
    }
    func_808061AC_bsfirstp(arg0, 0);
    state = *(int *)((u8 *)arg0 + 0x15C);
    switch (state) {
    case 2:
        _bsrest_entrypoint_16(arg0);
        func_80807BB8_bsfirstp(arg0);
        baanim_playForDuration_loop(arg0, 0x272, 2.0f);
        func_800936E8(arg0, 0);
        func_8009337C(arg0, 1);
        break;
    case 0:
        _bsrest_entrypoint_16(arg0);
        func_80807BB8_bsfirstp(arg0);
        baanim_playForDuration_loop(arg0, 0x272, 2.0f);
        break;
    case 1:
        _bsrest_entrypoint_16(arg0);
        func_80807BB8_bsfirstp(arg0);
        break;
    case 3:
        break;
    }
}

void func_8080762C_bsfirstp(struct player_state_s *arg0) {
    s32 _bsrest_entrypoint_16(void *);
    s32 _bsrest_entrypoint_20();
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void func_800936E8(void *, s32);
    void func_80807EEC_bsfirstp(BtIntPtr);
    void func_80807F5C_bsfirstp(BtIntPtr);

    switch (*(u32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
    case 2:
        func_808072C8_bsfirstp(arg0);
        func_80807328_bsfirstp(arg0);
        if (_bsrest_entrypoint_20(arg0) != 0) {
            func_80807F5C_bsfirstp((BtIntPtr)arg0);
        }
        break;
    case 1:
        func_80807328_bsfirstp(arg0);
        if (_bsrest_entrypoint_20(arg0) != 0) {
            func_80807F5C_bsfirstp((BtIntPtr)arg0);
        }
        break;
    case 3:
        if (baanim_isAt(arg0, 0.1081f) != 0) {
            func_800936E8(arg0, 1);
        }
        if (baanim_isStopped(arg0) != 0) {
            baanim_playForDuration_loopStartingAt(arg0, 0x30D, 2.0f, 0.5036f);
            func_808002CC_bsfirstp(arg0, 0x311, 2.0f, 0.5036f);
            func_8008B1C8(baanim_getAnimCtrlPtr(arg0), 0.75f);
            func_8008B1C8(func_8008D04C(arg0), 0.75f);
            _bsrest_entrypoint_16(arg0);
            *(u32 *)((u8 *)arg0 + 0x15C) = 4;
        }
        func_80807328_bsfirstp(arg0);
        break;
    case 4:
        func_80807328_bsfirstp(arg0);
        if (_bsrest_entrypoint_20(arg0) != 0) {
            func_80807EEC_bsfirstp((BtIntPtr)arg0);
            func_80807F5C_bsfirstp((BtIntPtr)arg0);
        }
        break;
    }
}

BsScript bsfirstp_entrypoint_32(BsScriptType arg0) {
    extern BtFnWord D_8080B590_bsfirstp[4];
    return (BsScript)D_8080B590_bsfirstp[arg0];
}

void func_808077AC_bsfirstp(BtIntPtr arg0) {
    void func_80801B64_bsfirstp(u8 *, s32);
    func_80801B64_bsfirstp(arg0, 3);
    _bsrest_entrypoint_14(arg0);
    func_80807C8C_bsfirstp(arg0);
}

void func_808077E0_bsfirstp(void *arg0) {
    void func_80801B64_bsfirstp(u8 *, s32);
    void func_80807BB8_bsfirstp(void *);
    s32 _bsrest_entrypoint_16(void *);
    u32 func_800A3404(void *);
    BT_IDO_ONLY(void baanim_playForDuration_loop(struct player_state_s *, s32, f32);)
    BT_IDO_ONLY(void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);)

    func_80801B64_bsfirstp(arg0, 2);
    func_80807BB8_bsfirstp(arg0);
    _bsrest_entrypoint_16(arg0);
    if (func_800A3404(arg0) != 0) {
        baanim_playForDuration_loopSmooth(arg0, 0x272, 2.0f);
    } else {
        baanim_playForDuration_loop(arg0, 0x30D, 2.0f);
        func_80800488_bsfirstp(arg0, 0x311, 2.0f);
    }
    ((Objfirstp_arg0 *)arg0)->unk15C = 0;
}

void func_80807864_bsfirstp(struct player_state_s *self) {
    s32 func_8009CC68(struct player_state_s *self);
    s32 _bsrest_entrypoint_20(struct player_state_s *self);
    void yaw_update(struct player_state_s *self);
    void func_80807328_bsfirstp(struct player_state_s *self);
    void func_80807F5C_bsfirstp(BtIntPtr arg0);

    if (func_8009CC68(self) == 0) {
        self->unk15C.word = 1;
    }
    switch (self->unk15C.word) {
        case 0:
            _bsrest_entrypoint_20(self);
            yaw_update(self);
            func_80807328_bsfirstp(self);
            break;
        case 1:
            func_80807F5C_bsfirstp((BtIntPtr)self);
            break;
    }
}

BsScript bsfirstp_entrypoint_33(BsScriptType arg0) {
    extern BtFnWord D_8080B5A0_bsfirstp[4];
    return (BsScript)D_8080B5A0_bsfirstp[arg0];
}    typedef struct { u8 pad0[0x184]; s32 unk184; } Objfirstp_func_808078F4_bsfirstp_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

void func_808078F4_bsfirstp(BtIntPtr self) {
    void func_8008CF7C(struct player_state_s *);
    void func_80092EC8(struct player_state_s *, s32);
    void func_8009312C(struct player_state_s *, s32);
    void func_8009316C(struct player_state_s *, s32);
    void func_80093230(struct player_state_s *, f32);
    void func_8009359C(void *, s32);
    void func_800936CC(void *, s32);
    void func_800936D8(void *, f32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_8009EA2C(void);
    s32 func_800A940C(s32);
    s32 func_800D3948(void);
    f32 *data;
    FirstpConfig *state;
    s16 anim[2];
    s16 mode[2];
    s16 index;
    f32 speed;

    state = func_80802484_bsfirstp(self);
    data = func_80802458_bsfirstp(self);
    if (func_800D3948() == 0) {
        if (func_8009EA2C() != 0) {
            anim[0] = 0x726;
            anim[1] = 0x725;
            mode[0] = 0;
            mode[1] = 0;
        } else {
            func_80802AA8_bsfirstp((u8 *)self, 0, (u8 *)anim, (u8 *)mode);
        }
    } else {
        index = func_800A940C(((Objfirstp_func_808078F4_bsfirstp_self *)self)->unk184);
        func_80802AA8_bsfirstp((u8 *)self, index, (u8 *)anim, (u8 *)mode);
    }
    speed = func_800D3948() ? *(f32 *)((u8 *)state + 0x44) : 1.0f;
    func_80092EC8(self, anim[0]);
    if (mode[0] != 0) {
        func_8009312C(self, mode[0]);
    }
    func_80093230(self, speed);
    func_8008CF7C(self);
    func_800936CC(self, 2);
    func_8009359C(self, anim[1]);
    if (mode[1] != 0) {
        func_8009316C(self, mode[1]);
    }
    func_800936D8(self, state->unkC);
    func_8009E55C(self, 0, data[0]);
    func_8009E55C(self, 1, data[1]);
}

/* extern */

void func_80807A70_bsfirstp(void *arg0) {
    void func_8008CFF0(struct player_state_s *);
    void func_80093230(struct player_state_s *, f32);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    void func_8009359C(void *, s32);
    void func_800936CC(void *, s32);
    s32 *temp_v0;

    temp_v0 = (((Objfirstp_arg0 *)arg0)->unk188_s32p);
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

enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;

void func_80807AF8_bsfirstp(struct player_state_s *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_13();
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

    temp_s1 = arg0->state_mem;
    sp28 = 1;
    if (func_800D3948() != 0) {
        if (func_800EA068(0x4000) != 0) {
            sp28 = _gcstatusDll_entrypoint_13(arg0->unk184);
        } else {
            _gcstatusDll_entrypoint_3(arg0->unk184, 1);
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

void func_80807BB8_bsfirstp(void *arg0) {
    void _bafpctrl_entrypoint_14(struct player_state_s *, s32);
    void func_800947EC(struct player_state_s *, s32, s32);
    s32 func_8009E77C(struct player_state_s *, s32);
    void func_80807F9C_bsfirstp(BtIntPtr);
    void func_8080995C_bsfirstp(u8 *);
    void func_80809C90_bsfirstp(BtIntPtr);
    void func_80809CD8_bsfirstp(BT_NATIVE_ONLY(PlayerState *));
    u8 *sp24;

    if (func_8009E77C(arg0, 5) == 0) {
        sp24 = func_80800000_bsfirstp(arg0);
        func_80807AF8_bsfirstp(arg0);
        func_800947EC(arg0, 8, 1);
        *(s32 *)(sp24 + 0xC) = 0;
        *(s32 *)(sp24 + 0x10) = 1;
        func_80801AC4_bsfirstp((BtIntPtr)arg0);
        func_80805F48_bsfirstp((BtIntPtr)arg0);
        func_80809CD8_bsfirstp(arg0);
        func_808067E8_bsfirstp(arg0);
        func_8080995C_bsfirstp(arg0);
        func_80803A84_bsfirstp(arg0);
        func_808047EC_bsfirstp(arg0);
        func_80802BD8_bsfirstp((BtIntPtr)arg0);
        func_80802F00_bsfirstp(arg0);
        func_80809C90_bsfirstp((BtIntPtr)arg0);
        _bafpctrl_entrypoint_14(arg0, 1);
        func_80800190_bsfirstp(arg0);
        func_80807F9C_bsfirstp((BtIntPtr)arg0);
    }
}

void func_80807C8C_bsfirstp(void *arg0) {
    s32 bainput_enable(void *, s32, s32);
    void func_800947EC(struct player_state_s *, s32, s32);
    s32 func_8009E74C(struct player_state_s *, s32);
    void func_800F7B9C(BtIntPtr, u32);
    void func_80808084_bsfirstp(BtIntPtr);
    void func_80809CB4_bsfirstp(u8 *);
    FirstpState *firstp;
    s32 temp_a0;

    firstp = ((PlayerState *)arg0)->state_mem;
    if (func_8009E74C(arg0, 5) == 0) {
        temp_a0 = firstp->unk68;
        if (temp_a0 >= 0) {
            func_800F7B9C(temp_a0, 0x4F);
            firstp->unk68 = -1;
        }
        func_80807A70_bsfirstp(arg0);
        func_80801AEC_bsfirstp((BtIntPtr)arg0);
        func_80805F68_bsfirstp(arg0);
        bainput_enable(arg0, 3, 1);
        func_800947EC(arg0, 8, 0);
        func_80809CB4_bsfirstp(arg0);
        func_80803B04_bsfirstp((BtIntPtr)arg0);
        func_808018E0_bsfirstp((BtIntPtr)arg0);
        func_80808084_bsfirstp((BtIntPtr)arg0);
        func_80800040_bsfirstp(arg0);
    }
}

void func_80807D48_bsfirstp(BtIntPtr arg0)
{
    func_80802BE0_bsfirstp(arg0);
    func_8080800C_bsfirstp(arg0);
}
void func_80807D70_bsfirstp(BtIntPtr arg0) {
    void func_8009BD50(void *);
    void func_800A34E4(void *, s32);
    void func_80809DA0_bsfirstp(void *, s32);

    func_808001D0_bsfirstp(arg0);
    func_80809DA0_bsfirstp((void *)arg0, 1);
    func_808067B0_bsfirstp((void *)arg0);
    func_80801B64_bsfirstp((u8 *)arg0, 1);
    func_80802ED4_bsfirstp((void *)arg0);
    func_800A34E4((void *)arg0, 0);
    func_8009BD50((void *)arg0);
}

void func_80807DD4_bsfirstp(BtIntPtr arg0) {
    s32 _bapreload_entrypoint_0(struct player_state_s *, s32, s16 *, s16 *);
    void func_80092EC8(struct player_state_s *, s32);
    void func_8008CF7C(struct player_state_s *);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    void func_8009359C(void *, s32);
    void func_800936CC(void *, s32);
    void func_800936D8(void *, f32);
    void func_800936E8(void *, s32);
    void func_8009B4FC(struct player_state_s *);
    u32 func_800A3404(void *);
    void func_800A34E4(void *, s32);
    void func_808078F4_bsfirstp(BtIntPtr);
    void func_80093230(struct player_state_s *, f32);
    s16 sp26;
    s16 sp24;
    s16 sp22;
    s16 sp20;

    if (func_800A3404((void *)arg0) != 0) {
        func_808078F4_bsfirstp(arg0);
        func_80807D70_bsfirstp(arg0);
        func_8080053C_bsfirstp((void *)arg0);
        func_8009B4FC((struct player_state_s *)arg0);
        func_800936E8((void *)arg0, 1);
        func_8009337C((void *)arg0, 0);
        func_80093370((void *)arg0, 1);
    } else {
        _bapreload_entrypoint_0((struct player_state_s *)arg0, 0xA, &sp26, &sp24);
        _bapreload_entrypoint_0((struct player_state_s *)arg0, 0xB, &sp22, &sp20);
        func_800936CC((void *)arg0, 1);
        func_80092EC8((struct player_state_s *)arg0, sp26);
        func_80093230((struct player_state_s *)arg0, 1.0f);
        func_8009337C((void *)arg0, 1);
        func_8009359C((void *)arg0, sp22);
        func_800936D8((void *)arg0, 1.0f);
        func_800936E8((void *)arg0, 1);
        func_800A34E4((void *)arg0, 1);
        func_8008CF7C((struct player_state_s *)arg0);
        func_808003B4_bsfirstp((struct player_state_s *)arg0, 0x310, 2.0f);
    }
}

/* extern */

void func_80807EEC_bsfirstp(BtIntPtr arg0) {
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    void func_80807DD4_bsfirstp(BtIntPtr);
    if (func_800A3404(arg0) == 0) {
        func_800A3544(arg0, 1);
        func_80807DD4_bsfirstp(arg0);
    }
}

/* extern */

void func_80807F24_bsfirstp(BtIntPtr arg0) {
    u32 func_800A3404(void *);
    void func_800A3544(void *, s32);
    void func_80807DD4_bsfirstp(BtIntPtr);
    if (func_800A3404(arg0) != 0) {
        func_800A3544(arg0, 0);
        func_80807DD4_bsfirstp(arg0);
    }
}

/* extern */

void func_80807F5C_bsfirstp(BtIntPtr arg0) {
    s32 bs_setState(void *, s32);
    void func_800A3544(void *, s32);
    void func_80807DD4_bsfirstp(BtIntPtr);
    void func_80801A5C_bsfirstp(void *);
    func_800A3544(arg0, 1);
    func_80807DD4_bsfirstp(arg0);
    func_80801A5C_bsfirstp(arg0);
    bs_setState((u8 *) arg0, 0xCA);
}

void func_80807FBC_bsfirstp(BtIntPtr arg0);
void func_808080A4_bsfirstp(void *, u8);
void func_808080B4_bsfirstp(BtIntPtr, s16 *, u8);
void func_80808100_bsfirstp(BtIntPtr, s16 *);

void func_80807F9C_bsfirstp(BtIntPtr arg0)
{
    func_80807FBC_bsfirstp(arg0);
}    typedef struct { u8 pad0[0x72]; u8 unk72; } Objfirstp_func_80807FBC_bsfirstp_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80807FBC_bsfirstp(BtIntPtr arg0) {
    void *volatile sp1C;
    volatile BtIntPtr sp18;
    BtIntPtr temp_a1;
    void *temp_v0;
    u8 temp_a2;

    temp_v0 = ((Objfirstp_arg0 *)arg0)->unk188;
    temp_a1 = (BtIntPtr)temp_v0 + 0x6C;
    sp18 = temp_a1;
    sp1C = temp_v0;
    func_80808100_bsfirstp(arg0, temp_a1);
    func_808080A4_bsfirstp((void *)arg0, 255);
    temp_a2 = ((Objfirstp_func_80807FBC_bsfirstp_sp1C *)sp1C)->unk72;
    func_808080B4_bsfirstp(arg0, (s16 *)*(s32 *)&sp18, temp_a2);
}

void func_8080800C_bsfirstp(BtIntPtr arg0) {
    s16 sp28[3];
    s16 *var_v1;
    FirstpState *firstp;
    u8 *var_v0;

    firstp = ((PlayerState *)arg0)->state_mem;
    func_80808100_bsfirstp(arg0, (BtIntPtr)sp28);
    var_v0 = firstp;
    var_v1 = sp28;
    do {
        *(s16 *)(var_v0 + 0x6C) = (*(s16 *)(var_v0 + 0x6C) * 3 + *var_v1++) >> 2;
        var_v0 += 2;
    } while (((BtUIntPtr)var_v1 ^ (BtUIntPtr)&sp28[3]) != 0);
    func_808080B4_bsfirstp(arg0, &firstp->unk6C, firstp->unk72);
}

void func_80808084_bsfirstp(BtIntPtr arg0)
{
    func_80092744(arg0,0);
}

void func_808080A4_bsfirstp(void *arg0, u8 arg1) {
    s8 *ptr = ((Objfirstp_arg0 *)arg0)->unk188_s8p;
    ptr[0x72] = arg1;
}

void func_808080B4_bsfirstp(BtIntPtr arg0, s16 *arg1, u8 arg2) {
    func_80092744((s32 *) arg0, 1);
    func_80092750((void *) arg0, arg1[0], arg1[1], arg1[2], arg2);
}

/* extern */

void func_80808100_bsfirstp(BtIntPtr arg0, s16 *arg1) {
    s32 func_80808148_bsfirstp(BtIntPtr, s32 *);
    void func_808084AC_bsfirstp(f32 *, f32);
    void func_8080853C_bsfirstp(f32 *, f32);
    void func_808085A8_bsfirstp(f32 *, s16 *);
    f32 sp1C[3];

    func_80808148_bsfirstp(arg0, sp1C);
    func_8080853C_bsfirstp(sp1C, 20.0f);
    func_808084AC_bsfirstp(sp1C, 0.5f);
    func_808085A8_bsfirstp(sp1C, arg1);
}

s32 func_80808148_bsfirstp(BtIntPtr arg0, s32 *arg1) {
    void func_800965E0(BtIntPtr, u8 *);
    void func_80096604(BtIntPtr, void *);
    s32 func_80096628(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_800EE84C(f32 *, s32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F36D4(s32 *, s32 *);
    f32 position[3];
    f32 from0[3];
    f32 delta[3];
    f32 *out;
    f32 distance;
    f32 ratio;
    s32 (*rows)[3];
    f32 scale;
    f32 perpendicular[3];
    f32 offset[3];
    f32 point[3];
    u8 bytes[3][4];
    s32 colors[3][3];
    s32 i;
    s32 j;
    f32 vertices[3][3];

    rows = colors;
    out = (f32 *)arg1;
    out[2] = out[1] = out[0] = 255.0f;
    func_8009C128((struct player_state_s *)arg0, position);
    if (!(func_80096628((struct player_state_s *)arg0) & 0x200000)) {
        func_80096604(arg0, vertices);
        func_800965E0(arg0, bytes[0]);
        for (i = 0; i < 3; i++) {
            vertices[i][1] = 0.0f;
            for (j = 0; j != 3; j++) {
                colors[i][j] = bytes[i][j];
            }
        }
        if (func_800F36D4(rows[0], rows[1]) && func_800F36D4(rows[0], rows[2])) {
            func_800EE84C(out, rows[0]);
            BT_NATIVE_ONLY(return 0;) BT_IDO_ONLY(return;)
        }
        position[1] = 0.0f;
        func_800EFB24(from0, position, vertices);
        from0[1] = 0.0f;
        func_800EFB24(offset, vertices, vertices[1]);
        offset[1] = 0.0f;
        func_800EFB24(perpendicular, vertices[2], vertices[1]);
        scale = perpendicular[0];
        perpendicular[1] = 0.0f;
        perpendicular[0] = -perpendicular[2];
        perpendicular[2] = scale;
        ratio = func_800EEAA4(from0, perpendicular);
        if (ratio == 0.0f) {
            ratio = 0.1f;
        }
        scale = -(offset[0] * perpendicular[0] + offset[1] * perpendicular[1] + offset[2] * perpendicular[2]) / ratio;
        func_800EFA4C(point, vertices[0][0] + from0[0] * scale, 0.0, vertices[0][2] + from0[2] * scale);
        func_800EFB24(delta, point, vertices[1]);
        distance = func_800EEF94(delta);
        ratio = distance / (func_800EEF94(perpendicular) + 0.01f);
        for (i = 0; i < 3; i++) {
            out[i] = rows[1][i] + (rows[2][i] - rows[1][i]) * ratio;
        }
        func_800EFB24(delta, point, vertices);
        distance = func_800EEF94(from0);
        ratio = 1.0f - distance / (func_800EEF94(delta) + 0.01f);
        for (i = 0; i != 3; i++) {
            out[i] = out[i] + (rows[0][i] - out[i]) * ratio;
        }
    }
BT_NATIVE_ONLY(return 0;) }

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

s32 func_80808630_bsfirstp(BtIntPtr arg0) {
    int bakey_pressed(struct player_state_s *, int);
    s32 func_800C6E38(s32);
    if ((func_800C6E38(0x1A) != 0) && (bakey_pressed(arg0, 9) != 0)) {
        return 1;
    }
    return 0;
}

void func_808086B0_bsfirstp(Actor *, s32);

void func_80808678_bsfirstp(Actor *arg0, volatile BtIntPtr arg1) {
    void func_8080633C_bsfirstp(Actor *, f32);
    func_808086B0_bsfirstp(arg0, 3);
    func_8080633C_bsfirstp(arg0, 0.15f);
}    typedef struct { u8 pad0[0x15C]; s32 unk15C; } Objfirstp_func_808086B0_bsfirstp_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Objfirstp_func_808086B0_bsfirstp_anim2; /* offsets.py genstruct: fields from raw offsets on anim2; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Objfirstp_func_808086B0_bsfirstp_anim1; /* offsets.py genstruct: fields from raw offsets on anim1; rename once understood */ typedef struct { u8 pad0[0x8]; f32 unk8; } Objfirstp_func_808086B0_bsfirstp_config; /* offsets.py genstruct: fields from raw offsets on config; rename once understood */

void func_808086B0_bsfirstp(Actor *arg0, s32 arg1) {
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009E5A4(struct player_state_s *, s32, s32);
    void func_8009E4E0(void *, s32, BtIntPtr);
    void baflag_set(struct player_state_s *, s32);
    s32 baflag_clear(BtIntPtr, s32);
#ifndef BT_NATIVE
    extern s32 _bsfirstp_entrypoint_13;
#endif
    void *config;
    void *anim1;
    void *anim2;
    void *self = arg0;

    config = func_80802458_bsfirstp(self);
    switch (arg1) {
        case 1:
            baphysics_set_target_horizontal_velocity(self,
                baphysics_get_target_horizontal_velocity(self) * 0.3f);
            func_80802A40_bsfirstp(self, 8);
            func_808025C8_bsfirstp(self, &anim1, &anim2);
            func_80800424_bsfirstp(self, *(s16 *)anim1, ((Objfirstp_func_808086B0_bsfirstp_anim1 *)anim1)->unk4);
            baanim_playForDuration_onceSmooth(self, *(s16 *)anim2, ((Objfirstp_func_808086B0_bsfirstp_anim2 *)anim2)->unk4);
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(self, 1000.0f);
            func_8009E55C(self, 2, ((Objfirstp_func_808086B0_bsfirstp_config *)config)->unk8);
            func_8009E5A4(self, 2, 3);
            func_8009E4E0(self, 2, &_bsfirstp_entrypoint_13);
            baflag_set(self, 0x3B);
            func_80802A40_bsfirstp(self, 9);
            break;
        case 3:
            func_8080633C_bsfirstp(self, 0.3f);
            if (baphysics_get_target_horizontal_velocity(self) < 0.0f) {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
            }
            func_8009E5A4(self, 2, 2);
            func_8009E55C(self, 2, 0.0f);
            baflag_clear(self, 0x3B);
            break;
    }
    ((Objfirstp_func_808086B0_bsfirstp_self *)self)->unk15C = arg1;
}

void func_80808848_bsfirstp(Actor *arg0) {
    void _bainvisible_entrypoint_7(Actor *, s32, f32, f32, f32);
    void func_80807BB8_bsfirstp(void *);
    void func_80808DB0_bsfirstp(void *);
    func_80807BB8_bsfirstp(arg0);
    func_80808DB0_bsfirstp(arg0);
    _bainvisible_entrypoint_7(arg0, 3, 1.0f, 1.0f, 0.4f);
    func_808086B0_bsfirstp(arg0, 1);
}

void func_808088A4_bsfirstp(BtIntPtr arg0)
{
    func_808086B0_bsfirstp(arg0,0x3);
    func_80807C8C_bsfirstp(arg0);
}

void func_808088D0_bsfirstp(struct player_state_s *self) {
    f32 func_80013970(f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 yaw_get(struct player_state_s *);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    s32 bs_setState(void *, s32);
    void func_80808E78_bsfirstp(BtIntPtr);
    s32 next_state = 0;
    struct anctrl_s *anctrl = func_8008D04C(self);

    func_80808E78_bsfirstp(self);
    switch (self->unk15C.word) {
        case 1:
            if (anctrl_isAt(anctrl, 0.285f)) {
                func_808086B0_bsfirstp(self, 2);
            }
            break;
        case 2:
            baphysics_set_target_yaw(self, yaw_get(self));
            if (anctrl_isAt(anctrl, 0.8f)) {
                func_808086B0_bsfirstp(self, 3);
            }
            break;
        case 3:
            if (anctrl_isStopped(anctrl)) {
                next_state = 0xCA;
            }
            break;
    }
    func_80803B58_bsfirstp(self, func_80013970(
        (func_800F0D50(anctrl_getAnimTimer(anctrl), 0.285f, 0.8f) - 0.285f)
        * (1.0f / (0.8f - 0.285f)) * 180.0f));
    bs_setState(self, next_state);
}

BsScript bsfirstp_entrypoint_34(BsScriptType arg0) {
    extern BtFnWord D_8080B5B0_bsfirstp[4];
    return (BsScript)D_8080B5B0_bsfirstp[arg0];
}

void func_80808A24_bsfirstp(struct player_state_s *arg0) {
    void func_80807BB8_bsfirstp(void *);
    void func_80808DB0_bsfirstp(void *);
    void func_80808CAC_bsfirstp(struct player_state_s *, s32);
    void func_80808D80_bsfirstp(void *);
    FirstpState *firstp;

    firstp = arg0->state_mem;
    func_80807BB8_bsfirstp(arg0);
    firstp->unk8 = -1;
    func_80808DB0_bsfirstp(arg0);
    arg0->unk160.word = 0;
    func_80808CAC_bsfirstp(arg0, 1);
    func_80800858_bsfirstp((BtIntPtr)arg0, 1);
    func_80808D80_bsfirstp(arg0);
}

void func_80808A8C_bsfirstp(void *arg0)
{
    func_80807C8C_bsfirstp(arg0);
}
void func_80808AAC_bsfirstp(BtIntPtr arg0) {
    s32 bs_setState(void *, s32);
    void func_8080633C_bsfirstp(Actor *, f32);
    void func_80808E78_bsfirstp(BtIntPtr);
    s32 func_80808B24_bsfirstp(BtIntPtr);
    void func_80808B8C_bsfirstp(struct player_state_s *);
    s32 next_state;

    func_80807D48_bsfirstp(arg0);
    func_80808E78_bsfirstp(arg0);
    func_8080633C_bsfirstp((Actor *)arg0, 1.0f);
    next_state = func_80808B24_bsfirstp(arg0);
    if (next_state != 0) {
        bs_setState((void *)arg0, next_state);
    } else {
        func_80808B8C_bsfirstp((struct player_state_s *)arg0);
    }
}

BsScript bsfirstp_entrypoint_35(BsScriptType arg0) {
    extern BtFnWord D_8080B5C0_bsfirstp[4];
    return (BsScript)D_8080B5C0_bsfirstp[arg0];
}

/* extern */

s32 func_80808B24_bsfirstp(BtIntPtr arg0) {
    s32 func_80802D50_bsfirstp(BtIntPtr, s32 *);
    s32 func_80809540_bsfirstp(BtIntPtr, s32);
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
    void func_80808CAC_bsfirstp(struct player_state_s *, s32);
    s32 temp_v0;

    if (func_80802444_bsfirstp(arg0) == 1) {
        if ((arg0->unk15C.word) >= 2) {
            (arg0->unk160.word) = 0;
            func_80808CAC_bsfirstp(arg0, 1);
        }
    } else {
        temp_v0 = (arg0->unk15C.word);
        if (temp_v0 != 0) {
            if (temp_v0 == 1) {
                (arg0->unk16C) = (f32) ((arg0->unk16C) - func_800D9004());
                if ((arg0->unk16C) < 0.0f) {
                    func_80808CAC_bsfirstp(arg0, 1);
                }
            } else if (func_80800228_bsfirstp(arg0) != 0) {
                func_80808CAC_bsfirstp(arg0, 1);
            }
        }
    }
}

void func_80808C48_bsfirstp(struct player_state_s *arg0) {
    void func_80808CAC_bsfirstp(struct player_state_s *, s32);
    void func_80808D80_bsfirstp(void *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    struct anctrl_s *func_8008D04C(struct player_state_s *);
    void func_8008B304(struct anctrl_s *);

    arg0->unk160.word = 0;
    arg0->unk16C = 5.0f;
    func_80808CAC_bsfirstp(arg0, 0);
    func_80808D80_bsfirstp(arg0);
    func_8008B304(baanim_getAnimCtrlPtr(arg0));
    func_8008B304(func_8008D04C(arg0));
}

void func_80808CAC_bsfirstp(struct player_state_s *arg0, s32 arg1) {
    struct firstp_entry_s {
        s16 anim;
        s16 flags;
        f32 duration;
    } *entry;
    BtIntPtr base;
    s32 index;

    base = func_808024DC_bsfirstp(arg0);
    index = arg0->unk160.word;
    entry = (struct firstp_entry_s *)(index * 8 + base);
    arg0->unk160.word = index + 1;
    if (arg1 != 0) {
        func_80800424_bsfirstp(arg0, entry->anim, entry->duration);
    } else {
        func_808003B4_bsfirstp(arg0, entry->anim, entry->duration);
    }
    arg0->unk15C.word = 2;
    if (entry->flags & 1) {
        func_808001FC_bsfirstp(arg0);
        arg0->unk15C.word = 0;
    }
    if (entry->flags & 2) {
        arg0->unk16C = entry->duration;
        arg0->unk15C.word = 1;
    }
    if ((++entry)->anim == 0) {
        arg0->unk160.word = entry->flags;
    }
}    typedef struct { s16 unk0; u8 pad2[0x2]; f32 unk4; } Objfirstp_func_80808D80_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80808D80_bsfirstp(void *arg0) {
    BT_IDO_ONLY(void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);)
    void *func_80802508_bsfirstp(BT_NATIVE_ONLY(void *));
    void *temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_80802508_bsfirstp(arg0);
#else
    temp_v0 = func_80802508_bsfirstp();
#endif
    baanim_playForDuration_loopSmooth(arg0, (((Objfirstp_func_80808D80_bsfirstp_temp_v0 *)temp_v0)->unk0), (((Objfirstp_func_80808D80_bsfirstp_temp_v0 *)temp_v0)->unk4));
}

void func_80808DB0_bsfirstp(void *arg0) {
    void func_80809DA0_bsfirstp(void *, s32);
    void func_808099A8_bsfirstp(void *, s32);
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    s32 mode;

    mode = func_80802444_bsfirstp(arg0);
    if (mode != firstp->unk8) {
        firstp->unk8 = mode;
        switch (func_80802444_bsfirstp(arg0)) {
            case 0:
                func_808061AC_bsfirstp(arg0, 2);
                func_80809DA0_bsfirstp(arg0, 0);
                func_8080483C_bsfirstp(arg0, 0);
                func_808099A8_bsfirstp(arg0, 1);
                break;
            case 1:
                func_808061AC_bsfirstp(arg0, 3);
                func_80809DA0_bsfirstp(arg0, -1);
                func_8080483C_bsfirstp(arg0, 1);
                func_808099A8_bsfirstp(arg0, 2);
                break;
        }
    }
}

void func_80808E78_bsfirstp(BtIntPtr arg0) {
    void func_80804848_bsfirstp(u8 *, s32);
    void func_80808DB0_bsfirstp(void *);
    void func_80809D24_bsfirstp(void *);
    void func_808099B4_bsfirstp(void *);
    void func_80808EF0_bsfirstp(BtIntPtr);
    s32 func_80802F20_bsfirstp(struct player_state_s *);
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;

    func_80804848_bsfirstp((u8 *)arg0, firstp->unkC);
    func_80801928_bsfirstp((struct player_state_s *)arg0);
    func_80801DC0_bsfirstp((u8 *)arg0);
    func_80808DB0_bsfirstp((void *)arg0);
    func_80809D24_bsfirstp((void *)arg0);
    func_8080682C_bsfirstp((void *)arg0);
    func_808099B4_bsfirstp((void *)arg0);
    func_80800830_bsfirstp(arg0);
    func_80808EF0_bsfirstp(arg0);
    func_80802F20_bsfirstp((struct player_state_s *)arg0);
}

/* extern */

void func_80808EF0_bsfirstp(BtIntPtr arg0) {
    int bakey_pressed(struct player_state_s *, int);
    void func_8009C128(struct player_state_s *, f32 *);
    s32 func_801013A8(f32 *, s32, s32);
    f32 sp18[3];

    if (bakey_pressed(arg0, 8) != 0) {
        func_8009C128(arg0, sp18 BT_IDO_ONLY(- 1));
        func_801013A8(sp18 BT_IDO_ONLY(- 1), 0x6F, (((PlayerState *)arg0)->unk184));
    }
}    typedef struct { u8 pad0[0x10C]; f32 unk10C; } Objfirstp_func_80808F38_bsfirstp_state; /* offsets.py genstruct: fields from raw offsets on state; rename once understood */

void func_80808F38_bsfirstp(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void func_8008E944(PlayerState *);
    void func_8009C128(PlayerState *, f32 *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void baphysics_set_gravity(PlayerState *, f32);
    void yaw_applyIdeal(PlayerState *);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_14();
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_15();
    void _bababykaz_entrypoint_14(PlayerState *);
    s32 func_800D3948(void);
    s32 func_800F7F98(BtIntPtr, u32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_8080911C_bsfirstp(PlayerState *, s32);
    extern f32 D_8080A650_bsfirstp[6][5];
    s32 *state = *(s32 **)((u8 *)arg0 + 0x188);
    volatile s32 index = 0;
    f32 yaw[2];
    f32 pos[3];
    f32 unused;
    f32 *params;

    if (func_800D3948() && _gcstatusDll_entrypoint_14() == 5 &&
        _gcstatusDll_entrypoint_15() != arg0->unk184) {
        index = 1;
    }
    func_8008E944(arg0);
    func_800F7F98(arg0->unk184, 1);
    _bababykaz_entrypoint_14(arg0);
    if (index == 0) {
        if (state[0xEC / 4] == 0x45) {
            index = 2;
        } else {
            switch (state[0xF4 / 4]) {
                default:
                case 1:
                    index = 3;
                    break;
                case 2:
                    index = 4;
                    break;
                case 4:
                    index = 5;
                    break;
            }
        }
    }
    func_8009C128(arg0, pos);
    func_800F1E6C((f32 *)state + 0xF8 / 4, pos, yaw);
    params = D_8080A650_bsfirstp[index];
    baphysics_set_target_horizontal_velocity(arg0, params[0]);
    baphysics_set_target_yaw(arg0, yaw[0]);
    baphysics_set_horizontal_velocity(arg0, yaw[0], params[0]);
    baphysics_set_vertical_velocity(arg0, params[1]);
    baphysics_set_gravity(arg0, params[2]);
    ((Objfirstp_func_80808F38_bsfirstp_state *)state)->unk10C = params[3];
    func_8080911C_bsfirstp(arg0, 0);
    yaw_applyIdeal(arg0);
}

/* extern */

void func_808090D8_bsfirstp(void *arg0) {
    s32 func_800F7F98(BtIntPtr, u32);
    void func_80808DB0_bsfirstp(void *);
    FirstpState *firstp = ((PlayerState *)arg0)->state_mem;
    firstp->unk8 = -1;
    func_80808DB0_bsfirstp(arg0);
    func_8008E95C(arg0);
    func_800F7F98(((Objfirstp_arg0 *)arg0)->unk184, 0);
}

void func_8080911C_bsfirstp(struct player_state_s *arg0, s32 arg1) {
    void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    FirstpState *firstp;

    firstp = arg0->state_mem;
    switch (arg1) {
        case 0:
            func_8009FFD8(arg0, 1, 1, 2, 3);
            break;
        case 1:
            func_8009FFD8(arg0, 1, 0, 0, 0x10);
            break;
    }
    firstp->unk108 = arg1;
}



void func_80809198_bsfirstp(void *arg0) {
    void func_8080633C_bsfirstp(Actor *actor, f32 speed);
    struct firstp_state { u8 pad[0x104]; s32 index; s32 state; f32 timer; } *ptr;
    f32 speed;

    ptr = *(struct firstp_state **)((u8 *)arg0 + 0x188);
    switch (ptr->state) {
        case 0:
            if (func_800F1574(&ptr->timer, func_800D9004())) {
                func_8080911C_bsfirstp(arg0, 1);
            }
            break;
        case 1:
            if (func_8009E674(arg0, 4)) {
                speed = 0.0f;
            } else {
                speed = D_8080A650_bsfirstp[ptr->index][4];
            }
            func_8080633C_bsfirstp(arg0, speed);
            break;
    }
}

void func_80809250_bsfirstp(void *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_getIndex(struct anctrl_s *);
    BtIntPtr func_800D674C(s32);
    void func_800E0050(s16 *, f32, s32, f32 *);
    void func_8009C128(struct player_state_s *, f32[3]);
    f32 yaw_get(struct player_state_s *);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void _ncba1p_entrypoint_6(struct player_state_s *, f32[3]);
    void _ncba1p_entrypoint_7(struct player_state_s *, f32[3]);
    struct { f32 x, y, z, unused[6]; } animation;
    struct anctrl_s *ctrl;
    f32 timer;
    f32 yaw;
    f32 rotation[4];
    f32 position[3];
    FirstpConfig *ptr;

    ctrl = baanim_getAnimCtrlPtr(arg0);
    timer = anctrl_getAnimTimer(ctrl);
    func_800E0050(func_800D674C(anctrl_getIndex(ctrl)), timer, 3, &animation.x);
    ptr = func_80802484_bsfirstp(arg0);
    func_8009C128(arg0, position);
    position[1] += ((f32 *)ptr)[2];
    rotation[0] = -animation.x;
    yaw = yaw_get(arg0);
    rotation[1] = yaw + animation.y + 180.0f;
    rotation[2] = animation.z;
    _ncba1p_entrypoint_6(func_800A4CA8(arg0), position);
    _ncba1p_entrypoint_7(func_800A4CA8(arg0), rotation);
}

/* extern */

void func_80809684_bsfirstp(struct player_state_s *arg0, s32 arg1);

void func_80809334_bsfirstp(void *arg0) {
    void func_80807BB8_bsfirstp(void *);
    void func_80808DB0_bsfirstp(void *);
    void func_80809900_bsfirstp(void *);
    func_80807BB8_bsfirstp(arg0);
    func_80808DB0_bsfirstp(arg0);
    func_80809900_bsfirstp(arg0);
    func_80800858_bsfirstp((BtIntPtr)arg0, 1);
    func_80809684_bsfirstp(arg0, 0);
}

void func_80809384_bsfirstp(void *arg0)
{
    func_80807C8C_bsfirstp(arg0);
}
void func_808093A4_bsfirstp(struct player_state_s *arg0) {
    s32 bs_setState(void *, s32);
    void func_8080633C_bsfirstp(Actor *, f32);
    void func_80808E78_bsfirstp(BtIntPtr);
    s32 func_808094A4_bsfirstp(BtIntPtr);
    s32 func_80809540_bsfirstp(BtIntPtr, s32);
    void func_80809740_bsfirstp(struct player_state_s *);
    FirstpState *firstp;
    s32 sp20;

    firstp = arg0->state_mem;
    func_80807D48_bsfirstp((BtIntPtr)arg0);
    func_80808E78_bsfirstp((BtIntPtr)arg0);
    func_8080633C_bsfirstp((Actor *)arg0, 1.0f);
    sp20 = func_808094A4_bsfirstp((BtIntPtr)arg0);
    if (sp20 == 0) {
        switch (func_80809540_bsfirstp((BtIntPtr)arg0, firstp->unk218)) {
            case 0:
                sp20 = 0xCA;
                break;
            case 1:
                if (firstp->unk218 != 1) {
                    func_80809684_bsfirstp(arg0, 1);
                }
                break;
            case 2:
                if (firstp->unk218 != 2) {
                    func_80809684_bsfirstp(arg0, 2);
                }
                break;
        }
        func_80809740_bsfirstp(arg0);
    }
    if (sp20 != 0) {
        bs_setState(arg0, sp20);
    }
}

BsScript bsfirstp_entrypoint_36(BsScriptType arg0) {
    extern BtFnWord D_8080B5D0_bsfirstp[4];
    return (BsScript)D_8080B5D0_bsfirstp[arg0];
}

/* extern */

s32 func_808094A4_bsfirstp(BtIntPtr arg0) {
    s32 func_80802D50_bsfirstp(BtIntPtr, s32 *);
    s32 sp1C;

    if (func_80802D50_bsfirstp(arg0, &sp1C) != 0) {
        return sp1C;
    }
    if (func_80808630_bsfirstp(arg0) != 0) {
        return 0xD2;
    }
    return 0;
}

s32 func_808094F4_bsfirstp(BtIntPtr arg0) {
    s32 func_80809540_bsfirstp(BtIntPtr, s32);
    s32 temp_v0;

    temp_v0 = func_80809540_bsfirstp(arg0, 1);
    switch (temp_v0) {
    case 0:
        return 0xCA;
    case 1:
    case 2:
        return 0xD1;
    default:
        return 0;
    }
}    typedef struct { u8 pad0[0x1CC]; f32 unk1CC; } Objfirstp_func_80809540_bsfirstp_sp34; /* offsets.py genstruct: fields from raw offsets on sp34; rename once understood */

s32 func_80809540_bsfirstp(BtIntPtr arg0, s32 arg1)
{
  f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
  f32 mlAbsF(f32);
  void *sp34;
  f32 *sp30;
  f32 sp2C;
  f32 velocity;
  f32 sp24;
  f32 absolute;
  f32 sp1C;
  sp34 = *((void **) (arg0 + 0x188));
  sp30 = func_808024B0_bsfirstp((void *) arg0);
  sp2C = func_8080613C_bsfirstp((void *) arg0);
  velocity = baphysics_get_target_horizontal_velocity((struct player_state_s *) arg0);
  sp24 = ((Objfirstp_func_80809540_bsfirstp_sp34 *)sp34)->unk1CC;
  sp1C = mlAbsF(velocity);
  absolute = mlAbsF(sp24);
  switch (arg1)
  {
    case 0:
      if ((absolute + sp1C) > 0.0f)
    {
      return 1;
    }
      break;

    case 1:
      if (((absolute + sp1C) == ((0, 0.0f))) && (sp2C < sp30[0]))
    {
      return 0;
    }
      if ((sp30[1] * 1.05f) < sp2C)
    {
      return 2;
    }
      break;

    case 2:
      if (sp2C < (sp30[1] * 0.95f))
    {
      return 1;
    }
      break;

  }

  return arg1;
}    typedef struct { u8 pad0[0x218]; s8 unk218; u8 pad219[0x3]; f32 unk21C; f32 unk220; f32 unk224; f32 unk228; } Objfirstp_func_80809684_bsfirstp_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

void func_80809684_bsfirstp(struct player_state_s *arg0, s32 arg1) {
    f32 *sp28[2];
    struct {
        s16 unk0;
        f32 unk4;
        f32 unk8;
    } *sp24;
    void *temp_s0;

    temp_s0 = arg0->state_mem;
    sp28[0] = func_808024B0_bsfirstp(arg0);
    ((Objfirstp_func_80809684_bsfirstp_temp_s0 *)temp_s0)->unk218 = arg1;
    switch (arg1) {
        case 0:
            return;
        case 1:
            sp24 = func_80802560_bsfirstp(arg0);
            break;
        case 2:
            sp24 = func_80802594_bsfirstp(arg0);
            break;
    }
    func_80800290_bsfirstp(arg0, sp24->unk0, sp24->unk4);
    ((Objfirstp_func_80809684_bsfirstp_temp_s0 *)temp_s0)->unk21C = sp24->unk4;
    ((Objfirstp_func_80809684_bsfirstp_temp_s0 *)temp_s0)->unk220 = sp24->unk8;
    ((Objfirstp_func_80809684_bsfirstp_temp_s0 *)temp_s0)->unk224 = sp28[0][0];
    ((Objfirstp_func_80809684_bsfirstp_temp_s0 *)temp_s0)->unk228 = sp28[0][1];
}

void func_80809740_bsfirstp(struct player_state_s *arg0) {
    s32 func_800EA068(s32);
    f32 func_800F0D50(f32, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B188(struct anctrl_s *, s32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_800A2CE8(struct player_state_s *, f32, s32);
    s32 pad4C;
    struct anctrl_s *sp48;
    f32 sp3C[3];
    f32 progress;
    f32 pad;
    f32 start;
    f32 end;
    FirstpState *firstp;

    firstp = arg0->state_mem;
    sp48 = baanim_getAnimCtrlPtr(arg0);
    func_80806148_bsfirstp(arg0, sp3C);
    if (sp3C[2] >= 0.0f) {
        firstp->unk219 = 1;
    } else {
        firstp->unk219 = 0;
    }
    func_8008B188(sp48, firstp->unk219);
    progress = func_8080613C_bsfirstp(arg0);
    switch (firstp->unk218) {
        case 0:
            start = 0.0f;
            end = firstp->unk224;
            break;
        case 1:
            start = firstp->unk224;
            end = firstp->unk228;
            break;
        case 2:
            start = firstp->unk228;
            end = 1.0f;
            break;
    }
    if (start != end) {
        progress = func_800F0D50((progress - start) / (end - start), 0.0f, 1.0f);
    } else {
        progress = 1.0f;
    }
    start = firstp->unk21C;
    end = firstp->unk220;
    anctrl_setDuration(sp48, (end - start) * progress + start);
    if (!func_800EA068(0x20)) {
        switch (firstp->unk218) {
            case 1:
                func_800A2CE8(arg0, 0.45f, 4);
                func_800A2CE8(arg0, 0.9f, 3);
                break;
            case 2:
                func_800A2CE8(arg0, 0.45f, 4);
                func_800A2CE8(arg0, 0.95f, 3);
                break;
        }
    }
}

/* extern */

void func_80809900_bsfirstp(void *arg0) {
    void func_80800424_bsfirstp(struct player_state_s *, s32, f32);
    func_80800424_bsfirstp(arg0, func_80802534_bsfirstp(arg0), 1.0f);
    func_808001FC_bsfirstp(arg0);
}

f32 func_80809938_bsfirstp(void *arg0) {
    FirstpState *firstp;
    f32 result;

    firstp = ((PlayerState *)arg0)->state_mem;
    result = (1.0f / firstp->unk230) * firstp->unk24C;
    return result;
}

/* extern */

void func_8080995C_bsfirstp(u8 *arg0) {
    void *func_80802458_bsfirstp(void *);
    struct {
        s32 pad;
        u8 *data;
    } local;

    local.data = ((Objfirstp_arg0 *)arg0)->unk188_u8p;
    bcopy((u8 *)func_80802458_bsfirstp(arg0) + 0x74, local.data + 0x230, 0x18);
    *(s16 *)(local.data + 0x248) = 0;
    *(f32 *)(local.data + 0x24C) = 0.0f;
    *(f32 *)(local.data + 0x250) = 0.0f;
}    typedef struct { u8 pad0[0x248]; s16 unk248; } Objfirstp_func_808099A8_bsfirstp_state; /* offsets.py genstruct: fields from raw offsets on state; rename once understood */

void func_808099A8_bsfirstp(void *arg0, s32 arg1) {
    void *state = ((Objfirstp_arg0 *)arg0)->unk188;
    ((Objfirstp_func_808099A8_bsfirstp_state *)state)->unk248 = arg1;
}

void func_808099B4_bsfirstp(void *arg0) {
    void func_80809A10_bsfirstp(void *);
    void func_80809A7C_bsfirstp(void *);
    FirstpState *firstp;
    s16 state;

    firstp = ((PlayerState *)arg0)->state_mem;
    state = firstp->unk248;
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
    void func_80809AF8_bsfirstp(void *, f32, f32, f32);
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

    temp_v0 = ((Objfirstp_arg0 *)arg0)->unk188;
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
    void func_80809AF8_bsfirstp(void *, f32, f32, f32);
    FirstpState *firstp;
    f32 temp_a1;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_a1 = func_800F122C(-(firstp->unkC0), 5.0f, (firstp->unk234));
    func_80809AF8_bsfirstp(arg0, temp_a1,
        (firstp->unkC0) != 0.0f
            ? (firstp->unk23C)
            : (firstp->unk244),
        (firstp->unk234));
}

/* extern */

void func_80809AF8_bsfirstp(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800136E4(f32);
    f32 yaw_get(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_set(struct player_state_s *, f32);
    struct { u8 pad[0x24C]; f32 values[2]; } *state[1];
    f32 step;
    f32 dt;
    f32 first;
    f32 rest;
    f32 total;
    f32 angle;
    f32 *value;

    state[0] = (void *)((PlayerState *)arg0)->state_mem;
    step = 0.033333335f;
    dt = func_800D9004() - step;
    value = &state[0]->values[0];
    first = func_808057C8_bsfirstp(value, arg1, arg3, step, arg2);
    if (dt != 0.0f) {
        rest = func_808057C8_bsfirstp(value, arg1, arg3, dt, arg2);
    } else {
        rest = 0.0f;
    }
    func_808052A4_bsfirstp(&rest, &state[0]->values[1]);
    total = first + rest;
    angle = yaw_get(arg0);
    angle = func_800136E4(angle + total);
    yaw_setIdeal(arg0, angle);
    yaw_set(arg0, angle);
}

void bsfirstp_entrypoint_37(void *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    int func_800A4C68(void *);
    s32 func_800A89F8();
    void func_80809C30_bsfirstp(void * BT_PASS2(, s32) BT_PASS2(, s32));
    s32 state;

    state = func_800A89F8();
    if (func_800A4C68(arg0) == state) {
        func_80809C30_bsfirstp(arg0 BT_PASS2(, bt_a1) BT_PASS2(, bt_a2));
    }
}

/* extern */

void func_80809C30_bsfirstp(void *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    s32 func_8009239C(u8 **);
    u32 func_800936F4(void *);
    s32 func_80093DF4(void *, s32);
    s32 func_80093E18(void *, s32 *);
    s32 *func_800A7180(void);
    if ((func_80093DF4(arg0, 2) != 0) && (func_800936F4(arg0) != 0) && (func_8009239C(arg0) != 0)) {
        func_80093E18(arg0, func_800A7180());
    }
}

void func_80809C90_bsfirstp(BtIntPtr arg0) {
    void func_8009ADF0(void *arg0, s32 arg1, s32 arg2);
    func_8009ADF0(arg0, 0xB, 1);
}

void func_80809CB4_bsfirstp(u8 *arg0) {
    void func_8009ADF0(void *arg0, s32 arg1, s32 arg2);
    func_8009ADF0(arg0, 0xB, 0);
}

#ifdef BT_NATIVE
void func_80809CD8_bsfirstp(PlayerState *bt_a0)
#else
void func_80809CD8_bsfirstp()
#endif
{
    void func_80809CF8_bsfirstp(BT_NATIVE_ONLY(void *));
    func_80809CF8_bsfirstp(BT_NATIVE_ONLY(bt_a0));
}

void func_80809CF8_bsfirstp(void *arg0) {
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    firstp->unk29C = 162.5f;
    firstp->unk2A0 = 8.0f;
    firstp->unk264 = 0;
    firstp->unk25C = 0.0f;
}

void func_8080A194_bsfirstp(void *arg0);
void func_8080A250_bsfirstp(void *arg0);
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
    FirstpState *firstp;
    firstp = ((PlayerState *)arg0)->state_mem;
    result = 0;
    return firstp->unk254 == 1 ? 1 : result;
}    typedef struct { u8 pad0[0x25C]; f32 unk25C; } Objfirstp_func_80809D94_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

f32 func_80809D94_bsfirstp(void *arg0) {
    void *temp_v0;

    temp_v0 = BT_DATA_FIELD(((PlayerState *)arg0)->state_mem, ((Objfirstp_arg0 *)arg0)->unk188);
    return BT_DATA_FIELD(((FirstpState *)temp_v0)->unk25C, *&((Objfirstp_func_80809D94_bsfirstp_temp_v0 *)temp_v0)->unk25C);
}

void func_80809DA0_bsfirstp(void *arg0, s32 arg1) {
    FirstpState *firstp;

    firstp = ((PlayerState *)arg0)->state_mem;
    if (arg1 == 0) {
        if ((firstp->unk254) < 0) {
            (firstp->unk254) = arg1;
            (firstp->unk258) = 0;
        }
    } else {
        (firstp->unk254) = arg1;
        (firstp->unk258) = 0;
    }
}

void func_80809DD0_bsfirstp(void *arg0) {
    f32 mlAbsF(f32);
    FirstpState *firstp;
    s32 var_v1;
    f32 var_f14;
    f32 sp18;

    firstp = ((PlayerState *)arg0)->state_mem;
    var_v1 = 0;
    if (firstp->unkA0 == 1) {
        var_f14 = firstp->unkC4;
    } else {
        var_v1 = firstp->unk10;
        var_f14 = firstp->unk180;
    }
    switch (var_v1) {
    case 0:
        firstp->unk254 = 0;
        break;
    case 1:
        sp18 = mlAbsF(firstp->unk148);
        if (mlAbsF(var_f14) > 0.01f) {
            if (sp18 > 0.5f) {
                firstp->unk258 = 1;
            } else {
                firstp->unk258 = 0;
            }
            firstp->unk254 = 0;
        } else if (firstp->unk254 == 0) {
            if (firstp->unk258 != 0) {
                if (sp18 < 0.25f) {
                    firstp->unk254 = 1;
                }
            } else if (sp18 > 0.75f) {
                firstp->unk254 = 1;
            }
        }
        break;
    }
}

/* extern */

s32 *func_80809EF8_bsfirstp(f32 *arg0, f32 *arg1, f32 *arg2) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp1C[3];

    func_800EE7F8(sp1C, arg0);
    sp1C[1] += 300.0f;
    func_800EE7F8(arg1, arg0);
    arg1[1] += -300.0f;
    BT_NATIVE_ONLY(return) func_800BEF00(sp1C, arg1, arg2, 0x08020020);
}    typedef struct { u8 pad0[0x18]; s32 unk18; f32 unk1C; } Objfirstp_func_80809F74_bsfirstp_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */ typedef struct { u8 pad0[0x18]; s32 unk18; f32 unk1C; } Objfirstp_func_80809F74_bsfirstp_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

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
    BtIntPtr temp_v0;
    BtIntPtr temp_v0_2;

    sp44[0] = (*(s32 *)((s8 *)(arg0) + (0x188)));
    sp20 = func_80096628(arg0);
    sp24 = yaw_get(arg0);
    func_800963C0(arg0, sp34);
    if ((func_800F1B78(sp28, sp34, sp24, 1.0f) != 0) && !(sp20 & 0x08000000)) {
        temp_v0 = sp44[0] + 0x254;
        (((Objfirstp_func_80809F74_bsfirstp_temp_v0 *)temp_v0)->unk1C) = -sp28[0];
        if (sp20 & 0x10000000) {
            (((Objfirstp_func_80809F74_bsfirstp_temp_v0 *)temp_v0)->unk18) = 3;
            return;
        }
        (((Objfirstp_func_80809F74_bsfirstp_temp_v0 *)temp_v0)->unk18) = 1;
        return;
    }
    temp_v0_2 = sp44[0] + 0x254;
    (((Objfirstp_func_80809F74_bsfirstp_temp_v0_2 *)temp_v0_2)->unk1C) = 0.0f;
    if (sp20 & 0x10000000) {
        (((Objfirstp_func_80809F74_bsfirstp_temp_v0_2 *)temp_v0_2)->unk18) = 2;
        return;
    }
    (((Objfirstp_func_80809F74_bsfirstp_temp_v0_2 *)temp_v0_2)->unk18) = 0;
}    typedef struct { u8 pad0[0x14]; s32 unk14; u8 pad18[0x8]; f32 unk20; u8 pad24[0x8]; s32 unk2C; u8 pad30[0x8]; f32 unk38; u8 pad3C[0x8]; f32 unk44; u8 pad48[0x8]; s32 unk50; u8 pad54[0x248]; f32 unk29C; } Objfirstp_func_8080A03C_bsfirstp_state; /* offsets.py genstruct: fields from raw offsets on state; rename once understood */

int func_8080A03C_bsfirstp(void *arg0) {
    f32 func_80013728(f32);
    f32 func_80013788(void);
    f32 func_800137F4(f32);
    f32 func_80013B7C(f32, f32);
    void func_800EE7B4(f32[3], f32[3], f32[3], f32);
    f32 func_800EEFFC(void *);
    f32 func_800EF030(void *);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F0DC0(f32, f32);
    void func_800F3BB0(struct player_state_s *, f32[3]);
    f32 yaw_get(struct player_state_s *);
    void *sp6C[1];
    f32 sp5C[4];
    f32 sp50[3];
    f32 sp4C;
    s32 *hit;
    BtIntPtr sp44;
    f32 sp38[3];
    register f32 *start;
    register void *state;

    sp6C[0] = ((Objfirstp_arg0 *)arg0)->unk188;
    func_800F3BB0(arg0, sp5C);
    state = sp6C[0];
    sp4C = ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk29C;
    state = (u8 *)state + 0x254;
    sp50[0] = func_800137F4(yaw_get(arg0));
    sp50[1] = 0.0f;
    sp50[2] = func_80013788();
    hit = &((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk2C;
    sp44 = (BtIntPtr)((u8 *)state + 0x38);
    start = &((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk20;
    func_800EE7B4(start, sp5C, sp50, sp4C);
    hit = func_80809EF8_bsfirstp(start, (f32 *)hit, (f32 *)sp44);
    if (hit != 0) {
        sp44 = hit[2] & 0x10000000;
        ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk14 = 1;
        if (func_800EF030(&((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk38) > 0.01f) {
            if (sp44 != 0) {
                ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk50 = 3;
            } else {
                ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk50 = 1;
            }
        } else if (sp44 != 0) {
            ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk50 = 2;
        } else {
            ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk50 = 0;
        }
    } else {
        ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk14 = 0;
        ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk50 = 0;
    }
    func_800EFB24(sp38, (f32 *)((u8 *)state + 0x2C), sp5C);
    sp4C = func_800EEFFC(sp38);
    sp4C = func_80013B7C(sp38[1], sp4C);
    sp4C = func_80013728(sp4C);
    ((Objfirstp_func_8080A03C_bsfirstp_state *)state)->unk44 = func_800F0DC0(sp4C, 30.0f);
BT_NATIVE_ONLY(return 0;) }

void func_8080A194_bsfirstp(void *arg0) {
    int temp_a0;
    s32 temp_a1;
    int temp_a3;
    s32 temp_v1;
    int var_a2;
    FirstpState *firstp;
    s32 *temp_v1_2;

    firstp = ((PlayerState *)arg0)->state_mem;
    temp_v1 = (firstp->unk26C);
    temp_a1 = (firstp->unk2A4);
    var_a2 = temp_v1 == 3 || temp_v1 == 2;
    temp_a3 = temp_v1 == 3;
    temp_v1_2 = &firstp->unk254;
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

void func_8080A250_bsfirstp(void *arg0) {
    FirstpState *firstp;
    s32 *state;
    s32 current;
    firstp = ((PlayerState *)arg0)->state_mem;
    state = &firstp->unk254;
    switch (state[3]) {
        case 0:
            ((f32 *)state)[19] *= 0.5f;
            if (((f32 *)state)[19] < 1.0f) {
                ((f32 *)state)[19] = 1.0f;
            }
            break;
        case 1:
            break;
        default:
            ((f32 *)state)[19] *= 2.0f;
            if (((f32 *)state)[19] > 32.0f) {
                ((f32 *)state)[19] = 32.0f;
            }
            break;
    }
    if (state[5] != 0) {
        ((f32 *)state)[18] += ((f32 *)state)[19];
        if (((f32 *)state)[18] > 300.0f) {
            ((f32 *)state)[18] = 300.0f;
        }
    } else {
        ((f32 *)state)[18] -= 8.0f;
        if (((f32 *)state)[18] < 25.0f) {
            ((f32 *)state)[18] = 25.0f;
        }
    }
    current = state[5];
    if (current == state[4]) {
        state[3]++;
    } else {
        state[3] = 0;
        state[4] = current;
    }
    if (state[3] >= 5 && state[5] == 0) {
        ((f32 *)state)[18] = 25.0f;
    }
}
#include "firstp_data.inc"

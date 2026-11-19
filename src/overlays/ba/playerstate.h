#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include <ultra64.h>

#include "buttons.h"

typedef struct ba_unknown_c_s {
    u8 pad0[0xC];
    s32 unkC[3];
    s32 unk18;
} BaUnknownC;

typedef struct ba_unknown_2C_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} BaUnknown2C;

typedef struct { u8 mode, index, flags, cycle; } PlayerEggSelection;

typedef struct player_state_s {
    /* 0x00 */ struct ba_alarm_s *alarm;
    /* 0x04 */ struct ba_anim_s *anim;
    /* 0x08 */ struct ba_attach_s *attach;
    /* 0x0C */ struct ba_unknown_c_s *unkC; // baavatar? from BK XBox debug strings?
    /* 0x10 */ struct ba_babykaz_s *babykaz;
    /* 0x14 */ struct ba_backpack_s *backpack;
    f32 * unk18;
    /* 0x1C */ struct ba_bee_s *bee;
    /* 0x20 */ struct ba_unknown_20_s *unk20;
    /* 0x24 */ struct ba_boost_s *boost;
    /* 0x28 */ struct ba_bounce_s *bounce;
    /* 0x2C */ struct ba_unknown_2C_s *unk2C; //something with camera
    s32 unk30;
    /* 0x34 */ struct ba_buzz_s *buzz;
    u8 pad38[0x4];
    /* 0x3C */ struct ba_state_timer_list_s *state_timer; // clock?
    /* 0x40 */ struct ba_key_s *key; // controller?
    /* 0x44 */ struct ba_cough_s *cough;
    u8 pad48[0xC];
    /* 0x54 */ struct ba_drone_s *drone;
    union {
        u8 pad58[0x28];
        struct { u8 pad[0xC]; PlayerEggSelection *slot; } eggSelection;
    };
    /* 0x80 */ struct ba_flag_s *flag;
    u8 pad84[0x8]; f32 unk8C; u8 pad90[0x4]; f32 ** unk94; f32 * unk98;
    /* 0x9C */ struct ba_unk_9C* unk9C;
    f32 * unkA0;
    /* 0xA4 */ struct ba_input_s *input;
    u8 padA8[0x18];
    /* 0xC0 */ struct ba_unknown_C0_s *unkC0; // 1E72EA0
    u8 padC4[0x4]; s32 unkC8; u8 padCC[0x10]; f32 * unkDC; u8 padE0[0x4]; f32 * unkE4; u8 padE8[0x8]; u8 * unkF0;
    /* 0xF4 */ struct ba_roll_s *roll;
    /* 0xF8 */ struct ba_yaw_s *yaw;
    s32 * unkFC; u8 pad100[0x4]; u8 * unk104; u8 * unk108; u8 pad10C[0x8]; u8 pad114[0x4]; u8 pad118[0x8];
    /* 0x120 */ struct bs_state_s *state;
    s32 * unk124;
    /* 0x128 */ struct ba_stick_s *stick;
    s32 * unk12C; u8 pad130[0x8]; u8 * unk138;
    /* 0x13C */ struct ba_timer_s *timer;
    /* 0x140 */ struct ba_translate_s *translate;
    /* 0x144 */ struct ba_van_s *van;
    /* 0x148 */ struct ba_wandglow_s *wandglow;
    /* 0x14C */ struct ba_washer_s *washer;
    u8 * unk150;
    /* 0x154 */ struct ba_wobble_s *wobble;
    s32 unk158;
    union {
        s32 word;
        u8 bytes[4];
    } unk15C; // Some sort of state
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    union {
        s32 word;
        u8 bytes[4];
    } unk164;
    union {
        s32 word;
        u8 bytes[4];
    } unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x4]; s32 unk17C; u8 pad180[0x4];
    s32 unk184;
    /* 0x188 */ union {
        void *state_mem; // per-state memory, see bastatemem_entrypoint_0
        struct bs_kazfly_s *kazfly;
    };
} PlayerState;
#ifndef BT_NATIVE
typedef char bt_assert_player_state[(sizeof(PlayerState) == 0x18C) ? 1 : -1];
#endif

#endif

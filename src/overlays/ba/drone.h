#ifndef __BA_DRONE_H__
#define __BA_DRONE_H__

#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/bs/state.h"

typedef void (*BaDroneCallback)(uintptr_t context, s32 player_index, PlayerState *self);

typedef struct ba_drone_s {
    u8 type;
    u8 pending_type;
    u8 pad2[2];
    u8 unk4;
    u8 unk5;
    u8 pad6[2];
    f32 unk8;
    f32 unkC;
    f32 destination[3];
    BaDroneCallback callback;
    uintptr_t callback_context;
    f32 look_at[3];
    u8 unk30;
    u8 pad31[3];
    f32 target[3];
    f32 unk40;
    f32 unk44;
    Unk80132ED0 *marker;
} BaDrone;

extern s32 _badrone_entrypoint_3(PlayerState *self);
extern void _badrone_entrypoint_4(PlayerState *self);
#ifdef BT_NATIVE
extern void _badrone_entrypoint_11(PlayerState *, BaDroneCallback, uintptr_t);
#else
extern void _badrone_entrypoint_11(PlayerState*, void*, s32);
#endif
extern BanjoStateId _badrone_entrypoint_23(PlayerState *self, f32[3]);
extern BanjoStateId _badrone_entrypoint_24(PlayerState *self);
extern BanjoStateId _badrone_entrypoint_25(PlayerState *self);
s32 _badrone_entrypoint_30(PlayerState *self);
void _badrone_entrypoint_10(PlayerState *, s32);
void _badrone_entrypoint_12(PlayerState *, s32);
void _badrone_entrypoint_13(PlayerState *, f32[3]);
void _badrone_entrypoint_14(PlayerState *, f32[3], f32);
void _badrone_entrypoint_15(PlayerState *, f32[3], f32);
void _badrone_entrypoint_16(PlayerState *, f32[3], f32);

#ifdef BT_NATIVE
s32 _badrone_entrypoint_0(void);
u8 _badrone_entrypoint_1(PlayerState *);
void _badrone_entrypoint_2(PlayerState *, f32[3]);
void _badrone_entrypoint_5(PlayerState *);
void _badrone_entrypoint_6(PlayerState *);
u32 _badrone_entrypoint_7(PlayerState *);
void _badrone_entrypoint_8(PlayerState *, f32[3], f32 *, f32 *);
u32 _badrone_entrypoint_9(PlayerState *);
BanjoStateId _badrone_entrypoint_17(PlayerState *);
BanjoStateId _badrone_entrypoint_18(PlayerState *, Unk80132ED0 *);
BanjoStateId _badrone_entrypoint_19(PlayerState *);
BanjoStateId _badrone_entrypoint_20(PlayerState *, f32[3], s32);
BanjoStateId _badrone_entrypoint_21(PlayerState *);
BanjoStateId _badrone_entrypoint_22(PlayerState *, f32[3]);
BanjoStateId _badrone_entrypoint_26(PlayerState *);
BanjoStateId _badrone_entrypoint_27(PlayerState *);
BanjoStateId _badrone_entrypoint_28(PlayerState *);
BanjoStateId _badrone_entrypoint_29(PlayerState *);
s32 _badrone_entrypoint_31(PlayerState *);
void _badrone_entrypoint_32(PlayerState *);
void _badrone_entrypoint_33(PlayerState *, f32[3]);
#endif

#endif // __BA_DRONE_H__

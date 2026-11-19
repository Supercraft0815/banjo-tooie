#include "core2/actor_movement.h"

s32 func_8010B040(Actor *, f32 *, s32, s32);
s32 func_8010AFF8(Actor *, f32 *, s32, s32);
s32 func_8010B910(Actor *, f32 *, s32, s32);
s32 func_8010B8A4(Actor *, f32 *, s32, s32);
s32 func_8010B088(Actor *, f32 *, s32, s32);
s32 func_8010B0E0(Actor *, f32 *, s32, s32);
s32 func_8010B94C(Actor *, f32 *, s32, s32);
s32 func_8010B13C(Actor *, f32 *, s32, s32);
s32 func_8010B190(Actor *, f32 *, s32, s32);
s32 func_8010B800(Actor *, f32 *, s32, s32);
s32 _subaddierouteDll_entrypoint_8(Actor *, f32 *, s32, s32);
s32 _subaddierouteDll_entrypoint_9(Actor *, f32 *, s32, s32);
s32 func_8010BDB0(Actor *, f32 *, s32, s32);
s32 func_8010C100(Actor *, f32 *, s32, s32);
s32 func_8010B1F4(Actor *, f32 *, s32, s32);
s32 func_8010B69C(Actor *, f32 *, s32, s32);
s32 func_8010B71C(Actor *, f32 *, s32, s32);
s32 func_8010B410(Actor *, f32 *, s32, s32);
s32 func_8010B514(Actor *, f32 *, s32, s32);
s32 func_8010B330(Actor *, f32 *, s32, s32);
s32 func_8010A980(Actor *, f32 *, s32, s32);
s32 func_8010AAC0(Actor *, f32 *, s32, s32);
s32 func_8010ACE0(Actor *, f32 *, s32, s32);
s32 func_8010AD4C(Actor *, f32 *, s32, s32);
s32 func_8010AE30(Actor *, f32 *, s32, s32);
s32 func_8010AE9C(Actor *, f32 *, s32, s32);
s32 func_8010AF8C(Actor *, f32 *, s32, s32);

ActorMovementMethod D_80124690[10] BT_DATA(4, actor_movement_methods, 0x0) = {
    NULL, func_8010B040, func_8010AFF8, func_8010B910,
    func_8010B8A4, func_8010B088, func_8010B0E0, func_8010B94C,
    func_8010B13C, func_8010B190,
};

ActorMovementMethod D_801246B8[5] BT_DATA(4, actor_movement_methods, 0x28) = {
    NULL, func_8010B800, NULL, _subaddierouteDll_entrypoint_8,
    _subaddierouteDll_entrypoint_9,
};

ActorMovementMethod D_801246CC[3] BT_DATA(4, actor_movement_methods, 0x3c) = {
    NULL, func_8010BDB0, func_8010C100,
};

ActorMovementMethod D_801246D8[7] BT_DATA(4, actor_movement_methods, 0x48) = {
    NULL, func_8010B1F4, func_8010B69C, func_8010B71C,
    func_8010B410, func_8010B514, func_8010B330,
};

ActorMovementMethod D_801246F4[8] BT_DATA(4, actor_movement_methods, 0x64) = {
    NULL, func_8010A980, func_8010AAC0, func_8010ACE0,
    func_8010AD4C, func_8010AE30, func_8010AE9C, func_8010AF8C,
};

ActorMovementMethod *D_80124714[7] BT_DATA(4, actor_movement_methods, 0x84) = {
    D_80124690, D_801246CC, D_801246B8, D_801246D8,
    NULL, D_801246F4, NULL,
};

#include "overlays/bs/drone/bubbled.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/data.h"
#include "core2/1E72EA0.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1EB2840.h"
#include "core2/1EDA900.h"
#include <math.h>
#include <stdlib.h>

static PlayerState *expected_player;
static Unk80132ED0 marker;
static AnimCtrl animation_control;
static s32 event, forwarded_event, next_state;
static int message_count, fallback_count, setup_count, reset_count;
static f32 animation_duration, delta;

static void check(int condition) { if (!condition) abort(); }
static void near(f32 actual, f32 expected) { check(fabsf(actual - expected) < 0.00001f); }

/* The game state code and scalar math run unchanged; these are observations at
   the unported actor, animation, player-event and frame-clock boundaries. */
intptr_t func_8010114C(Unk80132ED0 *arg0, s32 message, uintptr_t player) {
    check(arg0 == &marker && message == 0x2C && player == 3);
    message_count++;
    return 17;
}
void _badata_entrypoint_0(PlayerState *self, AssetId *id, f32 *duration) {
    check(self == expected_player);
    *id = (AssetId)123;
    *duration = 6.0f;
}
s32 _badata_entrypoint_34(PlayerState *self) {
    check(self == expected_player); return 0x159;
}
void baanim_playForDuration_loopSmooth(PlayerState *self, AssetId id, f32 duration) {
    check(self == expected_player && id == 123);
    animation_duration = duration;
}
AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *self) {
    check(self == expected_player); return &animation_control;
}
void func_8009FFD8(PlayerState *self, BaAnimUpdateType animation, YawType yaw,
                  s32 arg2, BaPhysicsType physics) {
    check(self == expected_player && animation == 1 && yaw == 1 && arg2 == 3 && physics == 7);
    setup_count++;
}
void func_8009D9D4(PlayerState *self) {
    check(self == expected_player); reset_count++;
}
s32 func_8009E6EC(PlayerState *self) {
    check(self == expected_player); return event;
}
void func_8009E830(PlayerState *self, s32 value) {
    check(self == expected_player); forwarded_event = value;
}
void func_80099B94(PlayerState *self) {
    check(self == expected_player); fallback_count++;
}
void bs_setState(PlayerState *self, BanjoStateId value) {
    check(self == expected_player); next_state = value;
}
f32 func_800D8FF8(void) { return delta; }

int main(void) {
    PlayerState player = {0};
    BaDrone drone = {0};
    expected_player = &player;
    player.drone = &drone;
    player.unk184 = 3;
    drone.marker = &marker;
    _bsdronebubbled_entrypoint_0(&player);
    check(message_count == 1 && drone.marker == NULL);
    _bsdronebubbled_entrypoint_0(&player);
    check(message_count == 1);

    drone.unk40 = 0.8f;
    _bsdronebubbled_entrypoint_1(&player);
    check(animation_duration == 6.0f && drone.unk44 == 6.0f && drone.unk40 == 0.0f);
    check(setup_count == 1 && reset_count == 1);
    event = 0x21;
    _bsdronebubbled_entrypoint_2(&player);
    event = -1;
    _bsdronebubbled_entrypoint_2(&player);
    check(fallback_count == 2);
    event = 0x6F;
    _bsdronebubbled_entrypoint_2(&player);
    check(forwarded_event == 1);
    event = 0x70;
    _bsdronebubbled_entrypoint_2(&player);
    check(next_state == 0x159);
    event = 0x7B;
    for (int i = 0; i < 9; i++) _bsdronebubbled_entrypoint_2(&player);
    near(drone.unk40, 1.0f);

    delta = 0.0f;
    _bsdronebubbled_entrypoint_3(&player);
    near(animation_control.duration, 2.0f);
    delta = 0.6f;
    _bsdronebubbled_entrypoint_3(&player);
    near(drone.unk40, 0.5f);
    near(animation_control.duration, 4.0f);
    delta = 2.0f;
    _bsdronebubbled_entrypoint_3(&player);
    check(drone.unk40 == 0.0f);
    near(animation_control.duration, 6.0f);
    _bsdronebubbled_entrypoint_3(&player);
    check(drone.unk40 == 0.0f);

    _bsdronebubbled_entrypoint_4(&player);
    _bsdronebubbled_entrypoint_5(&player);
    near(animation_duration, 12.0f);
    check(setup_count == 2 && reset_count == 1);
    _bsdronebubbled_entrypoint_6(&player);
    check(fallback_count == 3);
    _bsdronebubbled_entrypoint_7(&player);
    check(message_count == 1 && setup_count == 2 && fallback_count == 3);
    return 0;
}

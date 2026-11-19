#include "overlays/ba/drone.h"
#include "overlays/ba/data.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/move/goto.h"
#include "core2/1EC8070.h"
#include "core2/1E75920.h"
#include "player.h"
#include <stdlib.h>

static PlayerState *expected_player;
static int callback_count, move_count, water, physics_mode;
static f32 current_position[3] = {10.0f, 20.0f, 30.0f};
static f32 *last_destination;
static BanjoStateId selected_state;
static int context_object;

static void check(int value) { if (!value) abort(); }
static void check_vector(f32 *value, f32 *expected) {
    for (int i = 0; i < 3; i++) check(value[i] == expected[i]);
}

/* External state selectors and physics are controlled; the drone, vector and flag
   implementations under test are compiled from the actual game sources. */
s32 _badata_entrypoint_21(PlayerState *self) {
    check(self == expected_player); return 0x154;
}
s32 _badata_entrypoint_22(PlayerState *self) {
    check(self == expected_player); return 0x155;
}
s32 _badata_entrypoint_23(PlayerState *self) {
    check(self == expected_player); return 0x156;
}
void bs_setState(PlayerState *self, BanjoStateId state) {
    check(self == expected_player); selected_state = state;
}
s32 player_inWater(PlayerState *self) {
    check(self == expected_player); return water;
}
s32 func_8009BAF4(void *self) {
    check(self == expected_player); return physics_mode;
}
s32 func_8009C128(PlayerState *self, f32 output[3]) {
    check(self == expected_player); func_800EE7F8(output, current_position);
    return 0;
}
void _bamovegoto_entrypoint_12(PlayerState *self, f32 *destination) {
    check(self == expected_player); move_count++; last_destination = destination;
}
static void completion(uintptr_t context, s32 player_index, PlayerState *self) {
    check(context == (uintptr_t)&context_object);
    check(player_index == 3 && self == expected_player);
    callback_count++;
}

int main(void) {
    PlayerState player = {0};
    BaFlag flags = {0};
    f32 destination[3] = {16.0f, 50.0f, 38.0f};
    f32 output[3], value8, valueC;
    Unk80132ED0 marker = {0};
    BanjoStateId (*select[])(PlayerState *) = {
        _badrone_entrypoint_17, _badrone_entrypoint_19, _badrone_entrypoint_21,
        _badrone_entrypoint_24, _badrone_entrypoint_25, _badrone_entrypoint_26,
        _badrone_entrypoint_27, _badrone_entrypoint_28, _badrone_entrypoint_29
    };
    const u8 types[] = {7, 13, 15, 2, 9, 3, 6, 4, 14};
    const s32 states[] = {0x156, 0x154, 0x155, 0x154, 0x154, 0x156, 0x154, 0x154, 0x154};
    expected_player = &player;
    check(_badrone_entrypoint_0() == sizeof(BaDrone));
    player.drone = calloc(1, _badrone_entrypoint_0());
    check(player.drone != NULL);
    player.unk184 = 3;
    player.flag = &flags;
    _badrone_entrypoint_11(&player, completion, (uintptr_t)&context_object);
    _badrone_entrypoint_6(&player);
    check(callback_count == 1);
    _badrone_entrypoint_5(&player);
    _badrone_entrypoint_6(&player);
    check(callback_count == 1 && player.drone->callback == NULL);
    _badrone_entrypoint_8(&player, output, &value8, &valueC);
    check(value8 == 1.0f && valueC == 1.0f);
    check(output[0] == 0.0f && output[1] == 0.0f && output[2] == 0.0f);
    check(_badrone_entrypoint_7(&player) == 0 && _badrone_entrypoint_9(&player) == 1);
    _badrone_entrypoint_10(&player, 258);
    _badrone_entrypoint_12(&player, 257);
    check(_badrone_entrypoint_7(&player) == 2 && _badrone_entrypoint_9(&player) == 1);

    for (int type = 0; type < 16; type++) {
        player.drone->pending_type = type;
        _badrone_entrypoint_4(&player);
        check(_badrone_entrypoint_3(&player) == type);
        check(_badrone_entrypoint_1(&player) == (type == 2 || type == 12 || type == 14));
        check(_badrone_entrypoint_31(&player) == (type == 1));
        for (water = 0; water < 2; water++)
            check(_badrone_entrypoint_30(&player) == (type == 2 && !water));
    }
    for (int i = 0; i < 9; i++) {
        baflag_set(&player, BA_FLAG_19);
        check(select[i](&player) == states[i]);
        check(player.drone->pending_type == types[i]);
        if (types[i] == 4) check(!baflag_isTrue(&player, BA_FLAG_19));
    }
    check(_badrone_entrypoint_18(&player, &marker) == 0x154);
    check(player.drone->marker == &marker && player.drone->pending_type == 12);
    check(_badrone_entrypoint_20(&player, destination, 7) == 0x154);
    check(player.drone->unk30 == 7 && player.drone->pending_type == 8);
    check_vector(player.drone->target, destination);
    check(_badrone_entrypoint_22(&player, destination) == 0x154);
    check(player.drone->pending_type == 11);
    check_vector(player.drone->target, destination);
    check(_badrone_entrypoint_23(&player, destination) == 0x154);
    check(player.drone->pending_type == 10);
    check_vector(player.drone->target, destination);
    _badrone_entrypoint_33(&player, destination);
    _badrone_entrypoint_2(&player, output);
    check_vector(output, destination);

    _badrone_entrypoint_14(&player, destination, 9.0f);
    check(selected_state == 0x154 && player.drone->pending_type == 1);
    _badrone_entrypoint_8(&player, output, &value8, &valueC);
    check_vector(output, destination);
    check(value8 == 0.0f && valueC == 9.0f);
    _badrone_entrypoint_15(&player, destination, 7.0f);
    _badrone_entrypoint_8(&player, output, &value8, &valueC);
    check_vector(output, destination);
    check(value8 == 7.0f && valueC == 0.0f);
    _badrone_entrypoint_16(&player, destination, 2.0f);
    check(player.drone->unk8 == 5.0f); /* Horizontal distance 10 / speed 2. */
    for (int type = 0; type < 3; type++) {
        player.drone->type = type;
        for (physics_mode = 11; physics_mode < 14; physics_mode++) {
            move_count = 0;
            _badrone_entrypoint_13(&player, destination);
            check(move_count == (type == 1 && physics_mode == 12));
            if (move_count) check(last_destination == destination);
            check_vector(player.drone->destination, destination);
        }
    }
    _badrone_entrypoint_32(&player);
    check(player.drone->type == 0 && player.drone->pending_type == 0);
    free(player.drone);
    return 0;
}

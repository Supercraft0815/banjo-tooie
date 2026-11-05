#include <stdio.h>
#include <stdlib.h>
#include "native_input.h"
#include "overlays/ba/input.h"
#include "overlays/ba/key.h"

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

static void test_button_mapping(PlayerState *player) {
    const u16 masks[] = {
        START_BUTTON, Z_TRIG, L_TRIG, R_TRIG,
        U_JPAD, D_JPAD, L_JPAD, R_JPAD,
        A_BUTTON, B_BUTTON, L_CBUTTONS, D_CBUTTONS, U_CBUTTONS, R_CBUTTONS
    };
    s32 controller, button, other;
    for (controller = 0; controller < 4; controller++) {
        bakey_setControllerIndex(player, controller);
        for (button = 0; button < BUTTON_COUNT; button++) {
            CHECK(bt_native_set_controller(controller, masks[button], 0.0f, 0.0f));
            func_800BD2D0(player->key->unk0);
            for (other = 0; other < BUTTON_COUNT; other++)
                CHECK(bakey_held(player, other) == (button == other));
        }
        CHECK(bt_native_set_controller(controller, 0, 0.0f, 0.0f));
    }
}

static void test_transitions(PlayerState *player) {
    f32 stick[2];
    s32 i;
    bakey_setControllerIndex(player, 0);
    func_800BD138(player->key->unk0);
    CHECK(bt_native_set_controller(0, R_TRIG, 0.25f, -0.75f));
    func_800BD2D0(player->key->unk0);
    CHECK(bakey_pressed(player, BUTTON_R));
    CHECK(bakey_heldCount(player, BUTTON_R) == 1);
    for (i = 0; i < 3; i++) func_800BD2D0(player->key->unk0);
    CHECK(!bakey_pressed(player, BUTTON_R));
    CHECK(bakey_heldCount(player, BUTTON_R) == 4);
    CHECK(bt_native_set_controller(0, 0, 0.25f, -0.75f));
    func_800BD2D0(player->key->unk0);
    CHECK(bakey_newlyReleased(player, BUTTON_R));
    CHECK(bakey_released(player, BUTTON_R));
    CHECK(bakey_func_80091940(player, BUTTON_R, 1) == 4);
    CHECK(bakey_heldCount(player, BUTTON_R) == 0);
    CHECK(bakey_releaseCount(player, BUTTON_R) == 1);
    func_800BD2D0(player->key->unk0);
    CHECK(!bakey_newlyReleased(player, BUTTON_R));
    CHECK(bakey_releaseCount(player, BUTTON_R) == 2);
    bakey_getStick(player, stick);
    CHECK(stick[0] == 0.25f && stick[1] == -0.75f);
    CHECK(!bt_native_set_controller(4, A_BUTTON, 0.0f, 0.0f));
    CHECK(!bt_native_set_controller(0, A_BUTTON, strtof("NAN", NULL), 0.0f));
    CHECK(!bt_native_set_controller(0, A_BUTTON, 2.0f, 0.0f));
    func_800BD2D0(player->key->unk0);
    CHECK(!bakey_held(player, BUTTON_A));
    bakey_setControllerIndex(player, 0xFF);
    func_800BD2D0(player->key->unk0);
    bakey_getStick(player, stick);
    CHECK(stick[0] == 0.0f && stick[1] == 0.0f);
}

static void test_controller_isolation(PlayerState *player) {
    CHECK(bt_native_set_controller(0, A_BUTTON, 1.0f, 0.0f));
    CHECK(bt_native_set_controller(1, B_BUTTON, -1.0f, 0.0f));
    bakey_setControllerIndex(player, 0);
    func_800BD2D0(player->key->unk0);
    CHECK(bakey_held(player, BUTTON_A) && !bakey_held(player, BUTTON_B));
    bakey_setControllerIndex(player, 1);
    func_800BD2D0(player->key->unk0);
    CHECK(bakey_held(player, BUTTON_B) && !bakey_held(player, BUTTON_A));
}

int main(void) {
    PlayerState player = {0};
    BaKey key = {0};
    BaInput input = {0};
    player.key = &key;
    player.input = &input;
    bakey_init(&player);
    test_button_mapping(&player);
    test_transitions(&player);
    test_controller_isolation(&player);
    bakey_free(&player);
    return 0;
}

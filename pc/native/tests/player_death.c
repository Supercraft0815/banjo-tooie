#include "common.h"
#include "overlays/ba/playerstate.h"
#include <stdlib.h>

static void check(int valid) { if (!valid) abort(); }

void func_80091E20(u8 *);
s32 func_80091E48(void *, s32);
void func_80091E6C(void *);
s32 func_80091E80(u8 *, s32);
void func_80091EA8(BtIntPtr);
void func_80091EC8(void *);
void func_80091EF0(PlayerState *);
void func_80091F30(void *);

static PlayerState player;
static s32 active = 1;
static s32 scene_locked;
static s32 inventory_result;
static s32 save_calls, inventory_calls, death_effects;

int func_800DB9B0(void) { return active; }
u8 func_800F8B70(void) { return scene_locked; }
void func_800F9104(s32 value) { check(value == 1); ++save_calls; }
s32 func_80101238(s32 id, s32 index) {
    check(id == 0x96 && index == player.unk184);
    ++inventory_calls;
    return inventory_result;
}
void func_800A05DC(void *actor) { check(actor == &player); ++death_effects; }

int main(void) {
    u8 bytes[4] = {0};
    u8 state = 0xff;
    player.action_flags = bytes;
    player.death_state = &state;
    player.unk184 = 7;

    func_80091E20((u8 *)&player);
    check(bytes[0] == 0x7f && bytes[3] == 1);
    func_80091E48(&player, 0x42);
    func_80091E48(&player, 0x12);
    check(bytes[1] == 0x42 && bytes[2] == 0x12 && bytes[3] == 3);
    check(func_80091E80((u8 *)&player, 0x12));
    func_80091E6C(&player);
    check(!func_80091E80((u8 *)&player, 0x12));
    check(func_80091E80((u8 *)&player, 0x40));

    func_80091EC8(&player);
    check(state == 1);
    func_80091EF0(&player);
    check(state == 2);
    active = 0; scene_locked = 1;
    func_80091F30(&player);
    check(state == 2 && save_calls == 0);
    scene_locked = 0;
    func_80091F30(&player);
    check(state == 3 && save_calls == 1 && inventory_calls == 1 && death_effects == 1);
    inventory_result = 1;
    func_80091EF0(&player);
    check(state == 3 && save_calls == 2 && inventory_calls == 2 && death_effects == 1);
    func_80091EA8((BtIntPtr)&player);
    check(state == 0);
    return 0;
}

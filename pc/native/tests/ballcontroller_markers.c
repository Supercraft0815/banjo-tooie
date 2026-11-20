#include "common.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #x); exit(1); } } while (0)

static Actor *expected_child;
static Unk80132ED0 *expected_marker;
static Actor child_actor;
static u8 ball_data[0x80];
static u8 child_data[0x80];
static int use_stone_data;

typedef struct {
    u8 prefix[0xA];
    u8 states[6];
    Unk80132ED0 *markers[4];
    u8 pad[0x24 - sizeof(void *) * 4];
    u8 bytes[6];
} StoneChildList;
static StoneChildList stone_data;

void *func_80100094(Actor *actor, u32 slot) {
    CHECK(slot == 0);
    if (actor != expected_child) return child_data;
    return use_stone_data ? (void *)&stone_data : (void *)ball_data;
}

Actor *func_80106790(Unk80132ED0 *marker) {
    CHECK(marker == expected_marker);
    return &child_actor;
}

s32 _sukickball_entrypoint_6(u8 *actor, BtIntPtr owner) {
    CHECK(actor == (u8 *)&child_actor && owner == 0x2A);
    return 0;
}

void _sukickball_entrypoint_11(u8 *actor, s32 owner) {
    CHECK(actor == (u8 *)&child_actor && owner == 0x2A);
}

void func_800F4F98(s32 owner, void *marker) {
    (void)owner; (void)marker; CHECK(0);
}
 s32 func_800EA05C(void) { return 0xBB; }
 void func_800F8294(BtIntPtr index, f32 *position) { (void)index; (void)position; }
 void func_800F82D4(BtIntPtr index, s32 value) { (void)index; (void)value; }
 s32 func_800F832C(BtIntPtr index, f32 *position) { (void)index; (void)position; return 0; }

f32 _sukickball_entrypoint_15(s32 index) { CHECK(index == 0); return 90.0f; }
void _sukickball_entrypoint_16(s32 index, f32 *position) { CHECK(index == 0 && position == child_actor.position); }
void func_800EE7F8(f32 *out, f32 *in) { out[0] = in[0]; out[1] = in[1]; out[2] = in[2]; }

void func_80802A50_chcollballcontrol(Actor *);
void func_80802F14_chstoneballcontrol(Actor *);
void func_80801330_chstoneballcontrol(Actor *, s32);

int main(void) {
    Actor owner = {0};
    expected_child = &owner;
    expected_marker = (Unk80132ED0 *)(uintptr_t)UINT64_C(0x12345678AABBCCDD);
    owner.unk3C = expected_marker;
    owner.parent_marker = expected_marker;
    ((u8 *)ball_data)[0x20] = 0x2A;
    func_80802A50_chcollballcontrol(&owner);
    CHECK(((u8 *)ball_data)[0x20] == 0x7F);

    expected_child = &owner;
    ((u8 *)ball_data)[0x20] = 0x2A;
    func_80802F14_chstoneballcontrol(&owner);
    CHECK(((u8 *)ball_data)[0x20] == 0x7F);

    _Static_assert(offsetof(StoneChildList, markers) == 0x10, "marker array offset");
    _Static_assert(offsetof(StoneChildList, bytes) == 0x34, "neighbor byte offset");
    stone_data = (StoneChildList){0};
    stone_data.states[0] = 1;
    stone_data.markers[0] = expected_marker;
    use_stone_data = 1;
    expected_child = &owner;
    for (size_t i = 0; i < sizeof(child_actor); ++i) ((u8 *)&child_actor)[i] = 0;
    func_80801330_chstoneballcontrol(&owner, 0);
    CHECK(stone_data.bytes[0] == 0);
    return 0;
}

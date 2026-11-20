#include "common.h"
#include <stdint.h>
#include <stdio.h>

Actor *chnewfreezy_entrypoint_0(Unk80132ED0 *marker, s32 x, s32 y, s32 z);

static Unk80132ED0 marker;
static Actor source_actor;
static Actor spawned_actor;
static u8 asset_bytes[64];
static u8 skeleton_bytes[64];
static u8 extra_bytes[64];
static s32 errors;
static u32 setup_count;
static void fail(int line) { errors++; fprintf(stderr, "fixture mismatch at line %d\n", line); }
static u8 *seen_getter_marker_data;
static u8 *seen_skeleton_input;
static u8 *seen_helper_data[4];
static void *seen_allocation;
static Actor *seen_spawn_actor;

Actor *func_80106790(Unk80132ED0 *arg) {
    if (arg != &marker) fail(__LINE__);
    return &source_actor;
}

void *func_80101080(void) { return extra_bytes; }

Actor *func_801084B0(BtIntPtr type, Actor **source) {
    if (type != 0x2FF || source == NULL || *source != &source_actor) fail(__LINE__);
    spawned_actor.unk0 = &marker;
    return &spawned_actor;
}

u8 *func_800B27E0(u8 *arg) {
    seen_skeleton_input = arg;
    return skeleton_bytes;
}

s32 func_8010108C(Actor *arg0, s32 field, BtIntPtr value) {
    (void)value;
    if (arg0 != &source_actor) fail(__LINE__);
    if (field != 0x38 && field != 0x94) fail(__LINE__);
    return 1;
}

u8 *func_801039E4(Unk80132ED0 *arg) {
    if (arg != &marker) fail(__LINE__);
    return asset_bytes;
}

s32 dbskeleton_entrypoint_0(u8 *arg) {
    if (arg != skeleton_bytes) fail(__LINE__);
    return 2;
}

void func_80103DFC(Actor *arg, f32 *dst) {
    if (arg != &source_actor) fail(__LINE__);
    dst[0] = 1.0f; dst[1] = 2.0f; dst[2] = 3.0f;
}

u32 *func_80100074(Actor *arg, u32 index, u32 size) {
    if (arg != &spawned_actor || index != 0 || size != 2 * 0x60) fail(__LINE__);
    return NULL;
}

s16 func_800AE020(void) { fail(__LINE__); return 1; }
f32 func_800EC708(Unk80132ED0 *arg) { if (arg != &marker) fail(__LINE__); return 2.0f; }
void func_80101038(f32 *out) { out[0] = 10.0f; out[1] = 20.0f; out[2] = 30.0f; }
struct anctrl_s *func_80104248(void *arg) { if (arg != &source_actor) fail(__LINE__); return (struct anctrl_s *)extra_bytes; }
void *func_8008B4D4(void *arg) { return arg; }
void func_800DF41C(void *arg) { if (arg != extra_bytes) fail(__LINE__); }
void func_808011A8_chnewfreezy(f32 a, f32 b) { if (a != 20.0f || b != 10.0f) fail(__LINE__); }
void func_80800974_chnewfreezy(Actor *arg, u8 *data) { if (arg != &spawned_actor || data != skeleton_bytes) fail(__LINE__); seen_helper_data[0] = data; }
void func_80800AA4_chnewfreezy(Actor *arg, u8 *data) { if (arg != &spawned_actor || data != skeleton_bytes) fail(__LINE__); seen_helper_data[1] = data; }
void func_80800BFC_chnewfreezy(Actor *arg, u8 *data) { if (arg != &spawned_actor || data != skeleton_bytes) fail(__LINE__); seen_helper_data[2] = data; }
void func_80800D28_chnewfreezy(Actor *arg, BtIntPtr data) { if (arg != &spawned_actor || data != (BtIntPtr)skeleton_bytes) fail(__LINE__); seen_helper_data[3] = (u8 *)data; }
void func_80800E74_chnewfreezy(Actor *arg, u8 *data, void *extra, s32 count) {
    if (arg != &spawned_actor || data != skeleton_bytes || extra != extra_bytes || count != 1) fail(__LINE__);
    seen_allocation = extra;
}
f32 func_808012F8_chnewfreezy(Actor *arg) { if (arg != &spawned_actor) fail(__LINE__); return 1.0f; }
void sufreezy_entrypoint_3(Actor *arg) { seen_spawn_actor = arg; }

int main(void) {
    Actor *result;
    marker.unk10 = 1;
    source_actor.unk0 = &marker;
    source_actor.scale = 1.0f;
    if ((uintptr_t)&marker <= UINT32_MAX || (uintptr_t)&source_actor <= UINT32_MAX ||
        (uintptr_t)&spawned_actor <= UINT32_MAX || (uintptr_t)asset_bytes <= UINT32_MAX ||
        (uintptr_t)skeleton_bytes <= UINT32_MAX || (uintptr_t)extra_bytes <= UINT32_MAX) return 2;
    result = chnewfreezy_entrypoint_0(&marker, 100, 200, 300);
    printf("marker=%p source=%p result=%p asset=%p skeleton=%p extra=%p errors=%d\n",
           (void *)&marker, (void *)&source_actor, (void *)result, (void *)asset_bytes,
           (void *)skeleton_bytes, (void *)extra_bytes, errors);
    if (result != &spawned_actor || seen_spawn_actor != &spawned_actor || seen_allocation != extra_bytes ||
        seen_skeleton_input != asset_bytes || errors != 0) return 3;
    for (setup_count = 0; setup_count < 4; setup_count++) {
        if (seen_helper_data[setup_count] != skeleton_bytes) return 4;
    }
    return 0;
}

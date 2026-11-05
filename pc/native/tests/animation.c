#include "core2/animation.h"
#include "core2/animation_resource.h"
#include "memory.h"
#include "core2/1EAF950.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

/* Controlled asset lookup/clock/render boundaries; resource sampling executes game C. */
static s16 *assets[2];
static const u8 resource_bytes[2][20] = {
    {0,0, 0,10, 0,1, 0,0, 0,0x16, 0,2, 0,0, 0,128, 0,10, 1,0},
    {0,0, 0,10, 0,1, 0,0, 0,0x16, 0,2, 0,0, 1,0, 0,10, 1,128}
};
static int callbacks, render_calls;
static BoneTransformList *last_pose;
static int model;

u32 func_800E6A00(void) { return 0; }
f32 func_800D8FF8(void) { return 0.1f; }
f32 _glintrosyncDll_entrypoint_5(void) { return 0.1f; }
ImageStruct *func_800D674C(s32 id) {
    CHECK(id == 1 || id == 2);
    return (ImageStruct *)assets[id - 1];
}
void func_800AE1E8(s16 handle, void *data, BoneTransformList *pose) {
    CHECK(handle == 17 && data == &model && pose == last_pose);
    render_calls |= 1;
}
void func_800AE290(s16 handle, void *data, BoneTransformList *pose) {
    CHECK(handle == 18 && data == &model && pose == last_pose);
    render_calls |= 2;
}
static void near(f32 actual, f32 expected) {
    CHECK(fabsf(actual - expected) < 0.00001f);
}
static void callback(void *ptr, uintptr_t context) {
    BoneTransformList *pose = ptr;
    CHECK(context == (uintptr_t)&callbacks);
    pose->ptr[108].unk1C[2] = 42;
    last_pose = pose;
    callbacks++;
}

static void test_cache(void) {
    s16 slots[25];
    BoneTransformList *pose, *again;
    int i;
    func_8008B610();
    for (i = 0; i < 25; ++i) {
        slots[i] = func_8008B8E0();
        CHECK(slots[i] == i + 1 && !func_8008B90C(slots[i]));
        CHECK(func_8008B9C4(slots[i], &pose) == 1);
        pose->ptr[108].unk1C[0] = i;
    }
    func_8008BA5C();
    for (i = 0; i < 25; ++i) {
        CHECK(func_8008B9C4(slots[i], &pose) == 0);
        near(pose->ptr[108].unk1C[0], i);
    }
    CHECK(func_8008B9C4(slots[0], &pose) == 0);
    CHECK(func_8008B9C4(slots[0], &again) == 0 && again == pose);
    for (i = 0; i < 59; ++i) func_8008B850();
    CHECK(func_8008B90C(slots[0]));
    func_8008B850();
    CHECK(!func_8008B90C(slots[0]));
    CHECK(func_8008B9C4(slots[0], &pose) == 1);
    near(pose->ptr[108].unk1C[0], 0);
    func_8008B6E0();
    CHECK(func_8008B90C(slots[0]));
    func_8008B850();
    func_8008B6E0();
    CHECK(func_8008B90C(slots[0]));
    func_8008B850();
    func_8008B6E0();
    CHECK(!func_8008B90C(slots[0]));
    /* Purging reserved slots with no allocation must accept the zero handle. */
    for (i = 10; i < 25; ++i) func_8008B954(slots[i]);
    func_8008B768();
    CHECK(func_8008B9C4(slots[9], &pose) == 1);
    CHECK(func_8008B8E0() == 11);
    func_8008B64C();
}

static void test_controller_pipeline(void) {
    AnimCtrl *ctrl;
    Animation *animation;
    BoneTransformList *pose;
    int previous_calls;
    func_8008B610();
    ctrl = func_8008AD80(0);
    animation = func_8008AEDC(ctrl);
    CHECK(func_8008C0B8() == sizeof(Animation));
    CHECK(func_8008B4F4() == sizeof(AnimCtrl) + sizeof(Animation));
    CHECK(animation->mode == 1 && animation->poses[0] != animation->poses[1]);
    CHECK(animation->poses[2] != animation->poses[1]);
    anctrl_reset(ctrl);
    anctrl_setDuration(ctrl, 1);
    anctrl_setPlaybackType(ctrl, 2);
    anctrl_setIndex(ctrl, (AssetId)1);
    func_8008AEE4(ctrl, callback);
    func_8008AF04(ctrl, (uintptr_t)&callbacks);
    anctrl_start(ctrl);
    func_8008ADE4(ctrl);
    func_8008B304(ctrl);
    pose = func_8008B4D4(ctrl);
    CHECK(pose == last_pose && callbacks == 1 && animation->loop == 1);
    near(pose->ptr[1].unk1C[0], 1.1f);
    near(pose->ptr[108].unk1C[2], 42);
    CHECK(animation->fresh == 0);
    func_8008C200(17, &model, animation);
    func_8008C238(18, &model, animation);
    CHECK(render_calls == 3);

    anctrl_setSmoothTransition(ctrl, 1);
    anctrl_setIndex(ctrl, (AssetId)2);
    anctrl_start(ctrl);
    func_8008B304(ctrl);
    pose = func_8008B4D4(ctrl);
    CHECK(pose == last_pose);
    near(pose->ptr[1].unk1C[0], 1.1f);
    func_8008ADE4(ctrl);
    func_8008B304(ctrl);
    near(pose->ptr[1].unk1C[0], 1.6f);
    func_8008ADE4(ctrl);
    func_8008B304(ctrl);
    near(pose->ptr[1].unk1C[0], 2.2f);
    CHECK(animation->blend_complete == 0);

    /* A hard switch resets channels the next resource does not write. */
    func_8008AEE4(ctrl, NULL);
    previous_calls = callbacks;
    anctrl_setSmoothTransition(ctrl, 0);
    anctrl_setIndex(ctrl, (AssetId)1);
    anctrl_start(ctrl);
    func_8008B304(ctrl);
    pose = func_8008B4D4(ctrl);
    near(pose->ptr[1].unk1C[0], 1);
    near(pose->ptr[108].unk1C[2], 0);
    CHECK(callbacks == previous_calls);
    func_8008ADBC(ctrl);
    CHECK(func_8008B8E0() == 1);
    func_8008B64C();
}

static void test_two_pose_mode(void) {
    Animation animation = {0};
    BoneTransformList *pose;
    func_8008B610();
    func_8008C124((s16 *)&animation, 0);
    func_8008C1CC((s8 *)&animation, 0);
    func_8008C1B8((s16 *)&animation, 1);
    func_8008C038(&animation);
    pose = func_8008BD1C(&animation);
    near(pose->ptr[1].unk1C[0], 1);
    CHECK(animation.poses[2] == 0 && animation.loop == 0);
    func_8008C0AC((s8 *)&animation);
    func_8008C1B8((s16 *)&animation, 2);
    func_8008C1E4((f32 *)&animation, 0.25f);
    func_8008C038(&animation);
    pose = func_8008C27C(&animation);
    near(pose->ptr[1].unk1C[0], 1.25f);
    CHECK(animation.current_pose == 1 && animation.pending == 0);
    func_8008C0D8(&animation);
    func_8008B64C();
}

int main(void) {
    assets[0] = native_animation_decode(resource_bytes[0], sizeof(resource_bytes[0]));
    assets[1] = native_animation_decode(resource_bytes[1], sizeof(resource_bytes[1]));
    CHECK(assets[0] && assets[1]);
    test_cache();
    test_controller_pipeline();
    test_two_pose_mode();
    heap_free(assets[0]);
    heap_free(assets[1]);
    puts("Native animation controller/cache/bone integration passed");
    return 0;
}

#include "core2/animation.h"
#include <math.h>
#include <stdlib.h>

/* Isolate controller behavior; animation.c tests the real backend and bones. */
typedef struct {
    AnimCallback callback;
    uintptr_t context;
    f32 timer, blend;
    s16 index;
    int type, loop, transition, complete;
} AnimationFixture;
static f32 frame_delta = 0.1f, intro_delta = 0.2f;
static u32 intro_mode;
static int released, callback_calls, pose;

static void check(int condition) { if (!condition) abort(); }
static void near(f32 actual, f32 expected) { check(fabsf(actual - expected) < 0.00001f); }
static AnimationFixture *fixture(void *ptr) {
    check((uintptr_t)ptr % _Alignof(AnimationFixture) == 0);
    return ptr;
}
s32 func_8008C0B8(void) { return sizeof(AnimationFixture); }
void func_8008C124(s16 *ptr, s32 type) {
    *fixture(ptr) = (AnimationFixture){.blend = 1.0f, .type = type};
}
void func_8008C0D8(void *ptr) { check(fixture(ptr)->type == 1); released++; }
s32 func_8008C0C0(s16 *ptr) { return fixture(ptr)->index; }
f32 func_8008C0C8(f32 *ptr) { return fixture(ptr)->timer; }
f32 func_8008C0D0(f32 *ptr) { return fixture(ptr)->blend; }
void func_8008C1C0(f32 *ptr, f32 value) { fixture(ptr)->timer = value; }
void func_8008C1E4(f32 *ptr, f32 value) { fixture(ptr)->blend = value; }
void func_8008C1F0(void *ptr, s32 value) { fixture(ptr)->complete = value; }
void func_8008C1CC(s8 *ptr, s32 value) { fixture(ptr)->loop = value; }
void func_8008C1B8(s16 *ptr, s32 index) { fixture(ptr)->index = index; }
void func_8008C0AC(s8 *ptr) { fixture(ptr)->transition = 1; }
void func_8008C270(s8 *ptr) { fixture(ptr)->transition = 2; }
void func_8008C1D4(void *ptr, AnimCallback callback) { fixture(ptr)->callback = callback; }
void func_8008C1DC(void *ptr, uintptr_t context) { fixture(ptr)->context = context; }
void *func_8008C27C(void *ptr) { fixture(ptr); return &pose; }
void func_8008C038(void *ptr) {
    AnimationFixture *anim = fixture(ptr);
    if (anim->callback) anim->callback(&pose, anim->context);
}
u32 func_800E6A00(void) { return intro_mode; }
f32 func_800D8FF8(void) { return frame_delta; }
f32 _glintrosyncDll_entrypoint_5(void) { return intro_delta; }
static void callback(void *bones, uintptr_t context) {
    check(bones == &pose && context == (uintptr_t)&callback_calls); callback_calls++;
}

static void flag_and_clock_checks(AnimCtrl *ctrl) {
    const f32 times[4] = {0.1f, 0.0333329998f, 0.2f, 0.1f};
    ctrl->index = 0x1234;
    ctrl->playback_type = 0xAB;
    ctrl->flags = 3;
    for (int mode = 0; mode < 4; mode++) {
        func_8008B2E8(ctrl, mode);
        check(ctrl->flags == (3 | mode << 3));
        near(func_8008A990(ctrl), times[mode]);
    }
    func_8008B188(ctrl, 1);
    check(func_8008B28C(ctrl) == 1 && (ctrl->flags & 0x80));
    anctrl_setSmoothTransition(ctrl, 1);
    check(func_8008B29C(ctrl) == 1 && (ctrl->flags & 0x40));
    func_8008B4A8(ctrl, 1);
    check(func_8008B4C4(ctrl) == 1 && (ctrl->flags & 4));
    func_8008B188(ctrl, 0);
    anctrl_setSmoothTransition(ctrl, 0);
    func_8008B4A8(ctrl, 0);
    check(ctrl->flags == 27 && ctrl->index == 0x1234 && ctrl->playback_type == 0xAB);
    for (int type = 0; type < 5; type++) {
        anctrl_setPlaybackType(ctrl, type);
        check(anctrl_getPlaybackType((u8 *)ctrl) == type);
        check(anctrl_isStopped(ctrl) == (type == 3));
        if (type) check(func_8008B4C4(ctrl) == (type == 2 || type == 4));
    }
}

static void playback_checks(AnimCtrl *ctrl) {
    AnimationFixture *anim = func_8008AEDC(ctrl);
    intro_mode = 0;
    anctrl_reset(ctrl);
    anctrl_setDuration(ctrl, 1.0f);
    anctrl_setIndex(ctrl, (AssetId)123);
    anctrl_start(ctrl);
    check(anctrl_getIndex(ctrl) == 123 && anim->transition == 2 && anim->blend == 1.0f);
    near(anctrl_getAnimTimer(ctrl), 0.0f);
    func_8008ADE4(ctrl);
    near(anctrl_getAnimTimer(ctrl), 0.1f);
    check(anctrl_isAt(ctrl, 0.0f) && !anctrl_isAt(ctrl, 0.1f));
    func_8008B10C(ctrl, 0.95f);
    func_8008ADE4(ctrl);
    near(anctrl_getAnimTimer(ctrl), 0.05f);
    check(anctrl_isAt(ctrl, 0.99f) && anctrl_isAt(ctrl, 0.01f) && !anctrl_isAt(ctrl, 0.5f));
    func_8008B188(ctrl, 0);
    func_8008ADE4(ctrl);
    near(anctrl_getAnimTimer(ctrl), 0.95f);
    check(anctrl_isAt(ctrl, 0.0f) && anctrl_isAt(ctrl, 0.98f) && !anctrl_isAt(ctrl, 0.5f));
    func_8008B10C(ctrl, 0.75f);
    func_8008ADE4(ctrl);
    near(anctrl_getAnimTimer(ctrl), 0.65f);
    check(anctrl_isAt(ctrl, 0.7f) && !anctrl_isAt(ctrl, 0.8f));
    anctrl_setPlaybackType(ctrl, 1);
    func_8008B10C(ctrl, 0.03f);
    func_8008ADE4(ctrl);
    check(anctrl_isStopped(ctrl) && anim->timer == 0.0f && !anim->loop);

    func_8008B188(ctrl, 1);
    anctrl_setSubrange(ctrl, 0.2f, 0.7f);
    anctrl_setPlaybackType(ctrl, 4);
    func_8008B10C(ctrl, 0.65f);
    func_8008ADE4(ctrl);
    near(anim->timer, 0.25f);
    check(anim->loop);
    anctrl_setPlaybackType(ctrl, 1);
    func_8008B10C(ctrl, 0.65f);
    func_8008ADE4(ctrl);
    near(anim->timer, 0.7f);
    check(anctrl_isStopped(ctrl));
    anctrl_setPlaybackType(ctrl, 0);
    func_8008ADE4(ctrl);
    near(anim->timer, 0.7f);

    anctrl_reset(ctrl);
    anctrl_setIndex(ctrl, (AssetId)456);
    anctrl_setStart(ctrl, 0.35f);
    anctrl_start(ctrl);
    check(anim->transition == 1 && anim->blend == 0.0f && anim->index == 456);
    near(anim->timer, 0.35f);
    anctrl_setPlaybackType(ctrl, 3);
    func_8008ADE4(ctrl);
    near(anim->blend, 0.5f);
    func_8008ADE4(ctrl);
    check(anim->blend == 1.0f && anim->complete == 1);
    near(anim->timer, 0.35f);
    intro_mode = 1;
    anctrl_reset(ctrl);
    near(func_8008A990(ctrl), intro_delta);
    func_8008B188(ctrl, 0);
    anctrl_start(ctrl);
    near(anim->timer, 0.99999899f);
}

int main(void) {
    AnimCtrl *ctrl = func_8008AD80(1);
    check(func_8008B4F4() == sizeof(AnimCtrl) + sizeof(AnimationFixture));
    check((u8 *)func_8008AEDC(ctrl) - (u8 *)ctrl == sizeof(AnimCtrl));
    flag_and_clock_checks(ctrl);
    playback_checks(ctrl);
    func_8008AEE4(ctrl, callback);
    func_8008AF04(ctrl, (uintptr_t)&callback_calls);
    check(func_8008B4D4(ctrl) == &pose);
    func_8008B304(ctrl);
    check(callback_calls == 1);
    check(func_8008AEB4(ctrl) == ctrl);
    func_8008ADBC(ctrl);
    check(released == 1);
    return 0;
}

#include "native_assets.h"
#include "native_model.h"
#include "core2/1EAF950.h"
#include "core2/animation_resource.h"
#include "core2/animation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

/* Only the clock and memory-pressure policy are controlled by this fixture. */
static s32 frame = 100;
s32 func_8001211C(void) { return frame; }
s32 func_800A9F14(s32 mode) { return mode == 2 ? 3 : 18; }
s32 func_800A9F30(void) { return 1; }
f32 func_800D8FF8(void) { return 0.5f; }
f32 _glintrosyncDll_entrypoint_5(void) { return 0.5f; }
u32 func_800E6A00(void) { return 0; }
void func_800DBC68(void);
s32 func_800DBE28(u8, s32);
s32 func_800DB9FC(u8, s32, s32 *);

static void test_sorted_cache(void) {
    ImageStruct *pointers[130];
    int i;
    for (i = 129; i >= 0; --i) pointers[i] = func_800D674C(i);
    for (i = 0; i < 130; ++i) {
        CHECK(pointers[i] && func_800D6254(i) == i);
        CHECK(func_800D6B0C(i) == pointers[i] && func_800D674C(i) == pointers[i]);
    }
    CHECK(!func_800D674C(130));
    for (i = 0; i < 130; i += 2) CHECK(func_800D6CEC(i) == 0);
    for (i = 1; i < 130; i += 2) {
        CHECK(func_800D6254(i) == i / 2 && func_800D6B0C(i) == pointers[i]);
        CHECK(native_asset_cached_size(i) == 32);
    }
    CHECK(func_800D674C(130));
    func_800D6C64();
    for (i = 0; i <= 130; ++i) CHECK(!func_800D73CC(i) && !func_800D5A04(i));
    CHECK(!func_800D6B0C(-1) && !func_800D6C34(42));
}

static void test_pin_reload_and_release(void) {
    s16 *animation = (s16 *)func_800D674C(43);
    BoneTransformList *pose = func_800DFC80();
    CHECK(animation && func_800D6C34(43));
    func_800D70D0(1);
    CHECK(func_800D7138(43) == 1 && func_800D6CEC(43) == 1);
    func_800D71F4(1);
    func_800D6D68();
    CHECK(func_800D721C(43, 0));
    animation[7] = 0;
    CHECK(func_800D725C(43) == animation);
    func_800E0170(animation, 0.5f, 0, pose);
    CHECK(fabsf(pose->ptr[1].unk1C[0] - 43.5f) < 0.0001f);
    CHECK(func_800D738C(43) == 6 && func_800D73AC(43) == 1);
    CHECK(func_800D70F8(43, 0) && func_800D7138(43) == 0);
    CHECK(func_800D6CEC(43) == 0 && func_800D7138(43) == UINT32_MAX);
    CHECK(!func_800D70F8(43, 1) && !func_800D721C(43, 1));
    func_800DFC60(pose);

    CHECK(func_800D674C(149));
    CHECK(func_800D6CEC(149) == -1 && !func_800D73CC(149) && func_800D5A04(149));
    func_800D5E74();
    CHECK(func_800D5A04(149));
    func_800D5E74();
    CHECK(!func_800D5A04(149));
    CHECK(func_800D674C(150));
    frame += 2;
    CHECK(func_800D6CEC(150) == 0 && !func_800D5A04(150));
    CHECK(func_800D674C(152));
    CHECK(func_800D6CEC(152) == 0 && !func_800D5A04(152));
}

static void test_model_aux(void) {
    int i;
    s32 offset;
    u8 handle;
    CHECK(!func_800D674C(146) && !func_800D5A04(146));
    CHECK(!func_800D674C(147) && !func_800D5A04(147));
    CHECK(func_800D674C(145));
    handle = func_800D731C(145);
    CHECK(handle != 0);
    for (i = 0; i < 7; ++i) CHECK(func_800DBE28(handle, i) == 100 + i);
    func_800DBC68();
    CHECK(func_800DB9FC(handle, 3, &offset) && offset == 8);
    CHECK(func_800D674C(145));
    func_800D62E4(145);
    CHECK(func_800D6CEC(145) == -1);
    func_800D5E74();
    func_800D5E74();
    CHECK(!func_800D5A04(145));
    CHECK(func_800D674C(148) && func_800D731C(148) == 0);
    u64 copied[13];
    CHECK(func_800D5EB4(148,(u8 *)copied,sizeof(copied))==112);
    NativeVertexList *vertices=func_800B2840(copied);
    CHECK((u8 *)vertices==(u8 *)copied+80 && vertices->center[0]==-3 && vertices->center_radius==17);
    func_800D62E4(148);
    CHECK(func_800D6CEC(148) == 0);
}

static void test_eviction(void) {
    int i;
    for (i = 0; i < 60; ++i) CHECK(func_800D674C(i));
    CHECK(func_800D70F8(20, 1));
    frame += 30;
    func_800D6E54(2);
    for (i = 0; i < 60; ++i) CHECK(func_800D73CC(i) == (i == 20));
    CHECK(func_800D70F8(20, 0));
    func_800D6E54(2);
    CHECK(!func_800D73CC(20));
}

static void test_controller_archive_pipeline(void) {
    AnimCtrl *controller;
    BoneTransformList *pose;
    func_8008B610();
    controller = func_8008AD80(0);
    anctrl_reset(controller);
    anctrl_setDuration(controller, 1);
    anctrl_setPlaybackType(controller, 2);
    anctrl_setIndex(controller, (AssetId)43);
    anctrl_start(controller);
    func_8008ADE4(controller);
    func_8008B304(controller);
    pose = func_8008B4D4(controller);
    CHECK(fabsf(pose->ptr[1].unk1C[0] - 43.5f) < 0.0001f);
    CHECK(func_800D73CC(43));
    anctrl_setSmoothTransition(controller, 0);
    anctrl_setIndex(controller, (AssetId)44);
    anctrl_start(controller);
    func_8008B304(controller);
    pose = func_8008B4D4(controller);
    CHECK(fabsf(pose->ptr[1].unk1C[0] - 44) < 0.0001f);
    CHECK(func_800D73CC(44));
    func_8008ADBC(controller);
    func_8008B64C();
    func_800D6C64();
}

static void test_original_archive(void) {
    int id, count[11] = {0};
    for (id = 0; id < native_asset_count(); ++id) {
        int type = func_800D58FC(id);
        if (type != 0 && type != 6 && type != 10) continue;
        if (!func_800D674C(id)) { fprintf(stderr, "Cache load failed: %#x\n", id); exit(1); }
        frame += 2;
        CHECK(func_800D6CEC(id) == 0 && !func_800D5A04(id));
        count[type]++;
    }
    printf("Game cache loaded/released %d models, %d animations, %d databases\n",
           count[0], count[6], count[10]);
}

int main(int argc, char **argv) {
    CHECK(argc == 2 || argc == 3);
    CHECK(native_assets_open(argv[1]));
    func_800D66AC();
    if (argc == 3) {
        test_sorted_cache();
        test_pin_reload_and_release();
        test_model_aux();
        test_eviction();
        test_controller_archive_pipeline();
    } else test_original_archive();
    func_800D6C64();
    native_assets_close();
    puts("Native game asset-cache checks passed");
    return 0;
}

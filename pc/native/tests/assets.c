#include "native_assets.h"
#include "core2/animation_resource.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

static void test_cache(void) {
    void *pointers[130], *first, *second;
    int i;
    CHECK(func_800D593C() == 140 && func_800D58FC(0) == 6);
    CHECK(func_800D59C0(0) == 0 && func_800D59C0(1) == 1);
    CHECK(func_800D5950(0) == 20 && func_800D5DB8(0) == 20);
    CHECK(func_800D5A6C(0) == 0x5180 + 8 + 141 * 4);
    CHECK(!func_800D5B34(-1) && !func_800D5B34(140));
    CHECK(func_800D56C4(NULL) == 3);
    for (i = 0; i < 130; ++i) {
        pointers[i] = func_800D5B34(i);
        CHECK(pointers[i] && func_800D5A04(i));
    }
    CHECK(!func_800D5B34(130));
    CHECK(func_800D5B34(0) == pointers[0]);
    CHECK(func_800D56C4(pointers[0]) == 1);
    CHECK(func_800D56C4(pointers[0]) == 0);
    CHECK(func_800D5FE8(129) == pointers[129]);
    CHECK(func_800D5B34(130));
    for (i = 1; i <= 130; ++i) CHECK(func_800D56C4(func_800D5FE8(i)) == 0);

    first = func_800D5B34(5);
    for (i = 1; i < 255; ++i) CHECK(func_800D5B34(5) == first);
    CHECK(!func_800D5B34(5));
    for (i = 1; i < 255; ++i) CHECK(func_800D56C4(first) == 1);
    CHECK(func_800D56C4(first) == 0);

    first = func_800D5B34(1);
    second = func_800D5B34(1);
    CHECK(first == second && func_800D5804(first, 0) == first);
    func_800D5E28(&first);
    CHECK(first == NULL && func_800D54F0(second));
    func_800D5E54(second);
    func_800D5E74();
    CHECK(func_800D5A04(1));
    func_800D5E74();
    CHECK(!func_800D5A04(1));
    for (i = 0; i < 30; ++i) func_800D5440(func_800D5B34(i));
    func_800D5688();
    func_800D58AC();
    func_800D58CC();
    for (i = 0; i < 30; ++i) CHECK(!func_800D5A04(i));
    CHECK(!func_800D5B34(136) && !func_800D5A04(136));
    CHECK(!func_800D5B34(137) && !func_800D5A04(137));
    CHECK(!func_800D5B34(139) && !func_800D5A04(139));
}

static void test_copy_and_sampling(void) {
    s16 destination[16];
    u8 raw[4] = {42, 42, 42, 42};
    BoneTransformList *poses = func_800DFC80();
    s16 *resource = func_800D5B34(42);
    CHECK(resource && func_800D5944() == 20);
    func_800E0170(resource, 0.5f, 0, poses);
    CHECK(fabsf(poses->ptr[1].unk1C[0] - 42.5f) < 0.0001f);
    CHECK(func_800D56C4(resource) == 0);
    destination[0] = 1234;
    CHECK(!func_800D5EB4(1, (u8 *)destination, 31) && destination[0] == 1234);
    CHECK(func_800D5EB4(1, (u8 *)destination, sizeof(destination)) == 32);
    CHECK(func_800D5944() == 32);
    func_800E0170(destination, 0.5f, 0, poses);
    CHECK(fabsf(poses->ptr[1].unk1C[0] - 1.5f) < 0.0001f);
    CHECK(!func_800D5EB4(138, raw, 2) && raw[0] == 42);
    if (getenv("BT_MOD_ORDER")) {
        CHECK(func_800D5EB4(138, raw, 4) == 3);
        CHECK(raw[0] == 'm' && raw[1] == 'o' && raw[2] == 'd' && raw[3] == 42);
    } else {
        CHECK(func_800D5EB4(138, raw, 4) == 16);
        CHECK(raw[0] == 'a' && raw[1] == 'b' && raw[2] == 'c' && raw[3] == 0);
    }
    func_800DFC60(poses);
}

static void test_original_archive(void) {
    int id, count = 0, bone;
    BoneTransformList *poses = func_800DFC80();
    for (id = 0; id < func_800D593C(); ++id) {
        s16 *resource;
        if (func_800D58FC(id) != 6) continue;
        resource = func_800D5B34(id);
        if (!resource) fprintf(stderr, "Failed animation asset %#x\n", id);
        CHECK(resource && func_800D5FE8(id) == resource);
        func_800DFAD0(poses);
        func_800E0170(resource, 0.5f, 1, poses);
        for (bone = 0; bone < poses->count; ++bone) {
            CHECK(isfinite(poses->ptr[bone].unk0[0]));
            CHECK(isfinite(poses->ptr[bone].unk1C[0]));
        }
        CHECK(func_800D56C4(resource) == 0 && !func_800D5A04(id));
        count++;
    }
    CHECK(count > 0);
    printf("Loaded and sampled %d original animations through the game asset manager\n", count);
    func_800DFC60(poses);
}

int main(int argc, char **argv) {
    CHECK(argc == 2 || argc == 3);
    if (argc == 3) CHECK(!native_assets_open(argv[2]));
    CHECK(native_assets_open(argv[1]));
    CHECK(!native_assets_open(argv[1]));
    if (argc == 3) {
        test_cache();
        test_copy_and_sampling();
        CHECK(func_800D5B34(3)); /* Shutdown also frees an outstanding reference. */
    } else test_original_archive();
    native_assets_close();
    CHECK(native_asset_count() == 0 && !func_800D5B34(1));
    native_assets_close();
    CHECK(native_assets_open(argv[1]));
    native_assets_close();
    puts("Native asset loading and reference lifetime checks passed");
    return 0;
}

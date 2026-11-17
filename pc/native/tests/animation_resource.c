#include "core2/animation_resource.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

static void near(f32 actual, f32 expected) {
    CHECK(fabsf(actual - expected) < 0.0001f);
}
static f32 sample(u16 *channel, f32 time, s32 period) {
    return func_800E04C0((u8 *)channel, time, period);
}

static void test_channels(void) {
    u16 linear[] = {0x16, 2, 2, 256, 6, 1280};
    u16 cubic[] = {0x16, 4, 0, 0, 0x4002, 256, 0x8006, 1024, 8, 1280};
    u16 angle[] = {0x19, 2, 0, 21760, 10, (u16)-21760};
    u16 single[] = {0x19, 1, 0, (u16)-11520};
    /* Expected values follow 1EB9DB0.s: keys / 64, cubic keys / 128. */
    near(sample(linear, 0, 0), 4);
    near(sample(linear, 2, 0), 4);
    near(sample(linear, 4, 0), 12);
    near(sample(linear, 6, 0), 20);
    near(sample(linear, 9, 0), 20);
    near(sample(linear, 0, 10), 28.0f / 3.0f);
    near(sample(linear, 9, 10), 12);
    near(sample(cubic, 3, 0), 6.625f);
    cubic[6] = 6;
    near(sample(cubic, 3, 0), 6.71875f);
    cubic[4] = 2; cubic[6] = 0x8006;
    near(sample(cubic, 3, 0), 6.34375f);
    cubic[6] = 6;
    near(sample(cubic, 3, 0), 7.0f);
    near(sample(angle, 5, 0), 0);    /* 340 -> -340 unwraps to 380; midpoint 360 wraps to 0 */
    near(sample(angle, 10, 0), 20);
    angle[0] = 0x10;
    near(sample(angle, 5, 0), 0);
    near(sample(single, 4, 0), -180);
    near(sample(single, 40, 10), -180);
}

static const u16 resource_words[] = {
    0, 10, 5, 0,
    0x19, 2, 0, 0, 10, 11520,
    0x13, 1, 0, 256,
    0x16, 2, 0, 0, 10, 1280,
    0x17, 2, 0, 256, 10, 768,
    0x6C8, 1, 0, (u16)-256
};

static void pack_resource(u8 *bytes) {
    size_t i;
    for (i = 0; i < sizeof(resource_words) / sizeof(resource_words[0]); ++i) {
        bytes[2 * i] = resource_words[i] >> 8;
        bytes[2 * i + 1] = resource_words[i];
    }
}

static void test_decode_and_pose(void) {
    u8 bytes[sizeof(resource_words)];
    s16 *resource;
    BoneTransformList *poses = func_800DFC80();
    f32 transform[9], positions[2] = {-1, -1};
    pack_resource(bytes);
    resource = native_animation_decode(bytes, sizeof(bytes));
    CHECK(resource);
    CHECK(func_800E0448(resource) == 0 && func_800E0440(resource) == 10);
    CHECK(func_800E0450(resource) == 11 && func_800E0464(resource) == 5);
    near(func_800E0414(resource, 0.5f), 5);
    near(func_800E046C(resource, 10), 0.9999989867f);
    near(func_800E046C(resource, 3), 0.3f);
    func_800E0050(resource, 0.5f, 1, transform);
    near(transform[0], 90);
    near(transform[3], 4);
    near(transform[4], 1);
    near(transform[6], 10);
    near(transform[7], 8);
    func_800E02F8(resource, 0.5f, 0, 1, 108, positions);
    near(positions[0], 8);
    near(positions[1], -1);
    func_800E0170(resource, 0.5f, 0, poses);
    near(poses->ptr[1].unk0[0], 0.707106781f);
    near(poses->ptr[1].unk0[3], 0.707106781f);
    near(poses->ptr[1].scale[0], 4);
    near(poses->ptr[1].unk1C[0], 10);
    near(poses->ptr[1].unk1C[1], 8);
    near(poses->ptr[108].unk1C[2], -4);
    near(poses->ptr[0].unk0[3], 1);
    func_800E04AC(resource);
    heap_free(resource);
    func_800DFC60(poses);
}

static void test_invalid_resources(void) {
    u8 bytes[sizeof(resource_words)];
    s16 *resource;
    f32 transform[9];
    size_t size;
    pack_resource(bytes);
    CHECK(!native_animation_decode(NULL, sizeof(bytes)));
    for (size = 0; size < sizeof(bytes); ++size) CHECK(!native_animation_decode(bytes, size));
    bytes[8] = 0; bytes[9] = 9;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[8] = 6; bytes[9] = 0xD9;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[9] = 0x1C;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[10] = 0xFF; bytes[11] = 0xFF;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[11] = 0;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[13] = 1; bytes[17] = 0;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
    pack_resource(bytes); bytes[17] = 0;
    resource = native_animation_decode(bytes, sizeof(bytes));
    CHECK(resource);
    func_800E0050(resource, 0, 1, transform);
    near(transform[0], 90);
    heap_free(resource);
    pack_resource(bytes); bytes[1] = 11;
    CHECK(!native_animation_decode(bytes, sizeof(bytes)));
}

static void test_resource_file(const char *path) {
    FILE *file = fopen(path, "rb");
    long size;
    u8 *bytes;
    s16 *resource;
    BoneTransformList *poses;
    int loop, frame, bone, component;
    CHECK(file && fseek(file, 0, SEEK_END) == 0);
    size = ftell(file);
    CHECK(size > 0 && size < 1024 * 1024 && fseek(file, 0, SEEK_SET) == 0);
    bytes = malloc((size_t)size);
    CHECK(bytes && fread(bytes, 1, (size_t)size, file) == (size_t)size);
    CHECK(fclose(file) == 0);
    resource = native_animation_decode(bytes, (size_t)size);
    if (!resource) fprintf(stderr, "Invalid animation: %s\n", path);
    CHECK(resource);
    free(bytes);
    poses = func_800DFC80();
    for (loop = 0; loop < 2; ++loop) {
        for (frame = 0; frame <= 8; ++frame) {
            func_800DFAD0(poses);
            func_800E0170(resource, frame / 8.0f, loop, poses);
            for (bone = 0; bone < poses->count; ++bone) {
                f32 length = 0;
                for (component = 0; component < 4; ++component) {
                    f32 value = poses->ptr[bone].unk0[component];
                    CHECK(isfinite(value));
                    length += value * value;
                }
                near(length, 1);
                for (component = 0; component < 3; ++component) {
                    CHECK(isfinite(poses->ptr[bone].scale[component]));
                    CHECK(isfinite(poses->ptr[bone].unk1C[component]));
                }
            }
        }
    }
    func_800DFC60(poses);
    heap_free(resource);
}

int main(int argc, char **argv) {
    int i;
    test_channels();
    test_decode_and_pose();
    test_invalid_resources();
    for (i = 1; i < argc; ++i) test_resource_file(argv[i]);
    printf("Native animation sampling passed; %d external resources checked\n", argc - 1);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "core2/1EB93C0.h"
#include "memory.h"
#include <math.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

static void near_vector(f32 *actual, f32 *expected, int count) {
    int i;
    for (i = 0; i < count; ++i) CHECK(fabsf(actual[i] - expected[i]) < 0.00001f);
}

static void identity(BoneTransformList *list) {
    int i;
    CHECK(list->count == 109);
    CHECK(list->ptr == (BoneTransform *)(list + 1));
    for (i = 0; i < list->count; ++i) {
        near_vector(list->ptr[i].unk0, (f32[]){0, 0, 0, 1}, 4);
        near_vector(list->ptr[i].scale, (f32[]){1, 1, 1}, 3);
        near_vector(list->ptr[i].unk1C, (f32[]){0, 0, 0}, 3);
    }
}

static void test_access_and_relocation(void) {
    BoneTransformList *list = func_800DFC80();
    BoneTransformList *moved;
    f32 q[4], scale[3], position[3];
    int indices[] = {0, 108};
    int i;
    identity(list);
    for (i = 0; i < 2; ++i) {
        int index = indices[i];
        func_800DFF2C(list, index, (f32[]){0, 1, 0, 0});
        func_800DFF64(list, index, (f32[]){2, 3, 4});
        func_800DFFA0(list, index, (f32[]){-1, 7, 12});
        func_800DFB40(list, index, q);
        func_800DFBE0(list, index, scale);
        func_800DFC20(list, index, position);
        near_vector(q, (f32[]){0, 1, 0, 0}, 4);
        near_vector(scale, (f32[]){2, 3, 4}, 3);
        near_vector(position, (f32[]){-1, 7, 12}, 3);
        func_800DFB7C(list, index, q, scale, position);
        near_vector(q, (f32[]){0, 1, 0, 0}, 4);
        near_vector(scale, (f32[]){2, 3, 4}, 3);
        near_vector(position, (f32[]){-1, 7, 12}, 3);
    }
    CHECK(func_800E0018(list) == list);
    moved = malloc(sizeof(*list) + list->count * sizeof(*list->ptr));
    CHECK(moved);
    rare_memcpy(moved, list, sizeof(*list) + list->count * sizeof(*list->ptr));
    func_800E0040(moved);
    func_800DFC60(list);
    CHECK(moved->ptr == (BoneTransform *)(moved + 1));
    func_800DFC20(moved, 108, position);
    near_vector(position, (f32[]){-1, 7, 12}, 3);
    func_800DFAD0(moved);
    identity(moved);
    func_800DFC60(moved);
}

static void test_blending_and_handles(void) {
    s16 first = func_800DFD10(), second = func_800DFD10();
    BoneTransformList *a = func_800DFCE8(first), *b = func_800DFCE8(second);
    BoneTransformList *dst = func_800DFC80();
    f32 q[4];
    int i;
    CHECK(first != 0 && second != 0 && first != second && a != b);
    identity(a);
    identity(b);
    func_800DFFDC(b, 108, (f32[]){0, 90, 0});
    func_800DFF64(b, 108, (f32[]){5, 9, 13});
    func_800DFFA0(b, 108, (f32[]){8, -4, 12});
    func_800DFD64(dst, a, b, 0.5f);
    near_vector(dst->ptr[108].unk0, (f32[]){0, 0.382683432f, 0, 0.923879533f}, 4);
    near_vector(dst->ptr[108].scale, (f32[]){3, 5, 7}, 3);
    near_vector(dst->ptr[108].unk1C, (f32[]){4, -2, 6}, 3);
    near_vector(dst->ptr[0].unk0, (f32[]){0, 0, 0, 1}, 4);
    func_800DFD64(dst, a, b, 0);
    near_vector(dst->ptr[108].unk0, a->ptr[108].unk0, 4);
    func_800DFD64(dst, a, b, 1);
    near_vector(dst->ptr[108].unk0, b->ptr[108].unk0, 4);
    /* q and -q describe the same rotation; interpolation must take the short arc. */
    for (i = 0; i < 4; ++i) q[i] = -b->ptr[108].unk0[i];
    func_800DFF2C(a, 108, q);
    func_800DFD64(dst, a, b, 0.5f);
    near_vector(dst->ptr[108].unk0, q, 4);
    func_800DFEA8(b, dst);
    for (i = 0; i < 109; ++i) {
        near_vector(dst->ptr[i].unk0, b->ptr[i].unk0, 4);
        near_vector(dst->ptr[i].scale, b->ptr[i].scale, 3);
        near_vector(dst->ptr[i].unk1C, b->ptr[i].unk1C, 3);
    }
    func_800DFD64(dst, dst, b, 0.25f);
    for (i = 0; i < 109; ++i) {
        near_vector(dst->ptr[i].unk0, b->ptr[i].unk0, 4);
        near_vector(dst->ptr[i].scale, b->ptr[i].scale, 3);
        near_vector(dst->ptr[i].unk1C, b->ptr[i].unk1C, 3);
    }
    func_800DFCC0(first);
    func_800DFCC0(second);
    first = func_800DFD10();
    identity(func_800DFCE8(first));
    func_800DFCC0(first);
    func_800DFC60(dst);
}

static void test_euler_convention(void) {
    BoneTransformList *list = func_800DFC80();
    int axis;
    for (axis = 0; axis < 3; ++axis) {
        f32 angles[3] = {0, 0, 0}, expected[4] = {0, 0, 0, 0.707106781f};
        angles[axis] = 90;
        expected[axis] = 0.707106781f;
        func_800DFFDC(list, 0, angles);
        near_vector(list->ptr[0].unk0, expected, 4);
    }
    /* Combined axes distinguish the game's rotation order from other conventions. */
    func_800DFFDC(list, 0, (f32[]){90, 90, 90});
    near_vector(list->ptr[0].unk0, (f32[]){0.707106781f, 0, 0, 0.707106781f}, 4);
    func_800DFFDC(list, 0, (f32[]){0, 0, 0});
    near_vector(list->ptr[0].unk0, (f32[]){0, 0, 0, 1}, 4);
    func_800DFC60(list);
}

int main(void) {
    test_access_and_relocation();
    test_blending_and_handles();
    test_euler_convention();
    puts("Native bone pose storage, handles and quaternion blending passed");
    return 0;
}

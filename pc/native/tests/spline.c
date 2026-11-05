#include "core2/1EA1270.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

typedef struct {
    s16 id;
    u8 count, mode, clock, padding[3];
    f32 length, loop;
    s16 ids, padding_end;
    f32 points[6][3];
} TestSpline;
_Static_assert(offsetof(TestSpline, points) == 20, "game spline coordinate offset");

f32 func_800D8FF8(void) { return 0.1f; }
f32 _glintrosyncDll_entrypoint_5(void) { return 0.2f; }
f32 func_800136E4(f32);
f32 func_80013B7C(f32, f32);

static void near(f32 actual, f32 expected, f32 tolerance) {
    if (!isfinite(actual) || fabsf(actual - expected) > tolerance) {
        fprintf(stderr, "actual %.8g, expected %.8g, tolerance %.8g\n", actual, expected, tolerance);
        exit(1);
    }
}

static void test_line(void) {
    TestSpline line = {.count = 2, .points = {{0, 0, 0}, {3, 4, 0}}};
    f32 position[3], rotation[3], derivative[3], query[3] = {0.9f, 1.2f, 0};
    s32 wrapped;
    CHECK(func_800C79EC((Unk800C7A68 *)&line) == mlspline_entrypoint_0);
    CHECK(func_800C7980((u8 *)&line) == mlspline_entrypoint_6);
    func_800C7A68((Unk800C7A68 *)&line, -1, position);
    near(position[0], 0, 0);
    func_800C7A68((Unk800C7A68 *)&line, 2, position);
    near(position[1], 4, 0);
    func_800C7A68((Unk800C7A68 *)&line, 0.25f, position);
    near(position[0], 0.75f, 0.00001f);
    near(position[1], 1, 0.00001f);
    func_800C7980((u8 *)&line)(0.5f, 2, line.points, derivative);
    near(derivative[0], 3, 0); near(derivative[1], 4, 0);
    near(func_800C7AE4((u8 *)&line, 0, 1), 5, 0.00001f);
    near(func_800C7B28((u8 *)&line, 0.25f, 0.75f, 8), 2.5f, 0.00001f);
    near(func_800C7AE4((u8 *)&line, 1, 0), 5, 0.00001f);
    near(func_800C7E28(&line), 1, 0);
    near(func_800C82CC(&line, query), 0.3f, 0.00001f);
    near(func_800C7FD4((u8 *)&line, 0.2f, 5), 0.3f, 0.0001f);
    line.clock = 1;
    near(func_800C7FD4((u8 *)&line, 0.2f, 5), 0.4f, 0.0001f);
    near(func_800C8070((u8 *)&line, 0.9f, 5, &wrapped), 1, 0);
    CHECK(wrapped == 0);
    near(func_800C8070((u8 *)&line, 0.1f, -5, &wrapped), 0, 0);
    CHECK(wrapped == 0);
    func_800C810C((u8 *)&line, 0.5f, derivative, rotation);
    near(derivative[0], 0.6f, 0.00001f);
    near(derivative[1], 0.8f, 0.00001f);
    near(rotation[0], 53.130102f, 0.001f);
    near(rotation[1], 270, 0.001f);
    near(rotation[2], 0, 0);
}

static void test_derivatives(void) {
    TestSpline curve = {.points = {{0, 1, -2}, {3, 4, 5}, {8, -1, 4},
                                   {10, 6, 0}, {14, 3, 7}, {20, 8, 2}}};
    int count, mode, sample, axis;
    f32 before[3], after[3], derivative[3];
    for (count = 2; count <= 6; ++count) {
        curve.count = count;
        for (mode = 0; mode < 2; ++mode) {
            curve.mode = mode;
            for (sample = 1; sample < 20; ++sample) {
                f32 t = sample / 20.0f;
                func_800C7A68((Unk800C7A68 *)&curve, t - 0.0001f, before);
                func_800C7A68((Unk800C7A68 *)&curve, t + 0.0001f, after);
                func_800C7980((u8 *)&curve)(t, count, curve.points, derivative);
                for (axis = 0; axis < 3; ++axis)
                    near(derivative[axis] * (count >= 4 ? count - 1 : 1),
                         (after[axis] - before[axis]) / 0.0002f, 0.15f);
            }
            CHECK(func_800C7AE4((u8 *)&curve, 0, 1) > 0);
        }
    }
    curve.count = 1;
    CHECK(!func_800C79EC((Unk800C7A68 *)&curve) && !func_800C7980((u8 *)&curve));
}

static void test_loop_and_angles(void) {
    TestSpline curve = {.count = 3, .points = {{0, 0, 0}, {10, 0, 0}, {0, 0, 0}}};
    s32 wrapped;
    f32 value;
    near(func_800C7E28(&curve), 0, 0);
    near(func_800C7AE4((u8 *)&curve, 0, 1), 20, 0.0001f);
    value = func_800C8070((u8 *)&curve, 0.99f, 10, &wrapped);
    CHECK(wrapped == 1 && value >= 0 && value < 0.1f);
    value = func_800C8070((u8 *)&curve, 0.01f, -10, &wrapped);
    CHECK(wrapped == 1 && value > 0.9f && value <= 1);
    near(func_800136E4(-450), 270, 0);
    near(func_800136E4(720), 0, 0);
    near(func_80013B7C(0, 0), 0, 0);
    near(func_80013B7C(1, -1), 135, 0.001f);
    near(func_80013B7C(-1, -1), 225, 0.001f);
    near(func_80013B7C(-1, 1), 315, 0.001f);
    curve.count = 2;
    curve.points[1][0] = 0;
    near(func_800C7B7C((Unk800C7A68 *)&curve, 0.3f, 1, 0), 0.3f, 0);
}

int main(void) {
    test_line();
    test_derivatives();
    test_loop_and_angles();
    puts("Native spline evaluation, derivatives, arc length and traversal passed");
    return 0;
}
